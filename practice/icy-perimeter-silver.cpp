#include <bits/stdc++.h>
using namespace std;

void setIO(string name="") { 
  ios_base::sync_with_stdio(0); cin.tie(0);  
	if (!name.empty()) {
  	freopen((name+".in").c_str(), "r", stdin);  
  	freopen((name+".out").c_str(), "w", stdout);
  }
}

vector<string> v;
int visited[1005][1005];
int area;
int perimeter;

void dfs(int x, int y) {
	if (visited[x][y]) return;
	if (v[x][y]!='#') return;
	visited[x][y]=1;
	area++;
	if (v[x-1][y]=='0'||v[x-1][y]=='.') {
		perimeter++;
	} else {
		dfs(x-1,y);
	}
	if (v[x][y-1]=='0'||v[x][y-1]=='.') {
		perimeter++;
	} else {
		dfs(x,y-1);
	}
	if (v[x+1][y]=='0'||v[x+1][y]=='.') {
		perimeter++;
	} else {
		dfs(x+1,y);
	}
	if (v[x][y+1]=='0'||v[x][y+1]=='.') {
		perimeter++;
	} else {
		dfs(x,y+1);
	}
}

int main() {
	setIO("perimeter");
	int a;
	string b,c="";
	cin >> a;
	for (int i=0; i<a+2; ++i) {
		c+="0";
	}
	v.push_back(c);
	string d="0";
	for (int i=0; i<a; ++i) {
		cin >> b;
		b=d+b+d;
		v.push_back(b);
	}
	v.push_back(c);
	for (int i=0; i<1005; ++i) {
		for (int j=0; j<1005; ++j) {
			visited[i][j]=0;
		}
	}
	int maxa=0;
	int per=0;
	for (int i=1; i<a+1; ++i) {
		for (int j=1; j<a+1; ++j) {
			if (v[i][j]=='#'&&!visited[i][j]) {
				area=0;
				perimeter=0;
				dfs(i,j);
				if (area>maxa) {
					maxa=area;
					per=perimeter;
				}
				if (area==maxa) {
					per=min(perimeter,per);
				}
			}
		}
	}
	cout << maxa << " " << per; 
}
