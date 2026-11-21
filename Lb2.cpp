#include <string>
#include <msclr/marshal_cppstd.h>
#include "Lb2.h"
#include "HashTable.h"
#include "BST.h"

using namespace Project1;

static HashTable* hashTable = nullptr;
static BST* bst = nullptr;


void Project1::Lb2::UpdateDictionaryGrid()
{
    dataGridView1->Rows->Clear();
    dataGridView1->Columns->Clear();

    dataGridView1->Columns->Add("WordColumn", "Слово");
    dataGridView1->Columns->Add("HintColumn", "Підсказка");

    auto all = hashTable->getAll();
    for (const auto& pair : all) {
        dataGridView1->Rows->Add(
            gcnew System::String(pair.first.c_str()),
            gcnew System::String(pair.second.c_str())
        );
    }
}

void Project1::Lb2::UpdateOwnersGrid()
{
    dataGridView2->Rows->Clear();
    dataGridView2->Columns->Clear();

    dataGridView2->Columns->Add("SurnameColumn", "Прізвище");
    dataGridView2->Columns->Add("NameColumn", "Ім'я");
    dataGridView2->Columns->Add("PatronymicColumn", "По батькові");
    dataGridView2->Columns->Add("CarNumberColumn", "Номер авто");
    dataGridView2->Columns->Add("RegDateColumn", "Дата реєстрації");

    auto all = bst->getAll();
    for (const auto& owner : all) {
        dataGridView2->Rows->Add(
            gcnew System::String(owner.surname.c_str()),
            gcnew System::String(owner.name.c_str()),
            gcnew System::String(owner.patronymic.c_str()),
            gcnew System::String(owner.carNumber.c_str()),
            gcnew System::String(owner.regDate.c_str())
        );
    }
}


System::Void Project1::Lb2::button8_Click(System::Object^ sender, System::EventArgs^ e)
{
    std::string word = msclr::interop::marshal_as<std::string>(textBox1->Text);
    std::string hint = msclr::interop::marshal_as<std::string>(textBox2->Text);
    hashTable->insert(word, hint);
    UpdateDictionaryGrid();
}

System::Void Project1::Lb2::button3_Click(System::Object^ sender, System::EventArgs^ e)
{
    std::string word = msclr::interop::marshal_as<std::string>(textBox1->Text);
    hashTable->remove(word);
    UpdateDictionaryGrid();
}

System::Void Project1::Lb2::button12_Click(System::Object^ sender, System::EventArgs^ e)
{
    std::string word = msclr::interop::marshal_as<std::string>(textBox1->Text);
    std::string result = hashTable->search(word);
    if (!result.empty())
        MessageBox::Show(gcnew System::String(result.c_str()), "Підсказка");
    else
        MessageBox::Show("Слово не знайдено", "Пошук");
}

System::Void Project1::Lb2::button7_Click(System::Object^ sender, System::EventArgs^ e)
{
    hashTable->saveToFile("words.txt");
    MessageBox::Show("Словник збережено у файл!");
}

System::Void Project1::Lb2::button9_Click(System::Object^ sender, System::EventArgs^ e)
{
    hashTable->loadFromFile("words.txt");
    UpdateDictionaryGrid();
}

System::Void Project1::Lb2::button5_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (dataGridView2->SelectedRows->Count == 0) {
        MessageBox::Show("Оберіть власника для видалення.");
        return;
    }

    System::String^ carNumberStr = dataGridView2->SelectedRows[0]->Cells["CarNumberColumn"]->Value->ToString();
    std::string carNumber = msclr::interop::marshal_as<std::string>(carNumberStr);

    if (bst->remove(carNumber)) {
        UpdateOwnersGrid();
    }
    else {
    }
}

System::Void Project1::Lb2::button6_Click(System::Object^ sender, System::EventArgs^ e)
{
    UpdateOwnersGrid();
}

System::Void Project1::Lb2::button10_Click(System::Object^ sender, System::EventArgs^ e)
{
    auto many = bst->getOwnersWithManyCars();
    System::String^ msg = "";
    for (const auto& s : many) {
        msg += gcnew System::String(s.c_str()) + "\n";
    }
    if (msg->Length == 0) msg = "Немає власників з кількома авто";
    MessageBox::Show(msg, "Власники з кількома авто");
}

System::Void Project1::Lb2::button4_Click(System::Object^ sender, System::EventArgs^ e)
{
    bst->saveToFile("owners.txt");
    MessageBox::Show("Дані про власників збережено у файл!");
}

System::Void Project1::Lb2::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
    bst->loadFromFile("owners.txt");
    UpdateOwnersGrid();
    MessageBox::Show("Дані про власників оновлено з файлу!");
}

System::Void Project1::Lb2::button11_Click(System::Object^ sender, System::EventArgs^ e)
{
    std::string carNumber = msclr::interop::marshal_as<std::string>(textBox3->Text);
    ::Owner found;
    if (bst->search(carNumber, found)) {
        MessageBox::Show(
            gcnew System::String(
                (found.surname + " " + 
                 found.name + " " + 
                 found.patronymic + "\nДата: " + 
                 found.regDate).c_str()),
            "Власник знайдений"
        );
    }
    else {
        MessageBox::Show("Власник не знайдений", "Пошук");
    }
}

System::Void Project1::Lb2::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
	::Owner newOwner;
	newOwner.surname = msclr::interop::marshal_as<std::string>(textBox4->Text);
	newOwner.name = msclr::interop::marshal_as<std::string>(textBox6->Text);
	newOwner.patronymic = msclr::interop::marshal_as<std::string>(textBox7->Text);
	newOwner.carNumber = msclr::interop::marshal_as<std::string>(textBox3->Text);
	newOwner.regDate = msclr::interop::marshal_as<std::string>(textBox5->Text);
	bst->insert(newOwner);
	UpdateOwnersGrid();
}
