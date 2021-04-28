#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <Windows.h>

struct SystemThread_t
{
	HANDLE handle;
	DWORD (*pfFnStartRoutine)(void *);
	void* pThreadParm;
};

#define SystemThread struct SystemThread_t*

int post_count_send(char* deviceId, char* appName, char* appID, char* userID);
int post_time_send(char* deviceId, char* appName, char* appID, char* userID);
int post_subscription_send(char* deviceId, char* appName, char* appID, char* userID, char* year, char* month);
int post_buyout_send(char* deviceId, char* appName, char* appID, char* userID);
