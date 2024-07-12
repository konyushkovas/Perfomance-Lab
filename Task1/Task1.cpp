#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    int n; // Размер массива
    int m; // Длина интервала
 
    cout << "Введите размер массива (n): ";
    cin >> n;

    cout << "Введите длину интервала (m): ";
    cin >> m;

    int i = 0;
    while (true) {
        cout << to_string(i + 1);
        i = (i + m - 1) % n;
        if (i == 0)
            break;
    }

    return 0;
}
