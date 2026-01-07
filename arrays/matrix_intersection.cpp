#include <iostream>
#include <iomanip>
using namespace std;

/*
  Prints a 3x3 matrix
*/
void printMatrix(int matrix[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << setw(3) << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

/*
  Checks if 'num' exists in the 3x3 matrix
*/
bool existsInMatrix(int matrix[3][3], int num)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (matrix[i][j] == num)
                return true;
        }
    }
    return false;
}

/*
  Prints all numbers that are common between two 3x3 matrices
*/
void printIntersection(int matrix1[3][3], int matrix2[3][3])
{
    cout << "Intersection elements: ";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            int num = matrix1[i][j];
            if (existsInMatrix(matrix2, num))
                cout << num << "\t";
        }
    }
    cout << "\n";
}

int main()
{
    int matrix1[3][3] = { {60, 40, 3}, {1, 1, 6}, {7, 8, 9} };
    int matrix2[3][3] = { {1, 2, 3}, {10, 20, 6}, {40, 50, 60} };

    cout << "Matrix 1:\n";
    printMatrix(matrix1);
    cout << "\nMatrix 2:\n";
    printMatrix(matrix2);
    cout << endl;

    printIntersection(matrix1, matrix2);

    return 0;
}
