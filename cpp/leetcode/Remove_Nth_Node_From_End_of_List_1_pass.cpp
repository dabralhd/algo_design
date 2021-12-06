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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        assert(head != nullptr);

        ListNode * first = head;
        ListNode * second = first;

        // 1->2->3->4->5->6->NULL
        while(n-- > 0 && second != nullptr && second->next != nullptr) {
            second = second->next;            
        }          
        
        if(second == nullptr) return nullptr;

        while(first->next != nullptr && second->next != nullptr) {
            first = first->next;
            second = second->next;
        }

        while(first->next != second) {
            first->val = first->next->val;
            first = first->next;
        }
        
        first->data = second->data;
        delete second;
        first->next = nullptr;
        return head;
        
        
    }
};