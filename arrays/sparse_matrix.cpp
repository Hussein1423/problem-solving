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
            cout << setw(2) << matrix[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

/*
  Counts how many times 'num' appears in the matrix
*/
int countNumber(int matrix[3][3], int num)
{
    int count = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (matrix[i][j] == num)
                count++;
        }
    }
    return count;
}

/*
  Checks if a matrix is sparse:
  Returns true if number of zeros > half of total elements
*/
bool isSparseMatrix(int matrix[3][3], int rows, int cols)
{
    int totalElements = rows * cols;
    int zeroCount = countNumber(matrix, 0);
    return zeroCount > (totalElements / 2);
}

int main()
{
    int matrix[3][3] = { {0, 0, 0}, {0, 0, 2}, {2, 2, 3} };

    cout << "Matrix:\n";
    printMatrix(matrix);

    if (isSparseMatrix(matrix, 3, 3))
        cout << "Yes: it's a sparse matrix\n";
    else
        cout << "No: it's not a sparse matrix\n";

    return 0;
}
