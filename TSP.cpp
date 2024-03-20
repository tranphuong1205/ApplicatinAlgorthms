
#include <bits/stdc++.h>
using namespace std;

int A[1000][1000];

struct Priority
{
    int first;
    int second;
};
bool check(int k, vector<int> r, vector<Priority> p)
{
    bool c = true;
    for (auto &m : p)
    {
        if (m.second != k)
        {
            continue;
        }
        else
        {
            if (find(r.begin(), r.end(), m.first) != r.end())
            {
                c = true;
            }
            else
            {
                c = false;
                break;
            }
        }
    }
    return c;
}
/*int visited(int n, int k, int temp, int A[1000][1000], vector<int> &result, vector<Priority> &prio)
{
    int sum = 0;
    int i = k;
    for (int j = 1; j <= n; j++)
    {
        if (j == i)
            continue;
        if (find(result.begin(), result.end(), j) != result.end()){
             continue;
        }

        if (!check(j, result, prio))
        {
            return -1;
        }
        if (A[i][j] < temp && check(j, result, prio))
        {
            temp = A[i][j];
            sum += A[i][j];
            result.push_back(j);
            i = j;
            if (i == k)
                break;
            continue;
        }
    }
    return sum;
}
int visited(int n, int k, int A[1000][1000], vector<int> &result, vector<Priority> &prio)
{
    int a = 0;
    int i = k;
    int temp = 10000;
    int sum = 0;
    while (a != k)
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
        result.push_back(a);
        temp = 10000;
        i = a;
        if (result.size() == n)
        {
            sum += A[a][k];
            a = k;
        }
    }
    return sum;
}*/
int visited(int n, int k, int A[1000][1000], vector<int> &result, vector<Priority> &prio)
{
    int a = 0;
    int i = k;
    int temp = 10000;
    int sum = 0;

    for (int m = 1; m < n; m++)
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

        sum += A[i][a];
        result.push_back(a);
        temp = 10000;
        i = a;

        if (result.size() == n)
        {
            sum += A[a][k];
        }
    }

    return sum;
}

int main()
{
    int B[10000];
    int a, b;
    int n, m;
    vector<int> result;
    vector<Priority> prio;

    A[0][0] = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> B[i];
    }
    for (int i = 0; i < n; i++)
    {
        a = B[i];
        for (int j = 0; j < n; j++)
        {
            b = B[j];
            cin >> A[a][b];
        }
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        Priority p;
        cin >> p.first >> p.second;
        prio.push_back(p);
    }
    result.push_back(B[0]);
    int s = visited(n, B[0], A, result, prio);
    cout << s << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << A[i][j];
        }
        cout << endl;
    }
    return 0;
}
