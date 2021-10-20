#include "graph.h"
#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "");

    int nf = 0;           // ����� �������
    int v1 = 0, v2 = 0;   // ������ ���������� ��� ����������/�������� ����������
    int quantity = 0;     // ���������� ����������
    int stage;            // ���������� �����������
    Graph g;              // ����� ���� ���������
    string vName;         // ��� ���������

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
        cout << endl << "��������� ��������: " << endl;
        cout << "1 - �������� ��������� " << endl;
        cout << "2 - ������� ��������� " << endl;
        cout << "3 - �������� ���������� " << endl;
        cout << "4 - ������� ���������� " << endl;
        cout << "5 - �������� ���� ��������� ��� ����� ""�����������"", �� ����������� �������� " << endl;
        cout << "0 - ��������� " << endl;
        cout << "�������� ����� ��������: ";
        cin >> nf;

        switch (nf)
        {
        case 1:   // �������� ���������       
            cout << "������� ����� (����������) ���: ";
            cin >> vName;
            g.addName(vName);
            g.showGraph();
            break;

        case 2: // ������� ���������
            g.showList();
            cout << "������� ��� ���������� ���������: ";
            cin >> vName;
            g.delName(vName);
            break;

        case 3:  // �������� ����������
            quantity = g.showList();
            while (v1 == v2 || v1 < 1 || v1 > quantity || v2 < 1 || v2 > quantity)
            {
                cout << "������� ����� ������ ������ ��������������� ����������: ";
                cin >> v1 >> v2;
            }
            g.addEdge(v1 - 1, v2 - 1, 1);
            v1 = 0;
            v2 = 0;
            g.showGraph();
            break;

        case 4: // ������� ����������
            g.showList();
            while (v1 == v2 || v1 < 1 || v1 > quantity || v2 < 1 || v2 > quantity)
            {
                cout << "������� ����� ������ ������ ����������, ���������� ����������: ";
                cin >> v1 >> v2;
            }
            g.delEdge(v1 - 1, v2 - 1);
            g.showGraph();
            break;

        case 5:
            cout << endl << "������� ������������ ����� ""�����������"", ��� ������� ����������� ��������� ����������: ";
            cin >> stage;
            g.findFriends(stage);
            break;

        case 0: return 0;
        }

    }

}