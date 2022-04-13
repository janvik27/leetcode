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
    ListNode* solve(ListNode* list1, ListNode* list2)
    {
        ListNode* prev1= list1;
        ListNode* curr1= prev1->next;
        ListNode* temp= list2;
        ListNode* next2= NULL;
        
        if(curr1==NULL)
        {
            list1->next =list2;
            
        }
        
        while(curr1!=NULL && temp!=NULL)
        {
            if((temp->val >= prev1->val)  && (temp->val <= curr1->val))
            {
                // adding the node of second list to first list
                prev1->next = temp;
                next2 = temp->next;
                temp->next = curr1;
                
                // updating the pointers after addition
                prev1=temp;
                temp= next2;
                
            }
            else
            {
                // move the prev1 and curr1 pointers forward
                prev1= curr1;
                curr1 = curr1->next;
                
                //if while doing this, the curr1 pointer reaches NULL,
                // then merge the rest of the list2
                if(curr1 ==NULL)
                {
                    prev1->next = temp;
                    return list1;
                }
                    
            }
        }
        return list1;
    }
    
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL)
            return list2;
        if(list2==NULL)
            return list1;
        
        // check which list's first element is smaller
        // if first list's element is smaller, then we run the loop for second            list, i.e changes will be made in first list
        // else, changes will be made in second list
        
        if(list1->val <= list2->val)
        {
            return solve(list1,list2);
        }
        else
        {
            return solve(list2,list1);
        }
    }
};