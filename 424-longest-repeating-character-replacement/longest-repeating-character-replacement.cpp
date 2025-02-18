class Solution {
public:
    int characterReplacement(string s, int k) {
        std::unordered_map<char,int> frequency;
        int left_pointer = 0;
        int total_largest_char = 0;
        int max_length = 0;

        for(int i = 0; i < s.size();++i){ 
            ++frequency[s[i]];

            total_largest_char = max(frequency[s[i]], total_largest_char);

            if((i - left_pointer + 1) - total_largest_char > k){
                --frequency[s[left_pointer]];
                ++left_pointer;
            }

            max_length = max(max_length, (i - left_pointer + 1));

        } 
        return max_length;
    }
};
