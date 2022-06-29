#include <bits/stdc++.h>
using namespace std;

void setIO(string name="") { 
  ios_base::sync_with_stdio(0); cin.tie(0);  
	if (!name.empty()) {
  	freopen((name+".in").c_str(), "r", stdin);  
  	freopen((name+".out").c_str(), "w", stdout);
  }
}
struct coord {
	int x,y;
};

vector<vector<int>> adj(1e6);
vector<coord> v(1e6);
int visited[100006];
int minx=INT_MAX;
int maxx=0;
int miny=INT_MAX;
int maxy=0;

void dfs(int node) {
	if (visited[node]) return;
	visited[node]=1;
	minx=min(minx,v[node].x);
	maxx=max(maxx,v[node].x);
	miny=min(miny,v[node].y);
	maxy=max(maxy,v[node].y);
	for (auto i : adj[node]) {
		dfs(i);
	}
}

int main() {
	setIO("fenceplan");
	int a,b,c,d;
	cin >> a >> b;
	for (int i=0; i<a; ++i) {
		cin >> v[i].x >> v[i].y;
	}
	for (int i=0; i<b; ++i) {
		cin >> c >> d;
		adj[c-1].push_back(d-1);
		adj[d-1].push_back(c-1);
	}
	int minperimeter=INT_MAX;
	for (int i=0; i<a; ++i) {
		visited[i]=0;
	}
	for (int i=0; i<a; ++i) {
		minx=999999999;
		maxx=0;
		miny=99999999;
		maxy=0;
		dfs(i);
		minperimeter=min(minperimeter,(maxx-minx)*2+2*(maxy-miny));
	}
	cout << minperimeter;
}
