#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int a = 0;
        int b = numbers.size()-1;
        vector<int> res{};
        while(a<b){
            if(numbers[a]+numbers[b] == target){
                res.push_back(a+1);
                res.push_back(b+1);
                break;
            }else if(numbers[a]+numbers[b] < target){
                a++;
            }else{
                b--;
            }
        }
        return res;
    }
};
