//https://www.acmicpc.net/problem/2108
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int cntSort[8005]; //cntSort는 절대값 4000사이의 값의 개수를 세기 위한 함수
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, tmp, mxval = 0, mxnum;
	double sum=0;
	vector<int> v;
	cin >> n;
	for(int i=0; i<n; ++i){
		cin >> tmp;
		v.push_back(tmp);
		sum +=tmp;
		cntSort[tmp+4000]+=1;
	}

	//cntSort의 최대값 탐색
	for(int i=0; i<=8000; ++i){
		if(cntSort[i] > mxval){
			mxval = cntSort[i];
			mxnum = i;
		}
	}

	//mxnum값보다 큰 값중에 mxval값과 같은 것이 있다면 두번째로 작은 mxnum값이므로 mxnum값을 i로 변경해준뒤 for문을 종료
	for(int i=mxnum+1; i<=8000; ++i){
		if(mxval == cntSort[i]){
			mxnum = i;
			break;
		}
	}
  	
	//43~44줄 Comment
  	//양수일때 0.5~0.9 사이의 값에 +0.5를 한 뒤 int형으로 변환하면 반올림한 값과 같다
	//음수일때는 -0.5~-0.9사이의 값에 -0.5를 더해주면 int형으로 변환했을때 반올림한 값과 같다
	sum/=n;
	sum>0 ? sum+=0.5 : sum-=0.5;
  
	sort(v.begin(), v.end());
	cout << (int)sum << '\n'; //산술평균
	cout << v[n/2] << '\n'; //중앙값
	cout << mxnum-4000 << '\n'; //최빈값
	cout << v[n-1] - v[0] << '\n'; //범위

	return 0;
}
