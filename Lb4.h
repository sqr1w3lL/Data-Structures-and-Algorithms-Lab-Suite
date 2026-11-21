#pragma once

#include "GridTask.h"
namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class Lb4 : public System::Windows::Forms::Form
	{
	private:
		GridTask* grid;

	public:
		Lb4(void)
		{
			InitializeComponent();
			grid = new GridTask();
			UpdateGrid();
		}

	protected:
		~Lb4()
		{
			if (grid) {
				delete grid;
				grid = nullptr;
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
		System::Windows::Forms::Button^ button7;
		System::Windows::Forms::Button^ button8;
		System::Windows::Forms::Button^ button9;

		System::Windows::Forms::TextBox^ textBox1;
		System::Windows::Forms::TextBox^ textBox2;
		System::Windows::Forms::TextBox^ textBox3;
		System::Windows::Forms::TextBox^ textBox4;
		System::Windows::Forms::TextBox^ textBox5;
		System::Windows::Forms::TextBox^ textBox6;
		System::Windows::Forms::TextBox^ textBox7;

		System::Windows::Forms::Label^ label1;
		System::Windows::Forms::Label^ label2;
		System::Windows::Forms::Label^ label3;
		System::Windows::Forms::Label^ label4;
		System::Windows::Forms::Label^ label5;
		System::Windows::Forms::Label^ label6;
		System::Windows::Forms::Label^ label7;
		System::Windows::Forms::Label^ label8;
		System::Windows::Forms::Label^ label9;
		System::Windows::Forms::Label^ label12;

		System::Windows::Forms::DataGridView^ dataGridView1;

		System::Windows::Forms::PictureBox^ pictureBox1;
		System::Windows::Forms::PictureBox^ pictureBox2;

	private:
		System::ComponentModel::Container ^components;

		void UpdateGrid();

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(386, 466);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(178, 34);
			this->button1->TabIndex = 118;
			this->button1->Text = L"Додати/Редагувати";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Lb4::button1_Click);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->Location = System::Drawing::Point(541, 610);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(261, 34);
			this->button2->TabIndex = 123;
			this->button2->Text = L"Знайти мінімальний шлях";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Lb4::button2_Click);
			// 
			// button7
			// 
			this->button7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button7->Location = System::Drawing::Point(874, 639);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(173, 26);
			this->button7->TabIndex = 110;
			this->button7->Text = L"Зберегти у файл";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &Lb4::button7_Click);
			// 
			// button8
			// 
			this->button8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button8->Location = System::Drawing::Point(216, 466);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(137, 34);
			this->button8->TabIndex = 111;
			this->button8->Text = L"Створити поле";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &Lb4::button8_Click);
			// 
			// button9
			// 
			this->button9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button9->Location = System::Drawing::Point(879, 466);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(157, 34);
			this->button9->TabIndex = 115;
			this->button9->Text = L"Оновити поле";
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &Lb4::button9_Click);
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::Color::White;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1->Location = System::Drawing::Point(241, 652);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(71, 26);
			this->textBox1->TabIndex = 107;
			// 
			// textBox2
			// 
			this->textBox2->BackColor = System::Drawing::Color::White;
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox2->Location = System::Drawing::Point(354, 652);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(67, 26);
			this->textBox2->TabIndex = 116;
			// 
			// textBox3
			// 
			this->textBox3->BackColor = System::Drawing::Color::White;
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox3->Location = System::Drawing::Point(693, 564);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(130, 26);
			this->textBox3->TabIndex = 126;
			// 
			// textBox4
			// 
			this->textBox4->BackColor = System::Drawing::Color::White;
			this->textBox4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox4->Location = System::Drawing::Point(318, 690);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(103, 26);
			this->textBox4->TabIndex = 119;
			// 
			// textBox5
			// 
			this->textBox5->BackColor = System::Drawing::Color::White;
			this->textBox5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox5->Location = System::Drawing::Point(503, 564);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(145, 26);
			this->textBox5->TabIndex = 124;
			// 
			// textBox6
			// 
			this->textBox6->BackColor = System::Drawing::Color::White;
			this->textBox6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox6->Location = System::Drawing::Point(354, 564);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(67, 26);
			this->textBox6->TabIndex = 131;
			// 
			// textBox7
			// 
			this->textBox7->BackColor = System::Drawing::Color::White;
			this->textBox7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox7->Location = System::Drawing::Point(241, 564);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(71, 26);
			this->textBox7->TabIndex = 129;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::SystemColors::Control;
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(215, 656);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(25, 19);
			this->label1->TabIndex = 114;
			this->label1->Text = L"X:\r\n";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::SystemColors::Control;
			this->label2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(325, 656);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(23, 19);
			this->label2->TabIndex = 117;
			this->label2->Text = L"Y:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::SystemColors::Control;
			this->label3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(689, 534);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(133, 22);
			this->label3->TabIndex = 127;
			this->label3->Text = L"Кінець шляху:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::SystemColors::Control;
			this->label4->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(215, 692);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(97, 22);
			this->label4->TabIndex = 120;
			this->label4->Text = L"Значення:\r\n";
			this->label4->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::SystemColors::Control;
			this->label5->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(499, 534);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(148, 22);
			this->label5->TabIndex = 125;
			this->label5->Text = L"Початок шляху:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::SystemColors::Control;
			this->label6->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->Location = System::Drawing::Point(212, 532);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(167, 22);
			this->label6->TabIndex = 128;
			this->label6->Text = L"Координати поля:\r\n";
			this->label6->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->BackColor = System::Drawing::SystemColors::Control;
			this->label7->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label7->Location = System::Drawing::Point(325, 568);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(23, 19);
			this->label7->TabIndex = 132;
			this->label7->Text = L"Y:";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->BackColor = System::Drawing::SystemColors::Control;
			this->label8->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label8->Location = System::Drawing::Point(215, 568);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(25, 19);
			this->label8->TabIndex = 130;
			this->label8->Text = L"X:\r\n";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->BackColor = System::Drawing::SystemColors::Control;
			this->label9->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label9->Location = System::Drawing::Point(215, 615);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(202, 22);
			this->label9->TabIndex = 133;
			this->label9->Text = L"Заповнення клітинок:\r\n";
			this->label9->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Times New Roman", 24, System::Drawing::FontStyle::Bold));
			this->label12->Location = System::Drawing::Point(452, 38);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(409, 36);
			this->label12->TabIndex = 109;
			this->label12->Text = L"Динамічне Програмування";
			// 
			// dataGridView1
			// 
			this->dataGridView1->Location = System::Drawing::Point(205, 90);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(842, 357);
			this->dataGridView1->TabIndex = 106;
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Gainsboro;
			this->pictureBox1->Location = System::Drawing::Point(205, 453);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(842, 59);
			this->pictureBox1->TabIndex = 112;
			this->pictureBox1->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackColor = System::Drawing::SystemColors::Control;
			this->pictureBox2->Location = System::Drawing::Point(205, 518);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(633, 230);
			this->pictureBox2->TabIndex = 113;
			this->pictureBox2->TabStop = false;
			// 
			// Lb4
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1234, 815);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->textBox7);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button9);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->pictureBox2);
			this->Name = L"Lb4";
			this->Text = L"Lb4";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		private:
			System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
			System::Void button2_Click(System::Object^ sender, System::EventArgs^ e);
			System::Void button7_Click(System::Object^ sender, System::EventArgs^ e);
			System::Void button8_Click(System::Object^ sender, System::EventArgs^ e);
			System::Void button9_Click(System::Object^ sender, System::EventArgs^ e);

	};
}
