class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = 1e9+10;
        while(low <= high){
            int mid = low + (high - low)/2;
            int time = 0;
            for(int i = 0; i < piles.size(); i++){
                time += (ceil(1.0 * piles[i]/mid));
            }
            if(time > h){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return low;
    }
};