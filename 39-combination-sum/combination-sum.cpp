class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        std::vector<vector<int>> output;
        std::vector<int> current_order;
        depth_first_search(0, target, current_order, nums, output);
        return output;
    }

private:
    void depth_first_search(int root, int target, vector<int>& current_order, const vector<int>& nums, vector<vector<int>>& output){
        if (root >= nums.size()){
            return;
        }
        if (target == 0){
            output.push_back(current_order);
            return;
        }

        if (target - nums[root] >= 0){ // adding root
            current_order.push_back(nums[root]);
            depth_first_search(root, target - nums[root], current_order, nums, output);
            current_order.pop_back();
        }

        depth_first_search(root+1, target, current_order, nums, output);
    }
};
