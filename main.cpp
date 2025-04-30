#include <iostream>
#include "trikutnyk.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "ukr");
    Triangle t;
    cout << "Введiть координати вершини A (x y): ";
    cin >> t.a.x >> t.a.y;
    cout << "Введiть координати вершини B (x y): ";
    cin >> t.b.x >> t.b.y;
    cout << "Введiть координати вершини C (x y): ";
    cin >> t.c.x >> t.c.y;

    if (isDegenerate(t)) {
        cout << "Трикутник вироджений (площа = 0)." << endl;
    }

    cout << "Периметр трикутника: " << perimeter(t) << endl;

    int method;
    cout << "Оберiть метод обчислення площi:\n";
    cout << "1 — Формула Гауса\n";
    cout << "2 — Формула Герона\n";
    cout << "Ваш вибiр: ";
    cin >> method;

    if (method == 1) {
        cout << "Площа трикутника (Гаус): " << area(t) << endl;
    }
    else if (method == 2) {
        cout << "Площа трикутника (Герон): " << areaHeron(t) << endl;
    }
    else {
        cout << "Невiрний вибiр методу." << endl;
        return 1;
    }

    Point centr = centroid(t);
    cout << "Центроїд: (" << centr.x << ", " << centr.y << ")" << endl;

    int n;
    cout << "Скiльки точок бажаєте перевiрити? ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        Point p;
        cout << "Введiть координати точки #" << i + 1 << " (x y): ";
        cin >> p.x >> p.y;

        if (isInside(t, p)) {
            cout << "Точка знаходиться всерединi або на межi трикутника." << endl;
        }
        else {
            cout << "Точка поза трикутником." << endl;
        }
    }

    return 0;
}