#include <bits/stdc++.h>
#include <iostream>
#define ll long long int
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define gcd __gcd
#define int_string to_string
#define string_int stoi
#define mn(v) *min_element(v.begin(), v.end())
#define mx(v) *max_element(v.begin(), v.end())
#define index_character s.find('character')
#define countxchar count(s.begin(), s.end(), 'x')
#define index_ofX_vector find(v.begin(), v.end(), x) - v.begin()
#define point cout << fixed << setprecision(10)
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define n1 cout << "-1" << endl
#define ok cout << "ok" nl
#define sorted is_sorted(v.begin(), v.end())
#define nl << endl
#define sp << " "
#define mp make_pair
#define fi first
#define se second
#define Mx LLONG_MAX
#define Mn LLONG_MIN
#define mod %1000000007
// ordered_set
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;   
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
// bitsize-> ll size=log2(n)+1 (last set bit=size-1;/ /Last bit->__lg(value); )
// first bit-> name._Find_First()
// next bit after x-> name._Find_next()
// freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
// BesidesDuplicateCharacterEraseInString s.erase(unique(s.begin(), s.end()), s.end());
// Upper/lower-> transform(s.begin(), s.end(), s.begin(), ::toupper/tolower);
using namespace std;
ll i, j, k, n, m;
const ll N = 2e7+5;
const ll e=1e9;
const double pi=acos(-1);
bool cmp(pair<ll,ll> a,pair<ll,ll> b){
    if(a.fi==b.fi) return (a.se>b.se); return (a.fi>b.fi);}
//
// Don't get stuck on a single approach for long, think of multiple ways
// You will destroy your dream if you stay in your comfort zone
// **********************|| Main Code ||********************************
//
 
int main()
{ 
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    // point;
    ll test = 1; 
    // cin >> test;    
    again: 
    while (test--)
    {    
        ll n,total; // use every coin at most once as sum of coins equal total
        cin>>n>>total;
        vector<ll> coins(n+1);
        for(i=1;i<=n;i++){
            cin>>coins[i];
        }
        vector<vector<ll>> dp(n+1,vector<ll> (total+1));
        for(i=0;i<=n;i++) dp[i][0]=1;
        for(i=1;i<=n;i++){
            for(j=1;j<=total;j++){
                dp[i][j]=dp[i-1][j];
                if(coins[i]<=j){
                    dp[i][j]=(dp[i][j] or dp[i-1][j-coins[i]]);
                }
            }
        }
        if(dp[n][total]){
            yes;
            vector<ll> ans;
            for(i=n,j=total;i and j;i--){
                if(dp[i][j] and dp[i-1][j]==0){
                    ans.pb(coins[i]);
                    j=j-coins[i];
                }
            }
            reverse(ans.begin(),ans.end());
            for(auto x: ans){
                cout << x sp;
            }
            cout nl;
        }else no;
    }
}
