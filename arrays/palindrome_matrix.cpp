#include <iostream>
#include <iomanip>
using namespace std;

/*
  Prints a 3x3 matrix
*/
void printMatrix(int matrix[3][3], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << setw(3) << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

/*
  Checks if each row in the matrix is a palindrome
*/
bool isPalindromeMatrix(int matrix[3][3], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols / 2; j++)
        {
            if (matrix[i][j] != matrix[i][cols - 1 - j])
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int matrix[3][3] = { {1, 1, 1}, {1, 7, 1}, {0, 0, 0} };

    cout << "Matrix:\n";
    printMatrix(matrix, 3, 3);
    cout << endl;

    if (isPalindromeMatrix(matrix, 3, 3))
        cout << "Yes: Palindrome Matrix\n";
    else
        cout << "No: Not Palindrome Matrix\n";

    return 0;
}
