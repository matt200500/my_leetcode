class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0;
        int end = 0;

        for (int i = 0; i < s.length(); ++i){
            int left_char = i-1;
            int right_char = i+1;
            bool all_same = true;

            while(right_char < s.length()){
                if(left_char >= 0 && s[left_char] == s[right_char]){
                    if (s[left_char] != s[i]){
                        all_same = false;
                    }
                    if((right_char - left_char + 1) > (end - start +1)){
                        start = left_char;
                        end = right_char;
                    }

                    --left_char;
                    ++right_char;

                } else if ( all_same == true && s[right_char] == s[i]){

                    if((right_char - i + 1) > (end - start +1)){
                        start = i;
                        end = right_char;
                    }
                    ++right_char;
                }
                else{
                    break;
                }
            }
        }
        return s.substr(start, end - start + 1);
    }
};