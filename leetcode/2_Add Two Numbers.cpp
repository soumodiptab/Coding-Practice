// { Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

struct ListNode* buildList(int size)
{
    int val;
    cin>> val;
    
    ListNode* head = new ListNode(val);
    ListNode* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new ListNode(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(ListNode* n)
{
    while(n)
    {
        cout<< n->val << " ";
        n = n->next;
    }
    cout<< endl;
}


 // } Driver Code Ends
/* ListNode for linked list:

struct ListNode {
    int val;
    struct ListNode* next;
    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    bool isNull(ListNode* t)
    {
        if(t==NULL)
        return true;
        return false;
    }
    ListNode* init()
    {
        ListNode *temp=new ListNode;
        temp->val=0;
        temp->next=NULL;
        return temp;
    }
    ListNode* addTwoNumbers(ListNode* first,ListNode* second)
    {
        if(first==NULL && second==NULL)
            return NULL;
        bool carry=false;
        ListNode* t1=first;
        ListNode* t2=second;
        ListNode* head;
        ListNode* prev=NULL;
        ListNode* n1=init();
        head=n1;
        while(t1!=NULL || t2!=NULL)
        {
            if(!isNull(prev))
                n1=init();
            if(carry){
                ++(n1->val);
                carry=false;
            }
            if(!isNull(t1))
                n1->val=n1->val+t1->val;
            if(!isNull(t2))
                n1->val=n1->val+t2->val;
            if((n1->val)>9){
                carry=true;
                n1->val=n1->val-10;
            }
            if(!isNull(prev))
                prev->next=n1;
            prev=n1;
            if(!isNull(t1))
                t1=t1->next;
            if(!isNull(t2))
                t2=t2->next;
        }
        if(carry)
        {
            n1=init();
            ++(n1->val);
            prev->next=n1;
        }
        return head;
    }
    
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        ListNode* first = buildList(n);
        
        cin>>m;
        ListNode* second = buildList(m);
        Solution ob;
        ListNode* res = ob.addTwoNumbers(first,second);
        printList(res);
    }
    return 0;
}
  // } Driver Code Ends