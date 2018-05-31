#pragma once#
#include"Number.h"
#include"Calculator.h"
#include<iostream>
#include <sstream>
#include<vector>
#include <string>  
#include <iostream>  
#include<cctype>
//using namespace std;
using namespace System;
Calculator *c=new Calculator();

std::string  inputString;

std::string toString(std::ostream& str)
{
	std::ostringstream ss;
	ss << str.rdbuf();
	return ss.str();
}

void MarshalString(String ^ s, std::string& os) {
	using namespace Runtime::InteropServices;
	const char* chars =
		(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
	os = chars;
	Marshal::FreeHGlobal(IntPtr((void*)chars));
}

namespace Bigcalc {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;




	/// <summary>
	/// MyForm 的摘要
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO:  在此加入建構函式程式碼
			//
		}

	protected:
		/// <summary>
		/// 清除任何使用中的資源。
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	protected:
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::Button^  button7;
	private: System::Windows::Forms::Button^  button8;
	private: System::Windows::Forms::Button^  button9;
	private: System::Windows::Forms::Button^  button10;

	private: System::Windows::Forms::Button^  button12;
	private: System::Windows::Forms::Button^  button13;
	private: System::Windows::Forms::Button^  button14;
	private: System::Windows::Forms::Button^  button15;
	private: System::Windows::Forms::Button^  button16;
	private: System::Windows::Forms::Button^  button17;

	private: System::Windows::Forms::Button^  button19;

	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^  button21;
	private: System::Windows::Forms::Button^  button22;
	private: System::Windows::Forms::Button^  button23;
	private: System::Windows::Forms::Button^  button20;
	private: System::Windows::Forms::Button^  button24;
	private: System::Windows::Forms::Button^  button25;
	private: System::Windows::Forms::Button^  button26;
	private: System::Windows::Forms::Button^  button27;
	private: System::Windows::Forms::Button^  button11;
	private: System::Windows::Forms::Button^  button18;
	private: System::Windows::Forms::Button^  button28;

	private: System::ComponentModel::IContainer^  components;


			 //private: TextBox textBox1;



	private:
		/// <summary>
		/// 設計工具所需的變數。
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器修改
		/// 這個方法的內容。
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->button12 = (gcnew System::Windows::Forms::Button());
			this->button13 = (gcnew System::Windows::Forms::Button());
			this->button14 = (gcnew System::Windows::Forms::Button());
			this->button15 = (gcnew System::Windows::Forms::Button());
			this->button16 = (gcnew System::Windows::Forms::Button());
			this->button17 = (gcnew System::Windows::Forms::Button());
			this->button19 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button21 = (gcnew System::Windows::Forms::Button());
			this->button22 = (gcnew System::Windows::Forms::Button());
			this->button23 = (gcnew System::Windows::Forms::Button());
			this->button20 = (gcnew System::Windows::Forms::Button());
			this->button24 = (gcnew System::Windows::Forms::Button());
			this->button25 = (gcnew System::Windows::Forms::Button());
			this->button26 = (gcnew System::Windows::Forms::Button());
			this->button27 = (gcnew System::Windows::Forms::Button());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->button18 = (gcnew System::Windows::Forms::Button());
			this->button28 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(16, 215);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(55, 48);
			this->button1->TabIndex = 0;
			this->button1->Text = L"1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(86, 215);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(55, 48);
			this->button2->TabIndex = 1;
			this->button2->Text = L"2";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(157, 215);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(55, 48);
			this->button3->TabIndex = 2;
			this->button3->Text = L"3";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(16, 269);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(55, 48);
			this->button4->TabIndex = 3;
			this->button4->Text = L"4";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(86, 269);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(55, 48);
			this->button5->TabIndex = 4;
			this->button5->Text = L"5";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(157, 269);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(55, 48);
			this->button6->TabIndex = 5;
			this->button6->Text = L"6";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(16, 323);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(55, 48);
			this->button7->TabIndex = 6;
			this->button7->Text = L"7";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &MyForm::button7_Click);
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(157, 323);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(55, 48);
			this->button8->TabIndex = 7;
			this->button8->Text = L"9";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &MyForm::button8_Click);
			// 
			// button9
			// 
			this->button9->Location = System::Drawing::Point(86, 323);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(55, 48);
			this->button9->TabIndex = 7;
			this->button9->Text = L"8";
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &MyForm::button9_Click);
			// 
			// button10
			// 
			this->button10->Location = System::Drawing::Point(86, 377);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(55, 48);
			this->button10->TabIndex = 8;
			this->button10->Text = L"0";
			this->button10->UseVisualStyleBackColor = true;
			this->button10->Click += gcnew System::EventHandler(this, &MyForm::button10_Click);
			// 
			// button12
			// 
			this->button12->Location = System::Drawing::Point(157, 377);
			this->button12->Name = L"button12";
			this->button12->Size = System::Drawing::Size(55, 48);
			this->button12->TabIndex = 10;
			this->button12->Text = L".";
			this->button12->UseVisualStyleBackColor = true;
			this->button12->Click += gcnew System::EventHandler(this, &MyForm::button12_Click);
			// 
			// button13
			// 
			this->button13->Location = System::Drawing::Point(227, 164);
			this->button13->Name = L"button13";
			this->button13->Size = System::Drawing::Size(55, 48);
			this->button13->TabIndex = 11;
			this->button13->Text = L"/";
			this->button13->UseVisualStyleBackColor = true;
			this->button13->Click += gcnew System::EventHandler(this, &MyForm::button13_Click);
			// 
			// button14
			// 
			this->button14->Location = System::Drawing::Point(227, 218);
			this->button14->Name = L"button14";
			this->button14->Size = System::Drawing::Size(55, 48);
			this->button14->TabIndex = 12;
			this->button14->Text = L"*";
			this->button14->UseVisualStyleBackColor = true;
			this->button14->Click += gcnew System::EventHandler(this, &MyForm::button14_Click);
			// 
			// button15
			// 
			this->button15->Location = System::Drawing::Point(227, 272);
			this->button15->Name = L"button15";
			this->button15->Size = System::Drawing::Size(55, 48);
			this->button15->TabIndex = 13;
			this->button15->Text = L"-";
			this->button15->UseVisualStyleBackColor = true;
			this->button15->Click += gcnew System::EventHandler(this, &MyForm::button15_Click);
			// 
			// button16
			// 
			this->button16->Location = System::Drawing::Point(227, 326);
			this->button16->Name = L"button16";
			this->button16->Size = System::Drawing::Size(55, 48);
			this->button16->TabIndex = 14;
			this->button16->Text = L"+";
			this->button16->UseVisualStyleBackColor = true;
			this->button16->Click += gcnew System::EventHandler(this, &MyForm::button16_Click);
			// 
			// button17
			// 
			this->button17->Location = System::Drawing::Point(227, 380);
			this->button17->Name = L"button17";
			this->button17->Size = System::Drawing::Size(55, 48);
			this->button17->TabIndex = 15;
			this->button17->Text = L"=";
			this->button17->UseVisualStyleBackColor = true;
			this->button17->Click += gcnew System::EventHandler(this, &MyForm::button17_Click);
			// 
			// button19
			// 
			this->button19->Location = System::Drawing::Point(86, 164);
			this->button19->Name = L"button19";
			this->button19->Size = System::Drawing::Size(55, 48);
			this->button19->TabIndex = 17;
			this->button19->Text = L"C";
			this->button19->UseVisualStyleBackColor = true;
			this->button19->Click += gcnew System::EventHandler(this, &MyForm::button19_Click);
			// 
			// textBox1
			// 
			this->textBox1->AcceptsReturn = true;
			this->textBox1->AcceptsTab = true;
			this->textBox1->Location = System::Drawing::Point(16, 33);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(334, 53);
			this->textBox1->TabIndex = 20;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// button21
			// 
			this->button21->Location = System::Drawing::Point(16, 379);
			this->button21->Name = L"button21";
			this->button21->Size = System::Drawing::Size(55, 48);
			this->button21->TabIndex = 21;
			this->button21->Text = L"!";
			this->button21->UseVisualStyleBackColor = true;
			this->button21->Click += gcnew System::EventHandler(this, &MyForm::button21_Click);
			// 
			// button22
			// 
			this->button22->Location = System::Drawing::Point(157, 164);
			this->button22->Name = L"button22";
			this->button22->Size = System::Drawing::Size(55, 48);
			this->button22->TabIndex = 22;
			this->button22->Text = L"^";
			this->button22->UseVisualStyleBackColor = true;
			this->button22->Click += gcnew System::EventHandler(this, &MyForm::button22_Click);
			// 
			// button23
			// 
			this->button23->Location = System::Drawing::Point(16, 161);
			this->button23->Name = L"button23";
			this->button23->Size = System::Drawing::Size(55, 48);
			this->button23->TabIndex = 23;
			this->button23->Text = L"√";
			this->button23->UseVisualStyleBackColor = true;
			this->button23->Click += gcnew System::EventHandler(this, &MyForm::button23_Click);
			// 
			// button20
			// 
			this->button20->Location = System::Drawing::Point(16, 107);
			this->button20->Name = L"button20";
			this->button20->Size = System::Drawing::Size(55, 48);
			this->button20->TabIndex = 24;
			this->button20->Text = L"(";
			this->button20->UseVisualStyleBackColor = true;
			this->button20->Click += gcnew System::EventHandler(this, &MyForm::button20_Click);
			// 
			// button24
			// 
			this->button24->Location = System::Drawing::Point(86, 107);
			this->button24->Name = L"button24";
			this->button24->Size = System::Drawing::Size(55, 48);
			this->button24->TabIndex = 25;
			this->button24->Text = L")";
			this->button24->UseVisualStyleBackColor = true;
			this->button24->Click += gcnew System::EventHandler(this, &MyForm::button24_Click);
			// 
			// button25
			// 
			this->button25->Location = System::Drawing::Point(295, 164);
			this->button25->Name = L"button25";
			this->button25->Size = System::Drawing::Size(68, 48);
			this->button25->TabIndex = 26;
			this->button25->Text = L"Set ";
			this->button25->UseVisualStyleBackColor = true;
			this->button25->Click += gcnew System::EventHandler(this, &MyForm::button25_Click);
			// 
			// button26
			// 
			this->button26->Location = System::Drawing::Point(295, 272);
			this->button26->Name = L"button26";
			this->button26->Size = System::Drawing::Size(68, 48);
			this->button26->TabIndex = 27;
			this->button26->Text = L"Decimal ";
			this->button26->UseVisualStyleBackColor = true;
			this->button26->Click += gcnew System::EventHandler(this, &MyForm::button26_Click);
			// 
			// button27
			// 
			this->button27->Location = System::Drawing::Point(295, 218);
			this->button27->Name = L"button27";
			this->button27->Size = System::Drawing::Size(68, 48);
			this->button27->TabIndex = 28;
			this->button27->Text = L"Integer ";
			this->button27->UseVisualStyleBackColor = true;
			this->button27->Click += gcnew System::EventHandler(this, &MyForm::button27_Click);
			// 
			// button11
			// 
			this->button11->Location = System::Drawing::Point(295, 380);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(68, 48);
			this->button11->TabIndex = 29;
			this->button11->Text = L"Enter ";
			this->button11->UseVisualStyleBackColor = true;
			this->button11->Click += gcnew System::EventHandler(this, &MyForm::button11_Click_1);
			this->button11->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::button11_KeyDown);
			// 
			// button18
			// 
			this->button18->Location = System::Drawing::Point(157, 110);
			this->button18->Name = L"button18";
			this->button18->Size = System::Drawing::Size(55, 48);
			this->button18->TabIndex = 30;
			this->button18->Text = L"A";
			this->button18->UseVisualStyleBackColor = true;
			this->button18->Click += gcnew System::EventHandler(this, &MyForm::button18_Click);
			// 
			// button28
			// 
			this->button28->Location = System::Drawing::Point(227, 107);
			this->button28->Name = L"button28";
			this->button28->Size = System::Drawing::Size(55, 48);
			this->button28->TabIndex = 31;
			this->button28->Text = L"B";
			this->button28->UseVisualStyleBackColor = true;
			this->button28->Click += gcnew System::EventHandler(this, &MyForm::button28_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(375, 439);
			this->Controls->Add(this->button28);
			this->Controls->Add(this->button18);
			this->Controls->Add(this->button11);
			this->Controls->Add(this->button27);
			this->Controls->Add(this->button26);
			this->Controls->Add(this->button25);
			this->Controls->Add(this->button24);
			this->Controls->Add(this->button20);
			this->Controls->Add(this->button23);
			this->Controls->Add(this->button22);
			this->Controls->Add(this->button21);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button19);
			this->Controls->Add(this->button17);
			this->Controls->Add(this->button16);
			this->Controls->Add(this->button15);
			this->Controls->Add(this->button14);
			this->Controls->Add(this->button13);
			this->Controls->Add(this->button12);
			this->Controls->Add(this->button10);
			this->Controls->Add(this->button9);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		this->textBox1->Text = this->textBox1->Text + "1";
		//inputString += "1";
		this->Invalidate();
	}

	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		this->textBox1->Text += "2";
		//inputString += "2";
		this->Invalidate();
	}
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
		this->textBox1->Text += "3";
		//inputString += "3";
		this->Invalidate();
	}
	private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
		this->textBox1->Text += "4";
		//inputString += '4';
		this->Invalidate();
	}
	private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
		this->textBox1->Text += "5";
		//inputString += "5";
		this->Invalidate();
	}
	private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {
		this->textBox1->Text += "6";
		//inputString += "6";
		this->Invalidate();
	}
	private: System::Void button7_Click(System::Object^  sender, System::EventArgs^  e) {
		this->textBox1->Text += "7";
		//inputString += "7";
		this->Invalidate();
	}
	private: System::Void button9_Click(System::Object^  sender, System::EventArgs^  e) {
		this->textBox1->Text += "8";
		//inputString += "8";
		this->Invalidate();
	}
	private: System::Void button8_Click(System::Object^  sender, System::EventArgs^  e) {
		this->textBox1->Text += "9";
		//inputString += "9";
		this->Invalidate();
	}
	private: System::Void button10_Click(System::Object^  sender, System::EventArgs^  e) {
		this->textBox1->Text += "0";
		//inputString += "0";
		this->Invalidate();
	}
	private: System::Void button12_Click(System::Object^  sender, System::EventArgs^  e) {
		this->textBox1->Text += ".";
		//inputString += ".";
		this->Invalidate();
	}
	private: System::Void button16_Click(System::Object^  sender, System::EventArgs^  e) {
		this->textBox1->Text += "+";
		//inputString += "+";
		this->Invalidate();
	}
	private: System::Void button15_Click(System::Object^  sender, System::EventArgs^  e) {
		this->textBox1->Text += "-";
		//inputString += "-";
		this->Invalidate();
	}
	private: System::Void button14_Click(System::Object^  sender, System::EventArgs^  e) {
		this->textBox1->Text += "*";
		//inputString += "*";
		this->Invalidate();
	}
	private: System::Void button13_Click(System::Object^  sender, System::EventArgs^  e) {
		this->textBox1->Text += "/";
		//inputString += "/";
		this->Invalidate();
	}
			 //private: System::Void button18_Click(System::Object^  sender, System::EventArgs^  e) {
			 //	this->textBox1->Text;
			 //	this->Invalidate();
			 //}
	private: System::Void button19_Click(System::Object^  sender, System::EventArgs^  e) {
		this->textBox1->Clear();
		inputString.clear();
		this->Invalidate();
	}
			 //private: System::Void button11_Click(System::Object^  sender, System::EventArgs^  e) {
			 //	if (inputString[inputString.size() - 1] == '-') {
			 //		inputString.pop_back();
			 //	}
			 //	else {
			 //		this->textBox1->Text += "-";
			 //		inputString += '-';
			 //	}
			 //	this->Invalidate();
			 //}
	private: System::Void button17_Click(System::Object^  sender, System::EventArgs^  e) {
		this->textBox1->Text += "=";
		this->Invalidate();
	}

	private: System::Void button22_Click(System::Object^  sender, System::EventArgs^  e) {
		this->textBox1->Text += "^";
		//inputString += "^";
		this->Invalidate();
	}
	private: System::Void button21_Click(System::Object^  sender, System::EventArgs^  e) {
		this->textBox1->Text += "!";
		//inputString += "!";
		this->Invalidate();
	}
	private: System::Void button20_Click(System::Object^  sender, System::EventArgs^  e) {
		this->textBox1->Text += "(";
		//inputString += ")";
		this->Invalidate();
	}
	private: System::Void button24_Click(System::Object^  sender, System::EventArgs^  e) {
		this->textBox1->Text += ")";
		//inputString += ")";
		this->Invalidate();
	}
	private: System::Void button23_Click(System::Object^  sender, System::EventArgs^  e) {
		this->textBox1->Text += "^0.5";
		//inputString += "^0.5";
		this->Invalidate();
	}
	private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	}

	private: System::Void button11_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
	}
	private: System::Void button11_Click_1(System::Object^  sender, System::EventArgs^  e) {


		MarshalString((this->textBox1->Text)->ToString(), inputString);

		std::cout << "Input : \n" << inputString << std::endl << std::endl;
		

		//inputString = "SetIntegerA=3";
		std::stringstream os;
		std::string str;

		bool digit = true;

		for (int i = 0; i < inputString.size(); i++) {
			if (inputString[i] - '0' >= 0 && inputString[i] - '0' < 10 && inputString[i] || inputString[i] == '+' || inputString[i] == '-' || inputString[i] == '*' || inputString[i] == '/' || inputString[i] == '!' || inputString[i] == '^' || inputString[i] == '.' || inputString[i] == 'A' || inputString[i] == 'B' || inputString[i] == '(' || inputString[i] == ')') {

			}
			else {
				digit = false;
			}
		}

		if (inputString.find('=')!=std::string::npos) {

			if (inputString[0] == 'S') {
				bool * haha;
				c->operateVariable(inputString, haha);
			}
			else {
				bool * haha;
				c->operateVariable(inputString, haha);
				Number *ya = c->operateVariable(inputString, haha);
				if (ya != NULL) {
					os << ya;
					os >> str;
				}
				std::cout << "Output : \n" << str << std::endl << std::endl;
			}


			
		}
		else if (digit) {
			os << c->compute(inputString);
			os >> str;
			std::cout << "Output : \n" << str << std::endl << std::endl;
		}
		else {
			std::cout << "Output : \n" << "invalid input" << std::endl << std::endl;
		}
		


		this->textBox1->Clear();

		for (int i = 0; i < str.size(); i++) {
			if (str[i] == '.')this->textBox1->Text += ".";
			else if (str[i] == '-')this->textBox1->Text += "-";
			else this->textBox1->Text += str[i] - '0';
		}

		inputString.clear();
		str.clear();

		this->Invalidate();
	}
	private: System::Void button25_Click(System::Object^  sender, System::EventArgs^  e) {
		this->textBox1->Text += "Set";
		this->Invalidate();
	}
	private: System::Void button27_Click(System::Object^  sender, System::EventArgs^  e) {
		this->textBox1->Text += "Integer";
		this->Invalidate();
	}
	private: System::Void button26_Click(System::Object^  sender, System::EventArgs^  e) {
		this->textBox1->Text += "Decimal";
		this->Invalidate();
	}
	private: System::Void button18_Click(System::Object^  sender, System::EventArgs^  e) {
		this->textBox1->Text += "A";
		this->Invalidate();
	}
	private: System::Void button28_Click(System::Object^  sender, System::EventArgs^  e) {
		this->textBox1->Text += "B";
		this->Invalidate();
	}
	};
}
