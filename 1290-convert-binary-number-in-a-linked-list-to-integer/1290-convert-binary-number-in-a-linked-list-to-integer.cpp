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
    int binary(ListNode* head){
        int ans=0;

        int var=0;
        while(head!=nullptr){
            int val = head->val;
            ans+= (val*pow(2,var));
            var++;
            head=head->next;
        }

        return ans;
    }

    int getDecimalValue(ListNode* head) {

        //reverse ll + binary calc O(1) space
        // put it into array then reverse the array , cal binary sum O(n) space

        if(head==nullptr) return 0;

        ListNode* ptr = head;
        ListNode* preptr=nullptr;

        while(ptr!=nullptr){
            ListNode* temp = ptr->next;
            ptr->next = preptr;
            preptr = ptr;
            ptr=temp;
        }

        return binary(preptr);
    }
};