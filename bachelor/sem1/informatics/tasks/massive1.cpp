/* Дан одномерный массив. За один проход нужно найти:
1) максимальный и минимальный элементы(max и min);
2) индекс (и номер) первого встретившегося максимума и минимума;
3) сколько элементов равны максимуму и сколько — минимуму, если таких несколько, вывести количество.*/
#include <iostream>
using namespace std;
int main()
{
    int m[15] = { 90,30,35,3,1,66,35,90,56,47,49,50,1,78,90 };
    int max = m[0], min = m[0], indmx = 0, indmn = 0, nmx = 1, nmn = 1;
    for (int i = 0;i < 16;i++)
    {
        if (m[i] > max)
        {
            max = m[i];
            indmx = i;
            nmx = 1;
        }
        else if (m[i] < min)
        {
            min = m[i];
            indmn = i;
            nmn = 1;
        }
        else if (m[i] == max) nmx++;
        else if (m[i] == min) nmn++;
    }
    cout << "max: " << max << " index: " << indmx << " number: " << indmx + 1 << endl;
    cout << "min: " << min << " index: " << indmn << " number: " << indmn + 1 << endl;
    if (nmx > 1) cout << "same max: " << nmx << endl;
    if (nmn > 1) cout << "same min: " << nmn << endl;
    return 0;
}