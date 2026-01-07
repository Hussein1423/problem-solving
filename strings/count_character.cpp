#include <iostream>
#include <string>
#include <cctype>
using namespace std;

/*
  Reads a single character from the user
*/
char getChar()
{
    char ch;
    cout << "Enter your letter: ";
    cin >> ch;
    return ch;
}

/*
  Reads a full line from the user
*/
string getString()
{
    string st;
    cout << "Enter your statement: ";
    getline(cin >> ws, st); // يتجاهل أي مسافات/newline متبقية
    return st;
}


/*
  Counts occurrences of a character in a string
  matchCase = true  -> 'A' != 'a'
  matchCase = false -> 'A' == 'a'
*/
short countLetter(const string& st, char ch, bool matchCase = true)
{
    short counter = 0;
    for (char c : st)
    {
        if (matchCase)
        {
            if (c == ch) counter++;
        }
        else
        {
            if (tolower(c) == tolower(ch)) counter++;
        }
    }
    return counter;
}

/*
  Inverts the case of a character
*/
char invertChar(char ch)
{
    return isupper(ch) ? tolower(ch) : toupper(ch);
}

int main()
{
    string st = getString();
    char ch = getChar();

    cout << "\nIgnoring case: '" << ch << "' or '" << invertChar(ch) << "' counted: " 
         << countLetter(st, ch, false) << endl;

    cout << "Matching case: '" << ch << "' counted: " << countLetter(st, ch) << endl;

    return 0;
}
