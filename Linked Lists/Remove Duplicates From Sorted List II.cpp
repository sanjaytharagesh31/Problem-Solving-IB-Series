/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {
    ListNode* cur = A;
    ListNode* pre = NULL;
    ListNode* head = NULL;
    if(cur->next == NULL)
        return A;
    while(cur!= NULL && cur->next != NULL) {
        // cout << cur->val << endl;
        if(cur->val != cur->next->val) {
            if(head == NULL) {
                head = cur;
                pre = cur;
            }
            else {
                pre->next = cur;
                pre = cur;
            }
            cur = cur->next;
        }
        else {
            int v = cur->val;
            while(cur != NULL && cur->val == v) {
                cur = cur->next;
            }
        }
    }
    if(head != NULL)
        pre->next = cur;
    return head;
}
