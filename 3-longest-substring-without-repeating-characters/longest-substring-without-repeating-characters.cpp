class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::unordered_set<char> current_string;
        std::queue<char> current_substring;
        int max_size = 0;
        int current_size = 0;
        for (int i = 0; i < s.size(); ++i){
            if (current_string.find(s[i]) == current_string.end()){ // not present
                current_string.insert(s[i]);
                current_substring.push(s[i]);
                ++current_size;
                if (current_size > max_size){
                    max_size = current_size;
                }
            }else{
                bool contains_item = true;
                current_substring.push(s[i]);
                ++current_size;
                while(contains_item){
                    if (current_substring.front() == s[i]){
                        contains_item = false;
                    }else{
                        current_string.erase(current_substring.front());
                    }
                    current_substring.pop();
                    --current_size;
                }  
            }
        }
        return max(current_size, max_size);
    }
};
