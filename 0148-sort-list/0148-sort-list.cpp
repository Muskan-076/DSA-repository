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

    // Merge two sorted linked lists
    ListNode* merge(ListNode* first, ListNode* second) {

        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        while (first != NULL && second != NULL) {

            if (first->val <= second->val) {
                temp->next = first;
                first = first->next;
            }
            else {
                temp->next = second;
                second = second->next;
            }

            temp = temp->next;
        }

        // If something is left in first
        if (first != NULL) {
            temp->next = first;
        }

        // If something is left in second
        if (second != NULL) {
            temp->next = second;
        }

        ListNode* ans = dummy->next;
        delete dummy;

        return ans;
    }


    ListNode* sortList(ListNode* head) {

        // 0 or 1 node is already sorted
        if (head == NULL || head->next == NULL) {
            return head;
        }

        // Find middle
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Break into two halves
        ListNode* second = slow->next;
        slow->next = NULL;

        // Sort both halves
        ListNode* first = sortList(head);
        second = sortList(second);

        // Merge sorted halves
        return merge(first, second);
    }
};