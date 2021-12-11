#include <bits/stdc++.h>
using namespace std;
#define long long long int
const long MOD = 1e9 + 7;
const int operation_1 = 1;
const int operation_2 = 2;
void solve(vector<pair<int, long>> array)
{
    long cumulative_xor = 0;
    long sum = 0;
    vector<pair<int, long>>::reverse_iterator it = array.rbegin();
    while (it != array.rend())
    {
        if (it->first == operation_1)
        {
            sum += cumulative_xor ^ it->second;
        }
        else if (it->first == operation_2)
        {
            cumulative_xor ^= it->second;
        }
        it++;
    }
    cout << sum;
}

int main()
{
    int n;
    cin >> n;
    vector<pair<int, long>> array;
    array.push_back(make_pair(1, 0));
    for (int i = 0; i < n; i++)
    {
        int temp1;
        long temp2;
        cin >> temp1 >> temp2;
        array.push_back(make_pair(temp1, temp2));
    }
    solve(array);
    return 0;
}