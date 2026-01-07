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
    getline(cin >> ws, st); // استخدام ws لتجاهل أي مسافات بيضاء متبقية
    return st;
}

/*
  Prints each character until a space, then starts a new line
  (less flexible, original version)
*/
void printEachWord(const string& st)
{
    for (char ch : st)
    {
        if (ch != ' ')
            cout << ch;
        else
            cout << endl;
    }
    cout << endl;
}

/*
  Prints each word in a new line using string manipulation
*/
void editPrintEachWord(string st)
{
    string delimiter = " ";
    size_t pos = 0;
    string word;

    while ((pos = st.find(delimiter)) != string::npos)
    {
        word = st.substr(0, pos);
        if (!word.empty())
            cout << word << endl;

        st.erase(0, pos + delimiter.length());
    }

    if (!st.empty())
        cout << st << endl;
}

/*
  Counts the number of words in a statement
*/
short countEachWord(string st)
{
    string delimiter = " ";
    size_t pos = 0;
    short count = 0;
    string word;

    while ((pos = st.find(delimiter)) != string::npos)
    {
        word = st.substr(0, pos);
        if (!word.empty())
            count++;

        st.erase(0, pos + delimiter.length());
    }

    if (!st.empty())
        count++;

    return count;
}

int main()
{
    string st = getString();

    cout << "\nWords in statement:" << endl;
    editPrintEachWord(st);

    cout << "\nCount of words: " << countEachWord(st) << endl;

    return 0;
}
