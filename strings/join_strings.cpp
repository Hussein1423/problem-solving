#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
  Joins elements of a vector into a string with a delimiter
*/
string join(const vector<string>& tk, const string& delim)
{
    string result;
    for (int i = 0; i < tk.size(); i++)
    {
        result += tk[i];
        if (i != tk.size() - 1)
            result += delim;
    }
    return result;
}

/*
  Joins elements of a fixed-size array into a string with a delimiter
*/
string join(const string arr[], int size, const string& delim)
{
    string result;
    for (int i = 0; i < size; i++)
    {
        result += arr[i];
        if (i != size - 1)
            result += delim;
    }
    return result;
}

int main()
{
    vector<string> tk = { "Hussein", "Mutaher", "Ali", "Qayed", "King" };
    string arr[5] = { "Hussein", "Mutaher", "Ali", "Qayed", "King" };

    cout << "Join With vector:" << endl;
    cout << join(tk, ",") << endl;

    cout << "\nJoin With Array:" << endl;
    cout << join(arr, 5, ",") << endl;

    return 0;
}
