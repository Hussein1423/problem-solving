#include <iostream>
#include <string>
#include <cctype>
using namespace std;

/*
  Reads a full line from the user
*/
string getString()
{
    string statement;
    cout << "Enter your string: ";
    getline(cin, statement);
    return statement;
}

/*
  Converts entire string to uppercase
*/
string toUpper(const string& str)
{
    string result = str;
    for (char& c : result)
        c = toupper(c);
    return result;
}

/*
  Converts entire string to lowercase
*/
string toLower(const string& str)
{
    string result = str;
    for (char& c : result)
        c = tolower(c);
    return result;
}

/*
  Converts first letter of each word to uppercase
*/
string capitalizeWords(const string& str)
{
    string result = str;
    bool isFirstLetter = true;
    for (char& c : result)
    {
        if (!isspace(c) && isFirstLetter)
            c = toupper(c);
        isFirstLetter = isspace(c);
    }
    return result;
}

/*
  Converts first letter of each word to lowercase
*/
string lowercaseFirstLetterWords(const string& str)
{
    string result = str;
    bool isFirstLetter = true;
    for (char& c : result)
    {
        if (!isspace(c) && isFirstLetter)
            c = tolower(c);
        isFirstLetter = isspace(c);
    }
    return result;
}

int main()
{
    string statement = getString();

    cout << "\nOriginal statement:\n" << statement << endl;
    cout << "\nAfter toUpper:\n" << toUpper(statement) << endl;
    cout << "\nAfter toLower:\n" << toLower(statement) << endl;
    cout << "\nAfter capitalizeWords:\n" << capitalizeWords(statement) << endl;
    cout << "\nAfter lowercaseFirstLetterWords:\n" << lowercaseFirstLetterWords(statement) << endl;

    return 0;
}
