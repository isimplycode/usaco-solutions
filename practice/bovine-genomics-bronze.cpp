#include <bits/stdc++.h>
using namespace std;

void setIO(string name="") {  // name is nonempty for USACO file I/O
  ios_base::sync_with_stdio(0); cin.tie(0);  // see Fast Input & Output
  // alternatively, cin.tie(0)->sync_with_stdio(0);
  if (!name.empty()) {
  	freopen((name+".in").c_str(), "r", stdin);  // see Input & Output
  	freopen((name+".out").c_str(), "w", stdout);
  }
}

int main() {
  setIO("cownomics");
  int n, m;
  cin >> n >> m;
  vector<string> v;
  string s;
  for (int i=0; i<n*2; ++i) {
		cin >> s;
		v.push_back(s);
	}
	int count=0;
	for (int i=0; i<m; ++i) {
		bool possible=true;
		for (int j=0; j<n; ++j) {
			for (int k=n; k<n*2; ++k) {
				if (v[j][i] == v[k][i]) {
					possible=false;
				}
			}
		}
		if (possible==true) {
			count++;
		}
	}
	cout << count;
}
