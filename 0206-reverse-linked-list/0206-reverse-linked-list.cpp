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
    ListNode* reverseList(ListNode* head) {

        if(head==NULL || head->next==NULL) return head;

        ListNode* preptr = head;
        ListNode*  ptr = head->next;
        
        while(ptr!=NULL){

            ListNode* temp = ptr->next;

            //invert
            ptr->next = preptr;

            preptr=ptr;
            ptr=temp;   
        }

        head->next=NULL;
        head=preptr;

        return preptr;
    }
};