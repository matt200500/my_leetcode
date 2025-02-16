class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int,int> numbers;
        for (int i = 0; i < nums.size(); ++i){
            ++numbers[nums[i]];
        }
        std::vector<vector<int>> bucket(nums.size() + 1);
        for (auto it = numbers.begin(); it != numbers.end(); ++it){
            bucket[it->second].push_back(it->first);
        }
        std::vector<int> output;
        
        for (int i = bucket.size() -1; i >= 0; --i){
            for (int y = 0; y < bucket[i].size(); ++y){
                if (k == 0){
                    return output;
                }
                output.push_back(bucket[i][y]);
                --k;
            }
        }
        return output;
    }
};
