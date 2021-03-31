#include "stdafx.h"
#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>
#include <curl.h>
#include "socket_client.h"


// Need to link with Ws2_32.lib, Mswsock.lib, and Advapi32.lib
#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")

#pragma comment(lib, "crypt32.lib")
#pragma comment(lib, "Wldap32.lib")
#pragma comment(lib, "Normaliz.lib")



#define DEFAULT_BUFLEN 512
#define DEFAULT_PORT "27015"

#define g_DOCKERIP "52.55.157.242"
#define g_DOCKERPORT 8080

#define _FUNC_NAME __FUNCTION__
#define _ERROR -1
#define _SUCCESS 0

struct HttpCtx
{
	int returnCode;
	int statusCode;
	char *responseData;
	size_t responseDataSize;
}HttpCtx_t;

struct ResponseData
{
	char *memory;
	size_t size;
};



int SYSTEM_ThreadCreate(SystemThread hThread)//, void *(*pFnStartRoutine)(void *), void *pThreadParm)
{
	int iReturn = 0;

	hThread->handle = CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)hThread->pfFnStartRoutine, hThread->pThreadParm,0,NULL);
	if(hThread->handle == 0)
	{
		//LOG(LOG_DEBUG, "PLATFORM_ThreadCreate is fail!!\n");
		return -1;
	}
	return 0;

}


static size_t responseCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
	size_t realsize = size * nmemb;
	struct ResponseData *mem = (struct ResponseData *)userp; 
	char *ptr ;

	if( userp == NULL || contents == NULL || size == 0)return 0;

	ptr = (char*)realloc(mem->memory, mem->size + realsize + 1);
	if(ptr == NULL)
	{
		/* out of memory! */ 
		printf("not enough memory (realloc returned NULL)\n");
		return 0;
	}

	mem->memory = ptr;
	memcpy(&(mem->memory[mem->size]), contents, realsize);
	mem->size += realsize;
	mem->memory[mem->size] = 0;
	return realsize;
}

struct HttpCtx * libcurl_httpPostFunc(char *Path, char *Payload)
{
	int iReturn = _SUCCESS;
	CURL *curl;
	CURLcode res;
	char szURL[512];
	struct ResponseData chunk;
	struct HttpCtx *retHttpCtx = NULL;
	struct curl_slist *parameter = NULL;

	printf("Start libcurl_httpPostFunc...\n");	

	retHttpCtx = (struct HttpCtx*)malloc(sizeof(struct HttpCtx));
	memset(retHttpCtx, 0, sizeof(struct HttpCtx));

	curl_global_init(CURL_GLOBAL_ALL);
	curl = curl_easy_init();

