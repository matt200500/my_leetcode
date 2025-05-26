class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        std::vector<int> output;
        for (int i = 0; i < words.size(); ++i){
            const string& word = words[i];
            for (char c : word){
                if(c == x){
                    output.push_back(i);
                    break;
                }
            }
        }
        return output;
    }
};