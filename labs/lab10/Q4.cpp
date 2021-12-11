#include <bits/stdc++.h>
#define LONG long long int
using namespace std;
int main()
{
    int n;
    cin >> n;
    unordered_map<int, int> mp;
    priority_queue<LONG, vector<LONG>, greater<LONG>> pq;
    vector<LONG> arr;
    vector<LONG> index;
    for (int i = 1; i <= n; i++)
    {
        LONG ele;
        cin >> ele;
        arr.push_back(ele);
        pq.push(ele);
    }
    while (!pq.empty())
    {
        LONG ele = pq.top();
        pq.pop();
        auto it = find(arr.begin(), arr.end(), ele);
        LONG index = it - arr.begin();
        cout << index << " ";
        arr.erase(it);
    }
    return 0;
}