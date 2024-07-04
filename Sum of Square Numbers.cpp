class Solution {
public:
    bool judgeSquareSum(int c) {
        if(c<0){
            return false;
        }
        long long a = 0;
        long long b = sqrt(c);
        while(a<=b){
            if((a*a+b*b) == c){
                return true;
            }else if((a*a+b*b)<c){
                a++;
            }else{
                b--;
            }
        }
        return false;
    }
};
