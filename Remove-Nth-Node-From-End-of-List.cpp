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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // int count = 0 ; 
        // ListNode* temp = head ; 
        // while(temp != NULL ){
        //     temp = temp->next ; 
        //     count ++ ; 
        // }
        // temp = head ; 
        // for(int i = 0 ; i < count-n-1  ; i++){
        //   temp = temp->next ; 
        // }

        // if (n == count) {
        //     ListNode* newHead = head->next;
        //     delete head;
        //     return newHead;
        // }
        // ListNode* toDelete = temp->next;
        // temp->next = temp->next->next;
        // delete toDelete;


        // return head;

        //Optimal 
        ListNode* temp = head ; 
        ListNode* fast = head ; 
        ListNode* slow = head ; 
        if(head == NULL) return head ;
        for(int i = 0 ; i < n ; i++){
            fast = fast->next ; 
        }
        if(fast == NULL) return head->next;

        while(fast->next != NULL){
            slow = slow->next ; 
            fast = fast->next ; 
        }
        

       ListNode* preserve = slow->next; 
       slow->next = slow->next->next ; 
       delete(preserve) ; 
       return head ; 

    }
};