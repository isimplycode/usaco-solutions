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
  setIO("notlast");
	unordered_map<string, int> m;
	int a, b;
	cin >> a;
	string s;
	for (int i=0;i<a;++i) {
		cin >> s >> b;
		if (m.find(s)==m.end()) {
			m[s]=b;
		} else {
			m[s]+=b;
		}
	}
	int currmin=INT_MAX;
	set<int> min;
	for (auto i=begin(m);i!=end(m);++i) {
		if (i->second<currmin) {
			currmin=i->second;
			}
		min.insert(i->second);
	}
	auto j=begin(min);
	if (size(m)==7) {
		j++;
	}
	int minmin=*j;
	unordered_set<string> set;
	for (auto i=begin(m);i!=end(m);++i) {
		if (i->second==minmin) {
			set.insert(i->first);
		}
	}
	if (set.size()==1) {
		auto i=begin(set);
		cout << *i << "\n";
	} else {
		cout << "Tie" << "\n";
		}
}
