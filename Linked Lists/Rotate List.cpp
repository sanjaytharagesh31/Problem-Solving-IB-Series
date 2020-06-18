/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::rotateRight(ListNode* A, int B) {
    int len = 0;
    ListNode* cur = A;
    while(cur != NULL) {
        len++;
        cur = cur->next;
    }
    B = B%len;
    if(B == 0)
        return A;
    B = len-B;
    cur = A;
    for(int i=1; i<B; i++) {
        cur = cur->next;
    }
    ListNode* tmp = cur->next;
    cur->next = NULL;
    ListNode* head = tmp;
    while(tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = A;
    return head;
}
