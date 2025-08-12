#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
	if(a%b == 0) return b;
	else return gcd(b, a%b);
}

int solution(vector<int> arrayA, vector<int> arrayB) {
	int answer = 0; int agcd=0, bgcd=0;
	bool IsAOkay = true, IsBOkay = true;

	if(arrayA.size() == 1) agcd = arrayA[0];
	else {
		int a, b;
		a = arrayA[0]; b = arrayA[1];
		agcd = gcd(a, b);

		for(int i=0; i<arrayA.size(); ++i) {
			if(i==0 || i==1) continue;
			else {
				agcd = gcd(agcd, arrayA[i]);
			}
		}
	}

	if(arrayB.size() == 1) bgcd = arrayB[0];
	else {
		int a, b;
		a = arrayB[0]; b = arrayB[1];
		bgcd = gcd(a, b);

		for(int i=0; i<arrayB.size(); ++i) {
			if(i==0 || i==1) continue;
			else {
				bgcd = gcd(bgcd, arrayB[i]);
			}
		}
	}

	for(int a : arrayA) {
		if(a%bgcd == 0) {
			IsBOkay = false;
			break;
		}
	}
	for(int b : arrayB) {
		if(b%agcd == 0) {
			IsAOkay = false;
			break;
		}
	}

	if(!IsAOkay) agcd = 0;
	if(!IsBOkay) bgcd = 0;

	return max(agcd,bgcd);
}