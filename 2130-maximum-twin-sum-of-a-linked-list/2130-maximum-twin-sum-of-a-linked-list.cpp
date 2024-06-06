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

        ListNode* ptr=head;
        ListNode* preptr = nullptr;

        while(ptr){
            ListNode* temp= ptr->next;
            ptr->next=preptr;
            preptr=ptr;
            ptr=temp;
        }

        return preptr;

    }

    int pairSum(ListNode* head) {

        ListNode* slow=head;
        ListNode* fast=head;

        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }

        ListNode* mid = reverse(slow);
        ListNode* start = head;
        slow=mid;

        int maxm = -1;

        while(slow){

            int temp = slow->val;
            int temp2 = start->val;
            temp+=temp2;


            maxm = max(temp,maxm);

            slow=slow->next;
            start=start->next;

        }

        return maxm;
        
    }
};