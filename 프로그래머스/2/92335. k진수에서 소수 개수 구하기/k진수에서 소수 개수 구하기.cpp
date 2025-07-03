#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool isPrime(long long num) {
    if(num < 2) return false;
        
    for(int i=2; i<=sqrt(num); ++i) {
        if(num % i == 0) return false;
    }
    return true;

}
int solution(int n, int k) {
    int answer = 0;
    vector<pair<string, int>> v;
    
    //진수 구하기
    string s = "";
    while(n > 0) {
        s += to_string(n % k);
        n /= k;
    }
    reverse(s.begin(), s.end());
    //211020101011
    string tmp = "";
    for (char c : s) { 
        if (c == '0') { 
            if (!tmp.empty() && isPrime(stoll(tmp))) {
                answer++; 
            } 
            tmp = ""; 
        } 
        else tmp += c; 
    }
    
    if (!tmp.empty() && isPrime(stoll(tmp))) {  //마지막꺼 
        answer++;
    } 
    return answer;
}