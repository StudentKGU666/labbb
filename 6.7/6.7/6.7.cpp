
/*
Дан файл f, компоненты которого являются целыми числами. Получить в файле g все компоненты файла f:
а) являющимися четными числами;
б) делящиеся на 3 и не делящиеся на 7;
в) являющимися точными квадратами.
*/
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    ifstream fin("f.txt");
    ofstream fout("g.txt");
    int x;
    int count_x = 0;
    setlocale(LC_ALL, "Russian");
    if (!fin.is_open()) cout << "Ошибка, файл не открыт!"; 
    else if (fin.peek() == EOF) cout << "Файл пуст!";

    while (fin >> x) 
    {
        if (x % 2 == 0 && x % 3 == 0 && x % 7 != 0 && (int(sqrt(x)) * int(sqrt(x)) == x))
        {
            fout << x << " ";
            cout << "Число " << x << " перемещено в файл g" << endl;
        }
        else if (fin.peek() == EOF) {
            cout << "Не найдены удовлетворяющие условиям значения!" << endl;
        }
    }

    fin.close();
    fout.close();

    return 0;
}
	
