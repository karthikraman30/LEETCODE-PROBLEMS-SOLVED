class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        int slow = 1;
        for(int fast = 1;fast<nums.size();fast++){
            if(nums[fast] != nums[slow-1]){
                    nums[slow] = nums[fast];
                    slow+=1;
            }
        }
        return slow;
    }
};
