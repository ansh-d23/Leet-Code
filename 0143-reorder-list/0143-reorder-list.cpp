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

    int list_size(ListNode* head){
        int count=0;
        while(head){
            count++;
            head=head->next;
        }
        return count;
    }

    ListNode* reverse(ListNode* head){

        ListNode* ptr= head;
        ListNode* preptr=NULL;

        while(ptr){
            ListNode* temp = ptr->next;
            ptr->next=preptr;
            preptr=ptr;
            ptr=temp;
        }

        return preptr;
    }

    void print(ListNode* head){
        while(head){
            cout<<head->val<<" ";
            head=head->next;
        }
    }

    void reorderList(ListNode* head) {

        int n = list_size(head);

        ListNode* list1 = head;
        ListNode* head2 = new ListNode();
        ListNode* list2 = head2;

        while(list1){
            ListNode* temp = new ListNode(list1->val);
            list2->next = temp;
            list2=list2->next;
            list1=list1->next;
        }

        ListNode* rev = reverse(head2);
        head2=rev;

        if(n%2==0){

            int k = n/2;

            ListNode* temp1=head;
            ListNode* temp2=head2;

            for(int i=0;i<k;i++){

                if(i==(k-1)){
                  ListNode* t1 = temp1->next;
                  temp1->next=temp2;
                  temp2->next=nullptr;  
                }else{
                    ListNode* t1 = temp1->next;
                ListNode* t2 = temp2->next;
                temp1->next=temp2;
                temp1=t1;
                temp2->next=temp1;
                temp2=t2;
                }
            }

        }else{

            int k = (n+1)/2;

            ListNode* temp1=head;
            ListNode* temp2=head2;

            for(int i=0;i<k;i++){

                if(i==(k-1)){
                  ListNode* t1 = temp1->next;
                  temp1->next=temp2;
                  temp1->next=nullptr;  
                }else{
                    ListNode* t1 = temp1->next;
                ListNode* t2 = temp2->next;
                temp1->next=temp2;
                temp1=t1;
                temp2->next=temp1;
                temp2=t2;
                }
            }

        }

        print(head);      
        
    }
};