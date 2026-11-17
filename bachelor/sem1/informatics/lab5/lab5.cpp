#include <iostream>
#include <iomanip>
#include <clocale>
using namespace std;

const int MAXN = 10;  // максимальное число строк
const int MAXM = 10;  // максимальное число столбцов

// ввод матрицы
void inputMatrix(int a[][MAXM], int n, int m)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
}

// вывод матрицы
void printMatrix(int a[][MAXM], int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << setw(5) << a[i][j];
        cout << endl;
    }
}

// удаление строки с номером k (нумерация с 1):
// строки ниже сдвигаются вверх, последняя строка заполняется нулями
void deleteRow(int a[][MAXM], int n, int m, int k)
{
    for (int i = k - 1; i < n - 1; i++)
        for (int j = 0; j < m; j++)
            a[i][j] = a[i + 1][j];
    for (int j = 0; j < m; j++)
        a[n - 1][j] = 0;
}

// исключение из массива строк с номерами от A до B
void deleteRange(int a[][MAXM], int n, int m, int A, int B)
{
    // после удаления строки A на её место встаёт следующая,
    // поэтому строку с номером A удаляем (B - A + 1) раз
    for (int t = 0; t < B - A + 1; t++)
        deleteRow(a, n, m, A);
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int a[MAXN][MAXM];
    int n, m, A, B;

    cout << "Введите число строк и столбцов (не более "
        << MAXN << "): ";
    cin >> n >> m;
    if (n < 1 || n > MAXN || m < 1 || m > MAXM)
    {
        cout << "Недопустимые размеры массива" << endl;
        return 1;
    }

    cout << "Введите элементы массива:" << endl;
    inputMatrix(a, n, m);

    cout << "Введите номера строк A и B (1 <= A <= B <= "
        << n << "): ";
    cin >> A >> B;
    if (A < 1 || B > n || A > B)
    {
        cout << "Недопустимые номера строк" << endl;
        return 1;
    }

    cout << "\nИсходный массив:" << endl;
    printMatrix(a, n, m);

    deleteRange(a, n, m, A, B);

    cout << "\nМассив после исключения строк с " << A
        << " по " << B << ":" << endl;
    printMatrix(a, n, m);

    return 0;
}