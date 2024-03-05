#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("FOOD.INP", "r", stdin);
    freopen("FOOD.OUT", "w", stdout);
    int m, n;
    cin >> m >> n;
    vector<vector<int>> a(m+1, vector<int>(n+1, 0));
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            cin >> a[i][j];
        }
    }
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + a[i][j];
        }
    }
    cout << dp[m][n] << endl;
    return 0;
}

