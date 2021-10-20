//#ifndef __GRAPH__
//#define __GRAPH__

// класс граф
#define SIZE 20
#include <iostream>
#include <string>
using namespace std;

class Graph {
public:
    Graph();

    // добавление вершины (имени участника)
    void addName(string vName);

    // удаление вершины 
    void delName(string vName);

    // добавление ребра (знакомства через одно "рукопожатие")
    void addEdge(int v1, int v2, int weight);

    // удаление ребра
    void delEdge(int v1, int v2);

    // показать граф
    void showGraph();

    // показать список участников
    int showList();

    // найти знакомства
    void findFriends(int stage);

private:
    bool edgeExists(int v1, int v2);
    bool vertexExists(string v);

    int matrix[SIZE][SIZE];  // матрица знакомств

    string names[SIZE];   // хранилище имен
    int vertexCount;      // количество участников
};
//#endif