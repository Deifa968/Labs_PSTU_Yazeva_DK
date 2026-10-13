#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    cout << "1." << ' ' << (n++ * m) << '\n';
    cout << "2." << ' ' << (n++ < m) << '\n';
    cout << "3." << ' ' << (m-- > m) << '\n';
    return 0;
}
