#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool comparefn(vector<int>a,vector<int> b)
{
    if(a[0]<b[0] ||(a[0]==b[0]&&a[1]<b[1]))
    {
        return true;
    }
    return false;
}
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int i=0,j=0;
        vector<vector<int>>sol;
        sort(intervals.begin(),intervals.end(),comparefn);
        while(i<intervals.size())
        {
            int first=intervals[i][0];
            int last=intervals[i][1];
            j=i+1;
            while(j<intervals.size())
            {
                if(intervals[j][0]>last)
                {
                    break;
                }
                else if(last<intervals[j][1])
                {
                    last=intervals[j][1];
                }
                j++;
            }
            i=j;
            vector<int>temp;
            temp.push_back(first);
            temp.push_back(last);
            sol.push_back(temp);
        }
        return sol;
    }
};