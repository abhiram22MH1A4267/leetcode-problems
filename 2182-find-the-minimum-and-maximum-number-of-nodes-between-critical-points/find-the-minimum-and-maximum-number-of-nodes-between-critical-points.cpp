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
        vector<int>v;
        ListNode* curr = head;
        ListNode* next = head->next;
        ListNode* prev = NULL;
        int index = 0;
        while(next != NULL){
            if((prev != NULL && curr->val < prev->val && curr->val < next->val) || 
            (prev != NULL && curr->val > prev->val && curr->val > next->val)){
                v.push_back(index);
            }
            prev = curr;
            curr = next;
            next = next->next;
            index++;
        }
        if(v.size() < 2) return {-1,-1};
        int maxDistance = v.back()-v.front();
        int minDistance = INT_MAX;
        for(int i = 0; i < v.size()-1; i++){
            minDistance = min(minDistance, v[i+1]-v[i]);
        }
        return {minDistance,maxDistance};
    }
};