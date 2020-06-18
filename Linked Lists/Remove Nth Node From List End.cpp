/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::removeNthFromEnd(ListNode* A, int B) {
    ListNode* slow = A;
    ListNode* fast = A;
    int cnt = 0;
    while(fast!=NULL && cnt < B) {
        fast = fast->next;
        cnt++;
    }
    if(fast == NULL) {
        A = A->next;
        return A;
    }
    while(fast->next != NULL) {
        slow = slow->next;
        fast = fast->next;
    }
    slow->next = slow->next->next;
    return A;
}
