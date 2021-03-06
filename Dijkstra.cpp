#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fast() {ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);}
#define ll long long
#define ull unsigned long long
#define rep(i,a,b) for(int i = a; i < b; i++)
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pii>
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define oset tree < int ,  null_type ,  less<int> ,  rb_tree_tag ,  tree_order_statistics_node_update >

int n,m;
const int MAX = (1e5+3);
const int INF = INT_MAX;
vii adj[MAX];
int p[MAX], d[MAX];
bool seen[MAX];

bool dijkstra(){
  rep(i,1,n+1) d[i] = INF, p[i] = -1, seen[i] = 0;

  d[1] = 0;
  priority_queue<pair<int,int>, vii, greater<pii>> pq;
  pq.push(make_pair(0,1));
  while(!pq.empty()){
    int u = pq.top().ss, d_u = pq.top().ff;
    
    pq.pop();
    if(d[u] < d_u) continue;
    if(u == n) return true;

    seen[u] = 1;
    for(auto edge: adj[u]){
      int to = edge.ss,
          len = edge.ff;
      if(!seen[to] && (d[to] > d[u] + len)){ // invariant
        d[to] = d[u] + len;
        p[to] = u;
        pq.push({d[to], to});
      }
    }
  }
  return false;
}

vector<int> getPath(int src, int dest){
  vector<int> path;
  for(int i = dest; i != src; i = p[i]) path.push_back(i);
  path.push_back(src);
  reverse(all(path));
  return path;
}

int main(){
    fast();
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    cin>>n>>m;
    int a,b,c;
    rep(i,0,m){
      cin>>a>>b>>c;
      adj[a].push_back({c,b});
      adj[b].push_back({c,a});
    }
    if(dijkstra()){
      vector<int> path = getPath(1,n);
      for(auto i: path) cout<<i<<" ";
      cout<<"\n";
    }
    else cout<<"-1\n";
    return 0;
  }
