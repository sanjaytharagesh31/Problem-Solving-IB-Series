/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::swapPairs(ListNode* A) {
    ListNode* pre = A;
    ListNode* cur = A->next;
    if(cur == NULL)
        return A;
    ListNode* head = cur;
    ListNode* prepre = NULL;
    while(cur != NULL) {
        ListNode* tmp = cur->next;
        cur->next = pre;
        pre->next = tmp;
        if(prepre!=NULL)
            prepre->next = cur;
        if(tmp != NULL)
            cur = tmp->next;
        else
            cur = NULL;
        prepre = pre;
        pre = tmp;
    }
    return head;
}
