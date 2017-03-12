#include <iostream>
#include <conio.h>
#include <cstdlib>

using namespace std;

double checkfunc(string number)
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
        double num = atof(number.c_str());
        return num;
    }
}

int checkfunc2(string number)
{
    int check = 0;
    for (int i = 0; number[i] != '\0'; i++)
    {
        if (number[i] < '0' || number[i] > '9')
        {
            check++;
        }
    }
    if (check)
    {
        return 10;
    } else
    {
        int num = atoi(number.c_str());
        return num;
    }

}

void options(double way, double weight)
{
    double price, totalprice, insurance;

    int cars = weight / 20;
    int weight2 = weight;
    if (weight2 % 20 != 0)
    {
        cars++;
    }

    cout << "Для перевозки вашего груза нужно " << cars << " грузовых машин" << endl;

    price = cars * way * 2;
    insurance = price * 0.05;
    totalprice = price + insurance;

    cout << "Страховка: " << insurance << "$" << endl;
    cout << "Общая стоимость: " << totalprice << "$" << "\n--------------------------------------" << endl;
}

void order()
{
    string weight_check, way_check;
    double weight, way;

    do
    {
        cout << "--------------------------------------\nВведите вес груза (тонн): ";
        cin >> weight_check;
        weight = checkfunc(weight_check);
    } while (weight == 0);

    do
    {
        cout << "Введите расстояние перевозки (км): ";
        cin >> way_check;
        way = checkfunc(way_check);
    } while (way == 0);

    if (weight < 50 || weight > 300 || way > 4000)
    {
        cout << "Извините, но мы принимаем заказы 50-300 тонн и до 4000 км\n--------------------------------------\n";
        return;
    } else
    cout << "--------------------------------------\nВаш заказ принят\n--------------------------------------" << endl;
    options(way, weight);
}

int main()
{
    setlocale(LC_ALL, "rus");
    int switcher, exit = 0;
    string switcher_check;

    cout << "\t\tEurotrans Group \n--------------------------------------\n";
    cout << "Здравствуйте, вас приветсвует компания грузоперевозок" << endl;

    do
    {
        cout << "Выберите, что вам нужно:" << endl;
        cout << "1. Заказ грузоперевозок\n2. Автор и версия программы\n3. Выход" << endl;
        cin >> switcher_check;
        switcher = checkfunc2(switcher_check);
        switch(switcher)
        {
            case 1:
            {
                order();
                break;
            }
            case 2:
            {
                cout << "==================\nAuthor: Станислав Гальчинский \nVersion: 1.0 \n==================\n";
                break;
            }
            case 3:
            {
                exit = 1;
                break;
            }
            default:
            {
                cout << "Неверный ввод!\n--------------------------------------\n";
                break;
            }
        }
    } while(exit == 0);
    getch();
    return 0;
}
