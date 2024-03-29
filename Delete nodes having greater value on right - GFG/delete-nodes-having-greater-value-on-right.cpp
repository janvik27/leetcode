//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}



// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
    public:
    
    Node* reverse(Node* head)
    {
        if(head==NULL)
            return NULL;
        if(head->next==NULL)
            return head;
            
        Node* curr=head;
        Node* prev=NULL;
        Node* forward=NULL;
        
        while(curr!=NULL)
        {
            forward = curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        return prev;
    }
    Node *compute(Node *head)
    {
        if(head->next==NULL)
            return head;
        
        head = reverse(head);
        
        Node* curr=head;
        Node* temp=head->next;
        Node* forward = NULL;
        
        while(temp!=NULL)
        {
            if(temp->data < curr->data)
            {
                forward = temp->next;
                delete(temp);
                temp=forward;
                curr->next =forward;
            }
            else
            {
                curr=temp;
                temp=temp->next;
            }
        }
        head= reverse(head);
        return head;
            
    }
    
};
   


//{ Driver Code Starts.

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}

// } Driver Code Ends