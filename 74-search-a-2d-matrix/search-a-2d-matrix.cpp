class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (int i = 0; i < matrix.size(); ++i){
            if(matrix[i][matrix[i].size() - 1] == target){
                return true;
            }else if (matrix[i][matrix[i].size() - 1] > target){
                return binarysearch(0, matrix[i].size() - 1, target, matrix[i]);
            }
        }
        return false;
    }
    private:
    bool binarysearch(int start, int end, int target, vector<int>& nums){
        if (nums.size() <= 0 || start > end) return false;  

        int middle = start + (end - start) / 2;
        if (nums[middle] == target){
            return true;
        }

        if (nums[middle] > target){
            return binarysearch(start, middle - 1, target, nums);
        }else{
            return binarysearch(middle + 1, end, target, nums);
        }
    }
};
