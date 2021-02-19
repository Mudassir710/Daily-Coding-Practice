class Solution {
public:
    bool isValid(vector<int>& weights, int D, int max){
        int sum = 0;
        int days = 0;
        for(auto w: weights){
            if(sum + w > max) {
                sum = 0;
                days++;
            }
            sum+=w;
        }
        ++days;
        if(days>D) 
            return false;
        return true;
    }
    int shipWithinDays(vector<int>& weights, int D) {
        
        int sum =0,start=-1;
        for(auto w: weights){
            if(w>start) start = w;
            sum+=w;  
        } 
        int end = sum, ans = -1;
        while(start <= end){
            int mid = start + (end - start)/2;
            if(isValid(weights, D, mid)){
                ans = mid;
                end = mid-1;
            }
            else start = mid+1;
        }
        return ans;
    }
};
