#include <bits/stdc++.h>
using namespace std;
#define long long long int
const long MOD = 1e9 + 7;

void solve(priority_queue<int> pq)
{
    while (!pq.empty() && pq.size() != 1)
    {
        int wood1 = pq.top();
        pq.pop();
        int wood2 = pq.top();
        pq.pop();
        int val;
        if (wood1 > wood2)
            val = wood1 - wood2;
        else
            val = wood2 - wood1;
        pq.push(val);
    }
    cout << ((pq.empty()) ? 0 : pq.top());
}
int main()
{
    int n;
    priority_queue<int> heap;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        heap.push(temp);
    }
    solve(heap);
    return 0;
}