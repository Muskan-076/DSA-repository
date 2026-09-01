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
    ListNode* deleteMiddle(ListNode* head) {
        if (head->next == NULL) {
            
            return NULL;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;

        while(fast != NULL && fast->next != NULL){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        prev->next = slow->next;

        delete slow;

        return head;



        // If there is only one node
        // if (head->next == NULL) {
        //     delete head;
        //     return NULL;
        // }

        // // Find size
        // int size = 0;
        // ListNode* temp = head;

        // while (temp != NULL) {
        //     size++;
        //     temp = temp->next;
        // }

        // // Middle index
        // int mid = size / 2;

        // // Go to node just before middle
        // ListNode* prev = head;

        // for (int i = 0; i < mid - 1; i++) {
        //     prev = prev->next;
        // }

        // // Node to delete
        // ListNode* dlt = prev->next;

        // // Skip middle node
        // prev->next = dlt->next;

        // // Delete middle node
        // delete dlt;

        // return head;
    }
};