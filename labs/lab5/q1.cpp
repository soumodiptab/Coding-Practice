#include<bits/stdc++.h>
#define ll long long int
using namespace std;
void lcs(vector<int>arr)
{
    int max_len=1;
    pair<int,int>sub;
    unordered_map<int,int>hash;
    for(int i=0;i<arr.size();i++)
    {
        hash[arr[i]]=i;
    }
    for(auto i:hash)
    {
        //first element on seq
        if(hash.find(i.first-1)==hash.end())
        {
            int j=1;
            //loop till find last consecutive
            while(hash.find(i.first+j)!=hash.end())
            {
                j++;
            }
            if(j>max_len)
            {
                max_len=j;
                sub.first=i.second;
                sub.second=hash[i.first+j-1];
            }
            else if(j==max_len && i.second<sub.first)
            {
                max_len=j;
                sub.first=i.second;
                sub.second=hash[i.first+j-1];
            }
        }
    }
    if(max_len==1)
    {
        cout<<arr[sub.first];
    }
    else
        cout<<arr[sub.first]<<" "<<arr[sub.second];
}
int main()
{
    ll t,n;
    ll temp;
        vector<int>arr;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>temp;
            arr.push_back(temp);
        }
        lcs(arr);
    return 0;
}