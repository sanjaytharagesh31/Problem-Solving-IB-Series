/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) {
    ListNode* a = A;
    ListNode* b = B;
    ListNode* prea = a;
    int car = 0;
    while(a != NULL && b != NULL) {
        int tmp = a->val+b->val+car;
        a->val = tmp%10;
        car = tmp/10;
        prea = a;
        a = a->next;
        b = b->next;
    }
    // cout << a->val << endl;
    while(a != NULL) {
        // cout << a->val << endl;
        int tmp = a->val+car;
        a->val = tmp%10;
        car = tmp/10;
        prea = a;
        a = a->next;
        // cout << a->val << endl;
    }
    while(b != NULL) {
        int tmp = b->val+car;
        prea->next = new ListNode(tmp%10);
        car = tmp/10;
        prea = prea->next;
        b = b->next;
    }
    if(car != 0)
        prea->next = new ListNode(car);
    return A;
}
