class MinStack {
    private:
    stack <int> S_data;
    stack <int> S_min;
    public:
    MinStack() {
        
    }
    
    void push(int val) {
        if(S_min.empty()||val<=S_min.top()) S_min.push(val);
        S_data.push(val);
    }
    
    void pop() {
        if(S_data.top() == S_min.top()) S_min.pop();
        S_data.pop();
    }
    
    int top() {
        return S_data.top();
    }
    
    int getMin() {
        return S_min.top();
    }
};
/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */