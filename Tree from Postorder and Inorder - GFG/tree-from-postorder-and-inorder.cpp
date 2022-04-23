// { Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}

Node* buildTree(int in[], int post[], int n);

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Node* root = buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends


/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

void createmap(int in[],map<int,int> &nodetoindex,int n)
{
    for(int i=0;i<n;i++)
    {
        nodetoindex[in[i]] = i;
    }
}

Node* solve(int in[],int post[],int &index,int start,int end,int size,map<int,int> &nodetoindex)
{
    //base case
    if(start>end)
        return NULL;
    if(index<0)
        return NULL;
        
    int curr = post[index];
    index--;
    Node* newnode = new Node(curr);
    
    int pos = nodetoindex[curr];
    
    //right call first, then left call
    newnode->right = solve(in,post,index,pos+1,end,size,nodetoindex);
    newnode->left = solve(in,post,index,start,pos-1,size,nodetoindex);
    
    
    return newnode;
}


//Function to return a tree created from postorder and inoreder traversals.
Node *buildTree(int in[], int post[], int n) {
    int index= n-1;
    
    map<int,int> nodetoindex;
    createmap(in,nodetoindex,n);
    
    Node* ans = solve(in,post,index,0,n-1,n,nodetoindex);
    return ans;
}
