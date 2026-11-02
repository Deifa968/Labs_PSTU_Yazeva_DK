#include <iostream>
#include <vector>
#include <random>
#include <cmath>
#include <clocale>

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    // Настройка генератора случайных чисел
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distr(-50, 49); // Диапазон чисел от -50 до 49

    // 1) Сформировать одномерный массив целых чисел
    vector<int> M;
    int initial_size = 15;

    for (int i = 0; i < initial_size; ++i) {
        M.push_back(distr(gen));
    }

    // 2) Распечатать полученный массив
    cout << "1. Исходный массив:\n";
    for (int num : M) {
        cout << num << " ";
    }
    cout << "\n\n";

    // 3) Удалить элементы, индексы которых кратны 3 (0, 3, 6, 9...)
    // Идем с конца, чтобы удаление не ломало индексы еще не проверенных элементов
    for (int i = M.size() - 1; i >= 0; --i) {
        if (i % 3 == 0) {
            M.erase(M.begin() + i);
        }
    }

    cout << "2. Массив после удаления элементов с индексами, кратными 3:\n";
    for (int num : M) {
        cout << num << " ";
    }
    cout << "\n\n";

    // 4) Добавить после каждого отрицательного элемента элемент со значением |M[I-1] + 1|
    // Также идем с конца, чтобы вставляемые элементы не сбивали обход
    for (int i = M.size() - 1; i >= 0; --i) {
        if (M[i] < 0) {
            // Если отрицательный элемент первый (i == 0), предыдущего нет — берем 0
            int prev_val = (i > 0) ? M[i - 1] : 0;
            int new_val = abs(prev_val + 1);

            // Вставляем элемент сразу после текущего отрицательного
            M.insert(M.begin() + i + 1, new_val);
        }
    }

    // 5) Распечатать полученный массив
    cout << "3. Итоговый массив после добавления элементов:\n";
    for (int num : M) {
        cout << num << " ";
    }
    cout << "\n";

    return 0;
}