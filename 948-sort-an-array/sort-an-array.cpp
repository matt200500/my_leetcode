class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
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
        
        vector<int> leftArr;
        for(int i = start;i<=middle;++i){
            leftArr.push_back(nums[i]);
        }

        vector<int> rightArr;
        for(int i = middle+1; i<=end;++i){
            rightArr.push_back(nums[i]);
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
                left_2++;
            }
            else{
                nums[currIdx] = leftNum;
                left_1++;
            }
            currIdx++;
        }

        // while arr1
        while(left_1<= right_1){
            int leftNum = left[left_1];
            nums[currIdx] = leftNum;
            left_1++;           
            currIdx++;
        }
        // while arr2

        while(left_2<= right_2){
            int leftNum = right[left_2];
            nums[currIdx] = leftNum;
            left_2++;           
            currIdx++;
        }
    }

};
