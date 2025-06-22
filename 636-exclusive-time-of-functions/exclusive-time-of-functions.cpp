class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        std::vector<int> result(n, 0);
        std::stack<int> running_programs;
        int previous_time = 0;

        for(int i = 0; i < logs.size(); ++i){
            std::stringstream log_stream(logs[i]);
            std::vector<string> parts;
            std::string part;

            getline(log_stream, part, ':'); parts.push_back(part);
            getline(log_stream, part, ':'); parts.push_back(part);
            getline(log_stream, part, ':'); parts.push_back(part);

            int id_number = std::stoi(parts[0]);
            std::string call = parts[1];
            int timestamp = std::stoi(parts[2]);

            if (call == "start"){
                if(!running_programs.empty()){
                    result[running_programs.top()] += timestamp - previous_time;
                }
                running_programs.push(id_number);
                previous_time = timestamp;
            } else {
                result[running_programs.top()] += timestamp - previous_time + 1;
                running_programs.pop();
                previous_time = timestamp + 1;
            }
        }

        return result;
    }
};