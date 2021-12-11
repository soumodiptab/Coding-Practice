#include <bits/stdc++.h>
using namespace std;
vector<int> solver(vector<int> arr, int x)
{
    for (int i = 0; i < arr.size(); i += 2)
    {
        arr[i] = arr[i] ^ x;
    }
    return arr;
}
int main()
{
    int n, k, x;
    cin >> n >> k >> x;
    vector<int> arr;
    vector<int> temp;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
    sort(arr.begin(), arr.end());
    for (int i = 1; i <= k; i++)
    {
        temp = solver(arr, x);
        sort(temp.begin(), temp.end());
        bool flag = true;
        for (int i = 0; i < arr.size(); i++)
        {
            if (temp[i] != arr[i])
            {
                flag = false;
                break;
            }
        }
        if (flag)
            break;
        arr = temp;
    }
    cout << arr[arr.size() - 1] << " " << arr[0];
}