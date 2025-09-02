class Solution {
public:
    bool isStrictlyDecreasing(vector<int>& nums, int start){
        // checks if everyhing from start to end of nums is striclty decremented
        while(start <nums.size()-1){
            if(nums[start]<nums[start+1]){
                return false;
            }
            start++;
        }
        return true;
    }
    void nextPermutation(vector<int>& nums) {
        if(nums.size()==1){
            return;
        }

        int start = nums.size()-2;
        int end = nums.size() -1;

        while(start>=0 && isStrictlyDecreasing(nums,start)){
            --start;
        }
        if(start<0){
            std::sort(nums.begin(), nums.end());
            return;
        }

        int firstDigitInSubArr = nums[start];
        std::sort(nums.begin() + start, nums.end());

        int i = start;
        while( i < nums.size()){
            if(nums[i]>firstDigitInSubArr){
                break;
            } 
            ++i;
        }
    
        int temp = nums[i];
        nums[i] = nums[start];
        nums[start] = temp;
        ++start;
        std::sort(nums.begin() + start, nums.end());
    }
};