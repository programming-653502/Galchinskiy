#include <iostream>
#include <cstdlib>
#include <conio.h>

using namespace std;

struct Node       //Структура являющаяся звеном списка
 {
     int x;
     int y;
     Node *Next, *Prev;
 };

 class List   //Создаем тип данных Список
 {
     Node *Head, *Tail;
     public:
     List():Head(NULL),Tail(NULL){};
     ~List();
     void Show();
     void Add(int x, int y);
 };

List::~List() //Деструктор
 {
     while (Head)
     {
         Tail = Head->Next;
         delete Head;
         Head = Tail;
     }
 }

 void List::Add(int x, int y) //Добавляекм в список
 {
   Node *temp = new Node;
   temp->Next = NULL;
   temp->x = x;
   temp->y = y;

   if (Head != NULL)
   {
       temp->Prev = Tail;
       Tail->Next = temp;
       Tail = temp;
   }
   else
   {
       temp->Prev = NULL;
       Head = Tail = temp;
   }
 }

 void List::Show() //Вывод списка с начала
 {
     system("cls");
     Node *temp = Head;
     int i = 1;

     while (temp != NULL)
     {
	     cout << i << ". 10-е: " << temp->x << ", 8-е: " << temp->y << endl;
	     temp = temp->Next;
	     i++;
     }

     cout << "\nНажмите любую клавишу...";
     getch();
 }

List lst;

int enter_and_check(int variant) //Ввод и проверка
{
    bool exit_check = 0;
    string number;
    int num;
    do
    {
        if (variant == 1)
        {
            system("cls");
            cout << "Введите число в 10-ой системе: " << endl;
        }

        cin >> number;

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
            cout << "Ошибка ввода" << endl;
            exit_check = 1;

        } else
        {
            num = atoi(number.c_str());
            exit_check = 0;
        }
    } while(exit_check);

    return num;
}

void change_number(int number_10) //Перевод в 8-ую систему
{
    int number_8;
    char number_8_string[255];

    itoa(number_10, number_8_string, 8);
    number_8 = atoi(number_8_string);
    lst.Add(number_10, number_8);

    cout << "8-ая система: " << number_8 << endl;
    cout << "\nНажмите любую клавишу...";
    getch();
}


int main()
{
    setlocale(LC_ALL,"rus");
    do
    {
        system("cls");

        cout << "1.Перевести число" << endl;
        cout << "2.Показать список" << endl;
        cout << "3.Выход" << endl;

        int change = enter_and_check(0);

        switch (change)
        {
            case 1:
            {
                int number_10 = enter_and_check(1);
                change_number(number_10);
                break;
            }
            case 2:
            {
                lst.Show();
                break;
            }
            case 3:
            {
                exit(0);
            }
            default:
            {
                cout << "Неверный ввод!\n";
                break;
            }
        }

    } while(true);

    return 0;
}
