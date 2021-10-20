#include "graph.h"
#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "");

    int nf = 0;           // номер функции
    int v1 = 0, v2 = 0;   // номера участников для добавления/удаления знакомства
    int quantity = 0;     // количество участников
    int stage;            // количество рукопожатий
    Graph g;              // класс граф знакомств
    string vName;         // имя участника

    g.addName("Anna");
    g.addName("Ivan");
    g.addName("Serg");
    g.addName("Nata");
    g.addName("Alex");
    g.addName("Stas");
    g.addName("Dina");
    g.addName("Lena");
    g.addName("Nina");

    g.addEdge(0, 1, 1);
    g.addEdge(0, 2, 1);
    g.addEdge(0, 3, 1);
    g.addEdge(2, 5, 1);
    g.addEdge(1, 4, 1);
    g.addEdge(4, 3, 1);
    g.addEdge(5, 3, 1);
    g.addEdge(4, 7, 1);
    g.addEdge(5, 8, 1);
    g.addEdge(8, 6, 1);
    g.addEdge(7, 6, 1);

    g.showList();
    g.showGraph();

    while (nf <= 6)
    {
        cout << endl << "Возможные действия: " << endl;
        cout << "1 - добавить участника " << endl;
        cout << "2 - удалить участника " << endl;
        cout << "3 - добавить знакомство " << endl;
        cout << "4 - удалить знакомство " << endl;
        cout << "5 - показать граф знакомств для числа ""рукопожатий"", не превышающих заданное " << endl;
        cout << "0 - закончить " << endl;
        cout << "Выберите номер действия: ";
        cin >> nf;

        switch (nf)
        {
        case 1:   // добавить участника       
            cout << "Введите новое (уникальное) имя: ";
            cin >> vName;
            g.addName(vName);
            g.showGraph();
            break;

        case 2: // удалить участника
            g.showList();
            cout << "Введите имя удаляемого участника: ";
            cin >> vName;
            g.delName(vName);
            break;

        case 3:  // добавить знакомство
            quantity = g.showList();
            while (v1 == v2 || v1 < 1 || v1 > quantity || v2 < 1 || v2 > quantity)
            {
                cout << "Введите через пробел номера познакомившихся участников: ";
                cin >> v1 >> v2;
            }
            g.addEdge(v1 - 1, v2 - 1, 1);
            v1 = 0;
            v2 = 0;
            g.showGraph();
            break;

        case 4: // удалить знакомство
            g.showList();
            while (v1 == v2 || v1 < 1 || v1 > quantity || v2 < 1 || v2 > quantity)
            {
                cout << "Введите через пробел номера участников, прервавших знакомство: ";
                cin >> v1 >> v2;
            }
            g.delEdge(v1 - 1, v2 - 1);
            g.showGraph();
            break;

        case 5:
            cout << endl << "Введите максимальное число ""рукопожатий"", при котором учитывается косвенное знакомство: ";
            cin >> stage;
            g.findFriends(stage);
            break;

        case 0: return 0;
        }

    }

}