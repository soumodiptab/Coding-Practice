#include<bits/stdc++.h>
using namespace std;
/*
Wolves of WallStreet problem from binarysearch
*/
int solve(vector<int>& prices) {
    int profit=0;
    sort(prices.begin(),prices.end());
    int i=0,j=prices.size()-1;
    while(i<j)
    {
        profit=profit-prices[i]+prices[j];
        ++i;
        --j;
    }
    return profit;
}
/*
finding kth smallest element using priority queue
*/
int kthSmallest(int a[], int l, int r, int k) {
    int c;
    //minheap
    priority_queue<int,vector<int>,greater<int>> q(a,a+r-l+1);
    for(int i=1;i<=k;i++)
    {
        c=q.top();
        q.pop();
    }
    return c;
}






int main(){
    int arr[]={5,1,2,3,4};
    cout<<kthSmallest(arr,0,4,4);
    unordered_map<char,char> m;
    m['0']='0';
    m['1']='1';
    m['6']='9';
    m['8']='8';
    m['9']='6';
    cout<<(m['2']==m['7'];
    return 0;
}