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
    ListNode* reverseList(ListNode* head) {
        vector<long long> v ; 
        while(head != NULL){
            v.push_back(head->val) ; 
            head = head->next ; 
        }
        int n = v.size() ; 
        if (n == 0) return nullptr;

        ListNode* temp ;  
        for(int i = n-1; i >= 0 ; i--){
          ListNode* newNode = new  ListNode(v[i]) ; 
          if(i == n-1) {
            head = newNode ; 
            temp = newNode ;  
          }
          else{
            temp->next = newNode; 
            temp = temp->next ; 
          }
          
        }
        return head; 
    }
};