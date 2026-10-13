#include <iostream>
using namespace std;
int main()
{
	int a = 1000;
	float b = 0.0001;
	float r1 = (a + b) * (a + b) * (a + b);
	float r2 = a * a * a;
	float r3 = r1 - r2;
	float r4 = 3 * a * b * b + b * b * b + 3 * a * a * b;
	float r5 = r3 / r4;
	cout << r1 << endl << r2 << endl << r3 << endl << r4 << endl << r5;
	return 0;
}