// { Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

 // } Driver Code Ends


/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    //optimisation
    void createMap(int in[],map<int,int> &nodeToIndex,int n)
    {
        for(int i=0;i<n;i++)
        {
            nodeToIndex[in[i]] = i;
        }
    }
    /*
    int search(int in[],int curr,int start,int end)
    {
        for(int i=start;i<=end;i++)
        {
            if(in[i]==curr)
                return i;
        }
        return -1;
    }
    */
    
    Node* solve(int in[],int pre[],int &index,int start,int end,int size,map<int,int> &nodeToIndex)
    {
        // base case
        if(index>=size)
            return NULL;
        if(start>end)
            return NULL;
            
        int curr = pre[index];
        index++;
        Node* newnode = new Node(curr);
        
        // if(start==end)
        //     return newnode;
        
        // int pos = search(in,curr,start,end);
        int pos = nodeToIndex[curr]; //gives the index of curr element from map
        
        newnode->left = solve(in,pre,index,start,pos-1,size,nodeToIndex);
        newnode->right = solve(in,pre,index,pos+1,end,size,nodeToIndex);
        
        return newnode;
    }
    
    Node* buildTree(int in[],int pre[], int n)
    {
        int index= 0;
        
        //optimisation: using a map to store indexes of inorder elements
        map<int,int> nodeToIndex; //stores indexes of inorder elements so that,
        // we dont have to make the function call for search again and again
        
        createMap(in,nodeToIndex,n);
        
        Node* ans = solve(in,pre,index,0,n-1,n,nodeToIndex);
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}
  // } Driver Code Ends