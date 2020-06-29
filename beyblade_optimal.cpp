/* Read input from STDIN. Print your output to STDOUT*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    //Write code here
    ll t,n;
    ll count;
    cin>>t;
    while(t>0){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        count = 0;
        cin>>n;
        vector<ll> team_g(n,0);
        vector<ll> team_e(n,0);

        for(ll i=0;i<n;++i){
            cin>>team_g[i];
        }
        for(ll j=0;j<n;++j){
            cin>>team_e[j];
        }
        sort(team_g.begin(),team_g.end());
        sort(team_e.begin(),team_e.end());

        ll g_ptr=0, e_ptr=0;
        while(g_ptr<n){
            if(team_g[g_ptr] > team_e[e_ptr]){
                ++count;
                ++g_ptr;
                ++e_ptr;
            }else{
                ++g_ptr;
            }
        }
        --t;
        cout<<count<<endl;
    }
}
