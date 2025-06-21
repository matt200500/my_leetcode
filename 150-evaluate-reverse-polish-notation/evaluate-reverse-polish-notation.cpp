class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> stack;
        for (int i = 0; i < tokens.size(); ++i){
            if (tokens[i] == "+"){
                int second_number = stack.top();
                stack.pop();
                int first_number = stack.top();
                stack.pop();
                stack.push(first_number + second_number);
            }else if(tokens[i] == "-"){
                int second_number = stack.top();
                stack.pop();
                int first_number = stack.top();
                stack.pop();
                stack.push(first_number - second_number);
            }
            else if (tokens[i] == "*"){
                int second_number = stack.top();
                stack.pop();
                int first_number = stack.top();
                stack.pop();
                stack.push(first_number * second_number);
            }
            else if (tokens[i] == "/"){
                int second_number = stack.top();
                stack.pop();
                int first_number = stack.top();
                stack.pop();
                stack.push(first_number / second_number);
            }
            else{
                stack.push(std::stoi(tokens[i]));
            }
        }
        return stack.top();
    }
};
