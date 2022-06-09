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
  setIO("speeding");
  int n,m;
  vector<int> v = {};
  cin >> n >> m;
  int a,b;
  for (int i=0;i<n; i++) {
		cin >> a >> b;
		for (int j=0; j<a; j++) {
		v.push_back(b);
		}
	}
	vector<int>::iterator it = begin(v);
	int maximum = 0;
	for (int i=0; i<m; i++) {
		cin >> a >> b;
		for (int j=0; j<a; j++) {
			if (*it < b) {
				maximum = max(maximum, b-*it);
			}
			it++;
		}
	} 
	cout << maximum;
}
