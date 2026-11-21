#pragma once
#include "ShortestPaths.h"

namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class Lb6 : public System::Windows::Forms::Form
	{
	private:
		int vertexCount;
		int edgeCount;
		int currentEdge;
		int disabledEdgeCount;
		int currentDisabledEdge;
		BellmanFord* bellmanFord;
		Dijkstra* dijkstra;
		FloydWarshall* floydWarshall;
		int** edges;
		int** disabledEdges;

	public:
		Lb6(void)
		{
			InitializeComponent();
		}

	protected:
		~Lb6()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:

	private:

		 System::Windows::Forms::TextBox^ textBox1;
		 System::Windows::Forms::TextBox^ textBox2;
		 System::Windows::Forms::TextBox^ textBox4;
		 System::Windows::Forms::TextBox^ textBox5;
		 System::Windows::Forms::TextBox^ textBox6;
		 System::Windows::Forms::TextBox^ textBox7;
		 System::Windows::Forms::TextBox^ textBox8;
		 System::Windows::Forms::TextBox^ textBox9;
		 System::Windows::Forms::TextBox^ textBox10;
		 System::Windows::Forms::TextBox^ textBox11;
		 System::Windows::Forms::TextBox^ textBox12;
		 System::Windows::Forms::TextBox^ textBox13;
		 System::Windows::Forms::TextBox^ textBox14;
		 System::Windows::Forms::TextBox^ textBox15;

		 System::Windows::Forms::Button^ button1;
		 System::Windows::Forms::Button^ button2;
		 System::Windows::Forms::Button^ button4;
		 System::Windows::Forms::Button^ button6;
		 System::Windows::Forms::Button^ button7;
		 System::Windows::Forms::Button^ button8;
		 System::Windows::Forms::Button^ button9;
		 System::Windows::Forms::Button^ button10;

		 System::Windows::Forms::DataGridView^ dataGridView2;

		 System::Windows::Forms::PictureBox^ pictureBox3;
		 System::Windows::Forms::PictureBox^ pictureBox4;

		 System::Windows::Forms::Label^ label1;
		 System::Windows::Forms::Label^ label2;
		 System::Windows::Forms::Label^ label3;
		 System::Windows::Forms::Label^ label4;
		 System::Windows::Forms::Label^ label6;
		 System::Windows::Forms::Label^ label7;
		 System::Windows::Forms::Label^ label8;
		 System::Windows::Forms::Label^ label9;
		 System::Windows::Forms::Label^ label13;
		 System::Windows::Forms::Label^ label14;
		 System::Windows::Forms::Label^ label15;
		 System::Windows::Forms::Label^ label16;
		 System::Windows::Forms::Label^ label17;
		 System::Windows::Forms::Label^ label18;
		 System::Windows::Forms::Label^ label19;
		 System::Windows::Forms::Label^ label20;
		 System::Windows::Forms::Label^ label21;
		 System::Windows::Forms::Label^ label22;
		 System::Windows::Forms::Label^ label23;
		 System::Windows::Forms::Label^ label24;
		 System::Windows::Forms::Label^ label25;
		 System::Windows::Forms::Label^ label26;

		 System::Windows::Forms::CheckBox^ checkBox3;
		 System::Windows::Forms::CheckBox^ checkBox4;
		 System::Windows::Forms::CheckBox^ checkBox5;
		 System::Windows::Forms::CheckBox^ checkBox6;

		 System::Windows::Forms::PictureBox^ pictureBox1;
		 System::Windows::Forms::PictureBox^ pictureBox2;
		 System::Windows::Forms::PictureBox^ pictureBox5;

		 System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->textBox9 = (gcnew System::Windows::Forms::TextBox());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->textBox10 = (gcnew System::Windows::Forms::TextBox());
			this->textBox11 = (gcnew System::Windows::Forms::TextBox());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->checkBox3 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox4 = (gcnew System::Windows::Forms::CheckBox());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->textBox12 = (gcnew System::Windows::Forms::TextBox());
			this->textBox13 = (gcnew System::Windows::Forms::TextBox());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->label23 = (gcnew System::Windows::Forms::Label());
			this->checkBox5 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox6 = (gcnew System::Windows::Forms::CheckBox());
			this->label24 = (gcnew System::Windows::Forms::Label());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->label25 = (gcnew System::Windows::Forms::Label());
			this->textBox14 = (gcnew System::Windows::Forms::TextBox());
			this->textBox15 = (gcnew System::Windows::Forms::TextBox());
			this->label26 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox5 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->BeginInit();
			this->SuspendLayout();

			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::SystemColors::ControlLight;
			this->label4->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(504, 518);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(135, 22);
			this->label4->TabIndex = 144;
			this->label4->Text = L"Белман-Форд:\r\n";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::SystemColors::ControlLight;
			this->label3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(222, 246);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(187, 22);
			this->label3->TabIndex = 143;
			this->label3->Text = L"Кінцева вершина(v):";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::SystemColors::ControlLight;
			this->label2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(222, 137);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(66, 22);
			this->label2->TabIndex = 142;
			this->label2->Text = L"Ребро:\r\n";
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::Color::White;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1->Location = System::Drawing::Point(226, 276);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(138, 26);
			this->textBox1->TabIndex = 141;
			// 
			// textBox7
			// 
			this->textBox7->BackColor = System::Drawing::Color::White;
			this->textBox7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox7->Location = System::Drawing::Point(1081, 657);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(66, 24);
			this->textBox7->TabIndex = 136;
			// 
			// textBox5
			// 
			this->textBox5->BackColor = System::Drawing::Color::White;
			this->textBox5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox5->Location = System::Drawing::Point(69, 274);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(123, 26);
			this->textBox5->TabIndex = 134;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->BackColor = System::Drawing::SystemColors::ControlLight;
			this->label8->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label8->Location = System::Drawing::Point(65, 248);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(127, 38);
			this->label8->TabIndex = 135;
			this->label8->Text = L"Кількість ребер:\r\n\r\n";
			// 
			// textBox6
			// 
			this->textBox6->BackColor = System::Drawing::Color::White;
			this->textBox6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox6->Location = System::Drawing::Point(226, 206);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(138, 26);
			this->textBox6->TabIndex = 132;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->BackColor = System::Drawing::SystemColors::ControlLight;
			this->label9->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label9->Location = System::Drawing::Point(222, 176);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(213, 22);
			this->label9->TabIndex = 133;
			this->label9->Text = L"Початкова вершина(u):\r\n";
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(1002, 448);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(145, 34);
			this->button1->TabIndex = 129;
			this->button1->Text = L"Оновити записи";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Lb6::button1_Click);
			// 
			// textBox4
			// 
			this->textBox4->BackColor = System::Drawing::Color::White;
			this->textBox4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox4->Location = System::Drawing::Point(69, 206);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(138, 26);
			this->textBox4->TabIndex = 121;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::SystemColors::ControlLight;
			this->label6->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->Location = System::Drawing::Point(65, 178);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(142, 19);
			this->label6->TabIndex = 128;
			this->label6->Text = L"Кількість вершин:\r\n";
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->Location = System::Drawing::Point(69, 402);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(146, 34);
			this->button2->TabIndex = 125;
			this->button2->Text = L"Створити мережу";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Lb6::button2_Click);
			// 
			// button4
			// 
			this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button4->Location = System::Drawing::Point(1185, 452);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(161, 26);
			this->button4->TabIndex = 124;
			this->button4->Text = L"Зберегти у файл";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Lb6::button4_Click);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Times New Roman", 24, System::Drawing::FontStyle::Bold));
			this->label7->Location = System::Drawing::Point(653, 22);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(592, 36);
			this->label7->TabIndex = 123;
			this->label7->Text = L"Алгоритм пошуку найкоротшого шляху";
			// 
			// dataGridView2
			// 
			this->dataGridView2->Location = System::Drawing::Point(490, 69);
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->Size = System::Drawing::Size(865, 357);
			this->dataGridView2->TabIndex = 120;
			// 
			// pictureBox3
			// 
			this->pictureBox3->BackColor = System::Drawing::Color::Gainsboro;
			this->pictureBox3->Location = System::Drawing::Point(491, 435);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(864, 56);
			this->pictureBox3->TabIndex = 126;
			this->pictureBox3->TabStop = false;
			// 
			// pictureBox4
			// 
			this->pictureBox4->BackColor = System::Drawing::SystemColors::ControlLight;
			this->pictureBox4->Location = System::Drawing::Point(58, 128);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(393, 256);
			this->pictureBox4->TabIndex = 127;
			this->pictureBox4->TabStop = false;
			// 
			// button6
			// 
			this->button6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button6->Location = System::Drawing::Point(226, 402);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(119, 34);
			this->button6->TabIndex = 151;
			this->button6->Text = L"Додати ребро";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &Lb6::button6_Click);
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->BackColor = System::Drawing::SystemColors::ControlLight;
			this->label13->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label13->Location = System::Drawing::Point(222, 312);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(123, 22);
			this->label13->TabIndex = 153;
			this->label13->Text = L"Значення(w):";
			// 
			// textBox2
			// 
			this->textBox2->BackColor = System::Drawing::Color::White;
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox2->Location = System::Drawing::Point(226, 342);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(138, 26);
			this->textBox2->TabIndex = 152;
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->BackColor = System::Drawing::SystemColors::ControlLight;
			this->label14->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label14->Location = System::Drawing::Point(504, 629);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(166, 22);
			this->label14->TabIndex = 155;
			this->label14->Text = L"Цільова вершина:";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->BackColor = System::Drawing::SystemColors::ControlLight;
			this->label15->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label15->Location = System::Drawing::Point(504, 559);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(191, 22);
			this->label15->TabIndex = 154;
			this->label15->Text = L"Початкова вершина:\r\n";
			// 
			// textBox8
			// 
			this->textBox8->BackColor = System::Drawing::Color::White;
			this->textBox8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox8->Location = System::Drawing::Point(508, 663);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(138, 26);
			this->textBox8->TabIndex = 157;
			// 
			// textBox9
			// 
			this->textBox9->BackColor = System::Drawing::Color::White;
			this->textBox9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox9->Location = System::Drawing::Point(508, 593);
			this->textBox9->Name = L"textBox9";
			this->textBox9->Size = System::Drawing::Size(138, 26);
			this->textBox9->TabIndex = 156;
			// 
			// button7
			// 
			this->button7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button7->Location = System::Drawing::Point(508, 448);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(130, 34);
			this->button7->TabIndex = 158;
			this->button7->Text = L"Метод Форда";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &Lb6::button7_Click);

			// 
			// textBox10
			// 
			this->textBox10->BackColor = System::Drawing::Color::White;
			this->textBox10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox10->Location = System::Drawing::Point(1081, 970);
			this->textBox10->Name = L"textBox10";
			this->textBox10->Size = System::Drawing::Size(138, 26);
			this->textBox10->TabIndex = 163;
			// 
			// textBox11
			// 
			this->textBox11->BackColor = System::Drawing::Color::White;
			this->textBox11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox11->Location = System::Drawing::Point(1081, 900);
			this->textBox11->Name = L"textBox11";
			this->textBox11->Size = System::Drawing::Size(138, 26);
			this->textBox11->TabIndex = 162;
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->BackColor = System::Drawing::SystemColors::ControlLight;
			this->label16->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label16->Location = System::Drawing::Point(1077, 936);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(166, 22);
			this->label16->TabIndex = 161;
			this->label16->Text = L"Цільова вершина:";
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->BackColor = System::Drawing::SystemColors::ControlLight;
			this->label17->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label17->Location = System::Drawing::Point(1077, 866);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(191, 22);
			this->label17->TabIndex = 160;
			this->label17->Text = L"Початкова вершина:\r\n";
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->BackColor = System::Drawing::SystemColors::ControlLight;
			this->label18->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label18->Location = System::Drawing::Point(1077, 518);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(97, 22);
			this->label18->TabIndex = 159;
			this->label18->Text = L"Дейкстра:\r\n";
			// 
			// checkBox3
			// 
			this->checkBox3->AutoSize = true;
			this->checkBox3->BackColor = System::Drawing::SystemColors::ControlLight;
			this->checkBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->checkBox3->Location = System::Drawing::Point(1223, 587);
			this->checkBox3->Name = L"checkBox3";
			this->checkBox3->Size = System::Drawing::Size(41, 22);
			this->checkBox3->TabIndex = 166;
			this->checkBox3->Text = L"Ні";
			this->checkBox3->UseVisualStyleBackColor = false;
			// 
			// checkBox4
			// 
			this->checkBox4->AutoSize = true;
			this->checkBox4->BackColor = System::Drawing::SystemColors::ControlLight;
			this->checkBox4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->checkBox4->Location = System::Drawing::Point(1152, 587);
			this->checkBox4->Name = L"checkBox4";
			this->checkBox4->Size = System::Drawing::Size(52, 22);
			this->checkBox4->TabIndex = 165;
			this->checkBox4->Text = L"Так";
			this->checkBox4->UseVisualStyleBackColor = false;
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->BackColor = System::Drawing::SystemColors::ControlLight;
			this->label19->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label19->Location = System::Drawing::Point(1077, 559);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(269, 19);
			this->label19->TabIndex = 164;
			this->label19->Text = L"Чи є тимчасові недоступні ділянки\?";
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->BackColor = System::Drawing::SystemColors::ControlLight;
			this->label20->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label20->Location = System::Drawing::Point(1077, 623);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(215, 19);
			this->label20->TabIndex = 167;
			this->label20->Text = L"Скільки недоступних ребер\?";
			// 
			// button8
			// 
			this->button8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button8->Location = System::Drawing::Point(1075, 819);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(213, 34);
			this->button8->TabIndex = 168;
			this->button8->Text = L"Додати недоступне ребро";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &Lb6::button8_Click);

			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->BackColor = System::Drawing::SystemColors::ControlLight;
			this->label21->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label21->Location = System::Drawing::Point(1077, 754);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(187, 22);
			this->label21->TabIndex = 172;
			this->label21->Text = L"Кінцева вершина(v):";
			// 
			// textBox12
			// 
			this->textBox12->BackColor = System::Drawing::Color::White;
			this->textBox12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox12->Location = System::Drawing::Point(1081, 784);
			this->textBox12->Name = L"textBox12";
			this->textBox12->Size = System::Drawing::Size(138, 26);
			this->textBox12->TabIndex = 171;
			// 
			// textBox13
			// 
			this->textBox13->BackColor = System::Drawing::Color::White;
			this->textBox13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox13->Location = System::Drawing::Point(1081, 714);
			this->textBox13->Name = L"textBox13";
			this->textBox13->Size = System::Drawing::Size(138, 26);
			this->textBox13->TabIndex = 169;
			// 
			// label22
			// 
			this->label22->AutoSize = true;
			this->label22->BackColor = System::Drawing::SystemColors::ControlLight;
			this->label22->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label22->Location = System::Drawing::Point(1077, 684);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(213, 22);
			this->label22->TabIndex = 170;
			this->label22->Text = L"Початкова вершина(u):\r\n";
			// 
			// button9
			// 
			this->button9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button9->Location = System::Drawing::Point(835, 448);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(143, 34);
			this->button9->TabIndex = 173;
			this->button9->Text = L"Метод Дейкстра";
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &Lb6::button9_Click);

			// 
			// label23
			// 
			this->label23->AutoSize = true;
			this->label23->BackColor = System::Drawing::SystemColors::ControlLight;
			this->label23->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label23->Location = System::Drawing::Point(747, 521);
			this->label23->Name = L"label23";
			this->label23->Size = System::Drawing::Size(157, 22);
			this->label23->TabIndex = 174;
			this->label23->Text = L"Флойд-Уоршелл:\r\n";
			// 
			// checkBox5
			// 
			this->checkBox5->AutoSize = true;
			this->checkBox5->BackColor = System::Drawing::SystemColors::ControlLight;
			this->checkBox5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->checkBox5->Location = System::Drawing::Point(885, 589);
			this->checkBox5->Name = L"checkBox5";
			this->checkBox5->Size = System::Drawing::Size(41, 22);
			this->checkBox5->TabIndex = 177;
			this->checkBox5->Text = L"Ні";
			this->checkBox5->UseVisualStyleBackColor = false;
			// 
			// checkBox6
			// 
			this->checkBox6->AutoSize = true;
			this->checkBox6->BackColor = System::Drawing::SystemColors::ControlLight;
			this->checkBox6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->checkBox6->Location = System::Drawing::Point(818, 587);
			this->checkBox6->Name = L"checkBox6";
			this->checkBox6->Size = System::Drawing::Size(52, 22);
			this->checkBox6->TabIndex = 176;
			this->checkBox6->Text = L"Так";
			this->checkBox6->UseVisualStyleBackColor = false;
			// 
			// label24
			// 
			this->label24->AutoSize = true;
			this->label24->BackColor = System::Drawing::SystemColors::ControlLight;
			this->label24->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label24->Location = System::Drawing::Point(747, 559);
			this->label24->Name = L"label24";
			this->label24->Size = System::Drawing::Size(271, 19);
			this->label24->TabIndex = 175;
			this->label24->Text = L"Переглянути шлях між вершинами\?\r\n";
			// 
			// button10
			// 
			this->button10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button10->Location = System::Drawing::Point(669, 448);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(143, 34);
			this->button10->TabIndex = 178;
			this->button10->Text = L"Метод Уоршелла";
			this->button10->UseVisualStyleBackColor = true;
			this->button10->Click += gcnew System::EventHandler(this, &Lb6::button10_Click);

			// 
			// label25
			// 
			this->label25->AutoSize = true;
			this->label25->BackColor = System::Drawing::SystemColors::ControlLight;
			this->label25->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label25->Location = System::Drawing::Point(747, 699);
			this->label25->Name = L"label25";
			this->label25->Size = System::Drawing::Size(187, 22);
			this->label25->TabIndex = 182;
			this->label25->Text = L"Кінцева вершина(v):";
			// 
			// textBox14
			// 
			this->textBox14->BackColor = System::Drawing::Color::White;
			this->textBox14->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox14->Location = System::Drawing::Point(751, 729);
			this->textBox14->Name = L"textBox14";
			this->textBox14->Size = System::Drawing::Size(138, 26);
			this->textBox14->TabIndex = 181;
			// 
			// textBox15
			// 
			this->textBox15->BackColor = System::Drawing::Color::White;
			this->textBox15->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox15->Location = System::Drawing::Point(751, 659);
			this->textBox15->Name = L"textBox15";
			this->textBox15->Size = System::Drawing::Size(138, 26);
			this->textBox15->TabIndex = 179;
			// 
			// label26
			// 
			this->label26->AutoSize = true;
			this->label26->BackColor = System::Drawing::SystemColors::ControlLight;
			this->label26->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label26->Location = System::Drawing::Point(747, 629);
			this->label26->Name = L"label26";
			this->label26->Size = System::Drawing::Size(213, 22);
			this->label26->TabIndex = 180;
			this->label26->Text = L"Початкова вершина(u):\r\n";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::SystemColors::ControlLight;
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(65, 137);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(84, 22);
			this->label1->TabIndex = 183;
			this->label1->Text = L"Мережа:\r\n";
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::SystemColors::ControlLight;
			this->pictureBox1->Location = System::Drawing::Point(740, 509);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(288, 268);
			this->pictureBox1->TabIndex = 184;
			this->pictureBox1->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackColor = System::Drawing::SystemColors::ControlLight;
			this->pictureBox2->Location = System::Drawing::Point(1068, 509);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(287, 497);
			this->pictureBox2->TabIndex = 185;
			this->pictureBox2->TabStop = false;
			// 
			// pictureBox5
			// 
			this->pictureBox5->BackColor = System::Drawing::SystemColors::ControlLight;
			this->pictureBox5->Location = System::Drawing::Point(491, 509);
			this->pictureBox5->Name = L"pictureBox5";
			this->pictureBox5->Size = System::Drawing::Size(215, 199);
			this->pictureBox5->TabIndex = 186;
			this->pictureBox5->TabStop = false;
			// 
			// Lb6
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1515, 1024);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->label25);
			this->Controls->Add(this->textBox14);
			this->Controls->Add(this->textBox15);
			this->Controls->Add(this->label26);
			this->Controls->Add(this->button10);
			this->Controls->Add(this->checkBox5);
			this->Controls->Add(this->checkBox6);
			this->Controls->Add(this->label24);
			this->Controls->Add(this->label23);
			this->Controls->Add(this->button9);
			this->Controls->Add(this->label21);
			this->Controls->Add(this->textBox12);
			this->Controls->Add(this->textBox13);
			this->Controls->Add(this->label22);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->label20);
			this->Controls->Add(this->checkBox3);
			this->Controls->Add(this->checkBox4);
			this->Controls->Add(this->label19);
			this->Controls->Add(this->textBox10);
			this->Controls->Add(this->textBox11);
			this->Controls->Add(this->label16);
			this->Controls->Add(this->label17);
			this->Controls->Add(this->label18);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->textBox8);
			this->Controls->Add(this->textBox9);
			this->Controls->Add(this->label14);
			this->Controls->Add(this->label15);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->textBox7);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->dataGridView2);
			this->Controls->Add(this->pictureBox3);
			this->Controls->Add(this->pictureBox4);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox5);
			this->Name = L"Lb6";
			this->Text = L"Lb6";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		private:
			System::Void button2_Click(System::Object^ sender, System::EventArgs^ e);
			System::Void button6_Click(System::Object^ sender, System::EventArgs^ e);
			System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
			System::Void button4_Click(System::Object^ sender, System::EventArgs^ e);
			System::Void button7_Click(System::Object^ sender, System::EventArgs^ e);
			System::Void button10_Click(System::Object^ sender, System::EventArgs^ e);
			System::Void button9_Click(System::Object^ sender, System::EventArgs^ e);
			System::Void button8_Click(System::Object^ sender, System::EventArgs^ e);

			void UpdateDataGridView();
};
}
