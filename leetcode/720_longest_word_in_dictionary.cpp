#include<bits/stdc++.h>
using namespace std;
class Solution {
    class Node
    {
        public:
        Node* child[26]={};
        bool is_end;
        Node()
        {
            is_end=false;
        }
    };
    Node *root=new Node();
    string result="";
    void insert(string key)
    {
        Node* current=root;
        for(int i=0;i<key.length();i++)
        {
            int index=key[i]-'a';
            if(current->child[index]==NULL)
            {
                current->child[index]=new Node();
            }
            current=current->child[index];
        }
        current->is_end=true;
    }
    bool search(string key)
    {
        Node* current=root;
        for(int i=0;i<key.length();i++)
        {
            int index=key[i]-'a';
            if(current->child[index]==NULL)
            {
                return false;
            }
            current=current->child[index];
        }
        return current->is_end;
    }
    bool is_empty(Node *current)
    {
        if(current==NULL)
        {
            return true;
        }
        for(int i=0;i<26;i++)
        {
            if(current->child[i]!=NULL)
            {
                return false;
            }
        }
        return true;
    }
    void solve(Node *current,string temp)
    {
        Node* current=root;
        for(int index=0;index<26;index++)
        {
            if(current->child[index]==NULL)
            {
                continue;
            }
            else if(current->child[index]->is_end==false)
            {

                return;
            }
            solve(current->child[index]);
            
        }
        return;
    }
public:
    Solution()
    {

    }
    string longestWord(vector<string>& words) {
        for(auto w:words)
        {
            insert(w);          
        }
        string res="";
        for(auto s:words)
        {
            if(solve(s) && s.size()>res.size())
            {
                res=s;
            }
        }
        return res;
    }
};
int main()
{
    Solution sol=Solution();
    vector<string>words;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        string temp;
        cin>>temp;
        words.push_back(temp);
    }
    cout<<sol.longestWord(words)<<endl;
    return 0;
}