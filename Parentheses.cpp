// C++
#include <bits/stdc++.h>
using namespace std;
int compare(char a, char b)
{
    if (a == '(' && b == ')')
    {
        return 1;
    }
    if (a == '[' && b == ']')
    {
        return 1;
    }
    if (a == '{' && b == '}')
    {
        return 1;
    }
    return 0;
}
int main()
{
    stack<char> OpenData;
    vector<char> Data;
    char input;
    char open;
    char close;
    int result = 0;
    while (cin >> input)
    {
        Data.push_back(input);
    }
    for (int i = 0; i < Data.size(); i++)
    {
        if (Data.at(i) == '(' || Data.at(i) == '[' || Data.at(i) == '{')
        {
            OpenData.push(Data.at(i));
        }
        else
        {
            if (OpenData.empty())
            {
                result = 0;
                break;
            }
            close = Data.at(i);
            open = OpenData.top();
            OpenData.pop();
            result = compare(open, close);
            if (result == 0)
            {
                break;
            }
        }
    }
    if (!OpenData.empty())
        result = 0;
    cout << result;
    return 0;
}
