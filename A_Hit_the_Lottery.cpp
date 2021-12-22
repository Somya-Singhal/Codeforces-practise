#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 998244353;
double eps = 1e-12;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
 

// long long int solve(int idx,vector<int>& wt,long long int n){
//  if(n==0)
//  return 0;
//  if(idx==wt.size())
//  return INT_MAX-1;
//  if(wt[idx]<=n)
//  return min(1+solve(idx,wt,n-wt[idx]),solve(idx+1,wt,n));
//  else
//  return solve(idx+1,wt,n);
// }
int main()
{
 fast_cin();
 long long int n;
 cin>>n;
 vector<int>wt={1,5,10,20,100};
 long long int dp[6][n+1];
 for(int i=0;i<6;i++)
 {
     for(long long int j=0;j<=n;j++)
     {
         if(i==0 && j==0)
         dp[i][j]=0;
         else if(j==0)
         dp[i][j]=0;
         else if(i==0)
         dp[i][j]=LLONG_MAX-1;
         else if(i==1)
         dp[i][j]=j;
         else
         {
             if(wt[i-1]<=j)
             dp[i][j]=min(1+dp[i][j-wt[i-1]],dp[i-1][j]);
             else
             dp[i][j]=dp[i-1][j];
         }
     }
 }
 cout<<dp[5][n];
 return 0;
}