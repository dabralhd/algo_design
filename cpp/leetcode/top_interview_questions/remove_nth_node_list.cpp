// https://leetcode.com/problems/remove-nth-node-from-end-of-list/ 


/* Definition for singly-linked list.
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
        ListNode* dummy = new ListNode(0, head);
        ListNode* first = dummy;
        ListNode* second = dummy;
        int i = 0;
        for(i=0; i<n && second!=nullptr; i++)
            second = second->next;
        if(i != n)
            return head;
        while(second!=nullptr && second->next!=nullptr) {
            first = first->next;
            second = second->next;
        }

        //delete the node to which first->next is pointing
        ListNode* temp = first->next;
        first->next = first->next->next;
        delete temp;
        /* this is very important: head must be re-evaluated wrt dummy */
        head = dummy->next;
        delete dummy;        
        return head;
    }
};
