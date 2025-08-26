class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        std::vector<int> temp(nums.size());
        split(nums, 0, nums.size() -1);
        return nums;
    }

    void split(vector<int>& nums, int start, int end) {
        // base case, if they cannot be split further, return
        if (end-start == 0){
            return;
        }
        if(end-start==1){ // if nums contains two numbers
            if(nums[start]>nums[end]){
                int temp = nums[end];
                nums[end] = nums[start];
                nums[start] = temp;
            }
            return;
        }

        int middle = floor((end-start)/2) + start;
        
        split(nums, start, middle);
        split(nums, middle+1, end);
        int left_size = middle - start + 1;
        int right_size = end - middle;

        vector<int> leftArr(left_size);
        for(int i = 0; i < (left_size);++i){
            leftArr[i] = nums[i + start];
        }

        vector<int> rightArr(right_size);
        for(int i = 0; i < right_size;++i){
            rightArr[i] = nums[i + middle + 1];
        }
        
        
        merge(nums, start,leftArr, rightArr);
    }

    void merge(vector<int>& nums, int currIdx, vector<int>& left, vector<int>& right){
        int left_1 = 0;
        int right_1 = left.size()-1;

        int left_2 = 0;
        int right_2 = right.size()-1;

        while(left_1 <= right_1 && left_2 <= right_2){
            int leftNum = left[left_1];
            int rightNum = right[left_2];

            if(leftNum>=rightNum){
                nums[currIdx] = rightNum;
                ++left_2;
            }
            else{
                nums[currIdx] = leftNum;
                ++left_1;
            }
            ++currIdx;
        }

        // while arr1
        while(left_1<= right_1){
            int leftNum = left[left_1];
            nums[currIdx] = leftNum;
            ++left_1;           
            ++currIdx;
        }
        // while arr2

        while(left_2<= right_2){
            int leftNum = right[left_2];
            nums[currIdx] = leftNum;
            ++left_2;           
            ++currIdx;
        }
    }

};
