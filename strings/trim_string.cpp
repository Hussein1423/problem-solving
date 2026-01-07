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
  Removes leading spaces
*/
string trimLeft(const string& st)
{
    for (int i = 0; i < st.length(); i++)
    {
        if (st[i] != ' ')
            return st.substr(i);
    }
    return "";
}

/*
  Removes trailing spaces
*/
string trimRight(const string& st)
{
    for (int i = st.length() - 1; i >= 0; i--)
    {
        if (st[i] != ' ')
            return st.substr(0, i + 1);
    }
    return "";
}

/*
  Removes spaces from both ends
*/
string trim(const string& st)
{
    return trimLeft(trimRight(st));
}

int main()
{
    string st = getString();

    cout << "\nOriginal: [" << st << "]" << endl;
    cout << "Trim Left: [" << trimLeft(st) << "]" << endl;
    cout << "Trim Right: [" << trimRight(st) << "]" << endl;
    cout << "Trim Both: [" << trim(st) << "]" << endl;

    return 0;
}
