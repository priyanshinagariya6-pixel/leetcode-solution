class Solution {
public:
    bool isPalindrome(ListNode* head) {

        // 1. Find middle
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // 2. Reverse second half
        ListNode* prev = NULL;
        ListNode* curr = slow;

        while (curr != NULL) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // 3. Compare both halves
        ListNode* first = head;
        ListNode* second = prev;

        while (second != NULL) {
            if (first->val != second->val) {
                return false;
            }

            first = first->next;
            second = second->next;
        }

        return true;
    }
};