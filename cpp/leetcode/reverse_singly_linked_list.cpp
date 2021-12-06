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
        /*
        ALGO:
        if (head == nullptr)
            return head;

        ListNode * prev = nullptr;
        ListNode * current = head;
        prev = current;
        ListNode * next = current->next;        
        current->next = nullptr;        

        while(next != nullptr) {
            current = next;
            next = current->next;
            current->next = prev;
            prev = current;
        }
        /*
        
    }

};