class Solution {
public:
    double solve(double x, long long N){
        if(N == 0) return 1.0;

        double half = solve(x, N / 2);
        if(N % 2 == 0)
            return half * half;
        return x * half * half;

        /* n = 6, x = 2
        2^7;
        half = 2^3;
        return half * half;
        return 2 * 2^3 * 2^3;
        */
    }
    double myPow(double x, int n) {
        if(x == 0 || x == 1)
            return x;
        if(x == -1){
            if(n % 2 == 0) return 1;
            else return -1;
        }

        long long N = n;

        if(n < 0){
            N = -N;
        }

        // 2^(-3) = (1/2)^3

        double ans = solve(x, N);

        if(n < 0) return 1.0 / ans;
        return ans;
    }
};