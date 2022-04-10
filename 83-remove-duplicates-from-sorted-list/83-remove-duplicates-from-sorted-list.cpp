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
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL)
            return NULL;
        
        if(head->next == NULL)
            return head;
        
        else
        {
            ListNode* curr = head;
            while(curr!=NULL)
            {
                if((curr->next!=NULL) && curr->val == curr->next->val) //2 adjacent nodes are equal
                {
                    ListNode* next_next = curr->next->next;
                    ListNode* nodetodelete = curr->next;
                    delete(curr->next);
                    curr->next = next_next;
                }
                else // not equal
                {
                    curr = curr->next;
                }
            }
        }
        return head;
    }
};