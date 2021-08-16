#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> sol;
        sort(nums.begin(),nums.end());
        int target,sum,l,r;
        for(int i=0;i<nums.size();i++)
        {
            target=0-nums[i];
            l=i+1;
            r=nums.size()-1;
            while(l<r)
            {
                sum=nums[l]+nums[r];
                if(sum<target)
                    l++;
                else if(sum>target)
                    r--;
                else
                {
                    sol.push_back({nums[i],nums[l],nums[r]});
                    break;
                }
            }
        }
        return sol;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> test_cases={
        {-1,0,1,2,-1,-4},
        {}
    };
    for(int i=0;i<test_cases.size();i++)
    {
        s.threeSum(test_cases[i]);
    }
    return 0;
}