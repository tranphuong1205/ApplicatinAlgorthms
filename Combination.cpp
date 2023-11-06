#include <iostream>
using namespace std;
int n, m, A[20];
void showCombination(int arr[])
{
    for (int i = 1; i <= m; i++)
    {
        cout << arr[i];
    }
    cout << endl;
}
void Try(int k)
{
    for (int i = A[k - 1] + 1; i <= n - m + k; i++)
    {
        A[k] = i;
        if (k == m)
        {
            showCombination(A);
            continue;
        }
        Try(k + 1);
    }
}
int main()
{
    cin >> n >> m;
    A[0] = 0;
    Try(1);
}