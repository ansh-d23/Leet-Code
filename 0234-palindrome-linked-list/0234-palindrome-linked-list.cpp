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
    bool isPalindrome(ListNode* head) {

        ListNode* fast=head;
        ListNode* slow=head;

        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        }

        //rever algo
        ListNode* prev=NULL;
        while(slow){
            ListNode* temp = slow->next;
            slow->next=prev;
            prev=slow;
            slow=temp;
        }

        //comprison
        ListNode* left=head;
        ListNode* right=prev;

        while(right){

            if(left->val != right->val) return false;

            right=right->next;
            left=left->next;
        }

        return true;

    }
};