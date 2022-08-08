#include<iostream>
#include<string>
#include<vector>
using namespace std;

int LCS(string s1, string s2, int i, int j, vector<vector <int> > &dp)
{
    if(i==0||j==0)
    {
        if(s1[i]==s2[j])
            return 1;
        return 0;
    }
    if(s1[i]==s2[j])
        return dp[i][j] = 1+LCS(s1,s2,i-1,j-1,dp);
    if(dp[i][j]!=-1)
        return dp[i][j];
    else
        return dp[i][j] = max(LCS(s1,s2,i-1,j,dp), max(LCS(s1,s2,i,j-1,dp), LCS(s1,s2,i-1,j-1,dp)));
}

int LCS_wrapper(string s1, string s2)
{
    int m = s1.length();
    int n = s2.length();
    vector<vector <int> > dp(m, vector<int>(n,-1));
    int len = LCS(s1,s2,m-1,n-1,dp);
    return len;
}

int main()
{
    string s1, s2;
    cout<<"Enter the string s1: ";
    cin>>s1;
    cout<<"Enter the string s2: ";
    cin>>s2;
    cout<<"Length of longest common subsequence is "<<LCS_wrapper(s1,s2);
    return 0;
}
