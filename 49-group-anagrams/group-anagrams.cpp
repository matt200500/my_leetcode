class Solution {

struct VectorHash {
size_t operator()(const vector<int>& v) const {
    size_t hash = 0;
    for (int num : v) {
        hash ^= hash * 31 + num; // Simple hash combination
    }
    return hash;
}
};

public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<vector<int>,vector<string>, VectorHash> all_strings;

        for (int i = 0; i < strs.size(); ++i){
            string current_string = strs[i];
            vector<int> char_count(26, 0);  // Character frequency array
            for (int y = 0; y < current_string.size(); ++y){
                char_count[current_string[y] - 'a']++;
            }
            all_strings[char_count].push_back(current_string);

        }
        std::vector<std::vector<string>> output;
        for (auto it = all_strings.begin(); it != all_strings.end(); ++it){
            output.push_back(it->second);
        }
        return output;
    }  
};
