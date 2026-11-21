#include "Lb4.h"
#include "GridTask.h"
#include <msclr/marshal_cppstd.h>
#include <fstream>
using namespace Project1;
using namespace msclr::interop;

GridTask* grid = nullptr;

void Project1::Lb4::UpdateGrid()
{
    dataGridView1->Rows->Clear();
    dataGridView1->Columns->Clear();
    if (!grid) return;

    int rows = grid->getRows();
    int cols = grid->getCols();

    for (int j = 0; j < cols; ++j)
        dataGridView1->Columns->Add("", (j + 1).ToString());

    for (int i = 0; i < rows; ++i) {
        array<System::Object^>^ row = gcnew array<System::Object^>(cols);
        for (int j = 0; j < cols; ++j)
            row[j] = grid->getCell(i, j);
        dataGridView1->Rows->Add(row);
    }
}

void Project1::Lb4::button8_Click(System::Object^ sender, System::EventArgs^ e)
{
    try {
        int rows = System::Convert::ToInt32(textBox7->Text);
        int cols = System::Convert::ToInt32(textBox6->Text);
        grid->create(rows, cols);
        UpdateGrid();
    }
    catch (...) {
        System::Windows::Forms::MessageBox::Show("Некоректні дані для створення поля.");
    }
}

void Project1::Lb4::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
    try {
        int x = System::Convert::ToInt32(textBox1->Text) - 1;
        int y = System::Convert::ToInt32(textBox2->Text) - 1;
        double value = System::Convert::ToDouble(textBox4->Text);

        if (x >= 0 && x < grid->getRows() && y >= 0 && y < grid->getCols()) {
            grid->setCell(x, y, value);
            UpdateGrid();
        }
        else {
            System::Windows::Forms::MessageBox::Show("Координати поза межами таблиці.");
        }
    }
    catch (...) {
        System::Windows::Forms::MessageBox::Show("Некоректні дані для вводу.");
    }
}

void Project1::Lb4::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
    int r1 = 0, c1 = 0, r2 = 0, c2 = 0;
    try {
        System::String^ startText = textBox5->Text->Trim();
        array<System::String^>^ startParts = startText->Split(',');
        if (startParts->Length != 2)
            throw gcnew System::Exception();

        r1 = System::Convert::ToInt32(startParts[0]->Trim()) - 1;
        c1 = System::Convert::ToInt32(startParts[1]->Trim()) - 1;

        System::String^ endText = textBox3->Text->Trim();
        array<System::String^>^ endParts = endText->Split(',');
        if (endParts->Length != 2)
            throw gcnew System::Exception();

        r2 = System::Convert::ToInt32(endParts[0]->Trim()) - 1;
        c2 = System::Convert::ToInt32(endParts[1]->Trim()) - 1;
    }
    catch (...) {
        System::Windows::Forms::MessageBox::Show("Некоректні координати.");
        return;
    }
    std::vector<std::pair<int, int>> path;
    double res = grid->solvePath(r1, c1, r2, c2, path);
    if (res < 0) {
        System::Windows::Forms::MessageBox::Show("Некоректні координати для пошуку шляху.");
    }
    else {
        System::String^ pathStr = "";
        double sum = 0;
        for (size_t i = 0; i < path.size(); ++i) {
            int x = path[i].first + 1;
            int y = path[i].second + 1;
            double cost = grid->getCell(path[i].first, path[i].second);
            sum += cost;
            pathStr += "(" + x.ToString() + "," + y.ToString() + ") вартість " + cost.ToString();
            if (i != path.size() - 1)
                pathStr += " + ";
        }
        pathStr += " = " + sum.ToString();
        System::Windows::Forms::MessageBox::Show("Мінімальна вартість шляху: " + res.ToString() + "\nПуть: " + pathStr);
    }
}

void Project1::Lb4::button9_Click(System::Object^ sender, System::EventArgs^ e)
{
    grid->loadFromFile("table.txt");
    UpdateGrid();
    MessageBox::Show("Поле оновлено!");
}

void Project1::Lb4::button7_Click(System::Object^ sender, System::EventArgs^ e)
{
    grid->saveToFile("table.txt");
    MessageBox::Show("Поле збережено у файл!");
}