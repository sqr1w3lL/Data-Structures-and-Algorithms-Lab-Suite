#pragma once
#include "Heap.h"
#include "Lb2.h"
#include "Lb3.h"
#include "Lb4.h"
#include "Lb5.h"
#include "Lb6.h"
#include "Lb7.h"
#include <msclr/marshal_cppstd.h>
#include <sstream>
#include <iomanip>
#using <Microsoft.VisualBasic.dll>
#include <algorithm>


namespace Project1 {

	using namespace Microsoft::VisualBasic;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class Lb1 : public System::Windows::Forms::Form
	{
	private:

	System::Windows::Forms::ToolStripMenuItem^ ЛінійніСтруктуриДанихToolStripMenuItem;
	System::Windows::Forms::ToolStripMenuItem^ ДереваТаГешТаблиціToolStripMenuItem;
	System::Windows::Forms::ToolStripMenuItem^ ЖадібніАлгоритмиToolStripMenuItem;
	System::Windows::Forms::ToolStripMenuItem^ ДинамічнеПрограмуванняToolStripMenuItem;
	System::Windows::Forms::ToolStripMenuItem^ АлгоритмОбходуГрафівToolStripMenuItem;
	System::Windows::Forms::ToolStripMenuItem^ АлгоритмПошукуНайкороткшихШляхівToolStripMenuItem;
	System::Windows::Forms::ToolStripMenuItem^ МоделюванняТранспортноїМережіToolStripMenuItem;

		Heap* heap;
		void UpdateGrid() {
			dataGridView1->Columns->Clear();
			dataGridView1->Rows->Clear();

			dataGridView1->Columns->Add("Name", "Назва компанії");
			dataGridView1->Columns->Add("Address", "Адреса");
			dataGridView1->Columns->Add("Year", "Рік");
			dataGridView1->Columns->Add("Month", "Місяць");
			dataGridView1->Columns->Add("Profit", "Прибуток");

			for (size_t i = 0; i < heap->getSize(); ++i) {
				Company c = heap->getValue(i);
				dataGridView1->Rows->Add(
					gcnew System::String(c.name.c_str()),
					gcnew System::String(c.address.c_str()),
					c.year.ToString(),
					c.month.ToString(),
					c.profit.ToString("F2")
				);
			}
		}

	public:
		Lb1(void)
		{
			InitializeComponent();
			heap = new Heap();
			heap->load();

		}

	protected:
		~Lb1()
		{
			if (components)
			{
				delete components;
			}
			delete heap;
			heap = nullptr;
		}
	protected:

	private: 

		System::Windows::Forms::MenuStrip^ menuStrip1;

		System::Windows::Forms::ToolStripMenuItem^ МенюToolStripMenuItem;
		System::Windows::Forms::ToolStripMenuItem^ ВихідToolStripMenuItem1;

		System::Windows::Forms::DataGridView^ dataGridView1;

		System::Windows::Forms::Button^ button1;
		System::Windows::Forms::Button^ button3;
		System::Windows::Forms::Button^ button4;
		System::Windows::Forms::Button^ button7;
		System::Windows::Forms::Button^ button8;
		System::Windows::Forms::Button^ button9;
	
		System::Windows::Forms::TextBox^ textBox1;
		System::Windows::Forms::TextBox^ textBox2;
		System::Windows::Forms::TextBox^ textBox3;
		System::Windows::Forms::TextBox^ textBox4;
	
		System::Windows::Forms::Label^ label1;
		System::Windows::Forms::Label^ label2;
		System::Windows::Forms::Label^ label3;
		System::Windows::Forms::Label^ label4;
		System::Windows::Forms::Label^ label12;
	
		System::Windows::Forms::PictureBox^ pictureBox1;
		System::Windows::Forms::PictureBox^ pictureBox2;

	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->МенюToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ВихідToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ЛінійніСтруктуриДанихToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ДереваТаГешТаблиціToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ЖадібніАлгоритмиToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ДинамічнеПрограмуванняToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->АлгоритмОбходуГрафівToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->АлгоритмПошукуНайкороткшихШляхівToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->МоделюванняТранспортноїМережіToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(8) {
				this->МенюToolStripMenuItem,
					this->ЛінійніСтруктуриДанихToolStripMenuItem, this->ДереваТаГешТаблиціToolStripMenuItem, this->ЖадібніАлгоритмиToolStripMenuItem,
					this->ДинамічнеПрограмуванняToolStripMenuItem, this->АлгоритмОбходуГрафівToolStripMenuItem, this->АлгоритмПошукуНайкороткшихШляхівToolStripMenuItem,
					this->МоделюванняТранспортноїМережіToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1059, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// МенюToolStripMenuItem
			// 
			this->МенюToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->ВихідToolStripMenuItem1 });
			this->МенюToolStripMenuItem->Name = L"МенюToolStripMenuItem";
			this->МенюToolStripMenuItem->Size = System::Drawing::Size(53, 20);
			this->МенюToolStripMenuItem->Text = L"Меню";
			// 
			// ВихідToolStripMenuItem1
			// 
			this->ВихідToolStripMenuItem1->Name = L"ВихідToolStripMenuItem1";
			this->ВихідToolStripMenuItem1->Size = System::Drawing::Size(102, 22);
			this->ВихідToolStripMenuItem1->Text = L"Вихід";
			this->ВихідToolStripMenuItem1->Click += gcnew System::EventHandler(this, &Lb1::ВихідToolStripMenuItem1_Click);
			// 
			// ЛінійніСтруктуриДанихToolStripMenuItem
			// 
			this->ЛінійніСтруктуриДанихToolStripMenuItem->Name = L"ЛінійніСтруктуриДанихToolStripMenuItem";
			this->ЛінійніСтруктуриДанихToolStripMenuItem->Size = System::Drawing::Size(147, 20);
			this->ЛінійніСтруктуриДанихToolStripMenuItem->Text = L"ЛінійніСтруктуриДаних";
			// 
			// ДереваТаГешТаблиціToolStripMenuItem
			// 
			this->ДереваТаГешТаблиціToolStripMenuItem->Name = L"ДереваТаГешТаблиціToolStripMenuItem";
			this->ДереваТаГешТаблиціToolStripMenuItem->Size = System::Drawing::Size(138, 20);
			this->ДереваТаГешТаблиціToolStripMenuItem->Text = L"ДереваТаГешТаблиці";
			this->ДереваТаГешТаблиціToolStripMenuItem->Click += gcnew System::EventHandler(this, &Lb1::ДереваТаГештаблиціToolStripMenuItem_Click);
			// 
			// ЖадібніАлгоритмиToolStripMenuItem
			// 
			this->ЖадібніАлгоритмиToolStripMenuItem->Name = L"ЖадібніАлгоритмиToolStripMenuItem";
			this->ЖадібніАлгоритмиToolStripMenuItem->Size = System::Drawing::Size(124, 20);
			this->ЖадібніАлгоритмиToolStripMenuItem->Text = L"ЖадібніАлгоритми";
			this->ЖадібніАлгоритмиToolStripMenuItem->Click += gcnew System::EventHandler(this, &Lb1::ЖадібніАлгоритмиToolStripMenuItem_Click);
			// 
			// ДинамічнеПрограмуванняToolStripMenuItem
			// 
			this->ДинамічнеПрограмуванняToolStripMenuItem->Name = L"ДинамічнеПрограмуванняToolStripMenuItem";
			this->ДинамічнеПрограмуванняToolStripMenuItem->Size = System::Drawing::Size(167, 20);
			this->ДинамічнеПрограмуванняToolStripMenuItem->Text = L"ДинамічнеПрограмування";
			this->ДинамічнеПрограмуванняToolStripMenuItem->Click += gcnew System::EventHandler(this, &Lb1::ДинамічнеПрограмуванняToolStripMenuItem_Click);
			// 
			// АлгоритмОбходуГрафівToolStripMenuItem
			// 
			this->АлгоритмОбходуГрафівToolStripMenuItem->Name = L"АлгоритмОбходуГрафівToolStripMenuItem";
			this->АлгоритмОбходуГрафівToolStripMenuItem->Size = System::Drawing::Size(151, 20);
			this->АлгоритмОбходуГрафівToolStripMenuItem->Text = L"АлгоритмОбходуГрафів";
			this->АлгоритмОбходуГрафівToolStripMenuItem->Click += gcnew System::EventHandler(this, &Lb1::АлгоритмОбходуГрафівToolStripMenuItem_Click);
			// 
			// АлгоритмПошукуНайкороткшихШляхівToolStripMenuItem
			// 
			this->АлгоритмПошукуНайкороткшихШляхівToolStripMenuItem->Name = L"АлгоритмПошукуНайкороткшихШляхівToolStripMenuItem";
			this->АлгоритмПошукуНайкороткшихШляхівToolStripMenuItem->Size = System::Drawing::Size(240, 20);
			this->АлгоритмПошукуНайкороткшихШляхівToolStripMenuItem->Text = L"АлгоритмПошукуНайкороткшихШляхів";
			this->АлгоритмПошукуНайкороткшихШляхівToolStripMenuItem->Click += gcnew System::EventHandler(this, &Lb1::АлгоритмПошукуНайкороткшихШляхівToolStripMenuItem_Click);
			// 
			// МоделюванняТранспортноїМережіToolStripMenuItem
			// 
			this->МоделюванняТранспортноїМережіToolStripMenuItem->Name = L"МоделюванняТранспортноїМережіToolStripMenuItem";
			this->МоделюванняТранспортноїМережіToolStripMenuItem->Size = System::Drawing::Size(216, 20);
			this->МоделюванняТранспортноїМережіToolStripMenuItem->Text = L"МоделюванняТранспортноїМережі";
			this->МоделюванняТранспортноїМережіToolStripMenuItem->Click += gcnew System::EventHandler(this, &Lb1::МоделюванняТранспортноїМережіToolStripMenuItem_Click);
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(76, 646);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(398, 26);
			this->button1->TabIndex = 38;
			this->button1->Text = L"Сформувати топ найприбутковіших компаній за рік\r\n";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Lb1::button1_Click);
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button3->Location = System::Drawing::Point(339, 444);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(120, 34);
			this->button3->TabIndex = 34;
			this->button3->Text = L"Видалити";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Lb1::button3_Click);
			// 
			// button4
			// 
			this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button4->Location = System::Drawing::Point(193, 444);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(126, 34);
			this->button4->TabIndex = 37;
			this->button4->Text = L"Редагувати\r\n";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Lb1::button4_Click);
			// 
			// button7
			// 
			this->button7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button7->Location = System::Drawing::Point(815, 646);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(181, 26);
			this->button7->TabIndex = 41;
			this->button7->Text = L"Зберегти у файл";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &Lb1::button7_Click);
			// 
			// button8
			// 
			this->button8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button8->Location = System::Drawing::Point(76, 444);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(99, 34);
			this->button8->TabIndex = 42;
			this->button8->Text = L"Додати";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &Lb1::button8_Click);
			// 
			// button9
			// 
			this->button9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button9->Location = System::Drawing::Point(869, 444);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(127, 34);
			this->button9->TabIndex = 47;
			this->button9->Text = L"Оновити купу";
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &Lb1::button9_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->Location = System::Drawing::Point(66, 69);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(944, 357);
			this->dataGridView1->TabIndex = 3;
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::Color::White;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1->Location = System::Drawing::Point(76, 536);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(137, 26);
			this->textBox1->TabIndex = 25;
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Times New Roman", 24, System::Drawing::FontStyle::Bold));
			this->label12->Location = System::Drawing::Point(362, 24);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(385, 36);
			this->label12->TabIndex = 36;
			this->label12->Text = L"Пірамідальне сортування";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::SystemColors::ControlLight;
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(72, 508);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(123, 19);
			this->label1->TabIndex = 46;
			this->label1->Text = L"Назва компанії:";
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Gainsboro;
			this->pictureBox1->Location = System::Drawing::Point(66, 432);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(944, 58);
			this->pictureBox1->TabIndex = 43;
			this->pictureBox1->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackColor = System::Drawing::SystemColors::ControlLight;
			this->pictureBox2->Location = System::Drawing::Point(66, 496);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(437, 185);
			this->pictureBox2->TabIndex = 45;
			this->pictureBox2->TabStop = false;
			// 
			// textBox2
			// 
			this->textBox2->BackColor = System::Drawing::Color::White;
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox2->Location = System::Drawing::Point(76, 601);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(137, 26);
			this->textBox2->TabIndex = 49;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::SystemColors::ControlLight;
			this->label2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(72, 573);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(130, 19);
			this->label2->TabIndex = 50;
			this->label2->Text = L"Адреса компанії:";
			// 
			// textBox3
			// 
			this->textBox3->BackColor = System::Drawing::Color::White;
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox3->Location = System::Drawing::Point(251, 601);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(137, 26);
			this->textBox3->TabIndex = 51;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::SystemColors::ControlLight;
			this->label3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(247, 573);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(83, 19);
			this->label3->TabIndex = 52;
			this->label3->Text = L"Прибуток:";
			// 
			// textBox4
			// 
			this->textBox4->BackColor = System::Drawing::Color::White;
			this->textBox4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox4->Location = System::Drawing::Point(251, 536);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(137, 26);
			this->textBox4->TabIndex = 53;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::SystemColors::ControlLight;
			this->label4->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(247, 509);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(119, 19);
			this->label4->TabIndex = 54;
			this->label4->Text = L"Дата прибутку:";
			// 
			// Lb1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1059, 781);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->button9);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Lb1";
			this->Text = L"Lb1";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion
	private:
			   System::Void ЛінійніСтруктуриДанихToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
				    MessageBox::Show("ЛінійніСтруктуриДаних вибрані!");
			   }
			   System::Void ДереваТаГештаблиціToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
				   Lb2^ form2 = gcnew Lb2();
				   form2->Show();
			   }
			   System::Void ЖадібніАлгоритмиToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
				   Lb3^ form3 = gcnew Lb3();
				   form3->Show();
			   }
			   System::Void ДинамічнеПрограмуванняToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
				   Lb4^ form4 = gcnew Lb4();
				   form4->Show();
			   }
			   System::Void АлгоритмОбходуГрафівToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
				   Lb5^ form5 = gcnew Lb5();
				   form5->Show();
			   }
			   System::Void АлгоритмПошукуНайкороткшихШляхівToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
				   Lb6^ form6 = gcnew Lb6();
				   form6->Show();
			   }
			   System::Void МоделюванняТранспортноїМережіToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
				   Lb7^ form7 = gcnew Lb7();
				   form7->Show();
			   }

			   System::Void ВихідToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e) {
				   this->Close();
			   }

			   static bool CompareCompanies(const Company& a, const Company& b) {
				   if (a.profit != b.profit)
					   return a.profit > b.profit;
				   return a.month > b.month;
			   }

			   System::Void button8_Click(System::Object^ sender, System::EventArgs^ e) {
				   Company c;
				   c.name = msclr::interop::marshal_as<std::string>(textBox1->Text);
				   c.address = msclr::interop::marshal_as<std::string>(textBox2->Text);

				   std::string date = msclr::interop::marshal_as<std::string>(textBox4->Text);
				   size_t dash = date.find('-');
				   if (dash == std::string::npos) {
					   MessageBox::Show("Введіть дату у форматі РІК-МІСЯЦЬ, напр. 2023-5");
					   return;
				   }
				   try {
					   c.year = std::stoi(date.substr(0, dash));
					   c.month = std::stoi(date.substr(dash + 1));
				   }
				   catch (...) {
					   MessageBox::Show("Введіть коректну дату у форматі РІК-МІСЯЦЬ!");
					   return;
				   }

				   try {
					   std::string profitStr = msclr::interop::marshal_as<std::string>(textBox3->Text);
					   for (auto& ch : profitStr) if (ch == ',') ch = '.';
					   c.profit = std::stod(profitStr);
				   }
				   catch (...) {
					   MessageBox::Show("Введіть коректний прибуток!");
					   return;
				   }

				   std::vector<Company> all = heap->getAll();
				   all.push_back(c);
				   heap->buildHeap(all);
				   UpdateGrid();
			   }

			   System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
				   std::string name = msclr::interop::marshal_as<std::string>(textBox1->Text);
				   if (name.empty()) {
					   MessageBox::Show("Введіть назву компанії для видалення!");
					   return;
				   }

				   std::vector<Company> all = heap->getAll();
				   bool found = false;
				   for (auto it = all.begin(); it != all.end(); ++it) {
					   if (it->name == name) {
						   all.erase(it);
						   found = true;
						   break;
					   }
				   }

				   if (found) {
					   heap->buildHeap(all);
					   UpdateGrid();
				   }
				   else {
					   MessageBox::Show("Компанію з такою назвою не знайдено.", "Інформація", MessageBoxButtons::OK, MessageBoxIcon::Information);
				   }
			   }

			   System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
				   if (dataGridView1->SelectedCells->Count > 0) {
					   int row = dataGridView1->SelectedCells[0]->RowIndex;
					   std::vector<Company> all = heap->getAll();
					   if (row < 0 || row >= (int)all.size()) {
						   MessageBox::Show("Некоректний індекс!", "Помилка", MessageBoxButtons::OK, MessageBoxIcon::Error);
						   return;
					   }

					   Company c;
					   c.name = msclr::interop::marshal_as<std::string>(textBox1->Text);
					   c.address = msclr::interop::marshal_as<std::string>(textBox2->Text);

					   std::string date = msclr::interop::marshal_as<std::string>(textBox4->Text);
					   size_t dash = date.find('-');
					   if (dash == std::string::npos) {
						   MessageBox::Show("Введіть дату у форматі РІК-МІСЯЦЬ, напр. 2023-5");
						   return;
					   }
					   try {
						   c.year = std::stoi(date.substr(0, dash));
						   c.month = std::stoi(date.substr(dash + 1));
					   }
					   catch (...) {
						   MessageBox::Show("Введіть коректну дату у форматі РІК-МІСЯЦЬ!");
						   return;
					   }

					   try {
						   std::string profitStr = msclr::interop::marshal_as<std::string>(textBox3->Text);
						   for (auto& ch : profitStr) if (ch == ',') ch = '.';
						   c.profit = std::stod(profitStr);
					   }
					   catch (...) {
						   MessageBox::Show("Введіть коректний прибуток!");
						   return;
					   }

					   all[row] = c;
					   heap->buildHeap(all);
					   UpdateGrid();
				   }
				   else {
					   MessageBox::Show("Виберіть елемент для редагування!", "Помилка", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				   }
			   }

			   System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {
				   heap->save();
			   }

			   System::Void button9_Click(System::Object^ sender, System::EventArgs^ e) {
				   heap->load();
				   UpdateGrid();
			   }

			   System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
				   String^ yearStr = Interaction::InputBox("Введіть рік для топ-компаній:", "Рік", "2023", -1, -1);
				   int year = 0;
				   try {
					   year = System::Convert::ToInt32(yearStr);
				   }
				   catch (...) {
					   MessageBox::Show("Введіть коректний рік!");
					   return;
				   }

				   std::vector<Company> all = heap->getAll();
				   std::vector<Company> yearCompanies;
				   std::vector<Company> otherCompanies;

				   for (const auto& c : all) {
					   if (c.year == year)
						   yearCompanies.push_back(c);
					   else
						   otherCompanies.push_back(c);
				   }

				   std::sort(yearCompanies.begin(), yearCompanies.end(), CompareCompanies);
				   std::sort(otherCompanies.begin(), otherCompanies.end(), CompareCompanies);

				   std::vector<Company> top;
				   top.insert(top.end(), yearCompanies.begin(), yearCompanies.end());
				   top.insert(top.end(), otherCompanies.begin(), otherCompanies.end());

				   int topCount = 3;
				   dataGridView1->Rows->Clear();
				   for (int i = 0; i < topCount && i < (int)top.size(); ++i) {
					   const auto& c = top[i];

					   std::ostringstream oss;
					   oss << std::fixed << std::setprecision(2) << c.profit;
					   std::string profitStr = oss.str();

					   dataGridView1->Rows->Add(
						   gcnew System::String(c.name.c_str()),
						   gcnew System::String(c.address.c_str()),
						   gcnew System::String(std::to_string(c.year).c_str()),
						   gcnew System::String(std::to_string(c.month).c_str()),
						   gcnew System::String(profitStr.c_str())
					   );
				   }
				   MessageBox::Show("Топ компаній сформовано!");
			   }

	};
}
