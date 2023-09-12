class CustomStack {
public:

    // Use an extra array to store the increment value
    // inc[i] means for elements in stack[0]~stack[i],
    // we should add inc[i] when we popped form the Stack
    // after we pop, we add the value from inc[i] to inc[i-1]
    // so that we can accumulate the increment inc[i] for the bottom elements


    vector<int> stack;
    vector<int> inc;
    int index;

    CustomStack(int maxSize) {

        stack.resize(maxSize);
        inc.resize(maxSize);
        index = 0;   
    }
    
    void push(int x) {
        
        if(index >= stack.size())
            return;
        
        stack[index] = x;
        inc[index] = 0;
        index++;
    }
    
    int pop() {
        
        if(index-1 < 0)
            return -1;
        if(index-1 > 0)
            inc[index-2] += inc[index-1];
        int ret = stack[index-1] + inc[index-1];
        index--;

        return ret;
    }
    
    void increment(int k, int val) {
        
        int i = min(k, index) - 1;
        if(i >= 0)
            inc[i] += val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */