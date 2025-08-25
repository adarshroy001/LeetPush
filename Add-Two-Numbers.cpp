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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // ListNode* temp1 = l1 ; 
        // ListNode* temp2 = l2 ;
        // ListNode* temp = new ListNode();
        // ListNode* tempx = temp; 
        // int rem = 0 ; 
        // while(temp1 != NULL || temp2 != NULL){
        //     int sum = 0 ; 
        //     if(temp1 == NULL){
        //     sum = temp2->val + rem ; 
        //     if(sum  >9 ){
        //         rem = sum/10 ; 
        //         sum = sum % 10 ; 
        //          ListNode* newnode = new ListNode(sum) ; 
        //          temp->next = newnode ; 
        //          temp = temp->next ;
        //     }
        //     else{ 
        //          ListNode* newnode = new ListNode(sum) ; 
        //          temp->next = newnode ; 
        //          temp = temp->next ;
        //          rem = 0 ; 
        //     }
        //     temp2 = temp2->next ; 
        //     }
        //     else if(temp2 == NULL){
        //     sum = temp1->val + rem; 
        //     if(sum >9 ){
        //         rem = sum/10 ; 
        //         sum = sum % 10 ; 
        //          ListNode* newnode = new ListNode(sum) ; 
        //          temp->next = newnode ; 
        //          temp = temp->next ;
        //     }
        //     else{ 
        //          ListNode* newnode = new ListNode(sum) ; 
        //          temp->next = newnode ; 
        //          temp = temp->next ;
        //          rem = 0 ; 
        //     }
        //     temp1 = temp1->next ; 
        //     } 
        //     else{
        //     sum = temp1->val + temp2->val + rem; 
        //     if(sum  >9 ){
        //         rem = sum/10 ; 
        //         sum = sum % 10 ; 
        //          ListNode* newnode = new ListNode(sum) ; 
        //          temp->next = newnode ; 
        //          temp = temp->next ;
        //     }else{ 
        //          ListNode* newnode = new ListNode(sum) ; 
        //          temp->next = newnode ; 
        //          temp = temp->next ;
        //          rem = 0 ;
        //     }
        //     temp1 = temp1->next ; 
        //     temp2 = temp2->next ; 

        //     }

        // }
        // if(rem > 0){
        //     ListNode* newnode = new ListNode(rem) ; 
        //     temp->next = newnode ; 
        //     temp = temp->next ;
        // }
        // return tempx->next ; 


        //optimal 

        ListNode *dummy = new ListNode(); 
        ListNode *temp = dummy; 
        int carry = 0;
        while( (l1 != NULL || l2 != NULL) || carry) {
            int sum = 0; 
            if(l1 != NULL) {
                sum += l1->val; 
                l1 = l1 -> next; 
            }
            
            if(l2 != NULL) {
                sum += l2 -> val; 
                l2 = l2 -> next; 
            }
            
            sum += carry; 
            carry = sum / 10; 
            ListNode *node = new ListNode(sum % 10); 
            temp -> next = node; 
            temp = temp -> next; 
        }
        return dummy -> next; 
    }
};