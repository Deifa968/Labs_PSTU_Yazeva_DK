#include <iostream>
#include <clocale>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    int sum = 0;    // сумма искомых чисел
    int count = 0;  // количество слагаемых

    // перебираем целые числа, большие 20 и меньшие 100
    for (int n = 21; n < 100; n++)
    {
        if (n % 3 == 0)  // число кратно 3
        {
            sum += n;
            count++;
        }
    }

    cout << "Сумма целых положительных чисел, больших 20, меньших 100 и кратных 3" << endl;
    cout << "Количество слагаемых: " << count << endl;
    cout << "Сумма = " << sum << endl;

    return 0;
}

