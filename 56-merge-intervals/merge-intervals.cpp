class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end());

        vector<vector<int>> output;
        int main_start, main_end;
        
        for (int i = 0; i < intervals.size();){
            main_start = intervals[i][0];
            main_end = intervals [i][1];
            bool entered_loop = false;
            while(i<intervals.size() && main_end>= intervals[i][0]){
                main_end = max(main_end,intervals[i][1]);
                ++i;
                entered_loop = true;
            }
            vector<int> newAns = {main_start,main_end};
            output.push_back(newAns);
            if(!entered_loop){
            ++i;
            }
        }
        return output;
    }
};