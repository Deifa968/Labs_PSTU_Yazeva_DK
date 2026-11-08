//Дан двумерный массив, найти максимальный элемент и его индексы. 
#include <iostream>
#include <clocale>
using namespace std;
int main()
{
    setlocale(LC_ALL, "RU");
    int m[3][4] = {
        {5, 46, 78, 2},
        {5, 4, 2, 1},
        {42, 68, 25, 85}
    }
    , mx = m[0][0], indi = 0, indj = 0;

    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            if (m[i][j] > mx)
            {
                mx = m[i][j];
                indi = i;
                indj = j;
            }
        }
    }
    cout << "Max: " << mx << " Положение -> Строка: " << indi << " Столбец: " << indj << endl;
    cout << "Max: " << mx << " Положение(как в матрице) -> Строка: " << indi + 1 << " Столбец: " << indj + 1 << endl;
    return 0;
}