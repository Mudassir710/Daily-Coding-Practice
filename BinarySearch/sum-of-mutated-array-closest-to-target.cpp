class Solution {
public:
    int diff = INT_MAX;
    int findBestValue(vector<int>& arr, int target) {
        int max = INT_MIN;
        long long  sum = 0;
        for(auto val: arr){
            if(max < val) max = val;
            sum+=val;
        }
        if(target >= sum) return max;
        int res = -1;
        int min = 0; 
        while(min <= max){
            int mid = min + (max - min)/2;
            sum = 0;
            for(auto val: arr){
                sum += (val > mid) ? mid: val;
            }
            if(diff > abs(sum - target)){
                res = mid;
                diff = abs(sum - target);
            }
             if(abs(sum-target)==diff)
                res=(res > mid) ? mid : res;
            if(sum > target) max = mid -1;
            else if(sum == target) break;
            else min = mid +1;
        }
        return res;
    }
};