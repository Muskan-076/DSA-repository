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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
       if(head == NULL || head->next == NULL || head->next->next == NULL ){
            return {-1, -1};
        }
        ListNode* prev = head;
        ListNode* curr = head->next;
        ListNode* next = curr->next;

        int idx =2;
        
        int first = -1;
        int prevCritical = -1;

        int minDis = INT_MAX;
        int maxDis = -1;

        while(next != NULL){
            if((curr->val > prev->val && curr->val > next->val) ||
               (curr->val < prev->val && curr->val < next->val)) {

                // First critical point
                if(first == -1) {
                    first = idx;
                }
                else {
                    // Distance from previous critical point
                    minDis = min(minDis, idx - prevCritical);

                    // Distance from first critical point
                    maxDis = idx - first;
                }

                // Update previous critical point
                prevCritical = idx;
            }

            prev = curr;
            curr = next;
            next = next->next;

            idx++;
        }
        if(prevCritical == first) {
            return {-1, -1};
        }

        return {minDis, maxDis};

        // tc = o(n+k) , sc= o(n)
        // if(head == NULL || head->next == NULL || head->next->next == NULL ){
        //     return {-1, -1};
        // }  

        // ListNode* prev = head;
        // ListNode* temp = head->next;
        // ListNode* next = temp->next;

        // vector<int> critical;

        // int idx =2;

        // while(next != NULL){
        //     if(temp->val > prev->val && temp->val > next->val){
        //         critical.push_back( idx);
        //     }
        //     if(temp->val < prev->val && temp->val < next->val){
        //         critical.push_back( idx);
        //     }
            
        //     prev = temp;
        //     temp = next;
        //     next = temp->next;

        //     idx++;
        // }
        
        
        // int n = critical.size();
        // if(n<2){
        //     return{-1, -1};
        // }
        // int minDis = INT_MAX;
        // for(int i=1; i<n; i++){
        //     minDis = min(minDis, critical[i]- critical[i-1]);
        // }
        
        // int maxDis = critical.back() - critical.front();

        // return {minDis, maxDis};
        
    }
};