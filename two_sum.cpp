#include<iostream>
#include<vector>
#include<list>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, list<int>> positions;
        for (int i = 0; i < nums.size(); i++) {
            positions[nums[i]].push_back(i);   
        }
        sort(nums.begin(), nums.end());
        int left = 0;
        int right = nums.size() - 1;
        vector<int> result;
        while (left < right) {
            if (nums[left] + nums[right] == target) {
                result.push_back(positions[nums[left]].front());
                positions[nums[left]].pop_front();
                result.push_back(positions[nums[right]].front());
                positions[nums[right]].pop_front();
                break;
            } else if (nums[left] + nums[right] < target) {
                left++;
            } else {
                right--;
            }
        }
        return result;
    }
};