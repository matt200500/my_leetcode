class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int,int> numbers;
        std::vector<int> output;
        for (int i = 0; i < nums.size();++i){
            int difference = target - nums[i];
            auto difference_it = numbers.find(difference);
            if (difference_it != numbers.end()){
                output.push_back(difference_it->second);
                output.push_back(i);
                return output;
            }
            auto it = numbers.find(nums[i]);
            if (it == numbers.end()){
                numbers[nums[i]] = i;
            }
        }
        return output;  
    }
};