#pragma once
#include "Graph.h"


namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	public ref class Lb5 : public System::Windows::Forms::Form
	{

	private:
		void UpdateDataGridView();
		bool isGraphCreated;
		int currentEdgeIndex;
		Graph* graph;
		int* vertexValues;
		int vertexCount;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown3;
		   int edgeCount;

	public:
		Lb5(void)
		{
			isGraphCreated = false;
			currentEdgeIndex = 0;
			graph = nullptr;
			vertexValues = nullptr;
			vertexCount = 0;
			edgeCount = 0;
			InitializeComponent();
		}

	protected:
		~Lb5()
		{
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

		System::Windows::Forms::Label^ label1;
		System::Windows::Forms::Label^ label2;
		System::Windows::Forms::Label^ label3;
		System::Windows::Forms::Label^ label4;
		System::Windows::Forms::Label^ label5;
		System::Windows::Forms::Label^ label6;
		System::Windows::Forms::Label^ label7;
		System::Windows::Forms::Label^ label8;
		System::Windows::Forms::Label^ label9;
		System::Windows::Forms::Label^ label10;

		System::Windows::Forms::TextBox^ textBox1;
		System::Windows::Forms::TextBox^ textBox3;
		System::Windows::Forms::TextBox^ textBox4;	
		System::Windows::Forms::TextBox^ textBox5;
		System::Windows::Forms::TextBox^ textBox6;
		System::Windows::Forms::TextBox^ textBox7;

		System::Windows::Forms::DataGridView^ dataGridView2;

		System::Windows::Forms::PictureBox^ pictureBox3;
		System::Windows::Forms::PictureBox^ pictureBox4;

		System::Windows::Forms::CheckBox^ checkBox1;
		System::Windows::Forms::CheckBox^ checkBox2;


		System::Windows::Forms::NumericUpDown^ numericUpDown1;
		System::Windows::Forms::NumericUpDown^ numericUpDown2;

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown3 = (gcnew System::Windows::Forms::NumericUpDown());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown3))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(767, 466);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(157, 34);
			this->button1->TabIndex = 95;
			this->button1->Text = L"Оновити записи";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Lb5::button1_Click);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->Location = System::Drawing::Point(104, 466);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(204, 34);
			this->button2->TabIndex = 91;
			this->button2->Text = L"Додати/редагувати граф";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Lb5::button2_Click);
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button3->Location = System::Drawing::Point(422, 466);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(73, 34);
			this->button3->TabIndex = 116;
			this->button3->Text = L"DFS";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Lb5::button3_Click);
			// 
			// button4
			// 
			this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button4->Location = System::Drawing::Point(762, 806);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(173, 26);
			this->button4->TabIndex = 90;
			this->button4->Text = L"Зберегти у файл";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Lb5::button4_Click);
			// 
			// button5
			// 
			this->button5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button5->Location = System::Drawing::Point(325, 466);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(73, 34);
			this->button5->TabIndex = 88;
			this->button5->Text = L"BFS";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &Lb5::button5_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::SystemColors::ControlLight;
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(579, 524);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(154, 19);
			this->label1->TabIndex = 107;
			this->label1->Text = L"Граф орієнтований\?";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::SystemColors::ControlLight;
			this->label2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(321, 595);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(66, 22);
			this->label2->TabIndex = 111;
			this->label2->Text = L"Ребро:\r\n";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::SystemColors::ControlLight;
			this->label3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(321, 698);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(187, 22);
			this->label3->TabIndex = 112;
			this->label3->Text = L"Кінцева вершина(v):";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::SystemColors::ControlLight;
			this->label4->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(100, 600);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(94, 22);
			this->label4->TabIndex = 113;
			this->label4->Text = L"Вершина:\r\n";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::SystemColors::ControlLight;
			this->label5->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(485, 524);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(72, 19);
			this->label5->TabIndex = 97;
			this->label5->Text = L"Число S:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::SystemColors::ControlLight;
			this->label6->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->Location = System::Drawing::Point(100, 524);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(142, 19);
			this->label6->TabIndex = 94;
			this->label6->Text = L"Кількість вершин:\r\n";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Times New Roman", 24, System::Drawing::FontStyle::Bold));
			this->label7->Location = System::Drawing::Point(370, 40);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(363, 36);
			this->label7->TabIndex = 89;
			this->label7->Text = L"Алгоритм обходу графів";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->BackColor = System::Drawing::SystemColors::ControlLight;
			this->label8->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label8->Location = System::Drawing::Point(321, 524);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(127, 38);
			this->label8->TabIndex = 101;
			this->label8->Text = L"Кількість ребер:\r\n\r\n";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->BackColor = System::Drawing::SystemColors::ControlLight;
			this->label9->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label9->Location = System::Drawing::Point(321, 628);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(213, 22);
			this->label9->TabIndex = 99;
			this->label9->Text = L"Початкова вершина(u):\r\n";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->BackColor = System::Drawing::SystemColors::ControlLight;
			this->label10->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label10->Location = System::Drawing::Point(100, 639);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(97, 22);
			this->label10->TabIndex = 103;
			this->label10->Text = L"Значення:";
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::Color::White;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1->Location = System::Drawing::Point(325, 728);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(154, 26);
			this->textBox1->TabIndex = 110;
			// 
			// textBox3
			// 
			this->textBox3->BackColor = System::Drawing::Color::White;
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox3->Location = System::Drawing::Point(489, 554);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(68, 26);
			this->textBox3->TabIndex = 96;
			// 
			// textBox4
			// 
			this->textBox4->BackColor = System::Drawing::Color::White;
			this->textBox4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox4->Location = System::Drawing::Point(104, 554);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(138, 26);
			this->textBox4->TabIndex = 87;
			// 
			// textBox5
			// 
			this->textBox5->BackColor = System::Drawing::Color::White;
			this->textBox5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox5->Location = System::Drawing::Point(325, 554);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(123, 26);
			this->textBox5->TabIndex = 100;
			// 
			// textBox6
			// 
			this->textBox6->BackColor = System::Drawing::Color::White;
			this->textBox6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox6->Location = System::Drawing::Point(325, 658);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(174, 26);
			this->textBox6->TabIndex = 98;
			// 
			// textBox7
			// 
			this->textBox7->BackColor = System::Drawing::Color::White;
			this->textBox7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox7->Location = System::Drawing::Point(200, 637);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(50, 24);
			this->textBox7->TabIndex = 102;
			// 
			// dataGridView2
			// 
			this->dataGridView2->Location = System::Drawing::Point(93, 90);
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->Size = System::Drawing::Size(842, 357);
			this->dataGridView2->TabIndex = 86;
			// 
			// pictureBox3
			// 
			this->pictureBox3->BackColor = System::Drawing::Color::Gainsboro;
			this->pictureBox3->Location = System::Drawing::Point(93, 453);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(842, 59);
			this->pictureBox3->TabIndex = 92;
			this->pictureBox3->TabStop = false;
			// 
			// pictureBox4
			// 
			this->pictureBox4->BackColor = System::Drawing::SystemColors::ControlLight;
			this->pictureBox4->Location = System::Drawing::Point(93, 518);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(655, 314);
			this->pictureBox4->TabIndex = 93;
			this->pictureBox4->TabStop = false;
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->BackColor = System::Drawing::SystemColors::ControlLight;
			this->checkBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->checkBox1->Location = System::Drawing::Point(597, 554);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(52, 22);
			this->checkBox1->TabIndex = 108;
			this->checkBox1->Text = L"Так";
			this->checkBox1->UseVisualStyleBackColor = false;
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->BackColor = System::Drawing::SystemColors::ControlLight;
			this->checkBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->checkBox2->Location = System::Drawing::Point(668, 554);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(41, 22);
			this->checkBox2->TabIndex = 109;
			this->checkBox2->Text = L"Ні";
			this->checkBox2->UseVisualStyleBackColor = false;
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Location = System::Drawing::Point(200, 602);
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(50, 20);
			this->numericUpDown1->TabIndex = 114;
			// 
			// numericUpDown2
			// 
			this->numericUpDown2->Location = System::Drawing::Point(104, 799);
			this->numericUpDown2->Name = L"numericUpDown2";
			this->numericUpDown2->Size = System::Drawing::Size(93, 20);
			this->numericUpDown2->TabIndex = 115;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->BackColor = System::Drawing::SystemColors::ControlLight;
			this->label11->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label11->Location = System::Drawing::Point(100, 762);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(187, 22);
			this->label11->TabIndex = 118;
			this->label11->Text = L"Кінцева вершина(v):";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->BackColor = System::Drawing::SystemColors::ControlLight;
			this->label12->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label12->Location = System::Drawing::Point(100, 692);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(213, 22);
			this->label12->TabIndex = 117;
			this->label12->Text = L"Початкова вершина(u):\r\n";
			// 
			// numericUpDown3
			// 
			this->numericUpDown3->Location = System::Drawing::Point(104, 728);
			this->numericUpDown3->Name = L"numericUpDown3";
			this->numericUpDown3->Size = System::Drawing::Size(93, 20);
			this->numericUpDown3->TabIndex = 119;
			// 
			// Lb5
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1159, 875);
			this->Controls->Add(this->numericUpDown3);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->numericUpDown2);
			this->Controls->Add(this->numericUpDown1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->checkBox2);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->label1);
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
			this->Name = L"Lb5";
			this->Text = L"Lb5";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown3))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private:
		System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void button2_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void button3_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void button4_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void button5_Click(System::Object^ sender, System::EventArgs^ e);
};
}
