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
        bool flag = false ; 
        ListNode* slow = head , *fast = head ; 
        if(head == NULL ) return false ; 
        if(head->next == NULL) return false ; 
        if( head->next->next == NULL) return false ; 
        while(fast != NULL && fast->next != NULL  ){
            slow = slow->next ; 
            fast = fast->next->next ; 
            if(slow == fast ) return true ; 
            
        }
        return flag ; 
    }
};