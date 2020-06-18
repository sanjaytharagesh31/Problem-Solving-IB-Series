/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reorderList(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    if(fast->next == NULL) // 1 node
        return head;
    if(fast->next->next == NULL) // 2 node
        return head;
        
    while(fast->next != NULL) {
        slow = slow->next;
        fast = fast->next;
        if(fast->next != NULL)
            fast = fast->next;
    }
    
    ListNode* cur = slow->next;
    slow->next = NULL;
    ListNode* pre = NULL;
    while(cur != NULL) {
        ListNode* tmp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = tmp;
    }
    ListNode* right = pre;
    ListNode* left = head;
    while(right != NULL) {
        ListNode* tmp1 = left->next;
        ListNode* tmp2 = right->next;
        left->next = right;
        right->next = tmp1;
        left = tmp1;
        right = tmp2;
    }
    return head;
}
