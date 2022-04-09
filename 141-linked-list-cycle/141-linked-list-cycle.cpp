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
    }
};