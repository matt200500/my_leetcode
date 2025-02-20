class LRUCache {
public:
    LRUCache(int capacity) {
        max = capacity;
    }
    
    int get(int key) {
        auto it = cache.find(key);
        if (it != cache.end()) {
            cacheorder.splice(cacheorder.end(), cacheorder, it->second);
            return it->second->second;
        }
        return -1;
    }
    
    void put(int key, int value) {
        auto it = cache.find(key);
        if (it != cache.end()) {
            it->second->second = value;
            cacheorder.splice(cacheorder.end(), cacheorder, it->second);
        } else {
            if (cacheorder.size() == max) {
                auto removed_item = cacheorder.front();
                cache.erase(removed_item.first);
                cacheorder.pop_front();
            }
            cacheorder.push_back({key, value});
            cache[key] = --cacheorder.end();
        }
    }
private:
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> cache;
    std::list<std::pair<int, int>> cacheorder; 
    int max = 0;
};