	if(curl)
	{
		memset(szURL, 0, sizeof(szURL));
		sprintf(szURL, "http://%s:%d%s", g_DOCKERIP, g_DOCKERPORT, Path);
		printf("%s, POST URL: %s\n", _FUNC_NAME, szURL);

		//curl_easy_setopt(curl, CURLOPT_DEBUGFUNCTION, my_trace);
		curl_easy_setopt(curl, CURLOPT_URL, szURL);
		curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
		curl_easy_setopt(curl, CURLOPT_POST, 1L);
		curl_easy_setopt(curl, CURLOPT_NOSIGNAL, 1);
		curl_easy_setopt(curl, CURLOPT_TIMEOUT_MS, 20000L);
		/* complete connection within 10 seconds */
		curl_easy_setopt(curl, CURLOPT_CONNECTTIMEOUT_MS, 10000L);

		//set the type of HTTP content as JSON
		parameter=curl_slist_append(parameter, "Expect:");
		parameter=curl_slist_append(parameter, "Content-Type: application/json");
		//parameter=curl_slist_append(parameter, "charsets: utf-8");

		if( parameter == NULL )
		{
			curl_slist_free_all(parameter);
			goto FUNC_EXIT;
		}				
		curl_easy_setopt(curl, CURLOPT_HTTPHEADER, parameter);
		curl_easy_setopt(curl, CURLOPT_HEADER, 1);

		/* example.com is redirected, so we tell libcurl to follow redirection */ 
		curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
		/* abort if slower than 30 bytes/sec during 60 seconds */
		curl_easy_setopt(curl, CURLOPT_LOW_SPEED_TIME, 60L);
		curl_easy_setopt(curl, CURLOPT_LOW_SPEED_LIMIT, 60L);
		curl_easy_setopt(curl, CURLOPT_UPKEEP_INTERVAL_MS, 10000L);
		curl_easy_setopt(curl, CURLOPT_EXPECT_100_TIMEOUT_MS, 20000L);

		/* POSTFIELDS MUST be set */
		if ( Payload==NULL )
		{
			curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, 0);
			curl_easy_setopt(curl, CURLOPT_POSTFIELDS, "");
		}
		else
		{
			curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, strlen(Payload));
			curl_easy_setopt(curl, CURLOPT_POSTFIELDS, Payload);			
		}
		chunk.memory = (char*)malloc(1);  /* will be grown as needed by the realloc above */ 
		chunk.size = 0;    /* no data at this point */ 
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, responseCallback);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk);

		/* Perform the request, res will get the return code */ 
		res = curl_easy_perform(curl);

		/* Check for errors */ 
		if(res != CURLE_OK)
		{
			printf("%s, curl_easy_perform() failed: %s\n", _FUNC_NAME, curl_easy_strerror(res));
			iReturn = _ERROR;
			goto FUNC_EXIT;
		}
		curl_easy_getinfo (curl, CURLINFO_RESPONSE_CODE, &(retHttpCtx->statusCode));

		retHttpCtx->responseData = chunk.memory;
		retHttpCtx->responseDataSize = chunk.size;
	}
	else
	{
		printf("%s, curl_easy_init Fail!!!\n", _FUNC_NAME);
		iReturn = _ERROR;
		goto FUNC_EXIT;
	}

FUNC_EXIT:
	/* always cleanup */ 
	curl_easy_cleanup(curl);
	if(parameter!=NULL){
		curl_slist_free_all(parameter);
	}
	retHttpCtx->returnCode = iReturn;
	return retHttpCtx;
}



int post_count_send(char* deviceName, char* deviceId, char* appName, char* appID, char* userName, char* userID)
{
	struct HttpCtx *httpCtx = NULL;
	int iReturn = 0;
	char post_count_path[512] = "/dw/metering/count/raw";
	//char post_count_data[512] = "{\"deviceName\":\"device1\",\"deviceId\":\"ede98537-18a7-5c7b-8581-812dc48c5c80\",\"appName\":\"Production Visualization\",\"appId\":\"8f14e45fceea167a5a36dedd4bea2543\",\"userName\":\"mirdc@iii.org.tw\",\"userId\":\"f6e98537-18b7-4c7b-8581-812dc48c5c80\",\"type\":\"count\",\"countName\":\"APInumber\",\"count\":100}";
	char post_count_data[512] = "";
	sprintf(post_count_data, "{\"deviceName\":\"%s\",\"deviceId\":\"%s\",\"appName\":\"%s\",\"appId\":\"%s\",\"userName\":\"%s\",\"userId\":\"%s\",\"type\":\"count\",\"countName\":\"APInumber\",\"count\":100}", deviceName, deviceId, appName, appID, userName, userID);


	httpCtx = libcurl_httpPostFunc(post_count_path, post_count_data);

	if(httpCtx==NULL)
	{
		iReturn = _ERROR;
		goto FUNC_EXIT;
	}

	iReturn = httpCtx->statusCode;

FUNC_EXIT:

	return iReturn;
}


