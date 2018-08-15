/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(!head) return NULL;
        RandomListNode * res = new RandomListNode (head-> label);
        RandomListNode * node = res ;
        RandomListNode * cur = head-> next;
        map<RandomListNode*, RandomListNode*> mp;
        mp[head] = res;
        while(cur){
            RandomListNode * tmp = new RandomListNode(cur->label);
            node->next = tmp;
            mp[cur] = tmp;
            node = node->next;
            cur = cur->next;
        }
        node = res;
        cur = head;
        while(cur){
            node->random = mp[cur->random];
            cur = cur->next;
            node= node->next;
        }
        return res;
    }
};