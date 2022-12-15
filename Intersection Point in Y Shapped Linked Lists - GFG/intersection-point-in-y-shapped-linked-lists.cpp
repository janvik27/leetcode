//{ Driver Code Starts
#include<iostream>

#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

int intersectPoint(struct Node* head1, struct Node* head2);

Node* inputList(int size)
{
    if(size==0) return NULL;
    
    int val;
    cin>> val;
    
    Node *head = new Node(val);
    Node *tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

/* Driver program to test above function*/
int main()
{
    int T,n1,n2,n3;

    cin>>T;
    while(T--)
    {
        cin>>n1>>n2>>n3;
        
        Node* head1 = inputList(n1);
        Node* head2 = inputList(n2);
        Node* common = inputList(n3);
        
        Node* temp = head1;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        temp = head2;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        cout << intersectPoint(head1, head2) << endl;
    }
    return 0;
}


// } Driver Code Ends


/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

int getcount(Node* head)
{
    if(head==NULL)
        return 0;
    if(head->next==NULL)
        return 1;
    
    int count=0;
    Node* temp=head;
    while(temp!=NULL)
    {
        count+=1;
        temp=temp->next;
    }
    return count;
}

int getIntersectionNode(int d, Node* head1,Node* head2)
{
    Node* temp1= head1;
    Node* temp2= head2;
    
    // traverse the bigger list from the first node to d nodes 
    // so that from here onwards both the lists have equal no of nodes
    for(int i=0;i<d;i++)
    {
        if(temp1==NULL)
            return -1;
        temp1 = temp1->next;
    }
    
    while(temp1!=NULL && temp2!=NULL)
    {
        if(temp1==temp2)
            return temp1->data;
        
        temp1=temp1->next;
        temp2=temp2->next;
    }
    return -1;
}

//Function to find intersection point in Y shaped Linked Lists.
int intersectPoint(Node* head1, Node* head2)
{
    int count1 = getcount(head1);
    int count2 = getcount(head2);
    int d;
    
    if(count1>count2)
    {
        d = count1-count2;
        return getIntersectionNode(d,head1,head2);
    }
    else
    {
        d = count2-count1;
        return getIntersectionNode(d,head2,head1);
    }
}

