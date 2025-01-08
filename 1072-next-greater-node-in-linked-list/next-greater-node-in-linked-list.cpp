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
    int isGreater(ListNode* temp){
        int n = temp->val;
        while(temp != NULL){
            if(temp->val > n){
                return temp->val;
            }
            temp = temp->next;
        }
        return 0;
    }
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int>ans;
        ListNode* temp = head;
        while(temp != NULL){
            int n = isGreater(temp);
            ans.push_back(n);
            temp = temp->next;
        }
        return ans;
    }
};