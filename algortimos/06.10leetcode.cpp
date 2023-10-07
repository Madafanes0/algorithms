class Solution {
public:
    int integerBreak(int n) {
        int c3=n/3;
        int c3res=pow(3,c3);
        if(n<4){
            return n-1;
        }
        if(n%3==1){
            c3res/=3;
            c3res*=4;
        }
        else if(n%3==2){
            c3res*=2;
        }
    return c3res;
    }
};