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

        // most optimal

        // bool flag = false ; 
        // ListNode* slow = head , *fast = head ; 
        // if(head == NULL ) return false ; 
        // if(head->next == NULL) return false ; 
        // if( head->next->next == NULL) return false ; 
        // while(fast != NULL && fast->next != NULL  ){
        //     slow = slow->next ; 
        //     fast = fast->next->next ; 
        //     if(slow == fast ) return true ; 
            
        // }
        // return flag ; 

        //Brute force 
        map<ListNode*,int> m ; 
        ListNode* temp = head ; 
        while(temp != NULL){
          if(m.find(temp) != m.end()) return true ; 
          m[temp] ++ ; 
          temp = temp->next ; 
        }
        return false ; 
    }
};