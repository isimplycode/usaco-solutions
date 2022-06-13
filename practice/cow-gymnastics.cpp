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
  setIO("gymnastics");
	int a, b;
	cin >> a >> b;
	map<pair<int,int>, int> m;
	for (int i=0; i<a; ++i) {
		vector<int> nums = {};
		int c;
		for (int j=0; j<b; ++j) {
			cin >> c;
			nums.push_back(c);
		}
		pair<int,int> pair;
		for (int j=0; j<nums.size(); ++j) {
			for (int k=j+1; k<nums.size(); ++k) {
				pair = make_pair(nums[j],nums[k]);
				if (m.find(pair) == m.end()) {
					m[pair] = 1;
				} else {
					m[pair]++;
				}
			}
		}
	}
	int count=0;
	for (auto i = m.begin(); i != m.end(); ++i) {
		if (i->second == a) {
			count++;
		}
	}
	cout << count;
}
