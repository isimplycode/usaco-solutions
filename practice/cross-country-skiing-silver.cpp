#include <bits/stdc++.h>
using namespace std;

void setIO(string name="") { 
  ios_base::sync_with_stdio(0); cin.tie(0);  
	if (!name.empty()) {
  	freopen((name+".in").c_str(), "r", stdin);  
  	freopen((name+".out").c_str(), "w", stdout);
  }
}

int vis[500][500];

void dfs(vector<vector<int>> &v,int a,int b,int dif) {
	if (vis[a][b]) return;
	vis[a][b]=1;
	if (a>0)
		if (abs(v[a][b]-v[a-1][b])<=dif)
			dfs(v,a-1,b,dif);
	if (b>0)
		if (abs(v[a][b]-v[a][b-1])<=dif)
			dfs(v,a,b-1,dif);
	if (a<size(v)-1)
		if (abs(v[a][b]-v[a+1][b])<=dif)
			dfs(v,a+1,b,dif);
	if (b<size(v[0])-1)
		if (abs(v[a][b]-v[a][b+1])<=dif)
			dfs(v,a,b+1,dif);
}

bool isVal(vector<vector<int>> &v,vector<pair<int,int>> &points,int dif) {
	dfs(v,points[0].first,points[0].second,dif);
	for (int i=0; i<size(points); ++i) {
		if (!vis[points[i].first][points[i].second])
			return false;
	}
	return true;
}	

int main() {
	setIO("ccski");
	int a,b,c;
	cin >> a >> b;
	vector<vector<int>> v(a,vector<int>(b));
	vector<pair<int,int>> points;
	for (int i=0; i<a; ++i) {
		for (int j=0; j<b; ++j) {
			cin >> c;
			v[i][j]=c;
		}
	}
	for (int i=0; i<a; ++i) {
		for (int j=0; j<b; ++j) {
			cin >> c;
			if (c) {
				points.push_back({i,j});
			}
		}
	}
	int l=0;
	int r=1000000000;
	while (l<r) {
		int m=(r+l)/2;
		for (int i=0; i<a; ++i) {
			for (int j=0; j<b; ++j) {
				vis[i][j]=0;
			}
		}
		if (isVal(v,points,m)) {
			r=m;
		} else {
			l=m+1;
		}
	}
	cout << l;
}
