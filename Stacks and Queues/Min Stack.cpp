stack<pair<int, int>> s;

MinStack::MinStack() {
    s = stack<pair<int, int>>();
}

void MinStack::push(int x) {
    if(s.empty()) {
        s.push(make_pair(x, x));
    }
    else {
        int pre = min(x, s.top().second);
        s.push(make_pair(x, pre));
    }
}

void MinStack::pop() {
    if(!s.empty())
        s.pop();
}

int MinStack::top() {
    if(s.empty())
        return -1;
    else {
        return s.top().first;
    }
}

int MinStack::getMin() {
    if(s.empty())
        return -1;
    return s.top().second;
}

