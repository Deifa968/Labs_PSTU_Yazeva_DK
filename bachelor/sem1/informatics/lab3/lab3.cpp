#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    double a = 0.1; // начало диапазона
    double b = 0.8; // конец диапазона
    double h = (b - a) / 10; // шаг
    double toch = 0.0001; // точность
    int n = 10; // количество членов ряда

    cout << fixed << setprecision(6);
    cout << "X\tSumN\t\tSumToch\t\tY" << endl;

    for (double x = a; x <= b + 0.000001; x = x + h)
    {
        double SumN = 0;

        for (int i = 1; i <= n; i++)
        {
            double ChlenN = pow(-1, i + 1) * pow(x, 2 * i) / (2 * i * (2 * i - 1));
            SumN = SumN + ChlenN;
        }

        double SumToch = 0;
        int i = 1;
        double ChlenN = x * x / 2;

        while (fabs(ChlenN) >= toch)
        {
            SumToch = SumToch + ChlenN;
            i++;
            ChlenN = pow(-1, i + 1) * pow(x, 2 * i) / (2 * i * (2 * i - 1));
        }

        double y = x * atan(x) - 0.5 * log(1 + x * x);

        cout << x << "\t" << SumN << "\t" << SumToch
            << "\t" << y << endl;
    }

    return 0;
}