class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::unordered_set<char> seen;
        int left = 0, max_size = 0;
        
        for (int right = 0; right < s.size(); ++right) {
            while (seen.find(s[right]) != seen.end()) {
                // Remove the leftmost character and move left pointer
                seen.erase(s[left]);
                left++;
            }
            // Add new character
            seen.insert(s[right]);
            max_size = max(max_size, right - left + 1);
        }
        
        return max_size;
    }
};
