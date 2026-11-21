#include "Lb6.h"
#include "ShortestPaths.h"
#include <vector>

using namespace System;
using namespace System::Windows::Forms;

std::vector<std::pair<int, int>> disabledEdgess;


void Project1::Lb6::UpdateDataGridView()
{
    if (!dijkstra) return;

    dataGridView2->Columns->Clear();
    dataGridView2->Rows->Clear();

    for (int i = 0; i < vertexCount; ++i)
        dataGridView2->Columns->Add(i.ToString(), "V" + i.ToString());

    long long** mat = dijkstra->getGraph();
    for (int i = 0; i < vertexCount; ++i) {
        array<String^>^ row = gcnew array<String^>(vertexCount);
        for (int j = 0; j < vertexCount; ++j) {
            if (mat[i][j] == INF)
                row[j] = "INF";
            else
                row[j] = mat[i][j].ToString();
        }
        dataGridView2->Rows->Add(row);
        dataGridView2->Rows[i]->HeaderCell->Value = "V" + i.ToString();
    }
}

System::Void Project1::Lb6::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
    disabledEdgess.clear();

    vertexCount = Convert::ToInt32(textBox4->Text);
    edgeCount = Convert::ToInt32(textBox5->Text);
    currentEdge = 0;
    if (edges) {
        for (int i = 0; i < edgeCount; ++i) delete[] edges[i];
        delete[] edges;
    }
    edges = new int* [edgeCount];
    for (int i = 0; i < edgeCount; ++i) edges[i] = new int[3];
    bellmanFord = new BellmanFord(edgeCount, vertexCount);
    dijkstra = new Dijkstra(vertexCount);
    floydWarshall = new FloydWarshall(vertexCount);

    dataGridView2->Columns->Clear();
    dataGridView2->Rows->Clear();
    dataGridView2->Columns->Add("u", "Початок");
    dataGridView2->Columns->Add("v", "Кінець");
    dataGridView2->Columns->Add("w", "Вага");

    MessageBox::Show("Мережу створено. Тепер додайте ребра.", "Інформація", MessageBoxButtons::OK, MessageBoxIcon::Information);
}
System::Void Project1::Lb6::button6_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (currentEdge >= edgeCount) {
        MessageBox::Show("Усі ребра вже додані.", "Попередження", MessageBoxButtons::OK, MessageBoxIcon::Warning);
        return;
    }
    int u = Convert::ToInt32(textBox6->Text);
    int v = Convert::ToInt32(textBox1->Text);
    int w = Convert::ToInt32(textBox2->Text);
    edges[currentEdge][0] = u;
    edges[currentEdge][1] = v;
    edges[currentEdge][2] = w;
    bellmanFord->addEdge(currentEdge, u, v, w);
    dijkstra->addEdge(u, v, w);
    currentEdge++;

    array<System::Object^>^ row = gcnew array<System::Object^>(3);
    row[0] = u;
    row[1] = v;
    row[2] = w;
    dataGridView2->Rows->Add(row);


    MessageBox::Show("Ребро додано.", "Інформація", MessageBoxButtons::OK, MessageBoxIcon::Information);
}

System::Void Project1::Lb6::button7_Click(System::Object^ sender, System::EventArgs^ e)
{

    int start = Convert::ToInt32(textBox9->Text);
    int end = Convert::ToInt32(textBox8->Text);
    int* prev = new int[vertexCount];
    long long* dist = bellmanFord->run(start, prev);
    if (!dist) {
        return;
    }
    if (dist[end] == INF) {
        MessageBox::Show("Шлях недоступний.", "Результат", MessageBoxButtons::OK, MessageBoxIcon::Information);
    }
    else {
        System::String^ path = end.ToString();
        int cur = end;
        while (cur != start && cur != -1) {
            cur = prev[cur];
            if (cur != -1) path = cur.ToString() + " -> " + path;
        }
        MessageBox::Show("Найкоротша відстань: " + dist[end].ToString() + "\nШлях: " + path, "Результат", MessageBoxButtons::OK, MessageBoxIcon::Information);
    }
    delete[] prev;
    delete[] dist;
}

System::Void Project1::Lb6::button10_Click(System::Object^ sender, System::EventArgs^ e)
{
    floydWarshall->loadGraph(dijkstra->getGraph());
    floydWarshall->run();

    long long** dist = floydWarshall->getDistances();

    dataGridView2->Columns->Clear();
    dataGridView2->Rows->Clear();
    for (int i = 0; i < vertexCount; ++i)
        dataGridView2->Columns->Add(i.ToString(), "V" + i.ToString());

    for (int i = 0; i < vertexCount; ++i) {
        array<String^>^ row = gcnew array<String^>(vertexCount);
        for (int j = 0; j < vertexCount; ++j) {
            if (dist[i][j] == INF)
                row[j] = "INF";
            else
                row[j] = dist[i][j].ToString();
        }
        dataGridView2->Rows->Add(row);
        dataGridView2->Rows[i]->HeaderCell->Value = "V" + i.ToString();
    }

    if (checkBox6->Checked) {
        int u = Convert::ToInt32(textBox15->Text);
        int v = Convert::ToInt32(textBox14->Text);
        int** next = floydWarshall->getNext();
        if (dist[u][v] == INF) {
            MessageBox::Show("Шлях відсутній.", "Результат", MessageBoxButtons::OK, MessageBoxIcon::Information);
            return;
        }
        System::String^ path = u.ToString();
        int cur = u;
        while (cur != v) {
            cur = next[cur][v];
            path += " -> " + cur.ToString();
        }
        MessageBox::Show("Відстань: " + dist[u][v].ToString() + "\nШлях: " + path, "Результат", MessageBoxButtons::OK, MessageBoxIcon::Information);
    }
    else {
        MessageBox::Show("Матриця найкоротших відстаней побудована.", "Готово", MessageBoxButtons::OK, MessageBoxIcon::Information);
    }
}

