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

void checkFreq(const string &a, array<int, 26> &b) {
	for (char c : a){
		b[c-'a'] += 1;
	}
}

int main() {
  setIO("blocks");
	int a;
	int blocks[26] = {};
	cin >> a;
	string b, c;
	for (int i = 0; i < a; i++) {
		cin >> b;
		cin >> c; 
		array <int, 26> sideone = {}, sidetwo = {};
		checkFreq(b, sideone);
		checkFreq(c, sidetwo);
		for (int j=0; j<26; ++j) {
			blocks[j] += max(sideone[j], sidetwo[j]);
		}
	}
	for (int i=0; i<26; ++i) {
		cout << blocks[i] << "\n";
	}
}
