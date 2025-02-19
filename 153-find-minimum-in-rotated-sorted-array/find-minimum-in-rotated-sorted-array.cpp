class Solution {
public:
    int findMin(vector<int> &nums) {
        return binary_search(0, nums.size() -1, nums);
    }

private:
    int binary_search(int left, int right, vector<int> &nums){
        int middle = left + (right - left) /2;
        if (right <= left){
            return nums[left];
        }
        if (nums[middle] >= nums[left]){ // left side of mid sorted
            if (nums[left] > nums[right]){
                return binary_search(middle+1, right, nums);
            }else{
                return binary_search(left, middle, nums);
            }
        }
        return binary_search(left, middle, nums);
    }
};
