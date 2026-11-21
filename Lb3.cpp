#include <msclr/marshal_cppstd.h>
#include "Lb3.h"
#include "ProductGroup.h"
#include <vector>

using namespace Project1;
using namespace msclr::interop;

void Project1::Lb3::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (dataGridView1->SelectedRows->Count > 0) {
		int idx = dataGridView1->SelectedRows[0]->Index;
		std::string name = marshal_as<std::string>(textBox1->Text);
		double price = System::Convert::ToDouble(textBox2->Text);
		int allowedDays = System::Convert::ToInt32(textBox3->Text);
		int daysLeft = System::Convert::ToInt32(textBox4->Text);

		ProductGroup p;
		p.name = name;
		p.price = price;
		p.allowedDays = allowedDays;
		p.daysLeft = daysLeft;

		planner->editProduct(idx, p);
		UpdateGrid();
	}
}

void Project1::Lb3::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
	std::vector<int> order;
	std::vector<double> profits;
	double baseProfit = 0.0;
	double greedyProfit = 0.0;
	double improvement = 0.0;
	double percent = 0.0;

	planner->planDelivery(order, profits, baseProfit, greedyProfit, improvement, percent);

	planner->reorderProducts(order);

	System::String^ message;
	if (improvement > 0.0001) {
		message = "Оптимізація успішна!\n"
			"Базовий прибуток: " + baseProfit.ToString("F2") + "\n"
			"Оптимізований прибуток: " + greedyProfit.ToString("F2") + "\n"
			"Покращення: " + improvement.ToString("F2") + " (" + percent.ToString("F2") + "%)";
	}
	else {
		message = "Порядок вже оптимальний.\n"
			"Прибуток: " + baseProfit.ToString("F2");
	}

	UpdateGrid();
	MessageBox::Show(message, "Результат оптимізації");
}

void Project1::Lb3::button3_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (dataGridView1->SelectedRows->Count > 0) {
		int idx = dataGridView1->SelectedRows[0]->Index;
		planner->deleteProduct(idx);
		UpdateGrid();
	}
}

void Project1::Lb3::button7_Click(System::Object^ sender, System::EventArgs^ e)
{
	planner->saveToFile("products.txt");
	MessageBox::Show("Дані про продукти збережено у файл!");
}

void Project1::Lb3::button8_Click(System::Object^ sender, System::EventArgs^ e)
{
	std::string name = marshal_as<std::string>(textBox1->Text);
	double price = System::Convert::ToDouble(textBox2->Text);
	int allowedDays = System::Convert::ToInt32(textBox3->Text);
	int daysLeft = System::Convert::ToInt32(textBox4->Text);

	ProductGroup p;
	p.name = name;
	p.price = price;
	p.allowedDays = allowedDays;
	p.daysLeft = daysLeft;

	planner->addProduct(p);
	UpdateGrid();
}

void Project1::Lb3::button9_Click(System::Object^ sender, System::EventArgs^ e)
{
	planner->loadFromFile("products.txt");
	UpdateGrid();
	MessageBox::Show("Дані про власників оновлено з файлу!");
}
