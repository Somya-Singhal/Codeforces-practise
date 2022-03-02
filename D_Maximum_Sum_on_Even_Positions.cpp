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
 

int main()
{
 fast_cin();
 ll t;
 cin >> t;
 for(int it=1;it<=t;it++) {
     int n;
     cin>>n;
     vector<long long int>arr(n),v1,v2;
     for(long long int &x: arr)
     cin>>x;
     long long int sum=0;
     for(int i=0;i<n;i++)
     {
         if(i%2==0)
         sum+=arr[i];
     }
     for(int i=0;i<n-1;i+=2)
     {
         v1.push_back(arr[i+1]-arr[i]);
     }
     for(int i=1;i<n-1;i+=2)
     {
         v2.push_back(arr[i]-arr[i+1]);
     }
     long long int currmax=LONG_LONG_MIN,totalMax1=LONG_LONG_MIN,totalMax2=LONG_LONG_MIN;
     if(v1.size()>0)
     {
         currmax=v1[0],totalMax1=v1[0];
        for(int i=1;i<v1.size();i++)
        {
            currmax=max(currmax+v1[i],v1[i]);
            totalMax1=max(totalMax1,currmax);
        }
     }
     if(v2.size()>0)
     {
        currmax=v2[0];
        totalMax2=v2[0];
        for(int i=1;i<v2.size();i++)
        {
            currmax=max(currmax+v2[i],v2[i]);
            totalMax2=max(totalMax2,currmax);
        }
     }
     if((totalMax1!=LONG_LONG_MIN || totalMax2!=LONG_LONG_MIN) && (totalMax1>0 || totalMax2>0))
     sum+=max(totalMax1,totalMax2);
     cout<<sum<<endl;
 }
 return 0;
}