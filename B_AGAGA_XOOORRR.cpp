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
vector<int>arr(2001);
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
 
//mistake in first attempt->at least two 
// means as soon as all elements beacme equal just stop
int main()
{
 fast_cin();
 int t;
 cin >> t;
 for(int it=1;it<=t;it++) {
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    cin>>arr[i];
    // case-1
    int total_xor=0;
    bool flag=false;
    for(int i=0;i<n;i++)
    {
        total_xor^=arr[i];
    }
    if(total_xor==0)
    {
        flag=true;
        cout<<"YES\n";
    }
    // case-2
    else{
        int pre_xor[n];
        pre_xor[0]=arr[0];
       for(int i=1;i<n;i++)
        pre_xor[i]=pre_xor[i-1]^arr[i];
       for(int i=0;i<n;i++)
       {
           for(int j=i+1;j<n;j++)
           {
              int first=pre_xor[i];
              int second=pre_xor[j]^pre_xor[i];
              int third=total_xor^pre_xor[j];
              if(first==second && first==third)
              {
                 cout<<"YES\n";
                 flag=true;
                 break;
              }
           }
           if(flag==true)
           {
              break;
           }
       } 
       if(flag==false)
       cout<<"NO\n";
    }
 }
 return 0;
}