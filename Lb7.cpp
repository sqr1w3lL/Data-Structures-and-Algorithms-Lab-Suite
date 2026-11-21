#define NOMINMAX
#include "Lb7.h"
#include <algorithm>
#include <climits>
#include <fstream>
#include "Task.h"


bool compareTasks(Task a, Task b) {
    return a.latestFinish < b.latestFinish;
}
bool CompareTasksByStartTime(const Task& a, const Task& b) {
    return a.startTime < b.startTime;
}

bool scheduleTasks(int robots, Task* tasks, int n) {
    std::sort(tasks, tasks + n, compareTasks);

    int* robotAvailable = new int[robots];
    for (int i = 0; i < robots; i++)
        robotAvailable[i] = 0;
    for (int i = 0; i < n; i++) {
        Task& t = tasks[i];
        int earliestStart = t.earliestStart;
        int selectedRobot = -1;
        int minAvailableTime = INT_MAX;
        for (int r = 0; r < robots; r++) {
            if (robotAvailable[r] <= t.latestFinish - t.duration &&
                std::max(robotAvailable[r], earliestStart) < minAvailableTime) {
                minAvailableTime = std::max(robotAvailable[r], earliestStart);
                selectedRobot = r;
            }
        }
        if (selectedRobot == -1) {
            delete[] robotAvailable;
            return false;
        }
        t.startTime = minAvailableTime;
        robotAvailable[selectedRobot] = t.startTime + t.duration;
    }
    delete[] robotAvailable;
    return true;
}

System::Void Project1::Lb7::button4_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (tasks->empty()) {
        MessageBox::Show("Додайте хоча б одне завдання!", "Помилка", MessageBoxButtons::OK, MessageBoxIcon::Error);
        return;
    }
    int robots = Convert::ToInt32(textBox7->Text);
    int n = tasks->size();
    std::vector<Task> tempTasks = *tasks;
    if (scheduleTasks(robots, tempTasks.data(), n)) {
        *tasks = tempTasks;

        UpdateTasksTable();

        MessageBox::Show("Завдання можна виконати за заданих умов.", "Успіх", MessageBoxButtons::OK, MessageBoxIcon::Information);
    }
    else {
        MessageBox::Show("Неможливо виконати всі завдання за заданих умов.", "Помилка", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
}
void Project1::Lb7::UpdateTasksTable() {
    dataGridView1->Columns->Clear();
    dataGridView1->Rows->Clear();
    dataGridView1->Columns->Add("ID", "ID");
    dataGridView1->Columns->Add("EarliestStart", "Earliest Start");
    dataGridView1->Columns->Add("LatestFinish", "Latest Finish");
    dataGridView1->Columns->Add("Duration", "Duration");
    dataGridView1->Columns->Add("StartTime", "Scheduled Start Time");

    for (const Task& task : *tasks) {
        dataGridView1->Rows->Add(
            task.id,
            task.earliestStart,
            task.latestFinish,
            task.duration,
            task.startTime >= 0 ? task.startTime.ToString() : "Not Scheduled"
        );
    }
}


System::Void Project1::Lb7::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
    try {
        Task t;
        t.id = tasks->size() + 1;
        t.earliestStart = Convert::ToInt32(textBox9->Text);
        t.latestFinish = Convert::ToInt32(textBox8->Text);
        t.duration = Convert::ToInt32(textBox10->Text);
        t.startTime = -1;
        tasks->push_back(t);

        UpdateTasksTable();
    }
    catch (...) {
        MessageBox::Show("Введіть коректні дані для завдання!", "Помилка", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
}

System::Void Project1::Lb7::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
    UpdateTasksTable();
}

System::Void Project1::Lb7::button3_Click(System::Object^ sender, System::EventArgs^ e)
{
    tasks->clear();
    dataGridView1->Columns->Clear();
    dataGridView1->Rows->Clear();
    dataGridView1->Columns->Add("ID", "ID");
    dataGridView1->Columns->Add("EarliestStart", "Час початку");
    dataGridView1->Columns->Add("LatestFinish", "Час закінчення");
    dataGridView1->Columns->Add("Duration", "Тривалість");
    dataGridView1->Columns->Add("StartTime", "Початок виконання");
}

void Project1::Lb7::ShowNetworkTable() {
    dataGridView1->Columns->Clear();
    dataGridView1->Rows->Clear();
    dataGridView1->Columns->Add("ID", "ID");
    dataGridView1->Columns->Add("EarliestStart", "Earliest Start");
    dataGridView1->Columns->Add("LatestFinish", "Latest Finish");
    dataGridView1->Columns->Add("Duration", "Duration");
    dataGridView1->Columns->Add("StartTime", "Scheduled Start Time");

    std::vector<Task> scheduled;
    for (const Task& t : *tasks)
        if (t.startTime >= 0)
            scheduled.push_back(t);

    std::sort(scheduled.begin(), scheduled.end(), CompareTasksByStartTime);

    for (const Task& task : scheduled) {
        dataGridView1->Rows->Add(
            task.id,
            task.earliestStart,
            task.latestFinish,
            task.duration,
            task.startTime
        );
    }
}

void Project1::Lb7::saveToFile(System::String^ filename) {
    std::ofstream out(msclr::interop::marshal_as<std::string>(filename));
    if (!out) return;
    out << tasks->size() << "\n";
    for (const Task& t : *tasks) {
        out << t.id << " " << t.earliestStart << " " << t.latestFinish << " " << t.duration << " " << t.startTime << "\n";
    }
}


void Project1::Lb7::loadFromFile(System::String^ filename) {
    std::ifstream in(msclr::interop::marshal_as<std::string>(filename));
    if (!in) return;
    int n;
    in >> n;
    tasks->clear();
    for (int i = 0; i < n; ++i) {
        Task t;
        in >> t.id >> t.earliestStart >> t.latestFinish >> t.duration >> t.startTime;
        tasks->push_back(t);
    }
}

void Project1::Lb7::button9_Click(System::Object^ sender, System::EventArgs^ e)
{
    loadFromFile("table.txt");
    UpdateTasksTable();
    MessageBox::Show("Порядок оновлено!");
}

void Project1::Lb7::button7_Click(System::Object^ sender, System::EventArgs^ e)
{
    saveToFile("table.txt");
    MessageBox::Show("Порядок збережено у файл!");
}