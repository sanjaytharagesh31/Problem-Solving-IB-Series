/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::detectCycle(ListNode* A) {
    ListNode* slow = A;
    ListNode* fast = A;
    while(fast->next!=NULL && fast->next->next!=NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
            break;
    }
    if(slow != fast)
        return NULL;
    slow = A;
    while(slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}
