class Solution {
public:
    double myPow(double x, int n) {
        long exp = n;

        if(n<0){
            exp = -exp;
        }

        double ans = solve(x,exp);

        if(n<0) return 1.0 / ans;
        
        return ans;
    }

    double solve(double x, long long n){
        if(n==0){
            return 1.0;
        }

        double half = solve(x , n/2);

        if(n%2==0){
            return half*half;
        }

        return x*half*half;
    }
};