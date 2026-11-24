#include <iostream>
#include <clocale>
#include <cstring>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    char s[256];      // исходная строка (не более 255 символов)
    char w[256];      // текущее слово
    int i = 0;        // индекс в строке s
    int k;            // длина текущего слова
    int digits;       // количество цифр в текущем слове
    bool found = false; // найдено ли хотя бы одно подходящее слово

    cout << "Введите текст (в конце поставьте точку):" << endl;
    cin.getline(s, 256);   // ввод строки (аналог Gets(s))

    cout << "Слова, содержащие ровно одну цифру:" << endl;

    // просматриваем строку до точки или до конца строки
    while (s[i] != '\0' && s[i] != '.')
    {
        if (s[i] == ' ')   // пропускаем пробелы между словами
        {
            i++;
        }
        else               // начало слова
        {
            k = 0;
            digits = 0;
            while (s[i] != '\0' && s[i] != ' ' && s[i] != '.')
            {
                if (s[i] >= '0' && s[i] <= '9')
                    digits++;      // считаем цифры в слове
                w[k] = s[i];
                k++;
                i++;
            }
            w[k] = '\0';
            if (digits == 1)       // ровно одна цифра - печатаем слово
            {
                cout << w << endl;
                found = true;
            }
        }
    }

    if (!found)
        cout << "Таких слов нет" << endl;

    return 0;
}
