class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        std::vector<int> output;
        for (int i = 0; i < words.size(); ++i){
            for (int y = 0; y < words[i].size(); y++){
                if(words[i][y] == x){
                    output.push_back(i);
                    break;
                }
            }
        }
        return output;
    }
};