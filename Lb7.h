#pragma once

#include <vector>
#include "Task.h"
#include <msclr/marshal_cppstd.h>
struct Task;

namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class Lb7 : public System::Windows::Forms::Form
	{

	private:
		void ShowNetworkTable();
		   int robots = 0;
		void UpdateTasksTable();
	public:
		void saveToFile(System::String^ filename);
		void loadFromFile(System::String^ filename);
		std::vector<Task>* tasks;
		Lb7(void)
		{
			tasks = new std::vector<Task>();
			InitializeComponent();
		}

	protected:
		~Lb7()
		{
			if (tasks) delete tasks;
			if (components) delete components;
		}

	protected:

	private:


		 System::Windows::Forms::TextBox^ textBox7;
		 System::Windows::Forms::TextBox^ textBox8;
		 System::Windows::Forms::TextBox^ textBox9;
		 System::Windows::Forms::TextBox^ textBox10;

		 System::Windows::Forms::Button^ button1;
		 System::Windows::Forms::Button^ button2;
		 System::Windows::Forms::Button^ button3;
		 System::Windows::Forms::Button^ button4;
		 System::Windows::Forms::Button^ button7;

		 System::Windows::Forms::Button^ button9;

		 System::Windows::Forms::DataGridView^ dataGridView1;

		 System::Windows::Forms::PictureBox^ pictureBox1;


		 System::Windows::Forms::Label^ label1;
		 System::Windows::Forms::Label^ label2;

		 System::Windows::Forms::Label^ label6;
		 System::Windows::Forms::Label^ label7;
		 System::Windows::Forms::Label^ label8;
		 System::Windows::Forms::Label^ label10;
		 System::Windows::Forms::Label^ label12;

		 System::Windows::Forms::PictureBox^ pictureBox3;

		 System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->textBox9 = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->textBox10 = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			this->SuspendLayout();
			// 
			// textBox7
			// 
			this->textBox7->BackColor = System::Drawing::Color::White;
			this->textBox7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox7->Location = System::Drawing::Point(315, 600);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(160, 26);
			this->textBox7->TabIndex = 153;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::SystemColors::Control;
			this->label6->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->Location = System::Drawing::Point(311, 574);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(168, 22);
			this->label6->TabIndex = 152;
			this->label6->Text = L"Кількість роботів:";
			this->label6->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(723, 675);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(164, 34);
			this->button1->TabIndex = 144;
			this->button1->Text = L"Додати завдання";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Lb7::button1_Click);
			// 
			// button9
			// 
			this->button9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button9->Location = System::Drawing::Point(1011, 455);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(157, 34);
			this->button9->TabIndex = 141;
			this->button9->Text = L"Оновити поле";
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &Lb7::button9_Click);
			// 
			// button7
			// 
			this->button7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button7->Location = System::Drawing::Point(1011, 696);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(173, 26);
			this->button7->TabIndex = 137;
			this->button7->Text = L"Зберегти у файл";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &Lb7::button7_Click);
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Times New Roman", 24, System::Drawing::FontStyle::Bold));
			this->label12->Location = System::Drawing::Point(476, 29);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(526, 36);
			this->label12->TabIndex = 136;
			this->label12->Text = L"Моделювання транспортної мережі";

			// 
			// dataGridView1
			// 
			this->dataGridView1->Location = System::Drawing::Point(301, 79);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(883, 357);
			this->dataGridView1->TabIndex = 134;
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Gainsboro;
			this->pictureBox1->Location = System::Drawing::Point(301, 442);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(883, 59);
			this->pictureBox1->TabIndex = 139;
			this->pictureBox1->TabStop = false;
			// 
			// textBox8
			// 
			this->textBox8->BackColor = System::Drawing::Color::White;
			this->textBox8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox8->Location = System::Drawing::Point(532, 678);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(160, 26);
			this->textBox8->TabIndex = 162;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->BackColor = System::Drawing::SystemColors::Control;
			this->label7->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label7->Location = System::Drawing::Point(525, 646);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(150, 22);
			this->label7->TabIndex = 161;
			this->label7->Text = L"Час закінчення:";
			this->label7->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// textBox9
			// 
			this->textBox9->BackColor = System::Drawing::Color::White;
			this->textBox9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox9->Location = System::Drawing::Point(532, 600);
			this->textBox9->Name = L"textBox9";
			this->textBox9->Size = System::Drawing::Size(160, 26);
			this->textBox9->TabIndex = 160;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->BackColor = System::Drawing::SystemColors::Control;
			this->label8->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label8->Location = System::Drawing::Point(528, 571);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(124, 22);
			this->label8->TabIndex = 159;
			this->label8->Text = L"Час початку:";
			this->label8->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// textBox10
			// 
			this->textBox10->BackColor = System::Drawing::Color::White;
			this->textBox10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox10->Location = System::Drawing::Point(727, 600);
			this->textBox10->Name = L"textBox10";
			this->textBox10->Size = System::Drawing::Size(160, 26);
			this->textBox10->TabIndex = 164;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->BackColor = System::Drawing::SystemColors::Control;
			this->label10->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label10->Location = System::Drawing::Point(726, 566);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(112, 22);
			this->label10->TabIndex = 163;
			this->label10->Text = L"Тривалість:";
			this->label10->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::SystemColors::Control;
			this->label2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(528, 521);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(99, 24);
			this->label2->TabIndex = 165;
			this->label2->Text = L"Завдання";
			this->label2->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// pictureBox3
			// 
			this->pictureBox3->BackColor = System::Drawing::SystemColors::Control;
			this->pictureBox3->Location = System::Drawing::Point(301, 507);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(635, 215);
			this->pictureBox3->TabIndex = 167;
			this->pictureBox3->TabStop = false;
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->Location = System::Drawing::Point(506, 455);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(178, 34);
			this->button2->TabIndex = 168;
			this->button2->Text = L"Показати завдання";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Lb7::button2_Click);
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button3->Location = System::Drawing::Point(315, 455);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(161, 34);
			this->button3->TabIndex = 169;
			this->button3->Text = L"Створити мережу";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Lb7::button3_Click);
			// 
			// button4
			// 
			this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button4->Location = System::Drawing::Point(743, 455);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(193, 34);
			this->button4->TabIndex = 170;
			this->button4->Text = L"Оптимізувати мережу";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Lb7::button4_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::SystemColors::Control;
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(311, 521);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(86, 24);
			this->label1->TabIndex = 171;
			this->label1->Text = L"Мережа";
			this->label1->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// Lb7
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1384, 857);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox10);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->textBox8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->textBox9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->textBox7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->button9);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->pictureBox3);
			this->Name = L"Lb7";
			this->Text = L"Lb7";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
				private:
					System::Void button4_Click(System::Object^ sender, System::EventArgs^ e);
					System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
					System::Void button2_Click(System::Object^ sender, System::EventArgs^ e);
					System::Void button3_Click(System::Object^ sender, System::EventArgs^ e);
					System::Void button7_Click(System::Object^ sender, System::EventArgs^ e);
					System::Void button9_Click(System::Object^ sender, System::EventArgs^ e);
};
}
