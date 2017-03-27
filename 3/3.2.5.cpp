#include <iostream>
#include <conio.h>
#include <cstdlib>

using namespace std;

bool danger(int** chess, int x, int y)
{
    bool boolvalue = false;
    for (int i = 0; i < 8; i++)
    {
        if (chess[i][y] == 1 || chess[x][i] == 1)
            boolvalue = true;
    }

    int line = 0, column = 0;
    if (x >= y)
        {
             line = 7;
            column = 7 - (x - y);
        }
    else
        {
             column = 7;
             line = 7 - (y - x);
        }
    while (line >=0 && column >= 0)
    {
        if (chess[line][column] == 1)
        {
            boolvalue = true;
        }
        line--;
        column--;
    }

    line = x;
    column = y;

    while (line >=0 && column >= 0)
    {
        if (line == 0 || column == 0 || line == 7 || column == 7)
            break;
        line++;
        column--;

    }
    while (line >=0 && column >= 0)
    {
        if (chess[line][column] == 1)
        {
            boolvalue = true;
        }
        line--;
        column++;
    }

    return boolvalue;
}

int checkfunction(string xORy)
{
    int checkednum;
    bool exit;
    do
    {
        string number;
        cout << xORy << ": ";
        cin >> number;
        exit = false;
        for (int i = 0; number[i] != '\0'; i++)
        {
            if (number[i] < '0' || number[i] > '9')
            {
                exit = true;
                break;
            }
        }
        checkednum = atoi(number.c_str());
        if (checkednum > 7 || exit)
        {
            cout << " Неверный ввод!(от 0 до 7)\n";
            exit = true;
        }
    } while(exit);

    return checkednum;
}

int main()
{
    setlocale(LC_ALL, "rus");
    int king_x, king_y, queen1_x, queen1_y, queen2_x, queen2_y;
    int **chess = new int* [8];
    for (int i = 0; i < 8; i++)
    {
        chess[i] = new int[8];
    }

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            chess[i][j] = 0;
        }
    }
    cout << "=======КОРОЛЬ И ФЕРЗИ=======\n" << endl;

    cout << "Введите координаты короля(x,y)\n";
    king_x = checkfunction("x");
    king_y = checkfunction("y");
    chess[king_x][king_y] = 1;

    first:
    cout << "\nВведите координаты первого ферзя(x,y)\n";
    queen1_x = checkfunction("x");
    queen1_y = checkfunction("y");
    if (chess[queen1_x][queen1_y] == 1)
    {
        cout << "Эта клетка уже занята" << endl;
        goto first;
    }
    chess[queen1_x][queen1_y] = 2;

    second:
    cout << "\nВведите координаты второго ферзя(x,y)\n";
    queen2_x = checkfunction("x");
    queen2_y = checkfunction("y");
    if (chess[queen2_x][queen2_y] == 1 || chess[queen2_x][queen2_y] == 2)
    {
        cout << "Эта клетка уже занята" << endl;
        goto second;
    }
    chess[queen2_x][queen2_y] = 2;

    bool queen_1, queen_2;
    queen_1 = danger(chess, queen1_x, queen1_y);
    queen_2 = danger(chess, queen2_x, queen2_y);

    if (queen_1)
        cout << "Король под угрозой первого ферзя!" << endl;
    if (queen_2)
        cout << "Король под угрозой второго ферзя!" << endl;
    if (!queen_1 && !queen_2)
        cout << "Король в безопасности!" << endl;

    getch();
    return 0;
}
