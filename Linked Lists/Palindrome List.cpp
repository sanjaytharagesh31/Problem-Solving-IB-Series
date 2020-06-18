/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int Solution::lPalin(ListNode* head) {
    ListNode* pre = NULL;
    ListNode* slow = head;
    ListNode* fast = head->next;
    if(fast == NULL)
        return 1;
    int cnt = 2;
    while(fast->next != NULL) {
        ListNode* tmp = slow->next;
        slow->next = pre;
        pre = slow;
        slow = tmp;
        fast = fast->next;
        cnt++;
        if(fast->next != NULL) {
            fast = fast->next;
            cnt++;
        }
    }
    // odd - slow is at exact middle element
    //even - slow at end of first part
    // cout << "size: " << cnt << endl;
    ListNode* left = slow;
    ListNode* right = slow->next;
    if(cnt%2 == 1) {
        left = pre;
    }
    else {
        slow->next = pre;
    }
    while(left != NULL) {
        if(left->val == right->val) {
            left = left->next;
            right = right->next;
        }
        else
            return 0;
    }
    return 1;
}
