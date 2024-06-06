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
    ListNode* swapNodes(ListNode* head, int k) {

        int n=k;
        ListNode* start=head;
        ListNode* left = head;
        ListNode* right=head;

        while(n>0 && right){
            right=right->next;
            n--;
        }

        while(k>1 && start){
            start=start->next;
            k--;
        }

        while(right){
            left=left->next;
            right=right->next;
        }

        swap(start->val, left->val);

        return head;







    }
};