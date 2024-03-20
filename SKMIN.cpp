#include <iostream>
#include <string>
using namespace std;
void rename(int k, string s)
{
    char max = s.at(0);
    int maxAddress = 0;
    string newString;
    for (int i = 1; i < k; i++)
    {
        cout << max << endl;
        if (s.at(i) > max)
        {
            max = s.at(i);
            maxAddress = i;
        }
    }
    newString = s.substr(maxAddress, s.size() - 1);
    if (maxAddress == k - 1)
    {
        cout << newString << endl;
    }
    else
    {
        newString = newString.substr(0, k - maxAddress);
        cout << newString << endl;
    }
}
int main()
{
    int k;
    string s;
    cin >> s;
    cin >> k;
    rename(k, s);
    return 0;
}