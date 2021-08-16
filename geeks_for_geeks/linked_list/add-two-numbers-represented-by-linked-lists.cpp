// { Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


 // } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    struct Node* reverseList(struct Node *head)
    {
        Node* current=head;
        Node* ahead=NULL;
        Node* prev=NULL;
        while(current!=NULL){
            ahead=current->next;
            current->next=prev;
            prev=current;
            current=ahead; 
        }
        return prev;
        // code here
        // return head of reversed list
    }
    bool isNull(Node* t)
    {
        if(t==NULL)
        return true;
        return false;
    }
    struct Node* init()
    {
        struct Node *temp=(struct Node *) malloc(sizeof(struct Node));
        temp->data=0;
        temp->next=NULL;
    }
    //Function to add two numbers represented by linked list.
    /*
Testcase:
2
4 5
3
3 4 5   
    */
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        if(first==NULL && second==NULL)
            return NULL;
        first=reverseList(first);
        second=reverseList(second);
        bool carry=false;
        struct Node* t1=first;
        struct Node* t2=second;
        struct Node* head;
        struct Node* prev=NULL;
        struct Node* n1=init();
        head=n1;
        while(t1!=NULL || t2!=NULL)
        {
            if(!isNull(prev))
                n1=init();
            if(carry){
                ++(n1->data);
                carry=false;
            }
            if(!isNull(t1))
                n1->data=n1->data+t1->data;
            if(!isNull(t2))
                n1->data=n1->data+t2->data;
            if((n1->data)>9){
                carry=true;
                n1->data=n1->data-10;
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
            ++(n1->data);
            prev->next=n1;
        }
        head=reverseList(head);
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
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}
  // } Driver Code Ends