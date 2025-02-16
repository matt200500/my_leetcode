class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_set<int> numbers(nums.begin(),nums.end());
        int output = 0;
        
        for (int i = 0; i < nums.size(); ++i){
            if (numbers.find(nums[i]) != numbers.end()){
                int new_output = 1;
                int current_number = nums[i];
                numbers.erase(current_number);
                while(numbers.find(++current_number) != numbers.end()){  
                    ++new_output;
                    ++current_number;
                    numbers.erase(--current_number); 
                }

                current_number = nums[i];
                while(numbers.find(current_number-1) != numbers.end()){  
                    ++new_output;
                    --current_number;
                    numbers.erase(current_number); 
                }


                output = max(output, new_output);
            }
        }
        return output;
    }
};