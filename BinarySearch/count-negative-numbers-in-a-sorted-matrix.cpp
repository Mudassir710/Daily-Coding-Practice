class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int ROW = grid.size();
        int COL = (grid.size()>0)?grid[0].size():0;
        int count = 0;
        
        for(int r=0; r<ROW; ++r){
            int start = 0;
            int end = COL-1;
            while(start<=end){
                int mid = start +(end-start)/2;
                if(grid[r][mid] >= 0) start = mid +1;
                else {
                    count+=end-mid+1;
                    end = mid - 1;
                }
            }
        }
     
        return count;
    }
};

// O(ROWlog(COL))