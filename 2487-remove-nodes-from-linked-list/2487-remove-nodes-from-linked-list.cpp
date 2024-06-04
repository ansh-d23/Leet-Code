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

    ListNode* reverse(ListNode* head){

        ListNode* revptr =head;
        ListNode* preptr =NULL;

        while(revptr){
            ListNode* temp = revptr->next;
            revptr->next = preptr;
            preptr = revptr;
            revptr= temp;
        }

        return preptr;

    }

    ListNode* removeNodes(ListNode* head) {

        if(!head) return nullptr;

        ListNode* newHead = reverse(head);

        int maxm=-1;
        ListNode* comp = newHead;
        ListNode* pre = nullptr;

        while(comp){

            if(comp->val >= maxm && comp){
                pre=comp;
                int temp = comp->val;
                maxm = max(maxm,temp);
                comp=comp->next;
                
            }else{
                ListNode* temp = comp->next;
                pre->next = temp;
                comp=temp;
            }
        }

        //re-reverse

        head  = reverse(newHead);

        return head;
    
    }
};