#include<bits/stdc++.h>
using namespace std;
unordered_map<int,int>ngr(vector<int>&arr)
{
    //index,nge
    unordered_map<int,int>sol;
    stack<int>s;
    for(int i=arr.size()-1;i>=0;i--)
    {
        if(s.size()==0)
            sol[arr[i]]=-1;
        else if(s.size()>0 && s.top()>arr[i])
            sol[arr[i]]=s.top();
        else if(s.size()>0 && s.top()<=arr[i])
        {
            while(s.size()>0 && s.top()<=arr[i])
            {
                s.pop();
            }
            if(s.size()==0)
                sol[arr[i]]=-1;
            else
                sol[arr[i]]=s.top();
        }
        s.push(arr[i]);
    }
    return sol;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    //ngr
    int n,temp;
    vector<int>super,sub;
    cin>>n;
    while(n--)
    {
        cin>>temp;
        super.push_back(temp);
    }
    cin>>n;
    while(n--)
    {
        cin>>temp;
        sub.push_back(temp);
    }
    unordered_map<int,int>ans=ngr(super);
    for(int i=0;i<sub.size();i++)
        cout<<ans[sub[i]]<<" ";
    return 0;
}
