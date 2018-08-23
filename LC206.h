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
    ListNode* reverseList(ListNode* head) {
        if(!head) return NULL;
        ListNode dummy(-1);
        dummy.next = head;
        ListNode* cur = head->next;
        while(cur){
            ListNode* tmp = cur->next;
            cur->next = dummy.next;
            dummy.next = cur;
            head->next = tmp;
            cur = tmp;            
        }
        return dummy.next;
    }
};