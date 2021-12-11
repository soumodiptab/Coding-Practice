#include <bits/stdc++.h>
#define LONG long long int
using namespace std;
priority_queue<pair<long long, long long>> pq;
int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    long long n, m;
    vector<long long> v;
    vector<long long> w;
    cin >> n;
    for (long long i = 0; i < n; i++)
    {
        cin >> m;
        v.push_back(m);
        pq.push({-m, i});
        // w.push_back(m);
    }
    while (!pq.empty())
    {
        pair<long long, long long> w = pq.top();
        pq.pop();
        //sort(w.begin(),w.end());
        auto it = find(v.begin(), v.end(), -w.first);
        cout << it - v.begin() << " ";
        //w.erase(w.begin());
        v.erase(it);
    }
}