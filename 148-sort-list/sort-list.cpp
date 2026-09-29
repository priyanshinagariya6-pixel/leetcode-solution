class Solution {
public:
    ListNode* sortList(ListNode* head) {

        // 0 or 1 node is already sorted
        if (head == NULL || head->next == NULL)
            return head;

        // Find middle
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Split into two lists
        ListNode* right = slow->next;
        slow->next = NULL;

        // Sort both halves
        ListNode* left = sortList(head);
        right = sortList(right);

        // Merge both sorted lists
        ListNode dummy(0);
        ListNode* temp = &dummy;

        while (left != NULL && right != NULL) {

            if (left->val <= right->val) {
                temp->next = left;
                left = left->next;
            }
            else {
                temp->next = right;
                right = right->next;
            }

            temp = temp->next;
        }

        if (left != NULL)
            temp->next = left;
        else
            temp->next = right;

        return dummy.next;
    }
};