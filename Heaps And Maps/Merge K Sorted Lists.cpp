/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class comp {
    public:
    bool operator()(ListNode* h1, ListNode* h2) {
        return h1->val > h2->val;
    }
};


ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
    
    priority_queue<ListNode*, vector<ListNode*>, comp> pq;
    
    for(ListNode* cur : A) {
        if(cur != NULL)
            pq.push(cur);
    }
    
    ListNode* head = new ListNode(0);
    ListNode* pre = head;
    while(!pq.empty()) {
        pre->next = pq.top();
        pre = pre->next;
        pq.pop();
        if(pre->next != NULL)
            pq.push(pre->next);
    }
    return head->next;
}
