class Solution {
public:
    int count(vector<int>& position, int d){
        int res = 1;
        int start = position[0];
        for(auto p: position){
            if(p-start >= d){
                res++;
                start = p;
            }
        }
        return res;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int start = 0;
        int end = position.back()-position.front();
        while(start <= end){
            int distance = start + (end - start)/2;
            if(count(position,distance) >= m){
                start = distance + 1; 
            }
            else{
                end = distance-1;
            }
        }
        return start-1;
    }
};