#include <bits/stdc++.h>
using namespace std;
bool sort_pair(const pair<int, int> &a, const pair<int, int> &b)
{
    if (a.first < b.first)
        return true;
    else if (a.first == b.first)
        return (a.second <= b.second);
    else
        return false;
}
int find_dist(const pair<int, int> &a, const pair<int, int> &b)
{
    return (pow((a.first - b.first), 2) + pow((a.second - b.second), 2));
}
void solver(vector<pair<int, int>> arr)
{
    int dist = INT_MAX;
    for (int i = 0; i < arr.size(); i++)
    {

        for (int j = 0; j < arr.size(); j++)
        {
            if (i == j)
                continue;
            int d;
            if ((d = find_dist(arr[i], arr[j])) < dist)
                dist = d;
        }
    }
    cout << dist;
}
int solver_recur(vector<pair<int, int>> &arr)
{
    int n=arr.size();
    if(n==2)
        return find_dist()
}
int main()
{
    int n, y, x;
    vector<pair<int, int>> arr1;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int temp1, temp2;
        cin >> temp1 >> temp2;
        arr1.push_back(make_pair(temp1, temp2));
    }
    sort(arr1.begin(), arr1.end(), sort_pair);
    cout << solver_recur(arr1) << endl;
    return 0;
}