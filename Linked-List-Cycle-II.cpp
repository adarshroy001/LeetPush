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
    ListNode *detectCycle(ListNode *head) {
        // Brute Force 
        //Storing each node with its index in map and checking if it is cyclic or not 
        // map<ListNode* , int > mpp ;  
        // while(head != NULL){
        //     if(mpp.find(head) != mpp.end()) return head ; 
        //     mpp[head] ++ ; 
        //     head = head->next ; 
        // }
        // return NULL ;


        // Optimal (Reducing space to o(1)) slow and Fast 
        ListNode* slow = head ; 
        ListNode* fast = head ; 
        if(head ==  NULL || head->next == NULL) return NULL   ;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next  ; 
            fast = fast->next->next ; 
            if(slow == fast){
                slow = head ; 
                while(slow != fast){
                    slow = slow->next ; 
                    fast = fast->next ; 
                }
                return slow ; 
            }
            
        }
        return NULL ; 
    }
};