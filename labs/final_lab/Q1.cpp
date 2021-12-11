#include <bits/stdc++.h>
using namespace std;
#define long long long int
const long MOD = 1e9 + 7;

int solve(vector<long> left, vector<long> right)
{
    int max_height = 0;
    int lp = 0, rp = 0;
    while (lp < left.size() && rp < right.size())
    {
        if (left[lp] > right[rp])
            rp++;
        else
            lp++;
        max_height = max(max_height, abs(rp - lp));
    }
    return max_height;
}
int main()
{
    int n;
    cin >> n;
    vector<long> left, right;

    for (int i = 0; i < n; i++)
    {
        int temp, temp2;
        cin >> temp >> temp2;
        left.push_back(temp);
        right.push_back(temp2);
    }
    sort(left.begin(), left.end());
    sort(right.begin(), right.end());
    cout << solve(left, right);
    return 0;
}