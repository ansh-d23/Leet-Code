/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {

        //Floyd's Algorithm

        ListNode* slow = head;
        ListNode* fast = head;

        int i=0;

        while(fast && fast->next){

            if(i>0 && fast == slow){
                return true;
            }

            fast=fast->next->next;
            slow=slow->next;
            i++;
        }

            return false;
    }
};