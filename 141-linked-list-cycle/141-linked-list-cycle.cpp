/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        // approach 1: using map or set
        /*
        // ht= hash table
        unordered_set<ListNode*> ht;
        
        while(head!=NULL)
        {
            if(ht.find(head)==ht.end())
            {
                ht.insert(head);
                head=head->next;
            }
            else
                return true;
        }
        return false;
        */
        
        // APPROACH 2 : FLOYD'S DETECTION ALGO : TWO POINTER APPROACH
        if(head==NULL)
            return false;
        
        if(head->next==NULL)
            return false;
        
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast!=NULL && slow!=NULL)
        {
            fast = fast->next;
            if(fast!=NULL)
                fast = fast->next;
            
            slow= slow->next;
            
            if(slow==fast)
                return true;
        }
        
        return false;
        
        
    }
};