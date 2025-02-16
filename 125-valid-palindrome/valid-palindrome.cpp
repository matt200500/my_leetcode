class Solution {
public:
    bool isPalindrome(string s) {
        auto left_pointer = s.begin();
        auto right_pointer = --s.end();
        while (left_pointer <= right_pointer && !std::isalnum(*left_pointer)) {
            ++left_pointer;
        }
        while (right_pointer >= left_pointer && !std::isalnum(*right_pointer)) {
            --right_pointer;
        }

        while(left_pointer <= right_pointer){
            cout << "we enter\n";
            while (left_pointer < right_pointer && !std::isalnum(*left_pointer)) {
                ++left_pointer;
            }
            while (left_pointer < right_pointer && !std::isalnum(*right_pointer)) {
                --right_pointer;
            }

            if (std::tolower(*right_pointer) != std::tolower(*left_pointer)){
                return false;
            }
            ++left_pointer;
            --right_pointer;
        }
        return true;
    }
};
