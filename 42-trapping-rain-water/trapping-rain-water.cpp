class Solution {
public:
    int trap(vector<int>& height) {
        int left_pointer = 0;
        int right_pointer = height.size() -1;
        int max_left = height[left_pointer];
        int max_right = height[right_pointer];
        int output = 0;
        while (left_pointer < right_pointer){
            if (max_left <= max_right){
                int current_output = (max_left - height[++left_pointer]);
                if(current_output > 0){
                    output += current_output;
                }
                if(height[left_pointer] > max_left){
                    max_left = height[left_pointer];
                }
            }else{
                int current_output = (max_right - height[--right_pointer]);
                if(current_output > 0){
                    output += current_output;
                }
                if(height[right_pointer] > max_right){
                    max_right = height[right_pointer];

                }
            }
        }
        return output;
    }
};
