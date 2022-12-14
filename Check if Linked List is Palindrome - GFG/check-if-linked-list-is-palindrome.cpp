//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};




// } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
#include <vector>
class Solution{
  public:
    bool checkPall(vector<int> arr)
    {
      int n=arr.size();
      int i=0;
      int j=n-1;
      while(i<=j)
      {
        if(arr[i]!=arr[j])
            return false;
        i++;
        j--;
      }
      return true;
    }
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        vector<int> arr;
        
        Node* temp = head;
        while(temp!=NULL)
        {
            arr.push_back(temp->data);
            temp=temp->next;
        }
        
        bool ans=checkPall(arr);
        return ans;
        
    }
};



//{ Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}


// } Driver Code Ends