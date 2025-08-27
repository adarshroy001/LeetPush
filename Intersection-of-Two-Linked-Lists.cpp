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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // ListNode *temp1 = headA ;
        // ListNode *temp2 = headB ; 
        // map<ListNode*,int> m; 
        // while(temp1 != NULL ){
        //     m[temp1]++ ; 
        //     temp1 = temp1->next ; 
        // }
        // while(temp2 != NULL){
        //     if(m.find(temp2) != m.end()) return temp2 ;
        //     temp2 = temp2->next ;
        // }
        // return NULL ;


        //Optimal 
        ListNode *temp1 = headA ;
        ListNode *temp2 = headB ; 
        if(headA == NULL || headB == NULL) return NULL ; 
        while(headA != headB){
            
            headA = headA->next ;
            headB = headB->next ;
            if(headA == headB) return headA ; 
            if(headA == NULL){
                headA = temp2 ; 
            }
            if(headB == NULL){
                headB = temp1 ; 
            }
        } 
        return headA ;
    }
};