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
	setIO("circlecross");
	string a;
	int start[26] = {}, end[26] = {};
	cin >> a;
	for (int i=1; i<53; ++i) {
		if (start[a[i-1]-'A']==0) {
			start[a[i-1]-'A']=i;
		} else {
			end[a[i-1]-'A']=i;
		}
	}
	string b = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int count=0;
	for (int i=0; i<26; ++i) {
		for (int j=i+1; j<26; ++j) {
			if (start[b[i]-'A']<start[b[j]-'A']&&end[b[i]-'A']<end[b[j]-'A']&&end[b[i]-'A']>start[b[j]-'A']) {
				count++;
			} else if (start[b[j]-'A']<start[b[i]-'A']&&end[b[j]-'A']<end[b[i]-'A']&&end[b[j]-'A']>start[b[i]-'A']) {
				count++;
			}
		}
	}
	cout << count;
}
