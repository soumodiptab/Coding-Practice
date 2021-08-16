// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}
// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


 // } Driver Code Ends
/*  Tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

// Should return true if tree is Sum Tree, else false
class Solution
{
    public:
    
    bool isLeaf(Node *root)
    {
        if(root==NULL)
            return false;
        else if (root->left==NULL && root->right==NULL)
        {
            return true;
        }
        return false;
    }
    // This algo doesnt work for case: 1 N 2 3
    /*bool isSumTree(Node* root)
    {
        int ls,rs;
        //if is null and leaf return true as 
        if(root==NULL || isLeaf(root))
            return true;
        //first recursively split and check left and right sub tree
        //until you hit a leaf and backtrack to internal node
        if(isSumTree(root->left)&&isSumTree(root->right))
        {
            if(root->left==NULL)
                return true;
            else if(isLeaf(root->left))
                ls=root->left->data;
            else
                ls=2*(root->left->data);
            if(root->right==NULL)
                return true;
            else if(isLeaf(root->right))
                rs=root->right->data;
            else
                rs=2*(root->right->data);
            return ((ls+rs)==root->data);
        }
        return false;
    }*/
    int sum(struct Node *root)
{
    if (root == NULL)
        return 0;
    
    return sum(root->left) + root->data +
           sum(root->right);
}

// Returns 1 if sum property holds for
// the given node and both of its children 
bool isSumTree(struct Node* node)
{
    int ls, rs;

    // If node is NULL or it's a leaf
    // node then return true 
    if (node == NULL ||
       (node->left == NULL && 
        node->right == NULL))
        return true;

   // Get sum of nodes in left and
   // right subtrees 
   ls = sum(node->left);
   rs = sum(node->right);

   // If the node and both of its 
   // children satisfy the property 
   // return 1 else 0
    if ((node->data == ls + rs) &&
          isSumTree(node->left) &&
          isSumTree(node->right))
        return true;

   return false;
}
};

// { Driver Code Starts.

int main()
{

    int t;
	scanf("%d ",&t);
    while(t--)
    {
        string s;
		getline(cin,s);
        Node* root = buildTree(s);
        Solution ob;
        cout <<ob.isSumTree(root) << endl;
    }
    return 1;
}  // } Driver Code Ends