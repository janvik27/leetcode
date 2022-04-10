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
    ListNode* floydDetect(ListNode* head)
    {
        if(head==NULL)
            return NULL;
        
        if(head->next==NULL)
            return NULL;
        
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast!=NULL && slow!=NULL)
        {
            fast = fast->next;
            if(fast!=NULL)
                fast = fast->next;
            
            slow= slow->next;
            
            if(slow==fast)
                return slow;
        }
        
        return NULL;
    }
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL)
            return NULL;
        
        if(head->next==NULL)
            return NULL;
        
        ListNode* intersect = floydDetect(head);
        ListNode* slow = head;
        
        if(intersect==NULL)
            return NULL;
        else
        {
            while(slow!= intersect)
            {
                slow = slow->next;
                intersect = intersect->next;
            }
            return slow;
        }
    }
};