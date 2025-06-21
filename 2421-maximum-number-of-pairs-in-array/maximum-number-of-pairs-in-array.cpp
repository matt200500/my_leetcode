class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        std::unordered_set<int> pairs;
        std::vector<int> answer;
        int total_pairs = 0;
        for (int i = 0; i < nums.size(); ++i){
            if(pairs.find(nums[i]) != pairs.end()){ 
                ++total_pairs;
                pairs.erase(nums[i]);
            }else{
                pairs.insert(nums[i]);
            }

        }
        answer.push_back(total_pairs);
        answer.push_back(nums.size() - total_pairs *2);
        return answer;
    }
};