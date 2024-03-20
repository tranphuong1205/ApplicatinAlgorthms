// C++
#include <bits/stdc++.h>
using namespace std;
int find(string a, set<string> data)
{
    if (data.count(a) == 1)
        return 1;
    else
        return 0;
}

int store_n_search(string a, string b, set<string> data)
{
    int isexist = find(b, data);
    if (a == "find" && isexist == 1)
        return 1;
    if (a == "insert" && isexist == 0)
        return 1;
    else
        return 0;
}

int main()
{
    set<string> data;
    vector<string> action;
    vector<string> item;
    string a;
    while (a != "*")
    {
        cin >> a;
        data.insert(a);
    }
    cin >> a;
    while (a != "***")
    {
        action.push_back(a);
        cin >> a;
        item.push_back(a);
        cin >> a;
    }
    for (int i = 0; i < action.size(); i++)
    {
        cout << store_n_search(action[i], item[i], data) << "\n";
    }
}
