class Solution {
public:
    int maximumGap(vector<int>& nums) {

        if (nums.size() <= 1){
            return 0;
        }
        
        int smallest = INT_MAX;
        int largest = INT_MIN;

        for (int i =0; i < nums.size();++i){
            if(nums[i] < smallest){
                smallest = nums[i];
            }
            if (nums[i] > largest){
                largest = nums[i];
            }
        }
        int n = nums.size();
        int bucket_size = (largest - smallest + n - 2) / (n - 1);
        if (bucket_size == 0){
            return 0;
        }
        int number_buckets = (largest - smallest) / bucket_size + 1;

        vector<int> bucket_minimum(number_buckets, INT_MAX);
        vector<int> bucket_max(number_buckets, INT_MIN);
        vector<bool> used_buckets(number_buckets, false);

        for (int i =0; i < nums.size(); ++i){
            int current_index = (nums[i] - smallest) / bucket_size;
            bucket_max[current_index] = std::max(bucket_max[current_index], nums[i]);
            bucket_minimum[current_index] = min(bucket_minimum[current_index], nums[i]);
            used_buckets[current_index] = true;
        }

        int current_max = 0;
        int previous_max = smallest;

        for (int i = 0; i < number_buckets; ++i){
            if (!(used_buckets[i])){
                continue;
            }
            current_max = std::max(current_max, bucket_minimum[i] - previous_max);
            previous_max = bucket_max[i];
        }
        return current_max;
    }
};
