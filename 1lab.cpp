#include <iostream>
#include <conio.h>
#include <cstdlib>
using namespace std;

int main()
{
    int num1, num2, num3, check;
    string num_1, num_2, num_3;
    char number[100];
    do
    {
        check = 0;
        cout << " Enter number: ";
        cin >> number;
        for (int i = 0; number[i] != '\0'; i++)
        {
		      if (number[i] < '0' || number[i] > '9' /*|| number[i] != '.'*/ ){
                    if (number[i] != '.'){
                        check++;
                    }
		      }

        }
        if (check)
            cout << " Wrong number!\n";
    }while (check);

    for (int i = 0; number[i] != '\0'; i++)
    {
        if(number[i] == '.') {
            num_1 = number[i+1];
            num_2 = number[i+2];
            num_3 = number[i+3];
            break;
        }
    }
    num1 = atoi(num_1.c_str());
    num2 = atoi(num_2.c_str());
    num3 = atoi(num_3.c_str());
    cout << "Sum = " << num1 + num2 + num3;
    getch();
    return 0;
}
