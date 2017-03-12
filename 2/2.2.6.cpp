#include <iostream>
#include <cmath>
#include <conio.h>
#include <cstdlib>

using namespace std;

double checkfunc(char number[])
{
    int check = 0;
    for (int i = 0; number[i] != '\0'; i++)
    {
        if (number[i] < '0' || number[i] > '9')
        {
            if (number[i] != ',')
            {
                check++;
            }
        }
    }
     if (check)
    {
       cout << " Неверный ввод!\n";
       return 0;
    } else
    {
       double num = atof(number);
       return num;
    }
}

int factor(int n)
{
	int fact=1;
	for (int i = 2; i <= n; i++)
	{
		fact *= i;
	}
	return fact;
}

double iteration(double x, int n)
{
	double res = 0;
	for (int i = 1; i <= n; i++)
	{
		 res += pow((-1), i - 1) * pow(x, 2 * i - 1) / factor(2 * i - 1);
	}
	return res;
}

int main()
{
	setlocale(LC_ALL, "rus");
	long double left, right=0;
	double x,e;
	char x_check[255], e_check[255];

    first:
    cout << endl << "Введите x: ";
	cin >> x_check;
	if (checkfunc(x_check) == 0)
    {
        goto first;
    }
	x = checkfunc(x_check);

    second:
    cout << "Введите e: ";
    cin >> e_check;
	if (checkfunc(e_check) == 0)
    {
        cout << endl << "Неверный ввод (е>0)" << endl;
        goto second;
    }
	e = checkfunc(e_check);

	left = sin(x);
	for (int i = 1; i < 1000; i++)
	{
		right = iteration(x, i);
		if (abs(left - right) < e)
		{
		    cout << "-----------------------------------------" << endl;
			cout << "Сходится при x = " << x << ", когда n = " << i << endl;
			break;
		}
	}

	cout << "Левая часть : " << left << endl;
	cout << "Правая часть : " << right << endl;

	getch();
    return 0;
}
