//https://leetcode.com/explore/interview/card/top-interview-questions-easy/93/linked-list/553/

#include <iostream>
#include <cassert>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        assert(node != nullptr);
        ListNode* prev = node;

        while(node->next != nullptr) {
            node->val = node->next->val;
            prev = node;
            node = prev->next;
        }

        delete node;
        prev->next = nullptr;
        return;
    }
        
    }
};


int main() {
    return 0;
}