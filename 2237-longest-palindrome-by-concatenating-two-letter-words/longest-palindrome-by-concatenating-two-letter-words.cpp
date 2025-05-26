class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        std::unordered_map<std::string, int> occurences;
        int output = 0;
        int middle = 0;
        for (int i = 0; i < words.size(); ++i){ // add all items to map, incrementing count for items in it
            auto it = occurences.find(words[i]);
            if (it != occurences.end()){ // if we found a duplicate
                occurences.at(words[i]) += 1; // increase count by 1
            }else{
                occurences.insert({words[i], 1}); // add new word to map
            }
        }
        for (int i = 0; i < words.size(); ++i){
            std::string current_word = words[i];
            auto it = occurences.find(current_word);

            if (current_word[0] == current_word[1]){ // if same char
                if (middle == 0 && it->second % 2 != 0){ // if odd
                    occurences.at(current_word) -= 1;
                    middle += 2;
                    output += 2;
                }
                if(it->second >= 2){
                    occurences.at(current_word) -= 2;
                    output += 4;
                }
            }else{
                std::string reversed = current_word;
                reverse(reversed.begin(), reversed.end());
                auto reverse_it = occurences.find(reversed);
                if (reverse_it != occurences.end()){ // if there is a reverse
                    if(reverse_it->second > 0 && it->second > 0){
                        occurences.at(reversed) -= 1;
                        occurences.at(current_word) -= 1;
                        output += 4;
                    }
                }
            }  
        }
        return output;
    }
};