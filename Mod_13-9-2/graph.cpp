#define VERYBIGINT 1000000 // очень большое число
#include "graph.h"
#include <iostream>

using namespace std;

Graph::Graph() {

    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            matrix[i][j] = 0;
    vertexCount = 0;
}
// добавление вершины
void Graph::addName(string vName)
{
    names[vertexCount] = vName;
    vertexCount++;
}
// добавление ребра
void Graph::addEdge(int v1, int v2, int weight)
{
    matrix[v1][v2] = weight;
    matrix[v2][v1] = weight;
}

// удаление участника 
void Graph::delName(string vName)
{
    int vnumber;
    bool vFind = false;
    cout << "”далить участника  " << vName << endl;
    for (int i = 0; i < vertexCount; i++)
        if (names[i] == vName) {
            vnumber = i;
            vFind = true;
        }
    if (vFind) {
        for (int i = vnumber; i < vertexCount - 1; i++) names[i] = names[i + 1];

        for (int j = 0; j < vertexCount; j++)
            for (int i = vnumber; i < vertexCount - 1; i++) matrix[i][j] = matrix[i + 1][j];

        for (int i = 0; i < vertexCount - 1; i++)
            for (int j = vnumber; j < vertexCount - 1; j++) matrix[i][j] = matrix[i][j + 1];

        names[vertexCount - 1] = "";

        vertexCount--;
    }
    else  cout << "”частник не найден " << endl;
}
// удаление ребра
void Graph::delEdge(int v1, int v2)
{
    matrix[v1][v2] = 0;
    matrix[v2][v1] = 0;
}

// проверка существовани€ ребра
bool Graph::edgeExists(int v1, int v2)
{
    return matrix[v1][v2] > 0;
}
// проверка существовани€ вершины
bool Graph::vertexExists(string v)
{
    for (int i = 0; i < vertexCount; i++)
        if (names[i] == v)
            return true;
    return false;
}

void Graph::showGraph() {
    setlocale(LC_ALL, "");
    cout << "√раф знакомств участников:" << endl;
    cout << "        ";
    for (int i = 0; i < vertexCount; i++) cout << names[i] << "     ";
    cout << endl;

    for (int i = 0; i < vertexCount; i++) {
        cout << names[i] << "     ";
        for (int j = 0; j < vertexCount; j++)  cout << matrix[i][j] << "        ";
        cout << endl;
    }
}

int Graph::showList() {
    setlocale(LC_ALL, "");
    cout << "”частников " << vertexCount << ":" << endl;
    for (int i = 0; i < vertexCount; i++) cout << i + 1 << " - " << names[i] << endl;
    cout << endl;
    return vertexCount;

}

void Graph::findFriends(int stage)
{
    int weights[SIZE][SIZE]; // матрица путей
    // инициализаци матрицы
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (i == j)
            {
                weights[i][j] = 0; // путь до самой себ€ равен 0
            }
            else {
                if (!edgeExists(i, j))
                {
                    weights[i][j] = VERYBIGINT; // если ребра нет
                }
                else {
                    weights[i][j] = matrix[i][j]; // если ребро есть
                }
            }
        }
    }

    for (int k = 0; k < vertexCount; k++) // итерации по k
    {
        int ck = k; // возьмем номер вершины
        for (int i = 0; i < vertexCount; i++)
        {
            if (i == k)
                continue;
            int ci = i;
            for (int j = 0; j < vertexCount; j++)
            {
                if (j == k)
                    continue;
                int cj = j;
                if (weights[ci][ck] + weights[ck][cj] < weights[ci][cj]) {
                    // пересчет мматрицы путей
                    weights[ci][cj] = weights[ci][ck] + weights[ck][cj];
                }
            }
        }
    }
    // вывод матрицы рассто€ний
    std::cout << endl << " ратчайшие пути между вершинами  (метод ‘лойда)" << endl;
    cout << "        ";
    for (int i = 0; i < vertexCount; i++) cout << names[i] << "     ";
    cout << endl;
    for (int i = 0; i < vertexCount; i++) {
        cout << names[i] << "     ";
        for (int j = 0; j < vertexCount; j++)
        {
            if (weights[i][j] == VERYBIGINT) cout << "0        ";
            else std::cout << weights[i][j] << "        ";
        }
        std::cout << std::endl;
    }
    // вывод пар с рассто€нием знакомства <= stage
    cout << endl << "ѕары, знакомые не более, чем через " << stage;
    if (stage == 1) cout << " рукопожатие " << endl;
    if (stage > 1 && stage < 5) cout << " рукопожати€ " << endl;
    if (stage > 4) cout << " рукопожатий " << endl;

    for (int i = 0; i < vertexCount; i++) {
        for (int j = i + 1; j < vertexCount; j++)
        {
            if (weights[i][j] <= stage)

                cout << names[i] << " - " << names[j] << "      " << weights[i][j] << endl;
        }
    }
}
