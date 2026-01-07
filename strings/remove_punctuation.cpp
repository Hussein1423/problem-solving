#include <iostream>
#include <string>
using namespace std;

/*
  Reads a full line from the user
*/
string getString()
{
    string st;
    cout << "Enter your statement: ";
    getline(cin >> ws, st); // تجاهل أي مسافات بيضاء متبقية
    return st;
}

/*
  Removes all punctuation characters from the string
*/
string removePunctuation(const string& st)
{
    string result;
    for (char ch : st)
    {
        if (!ispunct(ch))
            result += ch;
    }
    return result;
}

int main()
{
    string st = getString();

    cout << "\nOriginal: [" << st << "]" << endl;
    cout << "Without punctuation: [" << removePunctuation(st) << "]" << endl;

    return 0;
}
