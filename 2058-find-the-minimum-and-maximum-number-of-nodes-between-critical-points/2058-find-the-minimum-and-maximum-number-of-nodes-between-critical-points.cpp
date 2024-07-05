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
    bool check1(ListNode* ptr , ListNode* preptr){
        if(preptr->val<ptr->val && ptr->next->val<ptr->val){
            return true;
        }
        return false;
    }

    bool check2(ListNode* ptr, ListNode* preptr){
        if(preptr->val>ptr->val && ptr->next->val>ptr->val){
            return true;
        }
        return false;
    }

    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>  ans(2,-1);
        if(head==nullptr || head->next==nullptr || head->next->next==nullptr) return ans;

        ListNode* ptr = head->next;
        ListNode* preptr = head;

        int first_critical= -1;
        int next_critical =-1;
        int last_critical=-1;
        int iterator=1;
        bool flag = true;

        int mini_distance = INT_MAX;
        int max_distance = -1;

        while(ptr->next != nullptr){

            if( check1(ptr,preptr) || check2(ptr,preptr) ){
                if(flag){
                    first_critical = iterator;
                    last_critical = iterator;
                    flag = false;
                }else{
                    next_critical=iterator;
                    mini_distance = min(next_critical-last_critical , mini_distance);
                    last_critical = next_critical;
                }    
            }

            preptr=ptr;
            ptr=ptr->next;
            iterator++;
        }

        if(first_critical==-1 || next_critical==-1) return ans;
        max_distance = next_critical-first_critical;
        // ans.push_back({mini_distance , max_distance});
        ans[0] = mini_distance;
        ans[1] = max_distance;
        return ans;
    }
};