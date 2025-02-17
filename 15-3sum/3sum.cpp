class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        std::vector<vector<int>> output;
        int prev_character = 0;
         for (int i = 0; i < nums.size(); ++i) {
            // Skip duplicates for first element
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            if (nums[i] > 0) break; // No valid triplet if first number > 0
            
            twoSum(nums, i, output);
        }
        return output;
    }

private:
    void twoSum(vector<int>& nums, int index, vector<vector<int>>& output) {
        int left = index + 1, right = nums.size() - 1;
        while (left < right) {
            int sum = nums[index] + nums[left] + nums[right];

            if (sum > 0) {
                --right;
            } else if (sum < 0) {
                ++left;
            } else {
                output.push_back({nums[index], nums[left], nums[right]});
                while (left < right && nums[left] == nums[left + 1]) ++left;
                while (left < right && nums[right] == nums[right - 1]) --right;
                ++left;
                --right;
            }
        }
    }
};
