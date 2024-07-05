#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    bool isPalindrome(int x) {
        long long original = x;
        long long remainder;
        long long rev = 0;
        while(x>0){
            remainder = x%10;
            rev = (rev*10) + remainder;
            x/=10;
            
        }

        if(rev == original){
            return true;
        }
        else{
            return false;
        }
    }
};
