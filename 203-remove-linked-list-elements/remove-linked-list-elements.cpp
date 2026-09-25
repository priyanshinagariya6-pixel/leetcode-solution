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
    ListNode* removeElements(ListNode* head, int k) {
         if( head == NULL ){
            return NULL ;

         }
        ListNode*delHead ;

        while( head != NULL && head->val == k ){
            delHead = head ;
            head = head->next ;
               delete delHead ;
            
        }
        ListNode* delNode ;
         ListNode* temp = head ;
         while(temp != NULL && temp->next != NULL ){
            if( temp->next->val == k ){
                delNode = temp->next;
                 temp->next = temp->next->next ;
                     delete delNode ;

                     
            }
            else 
            {
                temp = temp->next ;
            }
         }
         return head ;
        
    }
};