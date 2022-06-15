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
	setIO("div7");
	int a,b;
	cin >> a;
	vector<int> prefix;
	long long sum=0;
	for (int i=0;i<a;++i) {
		cin >> b;
		sum+=b;
		prefix.push_back(sum%7);
	}
	int mx=0;
	for (int i=0; i<prefix.size(); ++i) {
		int j=prefix.size()-1;
		bool answerfound=false;
		while (j>0&&answerfound==false) {
			if (prefix[i] == prefix[j]) {
				mx = max(j-i, mx);
				answerfound=true;
			}
			--j;
		}
	}
	cout << mx;
}
