struct Node {
    int key; 
    int val;
    Node* next;
    Node* pre;
    Node(int key, int val) : key(key), val(val), next(NULL), pre(NULL){}
};

class doubleList {
    private:
        Node* head;
        Node* tail;
    public:
        doubleList() {
            head = NULL;
            tail = NULL;
        }
        
        void setNULL() {
            head = NULL;
            tail = NULL;
        }
        
        void moveFront(Node* cur) {
            Node* tmp = cur;
            if(cur == head) {
                return;
            }
            else if(cur == tail) {
                tail = tail->pre;
                tail->next = NULL;
                tmp->pre = NULL;
            }
            else {
                cur->pre->next = cur->next;
                cur->next->pre = cur->pre;
                cur->pre = NULL;
                cur->next = NULL;
            }
            Node* tmp_head = head;
            head->pre = tmp;
            head = head->pre;
            head->next = tmp_head;
        }
        
        void moveBack(Node* cur) {
            Node* tmp = cur;
            if(cur == tail) {
                return;
            }
            else if(cur == head) {
                head = head->next;
                head->pre = NULL;
                tmp->next = NULL;
                tmp->pre = NULL;
            }
            else {
                cur->pre->next = cur->next;
                cur->next->pre = cur->pre;
                cur->pre = NULL;
                cur->next = NULL;
            }
            Node* tmp_tail = tail;
            tail->next = tmp;
            tail = tail->next;
            tail->pre = tmp_tail;
        }
        
        void insertFront(Node* cur) {
            if(head == NULL) {
                head = cur;
                tail = cur;
            }
            else {
                Node* tmp_head = head;
                head->pre = cur;
                head = head->pre;
                head->next = tmp_head;
            }
        }
        
        void insertBack(Node* cur) {
            if(head == NULL) {
                head = cur;
                tail = cur;
            }
            else {
                Node* tmp_tail = tail;
                tail->next = cur;
                tail = tail->next;
                tail->pre = tmp_tail;
                tail->next = NULL;
            }
        }
        Node* removeFront() {
            Node* tmp = head;
            if(head == tail) {
                head = NULL;
                tail = NULL;
            }
            else {
                head = head->next;
                head->pre = NULL;
            }
            return tmp;
        }
};

map<int, Node*> mp;
int cap;
int cur;
doubleList obj;

LRUCache::LRUCache(int capacity) {
    mp.clear();
    cap = capacity;
    cur = 0;
    obj.setNULL();
}

int LRUCache::get(int key) {
    if(mp.find(key) != mp.end()) {
        int val = mp[key]->val;
        obj.moveBack(mp[key]);
        return val;
    }
    return -1;
}

void LRUCache::set(int key, int value) {
    Node* tmp = new Node(key, value);
    if(mp.find(key) != mp.end()) {
        mp[key]->val = value;
        obj.moveBack(mp[key]);
    }
    else if(cur < cap) {
        obj.insertBack(tmp);
        mp[key] = tmp;
        cur++;
    }
    else {
        Node* rem = obj.removeFront();
        mp.erase(rem->key);
        obj.insertBack(tmp);
        mp[key] = tmp;
    }
}
