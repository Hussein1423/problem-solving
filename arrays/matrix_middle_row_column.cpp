#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

/*
  Fills a 3x3 matrix with random values between 0 and 9
*/
void fillRandom(int matrix[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            matrix[i][j] = rand() % 10;
        }
    }
}

/*
  Prints a 3x3 matrix with fixed width formatting
*/
void printMatrix(int matrix[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << setw(2) << setfill('0') << matrix[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

/*
  Extracts the middle row from a square matrix with odd size
*/
void extractMiddleRow(int matrix[3][3], int result[3], int size)
{
    int middleIndex = size / 2;

    for (int j = 0; j < size; j++)
    {
        result[j] = matrix[middleIndex][j];
    }
}

/*
  Extracts the middle column from a square matrix with odd size
*/
void extractMiddleColumn(int matrix[3][3], int result[3], int size)
{
    int middleIndex = size / 2;

    for (int i = 0; i < size; i++)
    {
        result[i] = matrix[i][middleIndex];
    }
}

/*
  Prints a one-dimensional array
*/
void printArray(int arr[3])
{
    for (int i = 0; i < 3; i++)
    {
        cout << setw(2) << setfill('0') << arr[i] << "\t";
    }
    cout << endl << endl;
}

int main()
{
    srand(time(nullptr));

    int matrix[3][3];
    int middle[3];

    fillRandom(matrix);
    printMatrix(matrix);

    extractMiddleRow(matrix, middle, 3);
    printArray(middle);

    extractMiddleColumn(matrix, middle, 3);
    printArray(middle);

    return 0;
}
