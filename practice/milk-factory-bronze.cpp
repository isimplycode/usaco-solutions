#include <bits/stdc++.h>
using namespace std;

void setIO(string name="") {
  ios_base::sync_with_stdio(0); cin.tie(0); 
  if (!name.empty()) {
  	freopen((name+".in").c_str(), "r", stdin); 
  	freopen((name+".out").c_str(), "w", stdout);
  }
}
const int mxN=100;
vector<int> adj[mxN];
int cnt[mxN];

void dfs(int u) {
	cnt[u]=1;
	for (int j : adj[u]) {
		dfs(j);
		}
}

int main() {
  setIO("factory");
  int a,b,c;
  cin >> a;
  for (int i=0;i<a-1;++i) {
		cin >> b >> c;
		adj[c].push_back(b);
	}
	int res=-1;
	for (int i=1;i<a+1;++i) {
		fill(begin(cnt),end(cnt),0);
		dfs(i);
		int ct=0;
		for (int j=1;j<a+1;++j) {
			if (cnt[j]==1) {
				ct+=1;
			}
		}
		if (ct==a&&res==-1) {
			res=i;
		}
	}
	cout << res;
}
