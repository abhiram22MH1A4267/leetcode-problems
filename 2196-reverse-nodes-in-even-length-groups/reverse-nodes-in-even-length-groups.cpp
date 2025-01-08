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
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        vector<int>arr;
        while(head != NULL){
            arr.push_back(head->val);
            head = head->next;
        }
        int n = arr.size(), m = 1, i = 0;
        while(i < n){
            if((m&1) == 0){
                if((i+m) < n){
                    reverse(arr.begin()+i, arr.begin()+i+m);
                }
                else if(((n-i) & 1) == 0){
                    reverse(arr.begin()+i, arr.end());
                }
            }
            else if(((i+m) > n) && ((n-i)&1) == 0){
                reverse(arr.begin()+i, arr.end());
            }
            i += m;
            m++;
        }
        // for(int i : arr){
        //     cout<<i<<" ";
        // }
        head = new ListNode(0);
        ListNode* temp = head;
        for(int i = 0; i < n; i++){
            temp->next = new ListNode(arr[i]);
            temp = temp->next;
        }
        return head->next;
    }
};