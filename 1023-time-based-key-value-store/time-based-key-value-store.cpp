class TimeMap {
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        timeMap[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        return binary_search(key, 0, timeMap[key].size() -1, timestamp, -1);
    }
private:
    unordered_map<string, vector<pair<int, string>>> timeMap;

    std::string binary_search(string key, int start, int end, int target, int next_largest){
        int middle = start + (end - start) /2;
        if (timeMap[key].size() == 0){
            return "";
        }
        if (start > end){
            if (next_largest != -1){
                return timeMap[key][next_largest].second;
            }else{
                return "";
            }
        }
        if(timeMap[key][middle].first == target){
            return timeMap[key][middle].second;
        }
        if(timeMap[key][middle].first < target){
            return binary_search(key, middle+1, end, target, middle);
        }else{
            return binary_search(key, start, middle -1, target, next_largest);
        }
    }
};
