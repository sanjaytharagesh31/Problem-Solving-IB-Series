/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::insertionSortList(ListNode* A) {
    if(A == NULL || A->next == NULL)
        return A;
        
    ListNode* cur = A->next;
    ListNode* head = A;
    head->next = NULL;
    
    while(cur != NULL) {
        ListNode* tmp = head;
        ListNode* pre = NULL;
        while(tmp != NULL && tmp->val < cur->val) {
            pre = tmp;
            tmp = tmp->next;
        }
        if(tmp == head) {
            ListNode* tmp = head;
            head = cur;
            cur = cur->next;
            head->next = tmp;
        }
        else {
            pre->next = cur;
            cur = cur->next;
            pre = pre->next;
            pre->next = tmp;
        }
    }
    return head;
}
