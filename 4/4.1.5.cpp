#include <iostream>
#include <conio.h>
using namespace std;

int main()
{
    int counter = 0,count = 0,  position = 0;
    string text;
    cout << "Enter text: ";
    getline(cin, text);
    for (int unsigned i = 0; i < text.size() ;i++)
    {
        if (text[i] != ' ')
        {
            count++;
            if (count > counter)
            {
                counter = count;
                position = i - counter;
            }
        }
        else
        {
            count = 0;
        }
    }
    cout << "Longest word: ";
    for (int i = position; i <= position + counter; i++)
        cout << text[i];

    getch();
    return 0;
}
