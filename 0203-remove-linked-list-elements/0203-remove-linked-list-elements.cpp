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
    ListNode* removeElements(ListNode* head, int val) {

       while (head!=NULL && head->val == val) {
            head = head->next;
        }

        ListNode* ptr = head;
        ListNode* preptr = nullptr;

        while (ptr) {
            if (ptr->val == val) {
                preptr->next = ptr->next;
            }else  preptr = ptr;
            ptr = ptr->next;
        }
        
        return head;

    }
};