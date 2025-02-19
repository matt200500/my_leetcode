class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int largest = 0;
        for (int i = 0; i < piles.size(); ++i){
            if (piles[i] > largest){
                largest = piles[i];
            }
        }
        return binary_search(1, largest, piles, h);
    }

private:
    int binary_search(int start, int end, vector<int>& piles, int h){
        if (end <= start){
            return start;
        }
        int middle = start + (end - start) /2;

        int time = 0;
        for(int i = 0; i < piles.size(); ++i){
            time += (piles[i] + middle - 1) / middle;            
        }
        if(time <= h){ // too much time
            return binary_search(start, middle, piles, h);
        }else{
            return binary_search(middle + 1, end, piles, h);
        }
    }
};
