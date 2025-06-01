class Solution {
public:
    long long distributeCandies(int n, int limit) {
        //n/3 with limit
        long long result=0;
        for(int i=0;i<=min(limit,n);i++)
        {
            if(n-i>2*limit)
            continue;
            result+=min(n-i,limit)-max(0,n-i-limit)+1;
        }
        return result;
    }
};