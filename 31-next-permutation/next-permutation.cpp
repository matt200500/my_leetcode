class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int pivot = -1;
        for (int i = nums.size() -2; i >= 0; i--){
            if (nums[i] < nums[i+1]){
                pivot = i;
                break;
            }
        } 
        int smallest_index = pivot + 1;

        if (pivot != -1){
            for (int i = nums.size() -1; i > pivot; i--){
                if (nums[i] > nums[pivot]){
                    smallest_index = i;
                    break;
                }
            }
            std::swap(nums[pivot], nums[smallest_index]); // Swap pivot with the found element
            std::reverse(nums.begin() + (pivot + 1), nums.end());
        }else{
            std::reverse(nums.begin(), nums.end());
        }
    }
};