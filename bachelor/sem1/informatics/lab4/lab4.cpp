#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    int M[100];
    int N;

    cout << "Введите количество элементов (1-40): ";
    cin >> N;

    if (N < 1 || N > 40)
    {
        cout << "Неверное количество элементов";
        return 0;
    }

    // Заполняем массив случайными числами
    for (int i = 0; i < N; i++)
    {
        M[i] = rand() % 21 - 10;
    }

    cout << endl;
    cout << "Исходный массив:" << endl;
    for (int i = 0; i < N; i++)
    {
        cout << M[i] << " ";
    }
    cout << endl;

    // Удаляем эл индексы которых кратны 3
    int A[100];
    int K = 0;

    for (int i = 0; i < N; i++)
    {
        if (i % 3 != 0)
        {
            A[K] = M[i];
            K++;
        }
    }

    N = K;

    // Переносим оставшиеся эл обратно в основной массив
    for (int i = 0; i < N; i++)
    {
        M[i] = A[i];
    }

    cout << endl;
    cout << "Массив после удаления элементов:" << endl;
    for (int i = 0; i < N; i++)
    {
        cout << M[i] << " ";
    }
    cout << endl;

    // Добавляем новый эл после каждого отрицательного эл
    for (int i = 0; i < N; i++)
    {
        if (M[i] < 0)
        {
            int value = abs(M[i] + 1);

            // Освобождаем место для нового элемента
            for (int j = N; j > i + 1; j--)
            {
                M[j] = M[j - 1];
            }

            M[i + 1] = value;
            N++;
            i++;
        }
    }

    cout << endl;
    cout << "Итоговый массив:" << endl;
    for (int i = 0; i < N; i++)
    {
        cout << M[i] << " ";
    }
    cout << endl;

    return 0;
}