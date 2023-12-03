#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int MaxArea = 0, row, col;
int M[100][100];
int largesRetangleArea(vector<int> &height)
{
    stack<int> stk;
    stk.push(-1);
    for (int i = 0; i < height.size(); i++)
    {
        while (stk.top() != -1 && height[stk.top()] >= height[i])
        {
            int cur_height = height[stk.top()];
            stk.pop();
            int cur_width = i - stk.top() - 1;
            MaxArea = max(MaxArea, cur_height * cur_width);
        }
        stk.push(i);
    }
    while (stk.top() != -1)
    {
        int cur_height = height[stk.top()];
        stk.pop();
        int cur_width = height.size() - stk.top() - 1;
        MaxArea = max(MaxArea, cur_height * cur_width);
    }
    return MaxArea;
}
void newMatrix(int M[100][100])
{
    for (int j = 0; j < col; j++)
    {
        for (int i = 1; i < row; i++)
        {
            M[i][j] += M[i - 1][j];
        }
    }
}
std::vector<int> maxtrixToVector(int matrix[100][100], int i)
{
    vector<int> histogram;
    for (int j = 0; j < col; j++)
    {
        histogram[j] = matrix[i][j];
    }
    return histogram;
}
int maxAreaCaculate(int matrix[100][100])
{
    newMatrix(matrix);
    for (int i = 0; i < row; i++)
    {
        vector<int> histogram = maxtrixToVector(matrix, i);
        largesRetangleArea(histogram);
    }
    return MaxArea;
}
int main()
{
    printf(" please enter size of matrix");
    cin >> row >> col;
}
