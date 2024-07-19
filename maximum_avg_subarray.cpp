/*
You are given an integer array nums consisting of n elements, and an integer k.

Find a contiguous subarray whose length is equal to k that has the maximum average value and return this value. Any answer with a calculation error less than 10-5 will be accepted.

 

Example 1:

Input: nums = [1,12,-5,-6,50,3], k = 4
Output: 12.75000
Explanation: Maximum average is (12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75
Example 2:

Input: nums = [5], k = 1
Output: 5.00000
 

Constraints:

n == nums.length
1 <= k <= n <= 105
-104 <= nums[i] <= 104

*/



#include <iostream>
using namespace std;


float max_avg_sub(int arr[], int n, int k) {
    float window_sum = 0;
    for(int i = 0; i < k; i++) {
        window_sum += arr[i];
    }

    float max_avg = window_sum / k;

    for (int i = k; i < n; i++) {
        window_sum += arr[i] - arr[i - k];
        float current_avg = window_sum / k;
        max_avg = max(max_avg, current_avg);
    }
    return max_avg;
}


int main(){
    int arr[] = {1,12,-5,-6,50,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 4;
    float result = max_avg_sub(arr,n,k);
    result = round(result * 100000.0) / 100000.0;
    cout<<(result)<<endl;
    return 0;
}