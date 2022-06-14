#include <bits/stdc++.h>
using namespace std;

void setIO(string name="") {
  ios_base::sync_with_stdio(0); cin.tie(0); 
  if (!name.empty()) {
  	freopen((name+".in").c_str(), "r", stdin); 
  	freopen((name+".out").c_str(), "w", stdout);
  }
}

int main() {
  setIO("planting");
  int a,b,c;
  cin>>a;
  vector<vector<int>> adj(a);
  for (int i=0;i<a-1;++i) {
		cin>>b>>c;
		adj[b-1].push_back(c-1);
		adj[c-1].push_back(b-1);
	}
	int count=0;
	for (int i=0;i<a;++i) {
		int z=adj[i].size();
		count=max(count, z);
	}
	count++;
	cout << count;
}
