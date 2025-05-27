class MinStack {
public:
    std::vector<int> stack;
    std::vector<int> min_stack;


    MinStack() {
        stack.empty();
    }
    
    void push(int val) {
        if (min_stack.empty() || val <= min_stack.back()){
            min_stack.push_back(val);
        }
        stack.push_back(val);
    }
    
    void pop() {
        if (stack.back() == min_stack.back()){
            min_stack.pop_back();
        }
        stack.pop_back();
    }
    
    int top() {
        return stack[stack.size() -1];
    }
    
    int getMin() {
        return min_stack.back();
    }
};
