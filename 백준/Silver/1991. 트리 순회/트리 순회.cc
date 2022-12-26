#include <bits/stdc++.h>
using namespace std;

int n;
int lc[30];
int rc[30];
//전위 순회 VLR
void preOrder(int cur){
	cout << (char)(cur + 64);
	if(lc[cur] != 0) preOrder(lc[cur]);
	if(rc[cur] != 0) preOrder(rc[cur]);
}
//중위 순회 LVR
void inOrder(int cur){
	if(lc[cur] != 0) inOrder(lc[cur]);
	cout << (char)(cur + 64);
	if(rc[cur] != 0) inOrder(rc[cur]);
}
//후위 순회 LRV
void postOrder(int cur){
	if(lc[cur] != 0) postOrder(lc[cur]);
	if(rc[cur] != 0) postOrder(rc[cur]);
	cout << (char)(cur + 64);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	char v, l, r;
	cin >> n;
	//이진트리 입력 for문
	for(int i=1; i<=n; ++i){
		cin >> v >> l >> r;
		if(l != '.' && r != '.'){
			lc[v-64] = l-64;
			rc[v-64] = r-64;
		}
		else if(l == '.' && r != '.'){
			lc[v-64] = 0;
			rc[v-64] = r-64;
		}
		else if(r == '.' && l != '.'){
			lc[v-64] = l-64;
			rc[v-64] = 0;
		}
		else{
			lc[v-64] = 0;
			rc[v-64] = 0;
		}
	}
	//전위, 중위, 후위
	preOrder(1); cout << '\n';
	inOrder(1); cout << '\n';
	postOrder(1); cout << '\n';

	return 0;
}