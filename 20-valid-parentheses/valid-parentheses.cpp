class Solution {
public:
    bool isValid(string s) {
        std::unordered_set<char> open_brackets = {'(', '{', '['};
        std::unordered_set<std::string> valid_pairs = {"()", "{}", "[]"};
        std::stack<char> current_brackets;
        if (s.length() % 2 != 0){ // cant be odd
            return false;
        }
        for (int i = 0; i < s.length(); ++i){
            if (open_brackets.find(s[i]) != open_brackets.end()){ // if open
                current_brackets.push(s[i]);
            }
            else{ // if closed
                if (current_brackets.empty()){
                    return false;
                }
                char left = current_brackets.top();
                current_brackets.pop();
                if(valid_pairs.find(std::string(1, left) + std::string(1,s[i])) == valid_pairs.end()){
                    return false;
                }
            }
        }
        if (current_brackets.empty()){
            return true;
        }
        return false;
    }
};
