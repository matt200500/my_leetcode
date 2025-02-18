class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()){
            return false;
        }
        sort(s1.begin(), s1.end());
        int left_pointer = 0;
        for (int i = s1.size()-1; i < s2.size(); ++i){
            string substring = s2.substr(left_pointer, s1.size());
            sort(substring.begin(),substring.end());
            if(s1 == substring){
                return true;
            }
            ++left_pointer;
        }
        return false;
    }
};