System::Void Project1::Lb6::button9_Click(System::Object^ sender, System::EventArgs^ e)
{
    dataGridView2->Columns->Clear();
    dataGridView2->Rows->Clear();
    dataGridView2->Columns->Add("u", "Початок");
    dataGridView2->Columns->Add("v", "Кінець");
    for (size_t i = 0; i < disabledEdgess.size(); ++i) {
        array<System::Object^>^ row = gcnew array<System::Object^>(2);
        row[0] = disabledEdgess[i].first;
        row[1] = disabledEdgess[i].second;
        dataGridView2->Rows->Add(row);
    }

    int start = Convert::ToInt32(textBox11->Text);
    int end = Convert::ToInt32(textBox10->Text);
    int* prev = new int[vertexCount];
    long long* dist = dijkstra->run(start, prev);
    if (dist[end] == INF) {
        MessageBox::Show("Шлях недоступний.", "Результат", MessageBoxButtons::OK, MessageBoxIcon::Information);
    }
    else {
        System::String^ path = end.ToString();
        int cur = end;
        while (cur != start && cur != -1) {
            cur = prev[cur];
            if (cur != -1) path = cur.ToString() + " -> " + path;
        }
        MessageBox::Show("Найкоротша відстань: " + dist[end].ToString() + "\nШлях: " + path, "Результат", MessageBoxButtons::OK, MessageBoxIcon::Information);
    }
    delete[] prev;
    delete[] dist;
}

System::Void Project1::Lb6::button8_Click(System::Object^ sender, System::EventArgs^ e)
{
    int u = Convert::ToInt32(textBox13->Text);
    int v = Convert::ToInt32(textBox12->Text);
    dijkstra->getGraph()[u][v] = INF;
    disabledEdgess.push_back({ u, v });

    dataGridView2->Columns->Clear();
    dataGridView2->Rows->Clear();
    dataGridView2->Columns->Add("u", "Початок");
    dataGridView2->Columns->Add("v", "Кінець");
    for (size_t i = 0; i < disabledEdgess.size(); ++i) {
        array<System::Object^>^ row = gcnew array<System::Object^>(2);
        row[0] = disabledEdgess[i].first;
        row[1] = disabledEdgess[i].second;
        dataGridView2->Rows->Add(row);
    }

    MessageBox::Show("Недоступне ребро додано.", "Інформація", MessageBoxButtons::OK, MessageBoxIcon::Information);
}

System::Void Project1::Lb6::button4_Click(System::Object^ sender, System::EventArgs^ e)
{
    System::IO::StreamWriter^ sw = gcnew System::IO::StreamWriter("mereja.txt", false);
    sw->WriteLine(vertexCount.ToString());
    sw->WriteLine(edgeCount.ToString());
    for (int i = 0; i < edgeCount; ++i) {
        sw->WriteLine(edges[i][0].ToString() + " " + edges[i][1].ToString() + " " + edges[i][2].ToString());
    }
    sw->Close();
    MessageBox::Show("Мережа збережена у файл mereja.txt");
}

System::Void Project1::Lb6::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
    System::IO::StreamReader^ sr = gcnew System::IO::StreamReader("mereja.txt");
    int n = Convert::ToInt32(sr->ReadLine());
    int m = Convert::ToInt32(sr->ReadLine());
    vertexCount = n;
    edgeCount = m;
    currentEdge = 0;

    if (edges) {
        for (int i = 0; i < edgeCount; ++i) delete[] edges[i];
        delete[] edges;
    }
    edges = new int* [edgeCount];
    for (int i = 0; i < edgeCount; ++i) edges[i] = new int[3];

    delete bellmanFord; delete dijkstra; delete floydWarshall;
    bellmanFord = new BellmanFord(edgeCount, vertexCount);
    dijkstra = new Dijkstra(vertexCount);
    floydWarshall = new FloydWarshall(vertexCount);

    for (int i = 0; i < edgeCount; ++i) {
        System::String^ line = sr->ReadLine();
        array<System::String^>^ parts = line->Split(' ');
        int u = Convert::ToInt32(parts[0]);
        int v = Convert::ToInt32(parts[1]);
        int w = Convert::ToInt32(parts[2]);
        edges[i][0] = u; edges[i][1] = v; edges[i][2] = w;
        bellmanFord->addEdge(i, u, v, w);
        dijkstra->addEdge(u, v, w);
    }
    sr->Close();
    UpdateDataGridView();
    MessageBox::Show("Дані з файлу завантажено.");
}
