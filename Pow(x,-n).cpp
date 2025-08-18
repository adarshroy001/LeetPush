class Solution {
public:
    double myPow(double x, int n) {

        long long N = n;
        if(N==0) return 1;
        if(N<0){
            x = 1/x ;
            N = -N;
        // The range of int in C++ is [-2,147,483,648, 2,147,483,647].
        //If n = -2147483648 (i.e. INT_MIN), negating it (-n) overflows, because the positive counterpart 2147483648 does not fit in an int.
        }
        if(N%2 ==0){
           return myPow(x*x,N/2) ; 
        }
        else{
           return x*myPow(x*x,N/2) ; 
        }
    }
};