class Solution {
public:
    int trap(vector<int>& height) {
        int left_pointer = 0;
        int right_pointer = 0;
        int output = 0;
        if(height.size() < 3){
            return 0;
        }
        while(left_pointer < height.size()){
            while (left_pointer +1 < height.size() && height[left_pointer] <= height[left_pointer + 1]) {
                ++left_pointer;
            }
            if (left_pointer + 1 >= height.size()) {
                return output; // Prevents out-of-bounds access
            }
            right_pointer = left_pointer + 1;
            int max_right = right_pointer;

            while(right_pointer < height.size()){
                if (height[right_pointer] >= height[left_pointer]) {
                    max_right = right_pointer;
                    break;
                }
                if (height[right_pointer] > height[max_right]) {
                    max_right = right_pointer;
                }
                ++right_pointer;
            }
            
            for (int i = left_pointer+1; i < max_right; ++i){
                output += min(height[left_pointer], height[max_right]) - height[i];
            }
            left_pointer = max_right;
        }
        return output;
    }
};
