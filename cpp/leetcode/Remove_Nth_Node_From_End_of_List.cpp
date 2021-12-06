// Remove Nth Node From End of List
//https://leetcode.com/explore/interview/card/top-interview-questions-easy/93/linked-list/603/


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

#include <iostream>
#include <cassert>

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        assert(head != nullptr);

        // find size of list
        int size = 1;
        ListNode *ptr = head;
        while(ptr != null) {
            ptr = ptr -> next;
            ++size;
        }

        // calculate the node number starting from head-node
        int node_num = size - n + 1;
        assert(node_num > 0);

        // get pointer of node to delete
        ListNode *to_delete = head;
        ListNode * prev = to_delete;
        while(--node_num > 1) {
            prev = to_delete;
            to_delete = to_delete->next;
        }

        // now delete node to_delete
        prev->next = to_delete->next;
        delete(to_delete);
        
    }
};
