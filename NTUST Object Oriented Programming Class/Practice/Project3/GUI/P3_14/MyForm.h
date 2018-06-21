#pragma once
#include <vector>
#include <string>  
#include <iostream>
#include <sstream>
#include <cctype>
#include "GameSystem.h"
#include "vector"
using namespace System;

 
	

std::string  inputStringA, inputStringB;
GameSystem *game = new GameSystem();
int teamAVs = 0, teamBVs = 0, teamSs = 0;

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

namespace P314 {

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
		static int second = 0;
		static int minute = 0;
		String^ sec;

		String^ min;
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
	private: System::Windows::Forms::TextBox^  teamAbox;
	private: System::Windows::Forms::TextBox^  teamBbox;
	private: array<System::Windows::Forms::Label^>^ labelA;
	private: array<System::Windows::Forms::Label^>^ labelB;
	private: array<System::Windows::Forms::Label^>^ labelS;


	protected:


	protected:


	private: System::Windows::Forms::TextBox^  textBox3;

	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Button^  start;


	private: System::Windows::Forms::Button^  pause;

	private: System::Windows::Forms::Label^  time;

	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::GroupBox^  groupBox2;

	private: System::ComponentModel::IContainer^  components;

	protected:

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
			System::Media::SoundPlayer^ simpleSound = gcnew System::Media::SoundPlayer("doublebass.wav");
			simpleSound->PlayLooping();
			//simpleSound.Play();
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->teamAbox = (gcnew System::Windows::Forms::TextBox());
			this->teamBbox = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->start = (gcnew System::Windows::Forms::Button());
			this->pause = (gcnew System::Windows::Forms::Button());
			this->time = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->SuspendLayout();
			// 
			// teamAbox
			// 
			this->teamAbox->BackColor = System::Drawing::Color::AliceBlue;
			this->teamAbox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->teamAbox->Location = System::Drawing::Point(19, 28);
			this->teamAbox->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->teamAbox->Multiline = true;
			this->teamAbox->Name = L"teamAbox";
			this->teamAbox->Size = System::Drawing::Size(230, 210);
			this->teamAbox->TabIndex = 0;
			this->teamAbox->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// teamBbox
			// 
			this->teamBbox->BackColor = System::Drawing::Color::AliceBlue;
			this->teamBbox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->teamBbox->Location = System::Drawing::Point(19, 253);
			this->teamBbox->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->teamBbox->Multiline = true;
			this->teamBbox->Name = L"teamBbox";
			this->teamBbox->Size = System::Drawing::Size(230, 235);
			this->teamBbox->TabIndex = 1;
			// 
			// textBox3
			// 
			this->textBox3->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox3->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox3->Location = System::Drawing::Point(17, 28);
			this->textBox3->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox3->Multiline = true;
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(661, 462);
			this->textBox3->TabIndex = 2;
			this->textBox3->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox3_TextChanged);
			// 
			// timer1
			// 
			this->timer1->Interval = 1000;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// start
			// 
			this->start->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->start->Font = (gcnew System::Drawing::Font(L"Consolas", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->start->Location = System::Drawing::Point(45, 26);
			this->start->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->start->Name = L"start";
			this->start->Size = System::Drawing::Size(112, 42);
			this->start->TabIndex = 6;
			this->start->Text = L"Start";
			this->start->UseVisualStyleBackColor = false;
			this->start->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// pause
			// 
			this->pause->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->pause->Cursor = System::Windows::Forms::Cursors::Default;
			this->pause->Font = (gcnew System::Drawing::Font(L"Consolas", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->pause->Location = System::Drawing::Point(336, 26);
			this->pause->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pause->Name = L"pause";
			this->pause->Size = System::Drawing::Size(112, 42);
			this->pause->TabIndex = 7;
			this->pause->Text = L"Pause";
			this->pause->UseVisualStyleBackColor = false;
			this->pause->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// time
			// 
			this->time->AutoSize = true;
			this->time->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->time->Font = (gcnew System::Drawing::Font(L"Consolas", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->time->Location = System::Drawing::Point(205, 26);
			this->time->Name = L"time";
			this->time->Size = System::Drawing::Size(90, 33);
			this->time->TabIndex = 8;
			this->time->Text = L"00:00";
			// 
			// groupBox1
			// 
			this->groupBox1->AutoSize = true;
			this->groupBox1->BackColor = System::Drawing::Color::SkyBlue;
			this->groupBox1->Controls->Add(this->teamAbox);
			this->groupBox1->Controls->Add(this->teamBbox);
			this->groupBox1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Consolas", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox1->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->groupBox1->Location = System::Drawing::Point(515, 26);
			this->groupBox1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->groupBox1->Size = System::Drawing::Size(266, 518);
			this->groupBox1->TabIndex = 9;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Command";
			// 
			// groupBox2
			// 
			this->groupBox2->AutoSize = true;
			this->groupBox2->BackColor = System::Drawing::Color::SkyBlue;
			this->groupBox2->Controls->Add(this->textBox3);
			this->groupBox2->Font = (gcnew System::Drawing::Font(L"Consolas", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox2->Location = System::Drawing::Point(811, 26);
			this->groupBox2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Padding = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->groupBox2->Size = System::Drawing::Size(694, 520);
			this->groupBox2->TabIndex = 10;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Battle Log";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 18);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1536, 578);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->time);
			this->Controls->Add(this->pause);
			this->Controls->Add(this->start);
			this->DoubleBuffered = true;
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {


		array<System::Windows::Forms::Label^>^ labels;
		array<System::Windows::Forms::Label^>^ labelsV;
		labels = gcnew array<System::Windows::Forms::Label^>(21);
		labelsV = gcnew array<System::Windows::Forms::Label^>(21);
		System::Windows::Forms::Label^ DDlabel = gcnew System::Windows::Forms::Label();
		System::Windows::Forms::Label^ CVlabel = gcnew System::Windows::Forms::Label();
		System::Windows::Forms::Label^ Shelllabel = gcnew System::Windows::Forms::Label();
		int bias = 10;
		for (int i = 0; i < 21; i++)
		{
			labels[i] = gcnew System::Windows::Forms::Label();
			labels[i]->BackColor = System::Drawing::Color::Black;
			labels[i]->Location = System::Drawing::Point(10 + 0 + bias, 15 * i + bias + 50);
			labels[i]->Size = System::Drawing::Size(300, 1);
			labels[i]->AutoSize = false;
		}
		for (int i = 0; i < 21; i++)
		{
			labelsV[i] = gcnew System::Windows::Forms::Label();
			labelsV[i]->BackColor = System::Drawing::Color::Black;
			labelsV[i]->Location = System::Drawing::Point(10 + 15 * i + bias, 0 + bias + 50);
			labelsV[i]->Size = System::Drawing::Size(1, 300);
			labelsV[i]->AutoSize = false;
		}
		for (int i = 0; i < 21; i++)
		{
			this->Controls->Add(labels[i]);
			this->Controls->Add(labelsV[i]);
		}


	}
	private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {

	}
	private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {

	}

	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		second += 15;
		if (second == 60) {
			second = 0;
			minute++;
		}
		if (second == 0)
			sec = "00";
		else
			sec = Convert::ToString(second);

		min = Convert::ToString(minute);
		time->Text = min + ":" + sec;

		game->timer = 60 * minute + second;
		//std::cout << game->timer << std::endl;

		game->updateFrame();

		for (int i = 0; i < teamAVs; i++)
		{
			this->Controls->Remove(labelA[i]);
		}
		for (int i = 0; i < teamBVs; i++)
		{
			this->Controls->Remove(labelB[i]);
		}
		for (int i = 0; i < teamSs; i++)
		{
			this->Controls->Remove(labelS[i]);
		}

		labelA = gcnew array<System::Windows::Forms::Label^>(30);
		labelB = gcnew array<System::Windows::Forms::Label^>(30);
		labelS = gcnew array<System::Windows::Forms::Label^>(30);
		teamAVs = 0;
		teamBVs = 0;
		teamSs = 0;

		std::map<std::string, Vessel*>::iterator vesselsIter;
		for (vesselsIter = game->teamA.vessels.begin(); vesselsIter != game->teamA.vessels.end(); vesselsIter++, teamAVs++) {
			double x = vesselsIter->second->getPosition().getX();
			double y = vesselsIter->second->getPosition().getY();

			labelA[teamAVs] = (gcnew System::Windows::Forms::Label());
			labelA[teamAVs]->Location = System::Drawing::Point(x*15 + 12.5, y * 15 + 52.5);	//10 60
			labelA[teamAVs]->Name = L"labelha";
			labelA[teamAVs]->Size = System::Drawing::Size(15, 15);
			Image^image1 = Image::FromFile("teamA.png");
			labelA[teamAVs]->Image = image1;
			this->Controls->Add(labelA[teamAVs]);
		}
		for (vesselsIter = game->teamB.vessels.begin(); vesselsIter != game->teamB.vessels.end(); vesselsIter++, teamBVs++) {
			double x = vesselsIter->second->getPosition().getX();
			double y = vesselsIter->second->getPosition().getY();

			labelB[teamBVs] = (gcnew System::Windows::Forms::Label());
			labelB[teamBVs]->Location = System::Drawing::Point(x * 15+ 12.5, y * 15 + 52.5);	//10 60
			labelB[teamBVs]->Name = L"labelhaha";
			labelB[teamBVs]->Size = System::Drawing::Size(15, 15);
			Image^image1 = Image::FromFile("teamB.png");
			labelB[teamBVs]->Image = image1;
			this->Controls->Add(labelB[teamBVs]);
		}

		std::map<std::string, Shell*>::iterator shellIter;
		for (shellIter = game->shells.begin(); shellIter != game->shells.end(); shellIter++, teamSs++) {
			double x = shellIter->second->getPosition().getX();
			double y = shellIter->second->getPosition().getY();
			//printf("%d %d\n", x, y);
			labelS[teamSs] = (gcnew System::Windows::Forms::Label());
			labelS[teamSs]->Location = System::Drawing::Point(x * 15 + 12.5, y * 15 + 52.5);	//10 60
			labelS[teamSs]->Name = L"labelhahaha";
			labelS[teamSs]->Size = System::Drawing::Size(15, 15);
			Image^image1 = Image::FromFile("bullet.png");
			labelS[teamSs]->Image = image1;
			this->Controls->Add(labelS[teamSs]);
		}

		for (int i = 0; i < game->logs.size(); i++) {
			std::wstring str2(game->logs[i].begin(), game->logs[i].end());
			for (int j = 0; j < str2.size(); j++) {
				textBox3->Text += str2[j];
			}
			textBox3->Text += "\r\n";
		}
		game->logs.clear();

		Invalidate();

	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {	//start
		game->timer = 60 * minute + second;
		if (!game->running) {
			timer1->Enabled = true;

			std::string tempA;
			std::string tempB;

			MarshalString((this->teamAbox->Text)->ToString(), inputStringA);
			MarshalString((this->teamBbox->Text)->ToString(), inputStringB);

			if (inputStringA.size())
				game->teamA.fetchCommand(inputStringA);
			if (inputStringB.size())
				game->teamB.fetchCommand(inputStringB);

			game->start();
			game->running = true;

			teamAbox->Clear();
			teamBbox->Clear();
			inputStringA.clear();
			inputStringB.clear();

			for (int i = 0; i < game->logs.size(); i++) {
				std::wstring str2 (game->logs[i].begin(), game->logs[i].end());
				for (int j = 0; j < str2.size(); j++) {
					textBox3->Text += str2[j];
				}
				textBox3->Text += "\r\n";
			}
			game->logs.clear();
			Invalidate();
		}

	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {	//pause
		timer1->Enabled = false;
		game->pause();
		game->running = false;
		this->teamAbox->Clear();
		inputStringA.clear();
		this->teamBbox->Clear();
		inputStringB.clear();
	}
	private: System::Void textBox3_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	}
};
}
