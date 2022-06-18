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
//	setIO("stacking");
	int a,b,c,d;
	cin >> a >> b;
	vector<int> v(a);
	for (int i=0; i<b; ++i) {
		cin >> c >> d;
		c--;d--;
		v[c]++;
		v[d+1]--;
	}
	vector<int> n(a);
	for (int i=0; i<a; ++i) {
		n[i]=n[i-1]+v[i];
	}
	sort(begin(n),end(n));
	cout << n[(int)a/2];
}
