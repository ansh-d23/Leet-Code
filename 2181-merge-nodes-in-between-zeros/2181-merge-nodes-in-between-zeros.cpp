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
    ListNode* mergeNodes(ListNode* head) {

        if(head == nullptr || head->next == nullptr) return head;
        ListNode* dummy = new ListNode();
        ListNode* ptr = dummy;

        int curr = 0;
        while(head != nullptr){

            if(head->val == 0 && curr!=0){
                ListNode* node = new ListNode(curr);
                ptr->next = node;
                ptr=ptr->next;
                curr=0;
            }else{
                curr+=head->val;
            }

            head=head->next;
        }

        return dummy->next;
        
    }
};