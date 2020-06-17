//O(N+X) Space solution, X - number of times minimum changes
stack<int> s;
stack<int> mn;

MinStack::MinStack() {
    s = stack<int>();
    mn = stack<int>();
}

void MinStack::push(int x) {
    s.push(x);
    if(mn.empty()) {
        mn.push(x);
    }
    else {
        if(mn.top() >= x)
            mn.push(x);
    }
}

void MinStack::pop() {
    if(!s.empty()) {
        if(mn.top() == s.top())
            mn.pop();
        s.pop();
    }
}

int MinStack::top() {
    if(s.empty())
        return -1;
    else {
        return s.top();
    }
}

int MinStack::getMin() {
    if(mn.empty())
        return -1;
    return mn.top();
}



//O(N+N) Space solution

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

