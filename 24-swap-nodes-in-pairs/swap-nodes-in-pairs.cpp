class Solution {
public:
    ListNode* swapPairs(ListNode* head) {

        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* prev = NULL;
        ListNode* curr = head;

        while (curr != NULL && curr->next != NULL) {

            ListNode* next = curr->next;

            // swap the two nodes
            curr->next = next->next;
            next->next = curr;

            // connect previous pair with current pair
            if (prev != NULL) {
                prev->next = next;
            } else {
                head = next;
            }

            prev = curr;
            curr = curr->next;
        }

        return head;
    }
};