#include <iostream>
using namespace std;
const int N = 20;
int binary_string[N];
int n;
void Print(int arr[])
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
    }
    cout << endl;
}
void buildString(int k)
{

    for (int i = 0; i <= 1; i++)
    {
        binary_string[k] = i;
        if (k == n - 1)
        {
            Print(binary_string);
            continue;
        }

        buildString(k + 1);
    }
}

int main()
{
    cin >> n;
    buildString(0);
}