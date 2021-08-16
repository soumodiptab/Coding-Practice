#include <bits/stdc++.h>
using namespace std;
class Tree {
     public:
         int val;
        Tree *left;
       Tree *right;
 };
 class LLNode {
      public:
         int val;
        LLNode *next;
 };
LLNode* solve(Tree* root) {
    LLNode* head = new LLNode();
    head->next = NULL;
    vector<int> solved;
    queue<Tree*> q;
    q.push(root);
    while (q.empty() == false) {
        solved.push_back(q.front()->val);
        if (q.front()->left != NULL) q.push((q.front())->left);
        if (q.front()->right != NULL) q.push((q.front())->right);
        q.pop();
    }
    vector<int>::iterator i = solved.begin();
    head->val = *i;
    LLNode* prev = head;
    LLNode* cur;
    i++;
    for (; i != solved.end(); i++) {
        cur = new LLNode();
        cur->val = *i;
        prev->next = cur;
        prev = cur;
    }
    cur->next = NULL;
    return head;
}
int main()
{
    vector<string> msg {"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};
    for (const string& word : msg)
    {
        cout << word << " ";
    }
    cout << endl;
}