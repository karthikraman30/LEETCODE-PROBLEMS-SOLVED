#include <iostream>
#include<vector>

using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        cout<<"Started";
        for(auto i:nums){
            cout << i << ',';
        }
        cout <<endl;
        vector<vector<int>> result;
        int start = 0, end = nums.size() - 1, mid = (start + end) / 2;
        cout <<" Calculated S,M,E" << start<<", " << mid<<", " << end << endl;
        int iter =0 ;
        while (start < end) {
            iter ++;
            int compute = nums[start] + nums[mid] + nums[end];
            cout << "Try : "<< iter << " with index : " << start<<", " << mid<<", " << end << endl;
            cout << "Compute : "<< compute << endl;
            if (compute == 0) {
                vector<int> temp_arr;
                temp_arr.push_back(nums[start]);
                temp_arr.push_back(nums[mid]);
                temp_arr.push_back(nums[end]);
                result.push_back(temp_arr);
                start++;
            } else if (compute < 0) {
                start++;
                if (start == mid) {
                    mid++;
                }
                if (mid == end) {
                    cout << "Moved : "<< iter << " with index : " << start<<", " << mid<<", " << end << endl;
                    break;
                }
            } else {
                end--;
                if (end == mid) {
                    mid--;
                }
                if (start == mid) {
                    cout << "Moved : "<< iter << " with index : " << start<<", " << mid<<", " << end << endl;
                    break;
                }
            }
            cout << "Moved : "<< iter << " with index : " << start<<", " << mid<<", " << end << endl;
        }
        return result;
    }
};

int main(){
    Solution s;
    vector<int> test_case = {-1,0,1,2,-1,-4};
    vector<vector<int>> result = s.threeSum(test_case);
    for( auto value: result){
        cout << "Case : ";
        for(auto index:value){
            cout << index << ",";
        }
        cout <<endl;
    }
    return 0;
}

