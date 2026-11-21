#pragma once

#include "DeliveryPlanner.h"

namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	static DeliveryPlanner* planner = nullptr;

	public ref class Lb3 : public System::Windows::Forms::Form
	{
	private:
		

	public:
		DeliveryPlanner* planner;

		Lb3(void) {
			InitializeComponent();
			planner = new DeliveryPlanner();
			UpdateGrid();
		}

		void Lb3::UpdateGrid()
		{
			dataGridView1->Rows->Clear();
			dataGridView1->Columns->Clear();
			dataGridView1->Columns->Add("Name", "Назва");
			dataGridView1->Columns->Add("Price", "Ціна");
			dataGridView1->Columns->Add("DaysLeft", "Днів лишилось");
			dataGridView1->Columns->Add("AllowedDays", "Днів дозволено");

			for (int i = 0; i < planner->getSize(); ++i) {
				ProductGroup p = planner->getProduct(i);
				dataGridView1->Rows->Add(
					gcnew System::String(p.name.c_str()),
					p.price.ToString(),
					p.daysLeft.ToString(),
					p.allowedDays.ToString()
				);
			}
		}

	protected:

		~Lb3()
		{
			if (planner) {
				delete planner;
				planner = nullptr;
			}
			if (components)
			{
				delete components;
			}
		}

	protected:

		private:

		System::Windows::Forms::TextBox^ textBox1;
		System::Windows::Forms::TextBox^ textBox2;
		System::Windows::Forms::TextBox^ textBox3;
		System::Windows::Forms::TextBox^ textBox4;

		System::Windows::Forms::Label^ label1;
		System::Windows::Forms::Label^ label2;
		System::Windows::Forms::Label^ label3;
		System::Windows::Forms::Label^ label4;
		System::Windows::Forms::Label^ label12;

		System::Windows::Forms::Button^ button1;
		System::Windows::Forms::Button^ button2;
		System::Windows::Forms::Button^ button3;
		System::Windows::Forms::Button^ button7;
		System::Windows::Forms::Button^ button8;
		System::Windows::Forms::Button^ button9;

		System::Windows::Forms::DataGridView^ dataGridView1;

		System::Windows::Forms::PictureBox^ pictureBox1;
		System::Windows::Forms::PictureBox^ pictureBox2;

	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::Color::White;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1->Location = System::Drawing::Point(168, 554);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(168, 26);
			this->textBox1->TabIndex = 88;
			// 
			// textBox2
			// 
			this->textBox2->BackColor = System::Drawing::Color::White;
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox2->Location = System::Drawing::Point(379, 554);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(168, 26);
			this->textBox2->TabIndex = 97;
			// 
			// textBox3
			// 
			this->textBox3->BackColor = System::Drawing::Color::White;
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox3->Location = System::Drawing::Point(379, 627);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(168, 26);
			this->textBox3->TabIndex = 103;
			// 
			// textBox4
			// 
			this->textBox4->BackColor = System::Drawing::Color::White;
			this->textBox4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox4->Location = System::Drawing::Point(168, 627);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(168, 26);
			this->textBox4->TabIndex = 101;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::SystemColors::Control;
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(164, 524);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(160, 19);
			this->label1->TabIndex = 95;
			this->label1->Text = L"Назва групи товарів:\r\n";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::SystemColors::Control;
			this->label2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(375, 524);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(134, 19);
			this->label2->TabIndex = 98;
			this->label2->Text = L"Вартість товарів:\r\n";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::SystemColors::Control;
			this->label3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(375, 597);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(136, 19);
			this->label3->TabIndex = 104;
			this->label3->Text = L"Термін за угодою:\r\n";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::SystemColors::Control;
			this->label4->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(164, 597);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(153, 19);
			this->label4->TabIndex = 102;
			this->label4->Text = L"Термін придатності:\r\n";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Times New Roman", 24, System::Drawing::FontStyle::Bold));
			this->label12->Location = System::Drawing::Point(426, 38);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(308, 36);
			this->label12->TabIndex = 90;
			this->label12->Text = L"Жадібний Алгоритм";
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(338, 466);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(137, 34);
			this->button1->TabIndex = 100;
			this->button1->Text = L"Редагувати";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Lb3::button1_Click);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->Location = System::Drawing::Point(594, 579);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(167, 34);
			this->button2->TabIndex = 105;
			this->button2->Text = L"Жадібний алгоритм";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Lb3::button2_Click);
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button3->Location = System::Drawing::Point(508, 466);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(154, 34);
			this->button3->TabIndex = 89;
			this->button3->Text = L"Видалити";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Lb3::button3_Click);
			// 
			// button7
			// 
			this->button7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button7->Location = System::Drawing::Point(826, 643);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(173, 26);
			this->button7->TabIndex = 91;
			this->button7->Text = L"Зберегти у файл";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &Lb3::button7_Click);
			// 
			// button8
			// 
			this->button8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button8->Location = System::Drawing::Point(168, 466);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(137, 34);
			this->button8->TabIndex = 92;
			this->button8->Text = L"Додати ";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &Lb3::button8_Click);
			// 
			// button9
			// 
			this->button9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button9->Location = System::Drawing::Point(831, 466);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(157, 34);
			this->button9->TabIndex = 96;
			this->button9->Text = L"Оновити групу";
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &Lb3::button9_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->Location = System::Drawing::Point(157, 90);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(842, 357);
			this->dataGridView1->TabIndex = 87;
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Gainsboro;
			this->pictureBox1->Location = System::Drawing::Point(157, 453);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(842, 59);
			this->pictureBox1->TabIndex = 93;
			this->pictureBox1->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackColor = System::Drawing::SystemColors::Control;
			this->pictureBox2->Location = System::Drawing::Point(157, 518);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(633, 151);
			this->pictureBox2->TabIndex = 94;
			this->pictureBox2->TabStop = false;
			// 
			// Lb3
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1172, 745);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label3);
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
			this->Controls->Add(this->button3);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->pictureBox2);
			this->Name = L"Lb3";
			this->Text = L"Lb3";
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
		System::Void button3_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void button7_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void button8_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void button9_Click(System::Object^ sender, System::EventArgs^ e);


	};
}
