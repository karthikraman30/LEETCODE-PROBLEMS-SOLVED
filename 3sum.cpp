class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        int size = nums.size();
        for (int i = 0; i < size - 2; i++) {
            // Skip duplicates for i
            if (i > 0 && nums[i] == nums[i-1]) continue;
            
            int low = i + 1, high = size - 1;
            while (low < high) {
                int sum = nums[i] + nums[low] + nums[high];
                if (sum == 0) {
                    result.push_back({nums[i], nums[low], nums[high]});
                    
                    // Skip duplicates for low and high
                    while (low < high && nums[low] == nums[low+1]) low++;
                    while (low < high && nums[high] == nums[high-1]) high--;
                    
                    low++;
                    high--;
                }
                else if (sum < 0) {
                    low++;
                }
                else {
                    high--;
                }
            }
        }
        return result;
    }
};
/*class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());
        int size = nums.size();
        for(int i=0;i<size;i++){
            int low = i+1,high = size-1;
            while(low<high){
                int sum = nums[i]+nums[low]+nums[high];
                if(sum == 0){
                    vector<int> temp_arr;
                    temp_arr.push_back(nums[i]);
                    temp_arr.push_back(nums[low]);
                    temp_arr.push_back(nums[high]);
                    result.push_back(temp_arr);
                }
                else if(sum < 0){
                    low++;
                }
                else{
                    high--;
                }
            }
        }
        return result;
    }
};


1. sort
ex: nums = [-1,0,1,2,-1,-4]
3
0
-4.    -1.    -1.          0.          1.     2.
                                       START.   MIDEND

START + MID + END -> 0 + 1 + 2

*/