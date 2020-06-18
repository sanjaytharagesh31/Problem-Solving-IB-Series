/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseBetween(ListNode* head, int m, int n) {
    ListNode* cur = head;
    ListNode* left = head;
    ListNode* pre = NULL;
    ListNode* left_pre = NULL;
    
    int cnt = 1;
    while(cnt < m) {
        pre = cur;
        cur = cur->next;
        cnt++;
        if(cnt == m) {
            left_pre = pre;
            left = cur;
        }
    }
    cur = left;
    ListNode* prel = left_pre;
    for(int i=0; i<=(n-m); i++) {
        ListNode* tmp = cur->next;
        cur->next = left_pre;
        left_pre = cur;
        cur = tmp;
    }
    if(prel != NULL)
        prel->next = left_pre;
    else
        head = left_pre;
    left->next = cur;
    return head;
}
