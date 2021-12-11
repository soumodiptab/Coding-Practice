#include <bits/stdc++.h>
using namespace std;
vector<long> dp_x;
vector<long> dp_y;
const long mod = 1e9 + 7;
long modu(long x)
{
    if (x < 0)
    {
        return ((x % mod) + mod) % mod;
    }
    else
        return x % mod;
}
int main()
{
    long x, y, n;
    cin >> x >> y >> n;
    long new_x, new_y;
    for (int i = 1; i <= n; i++)
    {
        new_x = modu(y - modu(2 * x));
        new_y = modu(modu(2 * y) + x);
        if (x == new_x && y == new_y)
            break;
        x = new_x;
        y = new_y;
    }
    cout << x << " " << y;
    return 0;
}