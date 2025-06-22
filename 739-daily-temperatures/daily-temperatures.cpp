class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        std::vector<int> result(temperatures.size());
        std::stack<int> stack;
        std::fill(result.begin(), result.end(), 0);
        std::stack<int> indexes;

        for (int i = 0; i < temperatures.size(); ++i ){
            if ((stack.empty())){
                stack.push(temperatures[i]);
                indexes.push(i);

            }else{
                if (temperatures[i] > stack.top()){
                    while(!stack.empty() && stack.top() < temperatures[i]){
                        result.at(indexes.top()) = i - indexes.top();
                        stack.pop();
                        indexes.pop();
                    }
                    stack.push(temperatures[i]);
                    indexes.push(i);

                }else{
                    stack.push(temperatures[i]);
                    indexes.push(i);
                }
            }
        }

        return result;

    }
};
