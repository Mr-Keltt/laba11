#include <fstream>
#include <windows.h>
#include <iostream>
#include <string>
#include <list>
#include <iterator>

using namespace std;


string formateWord(string word)
{
    char blackList[10] = { '.', ',', '!', '?', '"', '"', ':', ':', '(', ')' };
    string res = word;


    for (int i = 0; i < res.length(); i++)
        for (int j = 0; j < 10; j++)
            if (res[i] == blackList[j]) res = res.erase(i, 1);

    if (res[0] >= 'а' && res[0] <= 'я') res[0] += 'А' - 'а';
    if (res[0] >= 'a' && res[0] <= 'z') res[0] += 'A' - 'a';

    return res;
}


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    list <string> myList;
    ifstream inputData("inputData.txt");
    string word;
    int n, i = 0;
    string prev;

    if (!inputData.good())
    {
        cerr << "Error opening file!" << std::endl;
    }
    else
    {
        while (!inputData.eof())
        {
            inputData >> word;
            word = formateWord(word);
            myList.push_back(word);
        }
    }

    myList.sort();
    int *count = new int[myList.size()];
    count[0] = 0;

    prev = myList.front();

    for (string cur : myList)
    {
        if (cur != prev)
        {
            i++;
            count[i] = 0;
            n = 0;
        }

        count[i]++;
        prev = cur;
    }

    i = 0;

    myList.unique();
    
    for (string cur : myList)
    {
        cout << count[i] << " - " << cur << endl;
        i++;
    }
}