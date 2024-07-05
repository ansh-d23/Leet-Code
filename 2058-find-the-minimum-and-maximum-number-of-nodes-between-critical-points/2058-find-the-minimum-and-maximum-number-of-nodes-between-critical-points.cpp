class Solution {
public:
    bool check1(ListNode* ptr, ListNode* preptr) {
        return preptr->val < ptr->val && ptr->next->val < ptr->val;
    }

    bool check2(ListNode* ptr, ListNode* preptr) {
        return preptr->val > ptr->val && ptr->next->val > ptr->val;
    }

    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans(2, -1);
        if (head == nullptr || head->next == nullptr || head->next->next == nullptr) return ans;

        ListNode* ptr = head->next;
        ListNode* preptr = head;

        int first_critical = -1;
        int last_critical = -1;
        int iterator = 1;
        bool flag = true;

        int mini_distance = INT_MAX;

        while (ptr->next != nullptr) {
            if (check1(ptr, preptr) || check2(ptr, preptr)) {
                if (flag) {
                    first_critical = iterator;
                    last_critical = iterator;
                    flag = false;
                } else {
                    mini_distance = min(iterator - last_critical, mini_distance);
                    last_critical = iterator;
                }
            }

            preptr = ptr;
            ptr = ptr->next;
            iterator++;
        }

        if (first_critical == -1 || last_critical == first_critical) return ans;
        int max_distance = last_critical - first_critical;
        ans[0] = mini_distance;
        ans[1] = max_distance;

        return ans;
    }
};