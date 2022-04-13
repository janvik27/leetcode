/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    ListNode* getMid(ListNode* head)
    {
        ListNode* slow= head;
        ListNode* fast= head->next;
        
        while(fast!=NULL && fast->next!=NULL)
        {
            fast = fast->next->next;
            slow= slow->next;
        }
        return slow;
    }
    
    ListNode* reverse(ListNode* head)
    {
        //base case
        if(head==NULL || head->next==NULL)
            return head;
        
        ListNode* newhead = reverse(head->next);
        
        head->next->next = head;
        head->next= NULL;
        
        return newhead;
        
    }
public:
    bool isPalindrome(ListNode* head) {
        
        // approach 1: using extra space for an array
        /*
        vector<int> arr;
        ListNode* temp = head;
        while(temp!=NULL)
        {
            arr.push_back(temp->val);
            temp = temp->next;
        }
        
        int n= arr.size();
        int i=0, j=n-1;
        while(i<=j)
        {
            if(arr[i]==arr[j])
            {
                i++;
                j--;
            }
            else
                return false;
        }
        return true;
        */
        
        // approach 2: 
        if(head==NULL || head->next==NULL)
            return true;
        
        // step 1: find middle node
        ListNode* middle = getMid(head);
            
        //step 2: reverse the linked list ahead of mid node
        ListNode* temp = middle->next;
        middle->next = reverse(temp);
        
        // step 3:
        ListNode* head1= head;
        ListNode* head2= middle->next;
        
        while(head2!=NULL)
        {
            if(head1->val != head2->val)
                return false;
            else
            {
                head1= head1->next;
                head2= head2->next;
            }
        }
        
        // step 4 : repeat step 2.. so that our original list is retained
        temp = middle->next;
        middle->next = reverse(temp);
        
        return true;
    }
};