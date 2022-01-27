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
     int arr[n];
     for(int i=0;i<n;i++)
     cin>>arr[i];
    //  int k=0;
    //  vector<int>res;
    //  while(k<n)
    //  {
    //     for(int i=k;i<n;i++)
    //     {
    //         set<int>s;
    //         for(int j=k;j<=i;j++)
    //         {
    //             s.insert({arr[j]});
    //         }
    //         int j=0;
    //         for(auto x: s)
    //         {
    //             if(x!=j)
    //             break;
    //             j++;
    //         }
    //        mex[i]=j;
    //     }
    //     int i;
    //     for(i=k;i<n;i++)
    //     {
    //         if(mex[i]==mex[n-1])
    //         {
    //             res.push_back(mex[i]);
    //             break;
    //         }
    //     }
    //     k=i+1;
    //  }
    //  cout<<res.size()<<endl;
    //  for(int i=0;i<res.size();i++)
    //  cout<<res[i]<<" ";
    //  cout<<endl;
    vector<int>cnt(2*100000,0);
    vector<bool>vis(2*100000,false);
    vector<int>res;
    for(int i=0;i<n;i++)
    {
        cnt[arr[i]]++;
    }
    int mex=0,j=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==mex)
        {
            cnt[arr[i]]--;
            vis[arr[i]]=true;
            while(vis[mex])
            mex++;
            if(cnt[mex]==0)
            {
                res.push_back(mex);
                mex=0;
                for(int l=i;l>=j;l--)
                vis[arr[l]]=false;
                j=i+1;
            }
        }
        else if(cnt[mex]==0)
        {
            res.push_back(mex);
            mex=0;
            cnt[arr[i]]--;
            j=i+1;
        }
        else{
            cnt[arr[i]]--;
            vis[arr[i]]=true;
        }
    }
    cout<<res.size()<<endl;
    for(int i=0;i<res.size();i++)
    cout<<res[i]<<" ";
    cout<<endl;
 }
 return 0;
}