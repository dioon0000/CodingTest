#include <iostream>
#include <cmath>
using namespace std;

int main(){
	int t;
	cin >> t;
	
	double x, y;
	
	for(int i=0; i<t; i++){
		cin >> x >> y;
		double dist = y-x; 
		double dpow = sqrt(dist); // dt의 제곱근
		int pow = round(dpow); // dt의 제곱근 반올림
		
		if(dpow <= pow)  //반올림 값보다 작을 때
      cout << pow * 2 - 1 << "\n"; //2N-1
		else 
      cout << pow * 2 << "\n";  //2N
	}
		
	return 0;
}