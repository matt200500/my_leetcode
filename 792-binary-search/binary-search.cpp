class Solution {
public:
    int search(vector<int>& nums, int target) {
        return binarysearch(0, nums.size() - 1, target, nums);
    }

private:
    int binarysearch(int start, int end, int target, vector<int>& nums){
        if (nums.size() <= 0 || start > end) return -1;  

        int middle = start + (end - start) / 2;
        if (nums[middle] == target){
            return middle;
        }

        if (nums[middle] > target){
            return binarysearch(start, middle - 1, target, nums);
        }else{
            return binarysearch(middle + 1, end, target, nums);
        }
    }
};
