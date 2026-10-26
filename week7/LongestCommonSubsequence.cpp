#include<iostream>
#include<vector>
using namespace std;
int recApp(int i, int j , string &A, string &B) {
    if(i<0 || j<0) 
        return 0;
    if(A[i]==B[j]) 
        return 1+recApp(i-1,j-1,A,B);
    return max(recApp(i-1,j,A,B),recApp(i,j-1,A,B));
}
int DPmem(int i,int j,string &A,string &B,vector<vector<int>> &dp) {
    if(i==0 || j==0) 
        return 0;
    if(dp[i][j]!=-1) 
        return dp[i][j];
    if(A[i-1]==B[j-1]) 
        return dp[i][j]=1+DPmem(i-1,j-1,A,B,dp);
    return dp[i][j]=max(DPmem(i-1,j,A,B,dp),DPmem(i,j-1,A,B,dp));
}
int DPtabulation(int n,int m,string &A, string &B,vector<vector<int>> &dp){
    for(int i=0;i<=n;i++) dp[i][0]=0;
    for(int j=0;j<=m;j++) dp[0][j]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(A[i-1]==B[j-1]) 
                dp[i][j]=1+dp[i-1][j-1];
            else 
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[n][m];
} 
int LCS(string &A, string &B) {
    int n=A.length();
    int m=B.length();
    // return recApp(n-1,m-1,A,B);

    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    // return DPmem(n,m,A,B,dp );
    return DPtabulation(n,m,A,B,dp);
}
 
int main() {
    string A, B;
    cout << "Enter first string: ";
    cin >> A;
    cout << "Enter second string: ";
    cin >> B;
 
    cout << "LCS length: "<<LCS(A,B)<<endl;
 
// Enter first string: ABCDE
// Enter second string: ACE
// LCS length: 3
    return 0;
}