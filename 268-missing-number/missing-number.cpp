class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int total = 0;
        int factorial = nums.size();
        for (int i = 0; i < nums.size(); ++i){
            total += nums[i];
            factorial += i;
        }
        return factorial - total;
    }
};