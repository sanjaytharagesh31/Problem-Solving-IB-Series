/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::partition(ListNode* A, int B) {
    ListNode* less = new ListNode(0);
    ListNode* more = new ListNode(0);
    ListNode* head1 = less;
    ListNode* head2 = more;
    ListNode* cur = A;
    while(cur != NULL) {
        if(cur->val < B) { //less
            less->next = cur;
            less = cur;
            cur = cur->next;
        }
        else { //more
            more->next = cur;
            more = cur;
            cur = cur->next;
        }
    }
    less->next = head2->next;
    more->next = NULL;
    return head1->next;
}
