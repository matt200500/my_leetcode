class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for (int i = 0 ; i < nums.size(); ++i){
            int number = abs(nums[i]);
            if (nums[number-1] < 0){
                return number;
            }
            nums[number-1] = nums[number-1] * -1;
        }
        return 0; 
    }
};
