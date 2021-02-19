class Solution {
public:
    int mySqrt(int x) {
        if(x==1) return 1;
        int start = 0;
        int end = (x/2);
        int res = 0;
        while(start<=end){
            double mid = start + (end - start)/2;  
            if(mid <= x/mid) {
                res = mid;
                start = mid +1;    
            }
            else end = mid -1;
        }
        return res;
    }
};
//O(logn)