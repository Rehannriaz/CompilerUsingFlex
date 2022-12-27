#include <iostream>
using namespace std;
#define SIZE 5

int main()
{
    int arr[SIZE][SIZE];
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            cin >> arr[i][j];

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
            cout << arr[i][j]<<" ";

        cout << "\n";
    }
}