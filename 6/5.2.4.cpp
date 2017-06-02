#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <conio.h>

using namespace std;

struct tree {
  int info;
  struct tree *left;
  struct tree *right;
};

struct tree *root;
int* tree_array;

int check(string number)           //Проверка на ввод
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
        return 0;
    } else
    {
        int num = atoi(number.c_str());
        return num;
    }

}

struct tree *stree(struct tree *root, struct tree *r, char info) //Заполнение дерева
{
  if(!r) {
    r = (struct tree *) malloc(sizeof(struct tree));
    if(!r) {
      cout << "Не хватает памяти\n";
      exit(0);
    }
    r->left = NULL;
    r->right = NULL;
    r->info = info;
    if(!root) return r;
    if(info < root->info) root->left = r;
    else root->right = r;
    return r;
  }

  if(info < r->info)
    stree(r, r->left, info);
  else
    stree(r, r->right, info);

  return root;
}

void inorderPrint(tree *root, int level)             //Вывод дерева
{
    if (root == NULL)
    {
       return;
    }
    inorderPrint(root->left, level++); //рекурсивный вызов левого поддерева
    for(int i = 0; i < level; i++)
        cout << "  ";
    cout << root->info << endl;
    inorderPrint(root->right, level++); //рекурсивный вызов правого поддерева

}

struct tree *search_tree(struct tree *root, int key)    //Поиск по дереву
{
    if(!root)
        return root;
    while(root->info != key)
    {
        if(key < root->info)
            root = root->left;
        else
            root = root->right;
        if(root == NULL)
            break;
    }
    return root;
}

int read_file()                  //Чтение из файла и заполнение массива
{
    string s;
    int count = 0;
    ifstream file("Numbers.txt");
    if (file.is_open())
    {
        while(getline(file, s))
        {
            int num = check(s);
            if (!num)
                continue;
            count++;
        }

        file.close();
        file.open("Numbers.txt");

        tree_array = new int[count];

        int i = 0;
        while(getline(file, s))
        {
            int num = check(s);
            if (!num)
                continue;
            tree_array[i] = num;
            i++;
        }
        file.close();
    }
    return count;
}

int main(){

    setlocale(LC_ALL,"rus");
    int count = read_file();
    string change_string;
    root = NULL;
    for (int i = 0; i < count; i++)
        root = stree(root, root, tree_array[i]);

    do
    {
        system("cls");

        cout << "1.Найти по ключу" << endl;
        cout << "2.Вывести дерево" << endl;
        cout << "3.Выход" << endl;
        cin >> change_string;
        int change = check(change_string);

        switch (change)
        {
            case 1:
            {
                system("cls");
                cout << "Введите ключ: ";
                int key;
                cin >> key;
                tree* r = search_tree(root, key);
                if (r)
                    cout << "Такой ключ существует\n";
                cout << "\nНажмите любую клавишу...";
                getch();
                break;
            }
            case 2:
            {
                system("cls");
                inorderPrint(root, 0);
                cout << "\nНажмите любую клавишу...";
                getch();
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
