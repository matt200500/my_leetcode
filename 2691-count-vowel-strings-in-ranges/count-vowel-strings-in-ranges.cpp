class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        std::unordered_set<char> vowels {'a', 'e', 'i', 'o', 'u'};
        std::vector<int> prefix_sum;
        std::vector<int> output;
        int prefix = 0;
        for (auto& word : words) {
            if (!word.empty() &&
                vowels.find(word.front()) != vowels.end() &&
                vowels.find(word.back()) != vowels.end()) {
                prefix++;
            }
            prefix_sum.push_back(prefix);
        }

        for (auto& query : queries){
            if (query[0] == 0){
                output.push_back(prefix_sum[query[1]]);            
            }else{
                output.push_back(prefix_sum[query[1]] - prefix_sum[query[0] -1]);            
            }
        }
        return output;
    }
};