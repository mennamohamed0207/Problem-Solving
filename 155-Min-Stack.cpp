class MinStack {
public:
    stack<int>St;
    vector<int>vec;
    MinStack() {
        
    }
    
    void push(int val) {
       St.push(val);


    }
    
    void pop() {
        St.pop();
    }
    
    int top() {
        return St.top();
    }
    
    int getMin() {
        stack<int> tmp;
        int mini=St.top();
        while(!St.empty())
        {   
            int place=St.top();
            St.pop();
            mini=min(mini,place);
            tmp.push(place);

        }
        while(!tmp.empty())
        {
            int ret=tmp.top();
            tmp.pop();
            St.push(ret);
        }
        return mini;
       
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