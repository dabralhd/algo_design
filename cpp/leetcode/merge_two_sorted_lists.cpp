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

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}      
 };

 ListNode * getList(vector<int> values) {
     ListNode* sentinel = ListNode();
     ListNode* head = sentinel;

     for(auto val:values) {
         head->next = ListNode(val);
         head = heae->next;
     }

     head = sentinel->next;
     delete sentinel;
     return head;
 }

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

        ListNode * sentinel = new ListNode();
        ListNode * head = sentinel;

        while(l1 != nullptr && l2 != nullptr) {
            ListNode * temp = nullptr;
            if(l1->val < l2->val) {
                temp = l1;
                l1 = l1->next
            } else {
                temp = l2;
                l2 = l2->next;
            }

            head->next = temp;
            head = temp;
        }

        ListNode * x = nullptr;
        if(l1 == nullptr) x = l1;
        else if(l2 == nullptr) x = l2;

        if(x != nullptr) {
            head->next = x;
            x = x->next;
            head = head->next;
        }

        head->next = x;
        head = sentinel->next;
        delete sentinel;

        return head;
    }


    
        
    
    };