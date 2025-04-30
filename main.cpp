#include <iostream>
#include "trikutnyk.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "ukr");
    Triangle t;
    cout << "����i�� ���������� ������� A (x y): ";
    cin >> t.a.x >> t.a.y;
    cout << "����i�� ���������� ������� B (x y): ";
    cin >> t.b.x >> t.b.y;
    cout << "����i�� ���������� ������� C (x y): ";
    cin >> t.c.x >> t.c.y;

    if (isDegenerate(t)) {
        cout << "��������� ���������� (����� = 0)." << endl;
    }

    cout << "�������� ����������: " << perimeter(t) << endl;

    int method;
    cout << "����i�� ����� ���������� ����i:\n";
    cout << "1 � ������� �����\n";
    cout << "2 � ������� ������\n";
    cout << "��� ���i�: ";
    cin >> method;

    if (method == 1) {
        cout << "����� ���������� (����): " << area(t) << endl;
    }
    else if (method == 2) {
        cout << "����� ���������� (�����): " << areaHeron(t) << endl;
    }
    else {
        cout << "���i���� ���i� ������." << endl;
        return 1;
    }

    Point centr = centroid(t);
    cout << "�������: (" << centr.x << ", " << centr.y << ")" << endl;

    int n;
    cout << "��i���� ����� ������ �����i����? ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        Point p;
        cout << "����i�� ���������� ����� #" << i + 1 << " (x y): ";
        cin >> p.x >> p.y;

        if (isInside(t, p)) {
            cout << "����� ����������� ��������i ��� �� ���i ����������." << endl;
        }
        else {
            cout << "����� ���� �����������." << endl;
        }
    }

    return 0;
}