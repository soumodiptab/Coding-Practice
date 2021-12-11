#include <bits/stdc++.h>
using namespace std;
void solver(vector<int> A, vector<int> B, int x, int y)
{
    set<pair<int, int>> ut;
    for (int i = 0; i < A.size(); i++)
    {
        for (int j = 0; j < B.size(); j++)
        {
            if ((((A[i] ^ B[j]) & x) ^ ((A[i] ^ B[j]) & y)) == 0)
            {
                ut.insert(make_pair(i + 1, j + 1));
            }
        }
    }
    cout << ut.size() << endl;
}
int main()
{
    int test, n, y, x;
    cin >> test;
    while (test--)
    {
        vector<int> arr1;
        vector<int> arr2;
        cin >> n >> x >> y;
        for (int i = 0; i < n; i++)
        {
            int temp;
            cin >> temp;
            arr1.push_back(temp);
        }
        for (int i = 0; i < n; i++)
        {
            int temp;
            cin >> temp;
            arr2.push_back(temp);
        }
        solver(arr1, arr2, x, y);
    }
    return 0;
}