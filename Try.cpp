#include <bits/stdc++.h>
using namespace std;
int visited(int n, int k, int A[1000][1000], vector<int> &result, vector<Priority> &prio)
{
    int a = 0;
    int i = k;
    int temp = 10000;
    int sum = 0;
    while (i != k)
    {
        for (int j = 1; j <= n; j++)
        {
            if (j == i)
                continue;
            if (find(result.begin(), result.end(), j) != result.end())
            {
                continue;
            }

            if (!check(j, result, prio))
            {
                return -1;
            }
            if (A[i][j] < temp && check(j, result, prio))
            {
                temp = A[i][j];
                a = j;
            }
        }
        sum += temp;
        result.push_back(j);
        temp = 10000;
        i = a;
        if (result.size() == n)
        {
            sum += A[a][k];
            a = k;
        }
    }
    return sum;
}
int main()
{
    int m;
    cin >> m;
    cout << m;
    return 0;
}