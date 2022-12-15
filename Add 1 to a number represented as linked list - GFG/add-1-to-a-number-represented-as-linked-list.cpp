//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
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
    Node* addOne(Node *head) 
    {
        if(head->next==NULL)
        {
            head->data+=1;
            return head;
        }
        // reverse the given linked list
        head= reverse(head);
        
        Node* temp=head;
        int carry=0;
        int digit=0;
        // for first node
        temp->data +=1;
        digit = temp->data%10;
        carry = temp->data/10;
        temp->data=digit;
        temp=temp->next;
        
        while(temp!=NULL)
        {
            digit = temp->data+carry;
            carry = digit/10;
            if(temp->next!=NULL)
                digit= digit%10;
            temp->data=digit;
            temp=temp->next;
        }
        
        
        head= reverse(head);
        return head;
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends