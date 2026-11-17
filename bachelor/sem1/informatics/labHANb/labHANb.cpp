
#include <iostream>
#include <clocale>

using namespace std;

const int N = 5;
int rods[3][N];
int count_disks[3] = { 0, 0, 0 };
int moves = 0;

void show_rods()
{
    for (int i = N - 1; i >= 0; i--)
    {
        for (int t = 0; t < 3; t++)
        {
            if (i < count_disks[t])
                cout << "  [" << rods[t][i] << "]  ";
            else
                cout << "   |   ";
        }
        cout << "\n";
    }

    cout << " =====  =====  =====\n";
    cout << "  Ст.1   Ст.2   Ст.3\n\n";
}

void move_ring(int from, int to)
{
    int f = from - 1;
    int t = to - 1;

    count_disks[f]--;
    int disk = rods[f][count_disks[f]];

    rods[t][count_disks[t]] = disk;
    count_disks[t]++;

    moves++;

    cout << "Ход " << moves << ": переложить кольцо " << disk
        << " со стержня " << from << " на стержень " << to << "\n";

    show_rods();
}

void han(int count, int from, int to, int aux)
{
    if (count == 1)
    {
        move_ring(from, to);
    }
    else
    {
        han(count - 1, from, aux, to);
        move_ring(from, to);
        han(count - 1, aux, to, from);
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");

    for (int i = 0; i < N; i++)
        rods[0][i] = N - i;

    count_disks[0] = N;

    cout << "Начальное состояние (5 колец на 1-м стержне):\n";
    show_rods();

    han(N, 1, 3, 2);

    cout << "Задача решена! Минимальное количество ходов: "
        << moves << "\n";

    return 0;
}
