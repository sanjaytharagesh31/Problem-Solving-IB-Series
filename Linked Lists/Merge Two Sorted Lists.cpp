/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {
    ListNode* cur1 = A;
    ListNode* cur2 = B;
    ListNode* head = new ListNode(0);
    ListNode* tmp = head;
    while(cur1!=NULL && cur2!=NULL) {
        if(cur1->val < cur2->val) {
            tmp->next = cur1;
            tmp = tmp->next;
            cur1 = cur1->next;
        }
        else {
            tmp->next = cur2;
            tmp = tmp->next;
            cur2 = cur2->next;
        }
    }
    while(cur1!=NULL) {
        tmp->next = cur1;
        tmp = tmp->next;
        cur1 = cur1->next;
    }
    while(cur2!=NULL) {
        tmp->next = cur2;
        tmp = tmp->next;
        cur2 = cur2->next;
    }
    return head->next;
}
