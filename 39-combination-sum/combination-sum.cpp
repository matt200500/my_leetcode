class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        std::vector<vector<int>> output;
        std::vector<int> current_order;
        depth_first_search(0, target, 0, current_order, nums, output);
        return output;
    }

private:
    void depth_first_search(int root, int target, int current_total, vector<int> current_order, const vector<int>& nums, vector<vector<int>>& output){
        if (root >= nums.size()){
            return;
        }
        if (current_total == target){
            output.push_back(current_order);
            return;
        }

        if (current_total + nums[root] <= target){ // adding root
            current_order.push_back(nums[root]);
            int new_total = current_total +  nums[root];
            depth_first_search(root, target, new_total, current_order, nums, output);
            current_order.pop_back();
        }

        depth_first_search(root+1, target, current_total, current_order, nums, output);
    }
};
