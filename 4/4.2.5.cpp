#include <iostream>
#include <fstream>
#include <conio.h>

using namespace std;

struct Words {
    string word;
    int count = 0;
};

Words dictionary[5000];

void bubbleSort(int length_array)
{
 int temp = 0;
 string temp_word;
 bool exit = false;

 while (!exit)
 {
  exit = true;
  for (int i = 0; i < (length_array - 1); i++)
    if (dictionary[i].count < dictionary[i + 1].count)
    {
     temp = dictionary[i].count;
     dictionary[i].count = dictionary[i + 1].count;
     dictionary[i + 1].count = temp;

     temp_word = dictionary[i].word;
     dictionary[i].word = dictionary[i + 1].word;
     dictionary[i + 1].word = temp_word;

     exit = false;
    }
 }
}

int main()
{

    string text, line;
    string word[5000];
    bool repeat;
    ifstream myfile("file.txt");

    if (myfile.is_open())
    {
        while (! myfile.eof() )
        {
            getline (myfile,line);
            text += line;
        }
        myfile.close();
    }
    else cout << "Unable to open file";

    int count = 0, dictionary_count = 0;

    for (int unsigned i = 0; i < text.size(); i++)
    {
        repeat = false;
        if (text[i] == ' ' || text[i] == '!' || text[i] == ',' || text[i] == '.' || text[i] == '-')
        {
            if (text[i-1] == ' ' || text[i-1] == '!' || text[i-1] == ',' || text[i-1] == '.' || text[i-1] == '-')
                count--;
            else
            {
                for (int j = 0; j <= dictionary_count; j++)
                {
                    if (dictionary[j].word == word[count])
                    {
                        dictionary[j].count++;
                        repeat = true;
                    }
                }
                if (!repeat)
                {
                    dictionary[dictionary_count].word = word[count];
                    dictionary_count++;
                }
            }
            count++;
        }
        else
        {
            word[count] += text[i];
        }
    }

    bubbleSort(dictionary_count);

    for (int i = 0; i < 20; i++)
    {
        cout << " " << dictionary[i].word << " - " << dictionary[i].count << endl;
    }

    getch();
    return 0;
}
