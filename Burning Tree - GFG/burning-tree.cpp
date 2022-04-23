// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
    // create node to parent mapping and also return the target node
    Node* createParentMapping(Node* root,int target,map<Node*,Node*> &nodetoParent)
    {
        Node* res=NULL;
        
        //level order traversal
        queue<Node*> q;
        q.push(root);
        
        //SINCE ROOT HAS NO PARENT, SO ITS PARENT WILL BE NULL
        nodetoParent[root]=NULL;
        
        while(!q.empty())
        {
            Node* front = q.front();
            q.pop();
            
            if(front->data==target)
                res= front;
                
            if(front->left)
            {
                nodetoParent[front->left] = front;
                q.push(front->left);
            }
            
            if(front->right)
            {
                nodetoParent[front->right] = front;
                q.push(front->right);
            }
        }
        return res; //target node
    }
    
    int burnTree(Node* targetnode, map<Node*,Node*> &nodetoParent)
    {
        map<Node*,bool> visited;
        queue<Node*> q;
        
        q.push(targetnode);
        visited[targetnode] = true;
        
        int ans=0;
        
        while(!q.empty())
        {
            // bool flag =0;
            int size= q.size();
            for(int i=0;i<size;i++)
            {
                Node* front= q.front();
                q.pop();
                
                // check for left child
                if(front->left && !visited[front->left])
                {
                    
                    q.push(front->left);
                    visited[front->left]=true;
                }
                
                //check for right child
                if(front->right && !visited[front->right])
                {
                    
                    q.push(front->right);
                    visited[front->right]=true;
                }
                
                // check for parent, if some value exists for that node in the map, 
                // that means, it has a parent. Also check if it is already visited or not
                if(nodetoParent[front] && !visited[nodetoParent[front]])
                {
                    
                    q.push(nodetoParent[front]);
                    visited[nodetoParent[front]]= true;
                }
            }
            if(!q.empty())
            {
                ans++;
            }
        }
        return ans;
    }
    
    int minTime(Node* root, int target) 
    {
        // step 1: create node to parent mapping
        // step 2: find the target node
        // step 3: find the min time to burn
        
        
        map<Node*,Node*> nodetoParent;
        Node* targetnode = createParentMapping(root,target,nodetoParent);
        
        int ans = burnTree(targetnode,nodetoParent);
        
        return ans;
        
    }
};

// { Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}
  // } Driver Code Ends