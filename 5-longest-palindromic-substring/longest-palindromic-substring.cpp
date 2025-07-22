class Solution {
public:
    string longestPalindrome(string s) {
        std::string longest_palindrome;
        longest_palindrome = s[0];
        for (int i = 0; i < s.length(); ++i){
            std::string current_palindrome;
            current_palindrome = s[i];
            int left_char = i-1;
            int right_char = i+1;
            bool all_same = true;
            while(right_char < s.length()){
                if(left_char >= 0 && s[left_char] == s[right_char]){
                    if (s[left_char] != s[i]){
                        all_same = false;
                    }
                    current_palindrome = s.substr(left_char, right_char - left_char + 1);
                    if(current_palindrome.length() > longest_palindrome.length()){
                        longest_palindrome = current_palindrome;
                    }

                    --left_char;
                    ++right_char;

                } else if ( all_same == true && s[right_char] == s[i]){
                    current_palindrome = s.substr(i, right_char - i + 1);

                    if(current_palindrome.length() > longest_palindrome.length()){
                        longest_palindrome = current_palindrome;
                    }
                    ++right_char;
                }
                else{
                    break;
                }
            }
        }
        return longest_palindrome;
    }
};