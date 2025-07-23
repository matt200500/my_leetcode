class Solution {
public:

    static bool comparison (int a, int b){
        return a > b;
    }

    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        std::stack<double> fleets;
        std::map<int, int> speed_mapping;
        for (int i = 0; i < position.size(); ++i){
           speed_mapping.insert({position[i], speed[i]}); 
        }
        std::sort(position.begin(), position.end(), comparison);
        for (int i = 0; i < position.size(); ++i){
            double time = static_cast<double>((target - position[i])) / speed_mapping[position[i]];
            if (!fleets.empty()){
                if (time > fleets.top()){
                    fleets.push(time);
                }
            }else{
                fleets.push(time);
            }
        }
        return fleets.size();
    }
};
