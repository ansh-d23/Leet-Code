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

    // ListNode* reverse(ListNode* head){

    //     ListNode* ptr = head;
    //     ListNode* preptr = nullptr;

    //     while(ptr){
    //         ListNode* temp = ptr->next;
    //         ptr->next = preptr;
    //         preptr = ptr;
    //         ptr=temp; 
    //     }

    //     return preptr;
    // }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

         
         ListNode* ptr1 = l1;
         ListNode* ptr2 = l2;

         ListNode* dummy = new ListNode();
         ListNode* ans = dummy;

         int carry=0;
         
         while(ptr1 &&  ptr2){

            int sum = ptr1->val + ptr2->val + carry;
            carry = sum/10;
            ListNode* temp = new ListNode(sum%10);
            ans->next = temp;
            ans=ans->next;
            ptr1=ptr1->next;
            ptr2=ptr2->next;

         }

         if(ptr1){
            while(ptr1){

                int sum = ptr1->val + carry;
                carry = sum/10;
                ListNode* temp = new ListNode(sum%10);
                ans->next = temp;
                ans=ans->next;
                ptr1=ptr1->next;

            }
         }

         if(ptr2){

            while(ptr2){

                int sum = ptr2->val + carry;
                carry = sum/10;
                ListNode* temp = new ListNode(sum%10);
                ans->next = temp;
                ans=ans->next;
                ptr2=ptr2->next;

            }
         }

         if(carry==1){
            ListNode* temp = new ListNode(1);
            ans->next = temp;
         }

         return dummy->next;
        
    }
};