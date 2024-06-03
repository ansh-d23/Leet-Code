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
    ListNode* deleteDuplicates(ListNode* head) {

        if(head==NULL) return head;
        
        while(head->next!=nullptr && head->next->val == head->val){
            head=head->next;
        }

        ListNode* ptr = head;
        ListNode* preptr = NULL;

        while(ptr->next!=NULL){

            if(ptr->next->val == ptr->val){
                preptr->next=ptr->next;
            }else{
                preptr=ptr;
            }
            ptr=ptr->next;
        }

        return head;

    }
};