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
	setIO("diamond");
	int a,b,c;
	cin >> a >> b;
	vector<int> v;
	for (int i=0; i<a; ++i) {
		cin >> c;
		v.push_back(c);
	}
	sort(begin(v),end(v));
	int maxfromhere[500001];
	for (int i=0,r; i<size(v); ++i) {
		r=i;
		while (r<size(v)&&v[r]-v[i]<=b) {
			r++;
		}
		maxfromhere[i]=r-i;
	}
	int maxright[50001]={0};
	int msf=0;
	for (int i=a-1; i>=0; --i) {
		msf=max(maxfromhere[i],msf);
		maxright[i]=msf;
	}
	int ans=0;
	for (int i=0; i<a; ++i) {
		ans=max(ans,maxfromhere[i]+maxright[i+maxfromhere[i]]);
	}
	cout << ans;
}
