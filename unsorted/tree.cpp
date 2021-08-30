#include<bits/stdc++.h>
using namespace std;
  class Tree {
      public:
          int val;
          Tree *left;
          Tree *right;
  };

vector<int> solve(Tree* root) {
    queue<pair<int,Tree*>>q;
    vector<int>sol;
    if(root!=NULL)
        q.push(make_pair(1,root));
    int curLevel=1;
    while(!q.empty())
    {
        pair<int,Tree*>temp=q.front();
        sol.push_back(temp.second->val);
        q.pop();
        if(temp.first ==1)
        {
            if(temp.second->right)
            q.push(make_pair(1+curLevel,temp.second->right));
            if(temp.second->right)
            q.push(make_pair(1+curLevel,temp.second->left));
        }
        else
        {
            if(temp.second->right)
            q.push(make_pair(1+curLevel,temp.second->left));
            if(temp.second->right)
            q.push(make_pair(1+curLevel,temp.second->right));  
        }
    }
    return sol;
}