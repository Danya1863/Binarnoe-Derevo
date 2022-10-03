#include <conio.h>
#include <iostream>
#include <fstream>
#include "Tree.h"
#include "Functions.h"

using namespace std;
char* path = "PAPKA.txt";

void Insert(Tree& tree)
{
    system("cls");
    cout << "Enter a quantity of elements to add: ";
    ofstream fout;
    fout.open(path);
    unsigned int count = 0U;
    cin >> count;
    for (unsigned int i = 0U; i < count; ++i)
    {
        Node* temp = new Node;

        cout << endl << "Enter an english word " << i + 1 << endl;
        cin >> temp->GetEnglish();
        fout << temp->GetEnglish() << endl;
        cout << endl << "Enter a russian word " << i + 1 << endl;
        cin >> temp->GetRussian();
        fout << temp->GetRussian() << endl;
        fout << endl;
        tree.Insert(temp);
    }
    fout.close();
}

void Print(const Tree& tree)
{
    system("cls");

    tree.Print(tree.GetRoot());

    _getch();
}

void PrintMenu()
{
    char menu[] = "1. Insert node\n2. Remove node\n3. Print node\n4. Search node\n5. Exit\n";

    system("cls");

    cout << menu;
}

void Remove(Tree& tree)
{
    system("cls");
    cout << "Enter an english word to remove:" << endl;

    char buffer[15] = {};
    cin >> buffer;

    Node* node = tree.Search(tree.GetRoot(), buffer);

    tree.Remove(node);
}

void Search(const Tree& tree)
{
    system("cls");
    cout << "Enter an english word to search:" << endl;

    char buffer[15] = {};
    cin >> buffer;

    Node* node = tree.Search(tree.GetRoot(), buffer);

    if (node != nullptr)
    {
        cout << node->GetRussian();
    }
    else
    {
        cout << "Word not found" << endl;
    }

    _getch();
}