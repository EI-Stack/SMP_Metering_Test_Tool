#include "socket_client.h"
#include <iostream>
#include <sstream>
#include <string>

//using namespace std;

#pragma once

namespace poyu_test {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	//using namespace System::String;
	using namespace std;

	/// <summary>
	/// Form1 的摘要
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: 在此加入建構函式程式碼
			//
		}

	protected:
		/// <summary>
		/// 清除任何使用中的資源。
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  btn_count;
	private: System::Windows::Forms::TextBox^  input_appID;
	protected: 


	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  count_response;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Button^  btn_time;

	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Button^  btn_subscription;
	private: System::Windows::Forms::Label^  label6;


	private: System::Windows::Forms::TextBox^  input_deviceId;


	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::TextBox^  input_appName;


	private: System::Windows::Forms::Label^  label10;

	private: System::Windows::Forms::TextBox^  input_userID;
	private: System::Windows::Forms::TextBox^  input_month;
	private: System::Windows::Forms::TextBox^  input_year;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Button^  btn_buyout;




	protected: 





	protected: 

	private:
		/// <summary>
		/// 設計工具所需的變數。
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器
		/// 修改這個方法的內容。
		/// </summary>
		void InitializeComponent(void)
		{
			this->btn_count = (gcnew System::Windows::Forms::Button());
			this->input_appID = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->count_response = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->btn_time = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->btn_subscription = (gcnew System::Windows::Forms::Button());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->input_deviceId = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->input_appName = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->input_userID = (gcnew System::Windows::Forms::TextBox());
			this->input_month = (gcnew System::Windows::Forms::TextBox());
			this->input_year = (gcnew System::Windows::Forms::TextBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->btn_buyout = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// btn_count
			// 
			this->btn_count->Location = System::Drawing::Point(269, 239);
			this->btn_count->Name = L"btn_count";
			this->btn_count->Size = System::Drawing::Size(87, 27);
			this->btn_count->TabIndex = 2;
			this->btn_count->Text = L"Exec";
			this->btn_count->UseVisualStyleBackColor = true;
			this->btn_count->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// input_appID
			// 
			this->input_appID->Location = System::Drawing::Point(118, 156);
			this->input_appID->Name = L"input_appID";
			this->input_appID->Size = System::Drawing::Size(217, 22);
			this->input_appID->TabIndex = 3;
			this->input_appID->Text = L"6512bd43d9caa6e02c990b0a82652dca";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label1->Location = System::Drawing::Point(12, 162);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(48, 16);
			this->label1->TabIndex = 4;
			this->label1->Text = L"appId:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label2->Location = System::Drawing::Point(9, 243);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(200, 16);
			this->label2->TabIndex = 5;
			this->label2->Text = L"POST  /dw/metering/count/raw";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label3->Location = System::Drawing::Point(9, 518);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(109, 16);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Response Code:";
			// 
			// count_response
			// 
			this->count_response->AutoSize = true;
			this->count_response->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->count_response->Location = System::Drawing::Point(124, 518);
			this->count_response->Name = L"count_response";
			this->count_response->Size = System::Drawing::Size(29, 16);
			this->count_response->TabIndex = 7;
			this->count_response->Text = L"\?\?\?";
			this->count_response->Click += gcnew System::EventHandler(this, &Form1::label4_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label4->Location = System::Drawing::Point(9, 300);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(192, 16);
			this->label4->TabIndex = 8;
			this->label4->Text = L"POST  /dw/metering/time/raw";
			// 
			// btn_time
			// 
			this->btn_time->Location = System::Drawing::Point(270, 292);
			this->btn_time->Name = L"btn_time";
			this->btn_time->Size = System::Drawing::Size(87, 27);
			this->btn_time->TabIndex = 9;
			this->btn_time->Text = L"Exec";
			this->btn_time->UseVisualStyleBackColor = true;
			this->btn_time->Click += gcnew System::EventHandler(this, &Form1::btn_time_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label5->Location = System::Drawing::Point(11, 351);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(241, 16);
			this->label5->TabIndex = 10;
			this->label5->Text = L"POST  /dw/metering/subscription/raw";
			// 
			// btn_subscription
			// 
			this->btn_subscription->Location = System::Drawing::Point(270, 347);
			this->btn_subscription->Name = L"btn_subscription";
			this->btn_subscription->Size = System::Drawing::Size(87, 27);
			this->btn_subscription->TabIndex = 11;
			this->btn_subscription->Text = L"Exec";
			this->btn_subscription->UseVisualStyleBackColor = true;
			this->btn_subscription->Click += gcnew System::EventHandler(this, &Form1::btn_subscription_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label6->Location = System::Drawing::Point(12, 87);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(66, 16);
			this->label6->TabIndex = 12;
			this->label6->Text = L"deviceId:";
			// 
			// input_deviceId
			// 
			this->input_deviceId->Location = System::Drawing::Point(118, 81);
			this->input_deviceId->Name = L"input_deviceId";
			this->input_deviceId->Size = System::Drawing::Size(238, 22);
			this->input_deviceId->TabIndex = 15;
			this->input_deviceId->Text = L"E3B3D13ADAB443D64E800CA88B06FC8F";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label8->Location = System::Drawing::Point(12, 124);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(72, 16);
			this->label8->TabIndex = 16;
			this->label8->Text = L"appName:";
			// 
			// input_appName
			// 
			this->input_appName->Location = System::Drawing::Point(118, 118);
			this->input_appName->Name = L"input_appName";
			this->input_appName->Size = System::Drawing::Size(143, 22);
			this->input_appName->TabIndex = 17;
			this->input_appName->Text = L"OPCUA";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label10->Location = System::Drawing::Point(12, 45);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(51, 16);
			this->label10->TabIndex = 19;
			this->label10->Text = L"userId:";
			// 
			// input_userID
			// 
			this->input_userID->Location = System::Drawing::Point(118, 42);
			this->input_userID->Name = L"input_userID";
			this->input_userID->Size = System::Drawing::Size(143, 22);
			this->input_userID->TabIndex = 21;
			this->input_userID->Text = L"paul@itri.org.tw";
			// 
			// input_month
			// 
			this->input_month->Location = System::Drawing::Point(217, 379);
			this->input_month->Name = L"input_month";
			this->input_month->Size = System::Drawing::Size(22, 22);
			this->input_month->TabIndex = 22;
			this->input_month->Text = L"6";
			this->input_month->TextChanged += gcnew System::EventHandler(this, &Form1::input_month_TextChanged);
			// 
			// input_year
			// 
			this->input_year->Location = System::Drawing::Point(175, 379);
			this->input_year->Name = L"input_year";
			this->input_year->Size = System::Drawing::Size(34, 22);
			this->input_year->TabIndex = 23;
			this->input_year->Text = L"2021";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label11->Location = System::Drawing::Point(86, 380);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(83, 16);
			this->label11->TabIndex = 24;
			this->label11->Text = L"year/month:";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label12->Location = System::Drawing::Point(208, 380);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(12, 16);
			this->label12->TabIndex = 25;
			this->label12->Text = L"/";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label7->Location = System::Drawing::Point(11, 431);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(209, 16);
			this->label7->TabIndex = 26;
			this->label7->Text = L"POST  /dw/metering/buyout/raw";
			// 
			// btn_buyout
			// 
			this->btn_buyout->Location = System::Drawing::Point(269, 427);
			this->btn_buyout->Name = L"btn_buyout";
			this->btn_buyout->Size = System::Drawing::Size(87, 27);
			this->btn_buyout->TabIndex = 27;
			this->btn_buyout->Text = L"Exec";
			this->btn_buyout->UseVisualStyleBackColor = true;
			this->btn_buyout->Click += gcnew System::EventHandler(this, &Form1::btn_buyout_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(415, 601);
			this->Controls->Add(this->btn_buyout);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->input_year);
			this->Controls->Add(this->input_month);
			this->Controls->Add(this->input_userID);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->input_appName);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->input_deviceId);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->btn_subscription);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->btn_time);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->count_response);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->input_appID);
			this->Controls->Add(this->btn_count);
			this->Controls->Add(this->label12);
			this->Name = L"Form1";
			this->Text = L"Metering API Test Tool";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {

				 /*
				 double temp;
				 temp = Convert::ToDouble(tbTempF->Text)-32.0;
				 temp = temp / 9.0;
				 temp = temp * 5.0; 
				 tbTempC->Text = Convert::ToString(temp);
				 */

				 //String^ deviceName_s;
				 int response_code = -1;

				 //char deviceName[256] = "";
				 char deviceId[256] = "";
				 char appName[256] = "";
				 char appID[256] = "";
				 //char userName[256] = "";
				 char userID[256] = "";


				 //deviceName_s = Convert::ToString(input_deviceName->Text);
				 //sprintf(deviceName, "%s", deviceName_s);
				 //sprintf(deviceName, "%s", Convert::ToString(input_deviceName->Text));
				 sprintf(deviceId, "%s", Convert::ToString(input_deviceId->Text));
				 sprintf(appName, "%s", Convert::ToString(input_appName->Text));
				 sprintf(appID, "%s", Convert::ToString(input_appID->Text));
				 //sprintf(userName, "%s", Convert::ToString(input_userName->Text));
				 sprintf(userID, "%s", Convert::ToString(input_userID->Text));


				 
				 response_code = post_count_send(deviceId, appName, appID,  userID);

				 count_response->Text = Convert::ToString(response_code);

			 } // end btnConvert_Click
			 
	private: System::Void label4_Click(System::Object^  sender, System::EventArgs^  e) {
			 }

	private: System::Void btn_time_Click(System::Object^  sender, System::EventArgs^  e) {
				 int response_code = -1;

				 //char deviceName[256] = "";
				 char deviceId[256] = "";
				 char appName[256] = "";
				 char appID[256] = "";
				 //char userName[256] = "";
				 char userID[256] = "";

				 //sprintf(deviceName, "%s", Convert::ToString(input_deviceName->Text));
				 sprintf(deviceId, "%s", Convert::ToString(input_deviceId->Text));
				 sprintf(appName, "%s", Convert::ToString(input_appName->Text));
				 sprintf(appID, "%s", Convert::ToString(input_appID->Text));
				 //sprintf(userName, "%s", Convert::ToString(input_userName->Text));
				 sprintf(userID, "%s", Convert::ToString(input_userID->Text));

				 response_code = post_time_send(deviceId, appName, appID, userID);

				 count_response->Text = Convert::ToString(response_code);

			 }
	private: System::Void btn_subscription_Click(System::Object^  sender, System::EventArgs^  e) {

				 int response_code = -1;

				 //char deviceName[256] = "";
				 char deviceId[256] = "";
				 char appName[256] = "";
				 char appID[256] = "";
				 //char userName[256] = "";
				 char userID[256] = "";
				 char year[32] = "";
				 char month[32] = "";

				 //sprintf(deviceName, "%s", Convert::ToString(input_deviceName->Text));
				 sprintf(deviceId, "%s", Convert::ToString(input_deviceId->Text));
				 sprintf(appName, "%s", Convert::ToString(input_appName->Text));
				 sprintf(appID, "%s", Convert::ToString(input_appID->Text));
				 //sprintf(userName, "%s", Convert::ToString(input_userName->Text));
				 sprintf(userID, "%s", Convert::ToString(input_userID->Text));
				 sprintf(year, "%s", Convert::ToString(input_year->Text));
				 sprintf(month, "%s", Convert::ToString(input_month->Text));

				 response_code = post_subscription_send(deviceId, appName, appID, userID, year, month);

				 count_response->Text = Convert::ToString(response_code);
		 }
private: System::Void label7_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void input_month_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void btn_buyout_Click(System::Object^  sender, System::EventArgs^  e) {


			 int response_code = -1;

			 char deviceId[256] = "";
			 char appName[256] = "";
			 char appID[256] = "";
			 char userID[256] = "";

			 sprintf(deviceId, "%s", Convert::ToString(input_deviceId->Text));
			 sprintf(appName, "%s", Convert::ToString(input_appName->Text));
			 sprintf(appID, "%s", Convert::ToString(input_appID->Text));
			 sprintf(userID, "%s", Convert::ToString(input_userID->Text));


			 response_code = post_buyout_send(deviceId, appName, appID, userID);

			 count_response->Text = Convert::ToString(response_code);




		 }
};
}

