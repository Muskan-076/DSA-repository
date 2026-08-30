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

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* temp = dummy;

        int idx = 0;

        // Move temp n steps ahead
        while (idx < n) {
            temp = temp->next;
            idx++;
        }

        // Move another pointer from dummy
        ListNode* prev = dummy;

        while (temp->next != NULL) {
            temp = temp->next;
            prev = prev->next;
        }

        // Delete the node
        ListNode* dlt = prev->next;
        prev->next = dlt->next;

        delete dlt;

        ListNode* newHead = dummy->next;
        delete dummy;

        return newHead;
    }
};