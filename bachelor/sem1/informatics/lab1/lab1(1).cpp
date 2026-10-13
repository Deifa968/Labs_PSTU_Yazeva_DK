#include <iostream>
using namespace std;
int main()
{
	int a = 1000; // значение а
	float b = 0.0001; // значение b
	float r1 = (a + b) * (a + b) * (a + b); // (a + b) в кубе
	float r2 = a * a * a; // а в кубе
	float r3 = r1 - r2; // числитель
	float r4 = 3 * a * b * b + b * b * b + 3 * a * a * b; // знаменатель
	float r5 = r3 / r4; // значение выражения
	cout << r1 << endl << r2 << endl << r3 << endl << r4 << endl << r5;
	int a2 = 1000; // значение а
	double b2 = 0.0001; // значение b
	double t1 = (a2 + b2) * (a2 + b2) * (a2 + b2); // (a + b) в кубе
	double t2 = a2 * a2 * a2; // а в кубе
	double t3 = t1 - t2; // числитель
	double t4 = 3 * a2 * b2 * b2 + b2 * b2 * b2 + 3 * a2 * a2 * b2; // знаменатель
	double t5 = t3 / t4; // значение выражения
	cout << t1 << endl << t2 << endl << t3 << endl << t4 << endl << t5;
	return 0;
}
