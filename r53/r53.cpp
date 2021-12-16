#include<iostream>
#include <locale>
#include <fstream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Rus");
    int choice = 0;
    while (choice == 0) {
        int n, m;
        int k = 0;
        int f = 0;
        cout << " Выберите действие:\n 1 - File\n 2 - Random\n 3 - Exit\n Your choiсe = ";
        cin >> choice;
        if (choice == 1) {
            ifstream file("Текст.txt");
            n = 3;
            m = 3;
            int** a = new int* [n];
            int* b = new int[n];
            int* c = new int[n];
            if (!file) {
                return 1;
            }
            else {
                for (int i = 0; i < n; i++) // цикл заполнения матрицы
                {
                    a[i] = new int[m];
                    for (int j = 0; j < m; j++)
                    {
                        file >> a[i][j];
                    }
                }
            }
            int* maxx = new int[n];
            int* minn = new int[n];
            for (int i = 0; i < n; i++) // проверка 1
            {
                minn[i] = a[i][0];
                maxx[i] = a[0][i];
                for (int j = 0; j < m; j++) {
                    if (a[i][j] < minn[i]) { // проверка на минимальное число в строке
                        minn[i] = a[i][j];
                    }
                }
                for (int j = 0; j < m; j++) {
                    if (a[j][i] > maxx[i]) { // проверка на максимальное число в столбце
                        maxx[i] = a[j][i];
                    }
                }
            }
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (minn[i] == maxx[j]) {
                        b[k] = minn[i];
                        k++;
                    }
                }
            }
            int* max = new int[n];
            int* min = new int[n];
            for (int i = 0; i < n; i++) // проверка наоборот
            {
                min[i] = a[0][i];
                max[i] = a[i][0];
                for (int j = 0; j < m; j++) {
                    if (a[j][i] < min[i]) { // проверка на минимальное число в столбце
                        min[i] = a[j][i];
                    }
                    if (a[i][j] > max[i]) { // проверка на максимальное число в строке
                        max[i] = a[i][j];
                    }
                }
            }
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (min[i] == max[j]) {
                        c[f] = min[i];
                        f++;
                    }
                }
            }
            cout << "Введенный массив:" << endl;
            for (int i = 0; i < n; i++) // вывод матрицы
            {
                for (int j = 0; j < m; j++)
                    cout << a[i][j] << " ";
                cout << endl;
            }
            if (k != 0 || f != 0) {
                cout << "\n Седловые точки : ";
                for (int i = 0; i < k; i++) {
                    cout << b[i] << " ";
                }
                for (int i = 0; i < f; i++) {
                    cout << c[i] << " ";
                }
                cout << endl;
            }
            else {
                cout << "\n Седловых точек не найдено.\n";
            }
            delete[] b;
            delete[] c;
            for (int i = 0; i < n; i++)
            {
                delete[]a[i];
            }
            system("pause");
            choice = 0;
        }
        if (choice == 2) {
            cout << " Введите размер матрицы: ";
            cin >> n;
            cin >> m;
            int** a = new int* [n];
            int* b = new int[n];
            int* c = new int[n];
            for (int i = 0; i < n; i++) // цикл заполнения матрицы
            {
                a[i] = new int[m];
                for (int j = 0; j < m; j++)
                {
                    a[i][j] = 10 + rand() % 20; // заполнения рандомом
                }
            }
            int* maxx = new int[n];
            int* minn = new int[n];
            for (int i = 0; i < n; i++) // проверка 1
            {
                minn[i] = a[i][0];
                maxx[i] = a[0][i];
                for (int j = 0; j < m; j++) {
                    if (a[i][j] < minn[i]) { // проверка на минимальное число в строке
                        minn[i] = a[i][j];
                    }
                }
                for (int j = 0; j < m; j++) {
                    if (a[j][i] > maxx[i]) { // проверка на максимальное число в столбце
                        maxx[i] = a[j][i];
                    }
                }
            }
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (minn[i] == maxx[j]) {
                        b[k] = minn[i];
                        k++;
                    }
                }
            }
            int* max = new int[n];
            int* min = new int[n];
            for (int i = 0; i < n; i++) // проверка наоборот
            {
                min[i] = a[0][i];
                max[i] = a[i][0];
                for (int j = 0; j < m; j++) {
                    if (a[j][i] < min[i]) { // проверка на минимальное число в столбце
                        min[i] = a[j][i];
                    }
                    if (a[i][j] > max[i]) { // проверка на максимальное число в строке
                        max[i] = a[i][j];
                    }
                }
            }
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (min[i] == max[j]) {
                        c[f] = min[i];
                        f++;
                    }
                }
            }
            cout << "Введенный массив:" << endl;
            for (int i = 0; i < n; i++) // вывод матрицы
            {
                for (int j = 0; j < m; j++)
                    cout << a[i][j] << " ";
                cout << endl;
            }
            if (k != 0 || f != 0) {
                cout << "\n Седловые точки : ";
                for (int i = 0; i < k; i++) {
                    cout << b[i] << " ";
                }
                for (int i = 0; i < f; i++) {
                    cout << c[i] << " ";
                }
                cout << endl;
            }
            else {
                cout << "\n Седловых точек не найдено.\n";
            }
            delete[] b;
            delete[] c;
            for (int i = 0; i < n; i++)
            {
                delete[]a[i];
            }
            system("pause");
            choice = 0;
        }
        if (choice == 3) {
            return 0;
        }
    }
}