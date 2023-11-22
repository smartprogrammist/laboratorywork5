#include <iostream>
#include <fstream>
using namespace std;

void CheckValidInput() {
    if (cin.fail())
        throw "Некоректнi введеннi даннi";
}
void CheckValidParams(double n) {
    if (n < 1)
        throw - 1;
}
void CheckValidParams(double a, double b, double h) {
    if (b > a && h < 0)
        throw - 2;
    else if (a > b && h > 0)
        throw - 3;
}

int main() {
    setlocale(LC_ALL, "Ukrainian");
    int n, i, j;
    double a, b, h;
    try {
        cout << "Введiть змiнну a" << endl;
        cin >> a;
        CheckValidInput();
        cout << "Введiть змiнну b" << endl;
        cin >> b;
        CheckValidInput();
        cout << "Введiть змiнну h" << endl;
        cin >> h;
        CheckValidParams(a, b, h);
        CheckValidInput();
        cout << "Введiть змiнну n" << endl;
        cin >> n;
        CheckValidInput();
        CheckValidParams(n);
        double x = a;

        if (x <= b) {
            while (x <= b) {
                if (x > b)
                    break;
                else {
                    double y = 0;
                    if (x < 0) {
                        int i = 1;
                        while (i <= n) {
                            if (i <= n) {
                                y = y + (i + x) * (i + x);
                                i++;
                            }
                        }
                    }
                    else {
                        for (i = 0; i < n; i++) {
                            double z = 1;
                            for (j = 1; j <= n; j++) {
                                if (i - j != 0)
                                    z = z * (x + i) / (i - j);
                                else
                                    cout << "Дiлення на нуль при значеннi i = j =" << i << endl;
                            }
                            y += z;
                        }
                    }
                    cout << "Результат: " << endl << "x: " << x << endl << "y: " << y << endl;
                    fstream results("results.txt", ios_base::out);
                    if (results.is_open()) {
                        results << "Результат: " << endl << "x: " << x << endl << "y: " << y << endl;
                        results.close();
                    }
                    x += h;
                }
            }
        }
        else
            cout << "Кiнцеве значення х, бiльше початкового" << endl; \
    }
    catch (int w) {
        if (w == -1)
            cout << "Помилка, n < 1" << endl;
        else if (w == -2)
            cout << "Помилка, кiнцеве значення бiльше початкового та крок менше нуля" << endl;
        else if (w == -3)
            cout << "Помилка, кiнцеве значення менше початкового та крок бiльше нуля" << endl;
    }
    catch (const char* ex) {
        cout << "Некоректнi даннi, введено не числове значення" << endl;
    }
    catch (...) {
        cout << "Некоректнi даннi" << endl;
    }
    return 0;
}
