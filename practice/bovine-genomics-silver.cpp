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
	setIO("cownomics");
	int a,b;
	cin >> a >> b;
	vector<vector<int>> spotty(a, vector<int>(b));
	string s;
	for (int i=0; i<a; ++i) {
		cin >> s;
		for (int j=0; j<size(s); ++j) {
			if (s[j]=='A') {
				spotty[i][j]=1;
			} else if (s[j]=='C') {
				spotty[i][j]=2;
			} else if (s[j]=='G') {
				spotty[i][j]=3;
			} else {
				spotty[i][j]=4;
			}
		}
	}
	vector<vector<int>> plain(a, vector<int>(b));
	for (int i=0; i<a; ++i) {
		cin >> s;
		for (int j=0; j<size(s); ++j) {
			if (s[j]=='A') {
				plain[i][j]=1;
			} else if (s[j]=='C') {
				plain[i][j]=2;
			} else if (s[j]=='G') {
				plain[i][j]=3;
			} else {
				plain[i][j]=4;
			}
		}
	}
	int res=0;
	for (int i=0; i<b; ++i) {
		for (int j=i+1; j<b; ++j) {
			for (int k=j+1; k<b; ++k) {
				vector<int> sp(128);
				for (int l=0; l<a; ++l) {
					sp[spotty[l][i]*16+spotty[l][j]*4+spotty[l][k]*1]=1;
				}
				bool val=true;
				for (int l=0; l<a; ++l) {
					int pltot=0;
					pltot+=plain[l][i]*16+plain[l][j]*4+plain[l][k]*1;
					if (sp[pltot]==1)
						val=false;
				}
				if (val)
					res++;
				}
			}
		}
		cout << res;
}
