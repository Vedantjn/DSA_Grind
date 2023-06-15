class Solution{
public:

    // TC : O(exponential)
    int recSolve(int n){
        // Base case
        if(n == 0 || n == 1){
            return n;
        }

        int ans = recSolve(n-1) + recSolve(n-2);
        return ans;
    }

    // Recursion + Memoisation 
    // TC : O(n), SC : O(n) + O(n)
    int topDownSolve(int n, vector<int>& dp){
         // Base case
        if(n == 0 || n == 1){
            return n;
        }
        // Step 3 : Check if ans exists
        if(dp[n] != -1){
            return dp[n];
        }


        // Step 2 : Replace ans with dp[n]
        int dp[n] = topDownSolve(n-1, dp) + topDownSolve(n-2, dp);
        return dp;
    }

    // TC : O(n), SC : O(n) 
    int bottomUpSolve(int n){

        // Step 1 : Create dp array
        vector<int> dp(n+1, -1);

        Step 2 : Observe base case in our solution
        dp[0] = 0;
        if(n == 0) return dp[0];
        dp[1] = 1;


        // Step 3 : 
        for(int i = 2; i <= n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];
    }

    // TC : O(n) , SC : O(1)
    int spaceOptSolve(int n){
       
       int prev2 = 0;
       int prev1 = 1;
       
       int curr;

       if(n == 0) return prev2;
       if(n == 1) return prev1;

        for(int i = 2; i <= n; i++){
            curr = prev1 + prev2;
            // Shifting
            prev2 = prev1;
            prev1 = curr;
        }

        return dp[n];

    }

    int fib(int n){
        // int ans = recSolve(n);
        // return ans;

        // Step 1 : Create DP array best on range of n
        vector<int> dp(n+1, -1);
        int ans = topDownSolve(n, dp);
        return ans;

        
    }
};