#include <bits/stdc++.h>
using namespace std;
#define long long long int
const long MOD = 1e9 + 7;

vector<long> input_array()
{
    vector<long> arr;
    int n;
    cin >> n;
    arr = vector<long>(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
    return input_array();
}
int main()
{
    return 0;
}