int post_time_send(char* deviceName, char* deviceId, char* appName, char* appID, char* userName, char* userID)
{
	struct HttpCtx *httpCtx = NULL;
	int iReturn = 0;
	char post_count_path[512] = "/dw/metering/time/raw";
	//char post_count_data[512] = "{\"deviceName\":\"device1\",\"deviceId\":\"ede98537-18a7-5c7b-8581-812dc48c5c80\",\"appName\":\"Production Visualization\",\"appId\":\"8f14e45fceea167a5a36dedd4bea2543\",\"userName\":\"mirdc@iii.org.tw\",\"userId\":\"f6e98537-18b7-4c7b-8581-812dc48c5c80\",\"type\":\"count\",\"countName\":\"APInumber\",\"count\":100}";
	char post_count_data[512] = "";
	sprintf(post_count_data, "{\"deviceName\":\"%s\",\"deviceId\":\"%s\",\"appName\":\"%s\",\"appId\":\"%s\",\"userName\":\"%s\",\"userId\":\"%s\",\"type\":\"time\",\"time\":3600}", deviceName, deviceId, appName, appID, userName, userID);


	httpCtx = libcurl_httpPostFunc(post_count_path, post_count_data);

	if(httpCtx==NULL)
	{
		iReturn = _ERROR;
		goto FUNC_EXIT;
	}

	iReturn = httpCtx->statusCode;

FUNC_EXIT:

	return iReturn;
}


int post_subscription_send(char* deviceName, char* deviceId, char* appName, char* appID, char* userName, char* userID)
{
	struct HttpCtx *httpCtx = NULL;
	int iReturn = 0;
	char post_count_path[512] = "/dw/metering/subscription/raw";
	//char post_count_data[512] = "{\"deviceName\":\"device1\",\"deviceId\":\"ede98537-18a7-5c7b-8581-812dc48c5c80\",\"appName\":\"Production Visualization\",\"appId\":\"8f14e45fceea167a5a36dedd4bea2543\",\"userName\":\"mirdc@iii.org.tw\",\"userId\":\"f6e98537-18b7-4c7b-8581-812dc48c5c80\",\"type\":\"count\",\"countName\":\"APInumber\",\"count\":100}";
	char post_count_data[512] = "";
	sprintf(post_count_data, "{\"deviceName\":\"%s\",\"deviceId\":\"%s\",\"appName\":\"%s\",\"appId\":\"%s\",\"userName\":\"%s\",\"userId\":\"%s\",\"type\":\"subscription/count/time\",\"year\":2021,\"month\":11}", deviceName, deviceId, appName, appID, userName, userID);


	httpCtx = libcurl_httpPostFunc(post_count_path, post_count_data);

	if(httpCtx==NULL)
	{
		iReturn = _ERROR;
		goto FUNC_EXIT;
	}

	iReturn = httpCtx->statusCode;

FUNC_EXIT:

	return iReturn;
}







#if 0
int post_subscription_send()
{
	struct HttpCtx *httpCtx = NULL;
	int iReturn = 0;
	char post_count_path[512] = "/dw/metering/subscription/raw";
	char post_count_data[512] = "{\"deviceName\":\"device1\",\"deviceId\":\"ede98537-18a7-5c7b-8581-812dc48c5c80\",\"appName\":\"Production Visualization\",\"appId\":\"8f14e45fceea167a5a36dedd4bea2543\",\"userName\":\"mirdc@iii.org.tw\",\"userId\":\"f6e98537-18b7-4c7b-8581-812dc48c5c80\",\"type\":\"subscription/count/time\",\"year\":2021,\"month\":11}";


	httpCtx = libcurl_httpPostFunc(post_count_path, post_count_data);

	if(httpCtx==NULL)
	{
		iReturn = _ERROR;
		goto FUNC_EXIT;
	}

	iReturn = httpCtx->statusCode;

FUNC_EXIT:

	return iReturn;
}
#endif









