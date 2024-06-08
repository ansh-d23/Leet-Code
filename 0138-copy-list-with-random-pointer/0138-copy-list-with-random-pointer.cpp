/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {

        Node* ptr = head;
        Node* ptr1 = head;

        unordered_map<Node* , Node*> mpp;

        while(ptr){
            Node* temp = new Node(ptr->val);
            mpp[ptr] = temp;
            ptr=ptr->next;
        }

        while(ptr1){
            Node* temp = mpp[ptr1];
            temp->next = mpp[ptr1->next];
            temp->random = mpp[ptr1->random];
            ptr1=ptr1->next;
        }

        return mpp[head];
        
    }
};