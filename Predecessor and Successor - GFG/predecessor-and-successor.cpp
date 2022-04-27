// { Driver Code Starts
// C++ program to find predecessor and successor in a BST
#include <iostream>
using namespace std;

// BST Node
struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    key = x;
	    left = NULL;
	    right = NULL;
	}
};

int key=0;
// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key);

 void insert(struct Node *root,int n1,int n2,char lr)
 {
     if(root==NULL)
        return;
     if(root->key==n1)
     {
         switch(lr)
         {
          case 'L': root->left=new Node(n2);
                    break;
          case 'R': root->right=new Node(n2);
                    break;
         }
     }
     else
     {
         insert(root->left,n1,n2,lr);
         insert(root->right,n1,n2,lr);
     }
 }
// Driver program to test above functions
int main()
{
    /* Let us construct the tree shown in above diagram */
    int t,k;
    cin>>t;
    while(t--)
    {
    int n;
    cin>>n;
    struct Node *root=NULL;
    Node *pre=NULL;
    Node *suc=NULL;
    while(n--)
    {
        char lr;
        int n1,n2;
        cin>>n1>>n2;
        cin>>lr;
        if(root==NULL)
        {
            root=new Node(n1);
            switch(lr){
                    case 'L': root->left=new Node(n2);
                    break;
                    case 'R': root->right=new Node(n2);
                    break;
                    }
        }
        else
        {
            insert(root,n1,n2,lr);
        }
    }
   // Inorder(root);
    //Node * target =ptr;
    //printkdistanceNode(root, target, k);
    //cout<<endl;
    cin>>key;
    findPreSuc(root, pre, suc, key);
	if (pre != NULL)
	cout << pre->key;
	else
	cout << "-1";

	if (suc != NULL)
	cout <<" "<<suc->key<<endl;
	else
	cout << " "<<"-1"<<endl;
    }
	return 0;
}// } Driver Code Ends


/* BST Node
struct Node
{
	int key;
	struct Node *left, *right;
};
*/

Node* predecessor(Node* root)
{
    Node* temp = root->left;
    while(temp->right)
        temp = temp->right;
    return temp;
}

Node* successor(Node* root)
{
    Node* temp = root->right;
    while(temp->left)
        temp = temp->left;
    return temp;
}

// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{

    if(root==NULL)
        return ;
        
    // case 1 : if key is found at root, then simply find predecessor and successor
    if(key == root->key)
    {
        if(root->left)
            pre = predecessor(root);
        
        if(root->right)
            suc = successor(root);
        return ;
    }
    
    //case 2 : key not found at root, search in left st and right st
    // 2(A) : key less than root->key : find in left subtree
    if(key < root->key)
    {
        // set the root as successor and search recusrively in left sub tree
        suc = root;
        findPreSuc(root->left,pre,suc,key);
    }
    
    // 2(B) : key greater than root
    else
    {
        // set the root as predecessor and search recursively in right subtree
        pre = root;
        findPreSuc(root->right,pre,suc,key);
    }
        
}