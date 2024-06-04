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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {

        if(list1==nullptr || !list2) return nullptr;

        ListNode* ptr1 =  list1;
        ListNode* ptr2 = list1;

        ListNode* list2_head = list2;
        ListNode* list2_tail = list2;

        while(list2_tail->next) list2_tail=list2_tail->next;

        a--;
        for(int i=0;i<a;i++){
            ptr1=ptr1->next;
        }

        b++;
        for(int i=0;i<b;i++){
            ptr2=ptr2->next;
        }

        ptr1->next=list2_head;
        list2_tail->next=ptr2;

        return list1;
        
    }
};