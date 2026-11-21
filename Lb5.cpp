#include "Lb5.h"
#include "Graph.h"

using namespace System;
using namespace System::Windows::Forms;

void Project1::Lb5::UpdateDataGridView()
{
    if (!graph) return;

    dataGridView2->Columns->Clear();
    dataGridView2->Rows->Clear();

    for (int i = 0; i < graph->n; ++i)
    {
        dataGridView2->Columns->Add(i.ToString(), "V" + i.ToString());
    }

    for (int i = 0; i < graph->n; ++i)
    {
        array<String^>^ row = gcnew array<String^>(graph->n);
        for (int j = 0; j < graph->n; ++j)
        {
            row[j] = graph->adj[i][j].ToString();
        }
        dataGridView2->Rows->Add(row);
        dataGridView2->Rows[i]->HeaderCell->Value = "V" + i.ToString();
    }
}

System::Void Project1::Lb5::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (!graph) graph = new Graph(1, false);
    graph->loadFromFile("graph.txt");
    UpdateDataGridView();
    MessageBox::Show("Дані з файлу завантажено.");
}

System::Void Project1::Lb5::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (!isGraphCreated) {
        if (graph) { delete graph; graph = nullptr; }
        if (vertexValues) { delete[] vertexValues; vertexValues = nullptr; }

        vertexCount = Convert::ToInt32(textBox4->Text);
        edgeCount = Convert::ToInt32(textBox5->Text);
        bool directed = checkBox1->Checked;

        graph = new Graph(vertexCount, directed);
        vertexValues = new int[vertexCount];
        for (int i = 0; i < vertexCount; ++i) vertexValues[i] = 0;

        currentEdgeIndex = 0;
        isGraphCreated = true;
        MessageBox::Show("Граф створено. Тепер додайте значення вершин і ребра.");
        UpdateDataGridView();
        return;
    }

    int v = Convert::ToInt32(numericUpDown1->Value);
    int value = Convert::ToInt32(textBox7->Text);
    vertexValues[v] = value;
    graph->vertex_values[v] = value;

    if (currentEdgeIndex < edgeCount) {
        if (String::IsNullOrWhiteSpace(textBox6->Text)) {
            MessageBox::Show("Введите номер вершины (u) для ребра!");
            return;
        }
        int u;
        if (!Int32::TryParse(textBox6->Text, u)) {
            MessageBox::Show("Некорректный номер вершины (u)!");
            return;
        }
        int w = Convert::ToInt32(textBox1->Text);
        graph->addEdge(u, w);
        currentEdgeIndex++;
        MessageBox::Show("Ребро додано.");
        UpdateDataGridView();
    }
    else {
        MessageBox::Show("Усі ребра вже додані.");
    }
}
System::Void Project1::Lb5::button3_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (!graph) { MessageBox::Show("Граф не створено!"); return; }
    graph->DFS_numbering_all();
    String^ msg = "DFS порядкові номери:\n";
    for (int i = 0; i < graph->n; ++i) {
        msg += "Вершина " + i + " -> номер " + graph->dfs_order[i];
        if (graph->parent[i] == -1) msg += " (корінь компоненти)";
        else msg += " , батько = " + graph->parent[i];
        msg += "\n";
    }

    int edgeCount = 0;
    for (int i = 0; i < graph->n; ++i)
        for (int j = 0; j < graph->n; ++j)
            if (graph->adj[i][j]) edgeCount++;

    if (!graph->directed)
        edgeCount /= 2;

    int maxEdges = graph->directed ? graph->n * (graph->n - 1) : graph->n * (graph->n - 1) / 2;
    double density = maxEdges > 0 ? (double)edgeCount / maxEdges : 0.0;

    msg += "\nМаксимальна кількість ребер: " + maxEdges.ToString();
    msg += "\nЩільність графа = " + density.ToString("F2");

    MessageBox::Show(msg);
}

System::Void Project1::Lb5::button4_Click(System::Object^ sender, System::EventArgs^ e)
{
    graph->saveToFile("graph.txt");
    MessageBox::Show("Граф збережено у файл graph.txt");
}

System::Void Project1::Lb5::button5_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (!graph) {
        MessageBox::Show("Граф не створено!");
        return;
    }

    int start = Convert::ToInt32(numericUpDown3->Value);
    int end = Convert::ToInt32(numericUpDown2->Value);

    int S;
    if (!Int32::TryParse(textBox3->Text, S)) {
        MessageBox::Show("Введіть коректне число S!", "Помилка", MessageBoxButtons::OK, MessageBoxIcon::Error);
        return;
    }

    int path_len = 0;
    int* path = graph->BFS_path(start, end, path_len);
    if (!path || path_len == 0) {
        MessageBox::Show("Шлях не знайдено!");
        if (path) delete[] path;
        return;
    }

    int sum = 0;
    for (int i = 0; i < path_len; ++i)
        sum += graph->vertex_values[path[i]];

    String^ msg = "";
    if (sum == S) {
        msg = "Шлях: ";
        for (int i = 0; i < path_len; ++i)
            msg += path[i].ToString() + (i + 1 < path_len ? " -> " : "");
        msg += "\nСума значень = " + sum.ToString();
    }
    else {
        msg = "Шлях знайдено, але сума значень = " + sum.ToString() + " (≠ S)";
    }

    MessageBox::Show(msg);
    delete[] path;
}

