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
        cout << node->data <<" "; 
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
class Solution{
public:
    Node* divide(int N, Node *head){
        Node* curr= head;
        Node* evenstart=NULL;
        Node* evenend= NULL;
        Node* oddstart=NULL;
        Node* oddend=NULL;
        
        while(curr!=NULL)
        {
            int val=curr->data;
            
            if(val%2==0)
            {
                if(evenstart==NULL)
                {
                    evenstart=curr;
                    evenend=evenstart;
                }
                else
                {
                    evenend->next = curr;
                    evenend = evenend->next;
                }
            }
            else
            {
                if(oddstart==NULL)
                {
                    oddstart=curr;
                    oddend=oddstart;
                }
                else
                {
                    oddend->next = curr;
                    oddend = oddend->next;
                }
                
            }
            curr=curr->next;
        }
        
        if(evenstart==NULL)
            return oddstart;
        if(oddstart==NULL)
            return evenstart;
            
        
        evenend->next =oddstart;
        oddend->next=NULL;
        
        return evenstart;
    }
};

//{ Driver Code Starts.

int main() {
    //code
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        Solution ob;
        Node *ans = ob.divide(N, head);
        printList(ans); 
    }
    return 0;
}

// } Driver Code Ends