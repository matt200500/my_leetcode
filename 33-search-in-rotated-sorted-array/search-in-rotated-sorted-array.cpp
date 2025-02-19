class Solution {
public:
    int search(vector<int>& nums, int target) {
        return binary_search(0, nums.size() -1, nums, target);
    }

private:
    int binary_search(int left, int right, vector<int> &nums, int target){
        int middle = left + (right - left) /2;
        if (right <= left){
            if (nums[left] == target){
                return left;
            }else{
                return -1;
            }
        }
        if (nums[middle] == target){
            return middle;
        }
        cout <<nums[middle];
        if (nums[middle] >= nums[left]){ // left side of mid sorted
            if (target < nums[middle] && target >= nums[left]){
                return binary_search(left, middle -1, nums, target);
            }else{
                return binary_search(middle+1, right, nums, target);
            }
        }
        if(target > nums[middle] && target <= nums[right]){
            return binary_search(middle+1, right, nums, target);
        }else{
            return binary_search(left, middle -1, nums, target);
        }
    }
};
