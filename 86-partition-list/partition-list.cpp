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
    ListNode* partition(ListNode* head, int x) {
        vector<int>less,high;
        while(head != NULL){
            if(head->val < x){
                less.push_back(head->val);
            }
            else{
                high.push_back(head->val);
            }
            head = head->next;
        }
        head = new ListNode(0);
        ListNode* temp = head;
        for(int i = 0; i < less.size(); i++){
            temp->next = new ListNode(less[i]);
            temp = temp->next;
        }
        for(int i = 0; i < high.size(); i++){
            temp->next = new ListNode(high[i]);
            temp = temp->next;
        }
        return head->next;
    }
};