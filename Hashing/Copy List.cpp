/**
 * Definition for singly-linked list.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
RandomListNode* Solution::copyRandomList(RandomListNode* A) {
    map<RandomListNode*, RandomListNode*> mp;
    mp[NULL] = NULL;
    RandomListNode* cur = A;
    RandomListNode* head = new RandomListNode(0);
    RandomListNode* pre = head;

    while(cur != NULL) {
        RandomListNode* tmp = new RandomListNode(cur->label);
        mp[cur] = tmp;
        pre->next = tmp;
        pre = tmp;
        cur = cur->next;
    }
    cur = A;
    pre = head->next;
    while(cur != NULL) {
        pre->random = mp[cur->random];
        cur = cur->next;
        pre = pre->next;
    }
    return head->next;
}
