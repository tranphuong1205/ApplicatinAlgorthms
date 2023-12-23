// C++
// C++
#include <bits/stdc++.h>

using namespace std;
deque<string> action;
vector<string> DataBase;

int findInList(string data)
{
    auto pointer = find(DataBase.begin(), DataBase.end(), data);
    if (pointer != DataBase.end())
        return 1;
    else
        return 0;
}

int insertToList(string data)
{
    auto pointer = find(DataBase.begin(), DataBase.end(), data);
    if (pointer != DataBase.end())
        return 0;
    else
    {
        DataBase.push_back(data);
        return 1;
    }
}

void dataHandler(deque<string> &a)
{
    int result = 0;
    while (!a.empty())
    {
        string action = a.front();
        a.pop_front();
        string object = a.front();
        a.pop_front();
        if (action == "insert")
        {
            result = insertToList(object);
            cout << result;
        }
        if (action == "find")
        {
            result = findInList(object);
            cout << result;
        }
    }
}

int main()
{
    int result;
    string arrItem;
    string queItem;

    while (cin >> arrItem && arrItem != "*")
    {
        DataBase.push_back({arrItem});
    }

    while (cin >> queItem && queItem != "***")
    {
        action.push_back(queItem);
    }

    action.pop_front();

    dataHandler(action);

    return 0;
}
