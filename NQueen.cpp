#include <iostream>
using namespace std;
const int MAX = 16;
int isSafe[MAX];
bool col[MAX], Diag1[MAX], Diag2[MAX];
int n;
void printSolution(int arr[])
{
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i];
    }
    cout << endl;
}
void nQueen(int i)
{
    for (int j = 1; j <= n; j++)
    {
        if (col[j] && Diag1[i + j - 1] && Diag2[i - j + n - 1])
        {
            isSafe[i] = j;
            col[j] = false;
            Diag1[i + j - 1] = false;
            Diag2[i - j + n - 1] = false;
            if (i == n)
            {
                printSolution(isSafe);
            }
            nQueen(i + 1);
            col[j] = true;
            Diag1[i + j - 1] = Diag2[i - j + n - 1] = true;
        }
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        Diag1[i] = true;
        Diag2[i] = true;
        col[i] = true;
    }
    nQueen(1);
    return 0;
}