#if 0
//static DWORD FirmwareUpgrade(void *Data)
int tcp_send()
{
	WSADATA wsaData;
	SOCKET ConnectSocket = INVALID_SOCKET;
	struct addrinfo *result = NULL,
		*ptr = NULL,
		hints;
	const char *sendbuf = "this is a test";
	char recvbuf[DEFAULT_BUFLEN];
	int iResult;
	int recvbuflen = DEFAULT_BUFLEN;
	char serverIP[128] = "192.168.2.242";
	

#if 1
	//int argc = 2;

	/*
	// Validate the parameters
	if (argc != 2) {
		printf("usage: %s server-name\n", argv[0]);
		return 1;
	}
	*/

	// Initialize Winsock
	iResult = WSAStartup(MAKEWORD(2,2), &wsaData);
	if (iResult != 0) {
		printf("WSAStartup failed with error: %d\n", iResult);
		return 1;
	}

	ZeroMemory( &hints, sizeof(hints) );
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;

	// Resolve the server address and port
	//iResult = getaddrinfo(argv[1], DEFAULT_PORT, &hints, &result);
	iResult = getaddrinfo(serverIP, DEFAULT_PORT, &hints, &result);
	if ( iResult != 0 ) {
		printf("getaddrinfo failed with error: %d\n", iResult);
		WSACleanup();
		return 1;
	}

	// Attempt to connect to an address until one succeeds
	for(ptr=result; ptr != NULL ;ptr=ptr->ai_next) {

		// Create a SOCKET for connecting to server
		ConnectSocket = socket(ptr->ai_family, ptr->ai_socktype, 
			ptr->ai_protocol);
		if (ConnectSocket == INVALID_SOCKET) {
			printf("socket failed with error: %ld\n", WSAGetLastError());
			WSACleanup();
			return 1;
		}

		// Connect to server.
		iResult = connect( ConnectSocket, ptr->ai_addr, (int)ptr->ai_addrlen);
		if (iResult == SOCKET_ERROR) {
			closesocket(ConnectSocket);
			ConnectSocket = INVALID_SOCKET;
			continue;
		}
		break;
	}

	freeaddrinfo(result);

	if (ConnectSocket == INVALID_SOCKET) {
		printf("Unable to connect to server!\n");
		WSACleanup();
		return 1;
	}

	// Send an initial buffer
	iResult = send( ConnectSocket, sendbuf, (int)strlen(sendbuf), 0 );
	if (iResult == SOCKET_ERROR) {
		printf("send failed with error: %d\n", WSAGetLastError());
		closesocket(ConnectSocket);
		WSACleanup();
		return 1;
	}

	printf("Bytes Sent: %ld\n", iResult);

	// shutdown the connection since no more data will be sent
	iResult = shutdown(ConnectSocket, SD_SEND);
	if (iResult == SOCKET_ERROR) {
		printf("shutdown failed with error: %d\n", WSAGetLastError());
		closesocket(ConnectSocket);
		WSACleanup();
		return 1;
	}

#if 0
	// Receive until the peer closes the connection
	do {

		iResult = recv(ConnectSocket, recvbuf, recvbuflen, 0);
		if ( iResult > 0 )
			printf("Bytes received: %d\n", iResult);
		else if ( iResult == 0 )
			printf("Connection closed\n");
		else
			printf("recv failed with error: %d\n", WSAGetLastError());

	} while( iResult > 0 );
#endif
	// cleanup
	closesocket(ConnectSocket);
	WSACleanup();
#endif



	return 0;
}
#endif

/*
int tcp_send()
{
	struct SystemThread_t firmwareUpgradeTH;

	firmwareUpgradeTH.pfFnStartRoutine = FirmwareUpgrade;
	//firmwareUpgradeTH.pThreadParm =(void*) NULL;
	firmwareUpgradeTH.pThreadParm = (void*) NULL;
	SYSTEM_ThreadCreate(&firmwareUpgradeTH);
	return 0;
}
*/


