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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if (head==NULL or head->next==NULL){
            return head;
        }
        ListNode* temp1=head;
        ListNode* temp2=head->next;
        int a=0;//b=0;
        while(temp1!=NULL && temp1->next!=NULL){
            a=gcd(temp1->val,temp2->val);
            // for(int i=1;i<=a;i++){
            //     if(temp1->val % i==0 && temp2->val %i==0){
            //         b=i;
            //     }
            // }
            ListNode* temp=new ListNode(a);
            temp1->next=temp;
            temp->next=temp2;
            temp1=temp2;
            temp2=temp2->next;
        }
        return head;
    }
};