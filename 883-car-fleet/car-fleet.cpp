class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        std::stack<double> fleets;
        std::map<int, int, std::greater<int>> speed_mapping;
        for (int i = 0; i < position.size(); ++i){
           speed_mapping.insert({position[i], speed[i]}); 
        }
        for (auto key : speed_mapping){
            double time = static_cast<double>((target - key.first)) / key.second;
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
