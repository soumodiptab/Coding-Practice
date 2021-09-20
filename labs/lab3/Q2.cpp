#include<bits/stdc++.h>
using namespace std;
int min_swap(vector<int>arr)
{
    int n=arr.size();
    vector<pair<int, int>> arr_pos;
    for (int i = 0; i < n; i++)
    {
        arr_pos.push_back(make_pair(arr[i],i));
    }
    sort(arr_pos.begin(),arr_pos.end());
    vector<bool> visited(n,false);
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        if (visited[i]== true || arr_pos[i].second == i)
            continue;
        int size = 0;
        int j=i;
        while (visited[j]==false)
        {
            visited[j]=true;
            j=arr_pos[j].second;
            size++;
        }
        if (size>0)
        {
            res=res+(size-1);
        }
    }
    return res;
}
int main()
{
    vector<int> arr;
    int n,k=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int temp,k=0;
        cin>>temp;
        arr.push_back(temp);
    }
    cout<<min_swap(arr)<<endl;
    return 0;
}