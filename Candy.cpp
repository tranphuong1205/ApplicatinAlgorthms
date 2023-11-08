#include <iostream>
using namespace std;
int m, n, f, m_0, solution[20];
void showSolution(int arr[])
{
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i];
    }
    cout << endl;
}
void Try(int k)
{
    if (k == n)
    {
        solution[k] = m - f;
        showSolution(solution);
        return;
    }
    m_0 = m - f - (n - k);
    for (int i = 1; i <= m_0; ++i)
    {
        solution[k] = i;
        f = f + i;
        Try(k + 1);
        f = f - i;
    }
}
int main()
{
    cin >> n >> m;
    f = 0;
    solution[0] = 0;
    Try(1);
}
