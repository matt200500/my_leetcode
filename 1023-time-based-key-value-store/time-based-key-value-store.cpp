class TimeMap {
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        timeMap[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        auto &records = timeMap[key];
        if (records.empty()) return "";
        return binary_search(records, timestamp);
    }
private:
    unordered_map<string, vector<pair<int, string>>> timeMap;

    std::string binary_search(vector<pair<int, string>> &records, int target){
        int start = 0, end = records.size() - 1;
        int next_largest = -1;

        while(start <= end){
            int middle = start + (end - start) /2;

            if(records[middle].first == target){
                return records[middle].second;
            }
            if(records[middle].first < target){
                next_largest = middle;
                start = middle+1;
            }else{
                end = middle -1;
            }
        }

        if (next_largest != -1){
            return records[next_largest].second;
        }else{
            return "";
        }
    }
};
