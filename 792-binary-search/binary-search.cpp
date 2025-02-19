class Solution {
public:
    int search(vector<int>& nums, int target) {
        return binarysearch(nums.begin(), nums.end(), target, nums.begin());
    }

private:
    int binarysearch(std::vector<int>::iterator start, std::vector<int>::iterator end, int target, std::vector<int>::iterator begin){
        int size = std::distance(start,end);
        if (size <= 0) return -1;  

        auto middle = start + size/ 2;
        if (*middle == target){
            return std::distance(begin,middle);
        }

        int output1 = binarysearch(start, middle, target, begin);
        if (output1 != -1){
            return output1;
        }
        return binarysearch(middle+1, end, target, begin);

    }
};
