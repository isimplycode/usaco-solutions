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
	setIO("paintbarn");
	vector<vector<int>> p(1001, vector<int>(1001,0));
	int a,b,c,d,e,f;
	cin >> a >> b;
	for (int i=0; i<a; ++i) {
		cin >> c >> d >> e >> f;
		p[c][d]++;
		p[e][f]++;
		p[e][d]--;
		p[c][f]--;
	}
	int res=0;
	for (int i=0; i<size(p); ++i) {
		for (int j=0; j<size(p); ++j) {
			if (i>0)
				p[i][j]+=p[i-1][j];
			if (j>0)
				p[i][j]+=p[i][j-1];
			if (i>0&&j>0)
				p[i][j]-=p[i-1][j-1];
			if (p[i][j]==b)
				res++;
		}
	}
	cout << res;
}

