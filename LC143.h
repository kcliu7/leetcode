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
    void reorderList(ListNode* head) {
        if(!head||!head->next ||!head->next->next) return;
        ListNode *slow = head->next, *fast = slow->next;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* mid = slow->next;
        slow->next =NULL;
        ListNode* pre = NULL, *last = mid;
        while(last){
            ListNode* tmp = last->next;
            last -> next = pre;
            pre = last;
            last = tmp;
        }
        ListNode * cur = head;
        while(pre && cur){
            ListNode * tmp = cur->next;
            cur->next = pre;            
            pre = pre->next;
            cur->next->next = tmp;            
            cur = tmp;
        }
        
        
    }
};