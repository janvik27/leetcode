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
    ListNode* swapNodes(ListNode* head, int k) {
        vector<int> v;
        ListNode* temp = head;
        ListNode* temp2 = head;
        
        int count=0;
        while(temp!=NULL)
        {
            v.push_back(temp->val);
            temp = temp->next;
            count++;
        }
        swap(v[k-1],v[count-k]);
        
        int i=0;
        while(temp2!=NULL)
        {
            temp2->val= v[i];
            temp2= temp2->next;
            i++;
        }
        return head;
        
    }
};