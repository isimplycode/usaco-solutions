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
	setIO("outofplace");
	int a,b;
	cin >> a;
	vector<int> v,s;
	for (int i=0; i<a; ++i) {
		cin >> b;
		v.push_back(b);
		s.push_back(b);
	}
	sort(begin(s),end(s));
	int res=0;
	for (int i=0; i<a; ++i) {
		if (s[i]!=v[i]) {
			res++;
		}
	}
	cout << res-1;
}
