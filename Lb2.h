#pragma once

#include "HashTable.h"
#include "BST.h"


namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class Lb2 : public System::Windows::Forms::Form
	{
	private:
		HashTable* hashTable;
		BST* bst;

	public:
		Lb2(void)
		{
			InitializeComponent();
			hashTable = new HashTable(17);
			bst = new BST();
			hashTable->loadFromFile("words.txt");
			bst->loadFromFile("owners.txt");
			UpdateDictionaryGrid();
			UpdateOwnersGrid();
		}

	protected:
		~Lb2()
			{
				if (hashTable) {
					hashTable->saveToFile("words.txt");
					delete hashTable;
					hashTable = nullptr;
				}
				if (bst) {
					bst->saveToFile("owners.txt");
					delete bst;
					bst = nullptr;
				}
				if (components)
				{
					delete components;
				}
			}

	protected:
	private: 
		System::Windows::Forms::Button^ button1;
		System::Windows::Forms::Button^ button2;
		System::Windows::Forms::Button^ button3;
		System::Windows::Forms::Button^ button4;
		System::Windows::Forms::Button^ button5;
		System::Windows::Forms::Button^ button6;
		System::Windows::Forms::Button^ button7;
		System::Windows::Forms::Button^ button8;
		System::Windows::Forms::Button^ button9;
		System::Windows::Forms::Button^ button10;
		System::Windows::Forms::Button^ button11;
		System::Windows::Forms::Button^ button12;

		System::Windows::Forms::TextBox^ textBox1;
		System::Windows::Forms::TextBox^ textBox2;
		System::Windows::Forms::TextBox^ textBox3;
		System::Windows::Forms::TextBox^ textBox4;
		System::Windows::Forms::TextBox^ textBox5;
		System::Windows::Forms::TextBox^ textBox6;
		System::Windows::Forms::TextBox^ textBox7;

		System::Windows::Forms::PictureBox^ pictureBox1;
		System::Windows::Forms::PictureBox^ pictureBox2;
		System::Windows::Forms::PictureBox^ pictureBox3;
		System::Windows::Forms::PictureBox^ pictureBox4;

		System::Windows::Forms::DataGridView^ dataGridView1;
		System::Windows::Forms::DataGridView^ dataGridView2;
	
		System::Windows::Forms::Label^ label1;
		System::Windows::Forms::Label^ label2;

		System::Windows::Forms::Label^ label5;
		System::Windows::Forms::Label^ label6;
		System::Windows::Forms::Label^ label7;
		System::Windows::Forms::Label^ label8;
		System::Windows::Forms::Label^ label9;
		System::Windows::Forms::Label^ label10;
		System::Windows::Forms::Label^ label12;

	private:

		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
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
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->button12 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(1661, 455);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(157, 34);
			this->button1->TabIndex = 73;
			this->button1->Text = L"Оновити записи";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Lb2::button1_Click);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->Location = System::Drawing::Point(998, 667);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(194, 34);
			this->button2->TabIndex = 69;
			this->button2->Text = L"Додати власника авто";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Lb2::button2_Click);
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button3->Location = System::Drawing::Point(265, 455);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(154, 34);
			this->button3->TabIndex = 50;
			this->button3->Text = L"Видалити слово";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Lb2::button3_Click);
			// 
			// button4
			// 
			this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button4->Location = System::Drawing::Point(1656, 695);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(173, 26);
			this->button4->TabIndex = 68;
			this->button4->Text = L"Зберегти у файл";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Lb2::button4_Click);
			// 
			// button5
			// 
			this->button5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button5->Location = System::Drawing::Point(1219, 667);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(165, 34);
			this->button5->TabIndex = 66;
			this->button5->Text = L"Видалити власника";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &Lb2::button5_Click);
			// 
			// button6
			// 
			this->button6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button6->Location = System::Drawing::Point(998, 455);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(143, 34);
			this->button6->TabIndex = 83;
			this->button6->Text = L"Всі власники";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &Lb2::button6_Click);
			// 
			// button7
			// 
			this->button7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button7->Location = System::Drawing::Point(747, 557);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(173, 26);
			this->button7->TabIndex = 55;
			this->button7->Text = L"Зберегти у файл";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &Lb2::button7_Click);
			// 
			// button8
			// 
			this->button8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button8->Location = System::Drawing::Point(89, 455);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(137, 34);
			this->button8->TabIndex = 56;
			this->button8->Text = L"Вставити слово";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &Lb2::button8_Click);
			// 
			// button9
			// 
			this->button9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button9->Location = System::Drawing::Point(752, 455);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(157, 34);
			this->button9->TabIndex = 60;
			this->button9->Text = L"Оновити словник";
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &Lb2::button9_Click);
			// 
			// button10
			// 
			this->button10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button10->Location = System::Drawing::Point(1169, 455);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(215, 34);
			this->button10->TabIndex = 84;
			this->button10->Text = L"Власники з кількома авто";
			this->button10->UseVisualStyleBackColor = true;
			this->button10->Click += gcnew System::EventHandler(this, &Lb2::button10_Click);
			// 
			// button11
			// 
			this->button11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button11->Location = System::Drawing::Point(1405, 667);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(179, 34);
			this->button11->TabIndex = 85;
			this->button11->Text = L"Пошук за номером";
			this->button11->UseVisualStyleBackColor = true;
			this->button11->Click += gcnew System::EventHandler(this, &Lb2::button11_Click);
			// 
			// button12
			// 
			this->button12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button12->Location = System::Drawing::Point(462, 455);
			this->button12->Name = L"button12";
			this->button12->Size = System::Drawing::Size(139, 34);
			this->button12->TabIndex = 86;
			this->button12->Text = L"Пошук";
			this->button12->UseVisualStyleBackColor = true;
			this->button12->Click += gcnew System::EventHandler(this, &Lb2::button12_Click);
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::Color::White;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1->Location = System::Drawing::Point(89, 543);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(168, 26);
			this->textBox1->TabIndex = 49;
			// 
			// textBox2
			// 
			this->textBox2->BackColor = System::Drawing::Color::White;
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox2->Location = System::Drawing::Point(300, 543);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(168, 26);
			this->textBox2->TabIndex = 61;
			// 
			// textBox3
			// 
			this->textBox3->BackColor = System::Drawing::Color::White;
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox3->Location = System::Drawing::Point(998, 619);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(143, 26);
			this->textBox3->TabIndex = 74;
			// 
			// textBox4
			// 
			this->textBox4->BackColor = System::Drawing::Color::White;
			this->textBox4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox4->Location = System::Drawing::Point(998, 543);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(143, 26);
			this->textBox4->TabIndex = 65;
			// 
			// textBox5
			// 
			this->textBox5->BackColor = System::Drawing::Color::White;
			this->textBox5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox5->Location = System::Drawing::Point(1180, 619);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(143, 26);
			this->textBox5->TabIndex = 79;
			// 
			// textBox6
			// 
			this->textBox6->BackColor = System::Drawing::Color::White;
			this->textBox6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox6->Location = System::Drawing::Point(1180, 543);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(143, 26);
			this->textBox6->TabIndex = 77;
			// 
			// textBox7
			// 
			this->textBox7->BackColor = System::Drawing::Color::White;
			this->textBox7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox7->Location = System::Drawing::Point(1359, 543);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(143, 26);
			this->textBox7->TabIndex = 81;
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Gainsboro;
			this->pictureBox1->Location = System::Drawing::Point(78, 442);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(842, 59);
			this->pictureBox1->TabIndex = 57;
			this->pictureBox1->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackColor = System::Drawing::SystemColors::Control;
			this->pictureBox2->Location = System::Drawing::Point(78, 507);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(416, 76);
			this->pictureBox2->TabIndex = 58;
			this->pictureBox2->TabStop = false;
			// 
			// pictureBox3
			// 
			this->pictureBox3->BackColor = System::Drawing::Color::Gainsboro;
			this->pictureBox3->Location = System::Drawing::Point(987, 442);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(842, 59);
			this->pictureBox3->TabIndex = 70;
			this->pictureBox3->TabStop = false;
			// 
			// pictureBox4
			// 
			this->pictureBox4->BackColor = System::Drawing::SystemColors::ControlLight;
			this->pictureBox4->Location = System::Drawing::Point(987, 507);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(627, 214);
			this->pictureBox4->TabIndex = 71;
			this->pictureBox4->TabStop = false;
			// 
			// dataGridView1
			// 
			this->dataGridView1->Location = System::Drawing::Point(78, 79);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(842, 357);
			this->dataGridView1->TabIndex = 48;
			// 
			// dataGridView2
			// 
			this->dataGridView2->Location = System::Drawing::Point(987, 79);
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->Size = System::Drawing::Size(842, 357);
			this->dataGridView2->TabIndex = 64;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::SystemColors::Control;
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(85, 513);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(59, 19);
			this->label1->TabIndex = 59;
			this->label1->Text = L"Слово:\r\n";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::SystemColors::Control;
			this->label2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(296, 513);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(85, 19);
			this->label2->TabIndex = 62;
			this->label2->Text = L"Підсказка:\r\n";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::SystemColors::ControlLight;
			this->label5->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(994, 589);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(98, 19);
			this->label5->TabIndex = 75;
			this->label5->Text = L"Номер авто:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::SystemColors::ControlLight;
			this->label6->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->Location = System::Drawing::Point(994, 513);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(82, 19);
			this->label6->TabIndex = 72;
			this->label6->Text = L"Прізвище:\r\n";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Times New Roman", 24, System::Drawing::FontStyle::Bold));
			this->label7->Location = System::Drawing::Point(1312, 28);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(232, 36);
			this->label7->TabIndex = 67;
			this->label7->Text = L"Бінарне дерево";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->BackColor = System::Drawing::SystemColors::ControlLight;
			this->label8->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label8->Location = System::Drawing::Point(1176, 589);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(124, 19);
			this->label8->TabIndex = 80;
			this->label8->Text = L"Дата реєстрації:\r\n";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->BackColor = System::Drawing::SystemColors::ControlLight;
			this->label9->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label9->Location = System::Drawing::Point(1176, 513);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(44, 19);
			this->label9->TabIndex = 78;
			this->label9->Text = L"Ім\'я:\r\n";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->BackColor = System::Drawing::SystemColors::ControlLight;
			this->label10->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label10->Location = System::Drawing::Point(1355, 513);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(100, 19);
			this->label10->TabIndex = 82;
			this->label10->Text = L"По батькові:";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Times New Roman", 24, System::Drawing::FontStyle::Bold));
			this->label12->Location = System::Drawing::Point(399, 28);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(202, 36);
			this->label12->TabIndex = 51;
			this->label12->Text = L"Геш-таблиця\r\n";
			// 
			// Lb2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->ClientSize = System::Drawing::Size(1983, 816);
			this->Controls->Add(this->button12);
			this->Controls->Add(this->button11);
			this->Controls->Add(this->button10);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->textBox7);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->dataGridView2);
			this->Controls->Add(this->pictureBox3);
			this->Controls->Add(this->pictureBox4);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button9);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->pictureBox2);
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"Lb2";
			this->Text = L"Lb2";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private:
		System::Void button8_Click(System::Object^ sender, System::EventArgs^ e);   
		System::Void button3_Click(System::Object^ sender, System::EventArgs^ e);   
		System::Void button12_Click(System::Object^ sender, System::EventArgs^ e);  
		System::Void button7_Click(System::Object^ sender, System::EventArgs^ e);   
		System::Void button9_Click(System::Object^ sender, System::EventArgs^ e);   

		System::Void button2_Click(System::Object^ sender, System::EventArgs^ e);   
		System::Void button5_Click(System::Object^ sender, System::EventArgs^ e);  
		System::Void button11_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void button6_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void button10_Click(System::Object^ sender, System::EventArgs^ e); 
		System::Void button4_Click(System::Object^ sender, System::EventArgs^ e); 
		System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);

		void UpdateDictionaryGrid();
		void UpdateOwnersGrid();

	};
}
