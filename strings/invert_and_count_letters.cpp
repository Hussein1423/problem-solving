#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// Enum to choose which letters to count
enum CountType {
    CountCapital = 0,
    CountLower = 1,
    CountAll = 2
};

/*
  Inverts the case of a single character: A->a, b->B
*/
char invertChar(char ch)
{
    return isupper(ch) ? tolower(ch) : toupper(ch);
}

/*
  Inverts the case of all characters in a string
*/
string invertString(const string& str)
{
    string result = str;
    for (char& ch : result)
        ch = invertChar(ch);
    return result;
}

/*
  Counts letters based on the type (capital, lower, or all)
*/
short countLetters(const string& str, CountType type = CountAll)
{
    if (type == CountAll)
        return str.length();

    short counter = 0;
    for (char ch : str)
    {
        if (type == CountCapital && isupper(ch))
            counter++;
        else if (type == CountLower && islower(ch))
            counter++;
    }
    return counter;
}

int main()
{
    string statement;
    cout << "Enter your statement:\n";
    getline(cin, statement);

    cout << "\nOriginal: " << statement << endl;
    cout << "Inverted case: " << invertString(statement) << endl;

    cout << "\nLetter counts:" << endl;
    cout << "Total letters: " << countLetters(statement) << endl;
    cout << "Capital letters: " << countLetters(statement, CountCapital) << endl;
    cout << "Lowercase letters: " << countLetters(statement, CountLower) << endl;

    return 0;
}
