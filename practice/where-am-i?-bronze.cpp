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
  setIO("whereami");
  int x;
  cin >> x;
	string y;
	cin >> y;
	int k=1;
	bool valid=false;
	while (valid!=true&&k<x) {
		set<string> s;
		for (int i=0;i<x-k+1;++i) {
			string temp="";
			for (int j=i;j<i+k;++j) {
				temp+=y[j];
			}
			if (s.count(temp)!=1&&i==x-k) {
				valid=true;
				break;
			} else if (s.count(temp)!=1) {
				s.insert(temp);
			} else {
				k+=1;
				break;
			}
		}
	}
	cout << k;
}
