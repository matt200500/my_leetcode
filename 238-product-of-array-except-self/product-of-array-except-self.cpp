class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int total = 1;
        int contains_0 = 0;
        std::vector<int> output;
        for (int i = 0; i < nums.size(); ++i){
            if (nums[i] == 0){
                ++contains_0;
            }else{
                total = total * nums[i];
            }
        }
        for (int i = 0; i < nums.size(); ++i){
            if (contains_0 >= 2){
                output.push_back(0);
            }else if (contains_0 == 1){
                if (nums[i] == 0){
                    output.push_back(total);
                }else{
                    output.push_back(0);
                }
            }else{
                output.push_back(total/nums[i]);
            }
        }
        return output;
    }
};
