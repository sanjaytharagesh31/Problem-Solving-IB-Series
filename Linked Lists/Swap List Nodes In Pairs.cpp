/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//A simpler solution
ListNode* Solution::swapPairs(ListNode* A) {
    ListNode* head = new ListNode(0);
    head->next = A;
    ListNode* cur = head;
    while(cur->next!=NULL && cur->next->next!=NULL) {
        ListNode* node1 = cur->next;
        ListNode* node2 = cur->next->next;
        node1->next = node2->next;
        node2->next = node1;
        cur->next = node2;
        cur = cur->next->next;
    }
    return head->next;
}

//My initial solution
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
