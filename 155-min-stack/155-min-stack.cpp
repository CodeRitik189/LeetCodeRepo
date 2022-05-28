class MinStack {
public:
    stack<pair<int,int>>sp;
    MinStack() {
        
    }
    
    void push(int val) {
        if(!sp.empty()){
            sp.push({val,min(sp.top().second,val)});
        }else{
            sp.push({val,val});
        }
    }
    
    void pop() {
        sp.pop();
    }
    
    int top() {
        return sp.top().first;
    }
    
    int getMin() {
        return sp.top().second;
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