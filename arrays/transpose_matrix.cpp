#include <iostream>
using namespace std;

/*
  Fills a 3x3 matrix with ordered values starting from 1
  Example:
  1 2 3
  4 5 6
  7 8 9
*/
void insertOrderMatrix(int arr[3][3])
{
    int value = 1;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            arr[i][j] = value++;
        }
    }
}

/*
  Prints the matrix in its original form
*/
void printOrderMatrix(int arr[3][3])
{
    cout << "\nOriginal Matrix:\n";

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

/*
  Prints the transpose of the matrix without creating a new matrix
  Transpose logic:
  element at (i, j) becomes (j, i)
*/
void printTransposeMatrix(int arr[3][3])
{
    cout << "\nTranspose Matrix:\n";

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << arr[j][i] << "\t";
        }
        cout << endl;
    }
}

int main()
{
    int matrix[3][3];

    insertOrderMatrix(matrix);
    printOrderMatrix(matrix);
    printTransposeMatrix(matrix);

    return 0;
}
