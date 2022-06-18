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
	setIO("lineup");
	string s;
	int a;
	cin >> a;
	vector<pair<string, string>> v(a);
	for (int i=0; i<a; ++i) {
		for (int j=0; j<6; ++j) {
			cin >> s;
			if (j==0) {
				v[i].first=s;
			} else if (j==5) {
				v[i].second=s;
			}
		}
	}
	vector<string> c = {"Beatrice","Belinda","Bella","Bessie","Betsy","Blue","Buttercup","Sue"};
	do {
		bool valid=true;
		for (int i=0; i<a; ++i) {
			for (int j=0; j<size(c); ++j) {
				if (v[i].second==c[j]) {
					if (c[j-1]!=v[i].first&&c[j+1]!=v[i].first) {
						valid=false;
					}
				}
			}
		}
		if (valid==true) {
			for (int i=0; i<size(c); ++i) {
				cout << c[i] << "\n";
			}
			return 0;
		}
	} while(next_permutation(begin(c),end(c)));
}
