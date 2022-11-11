class Solution {
public:
    // int SolveRec(vector<int>& coins, int amount){
    //     // base case
    //     if(amount == 0){
    //         return 0;
    //     }
    //     if(amount < 0){
    //         return INT_MAX;
    //     }
    //     int mini = INT_MAX;
    //     for(int i=0; i < coins.size(); i++){

    //         int ans = SolveRec(coins,amount - coins[i]);
    //         if(ans!=INT_MAX){
        
    //             mini = min(INT_MAX, 1+ans);

    //         }
    //     }
    //     return mini;
    // }

    // int SolveMem(vector<int>& coins, int amount, vector<int>&dp){
    //     // base case
    //     if(amount == 0){
    //         return 0;
    //     }
    //     if(amount < 0){
    //         return INT_MAX;
    //     }
    //     // step2
    //     if(dp[amount] != -1 ){

    //         return dp[amount];
    //     }
    //     int mini = INT_MAX;
    //     for(int i=0; i < coins.size(); i++){

    //         int ans = SolveMem(coins,amount - coins[i], dp);
    //         if(ans!=INT_MAX){
        
    //             mini = min(INT_MAX, 1+ans);

    //         }
        
   
    //     }
    //     dp[amount] = mini;
    //          return mini;    
    // }
    int SolveTab(vector<int>& coins, int amount){

        vector<int> dp(amount+1, INT_MAX);

        dp[0] = 0;

        for(int i=1; i<=amount; i++){
            // for every amount figure from 1 to amount 
            for(int  j = 0; j < coins.size(); j++){
                if( i-coins[j] >=0 && dp[i-coins[j]] != INT_MAX)
                {
                    dp[i] = min(dp[i], 1 + dp[i-coins[j]]);
                }

            }
        }

        if(dp[amount] == INT_MAX){
            return -1;
        }
        return dp[amount];


    }

    int coinChange(vector<int>& coins, int amount) {
        
        // int ans = SolveRec(coins, amount);
        // if(ans == INT_MAX){
        //     return -1;
        // }
        // return ans;
        // step1
    //     vector <int> dp(amount+1, -1);
    //     int ans = SolveMem(coins, amount, dp);
    //     if(ans == INT_MAX){
    //         return -1;
    //     }
    //     else
    //         return ans;
    // }

    // using tabulation method
     return SolveTab(coins, amount);
    
    }
};