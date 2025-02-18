class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::unordered_set<char> current_string;
        int left_index = 0;
        int max_size = 0;
        for (int i = 0; i < s.size(); ++i){
            while (current_string.find(s[i]) != current_string.end()){ //  present
                current_string.erase(s[left_index]);
                ++left_index;
            }
            current_string.insert(s[i]);

            max_size = max((i+1)-left_index,max_size);
        }
        return max_size;
    }
};
