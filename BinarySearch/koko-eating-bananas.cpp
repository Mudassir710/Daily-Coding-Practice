class Solution {
public:
    bool isValid(vector<int>& piles, int H, int mid){
        int hours = 0;
        for(auto p: piles){
            hours += (p%mid==0)?(p/mid):(p/mid +1);
           if(hours > H) return false;
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int H) {
        int min = 1;
        int max = INT_MIN;
        for(auto p : piles)
            if(p > max) max = p;
        int res = -1;
        while(min <= max){
            int mid = min + (max - min)/2;
            if(isValid(piles, H, mid)){
                res = mid;
                max = mid -1;
            }
            else min = mid+1;
        }
        return res;
    }
};