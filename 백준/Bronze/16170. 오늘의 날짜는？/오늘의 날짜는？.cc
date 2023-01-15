#define _CRT_SECURE_NO_WARNINGS // or localtime_s를 사용
#include <iostream>
#include <ctime>
using namespace std;

int main() {
    time_t timer;
    struct tm *t;
    timer = time(NULL); // 1970년 1월 1일 0시 0분 0초부터 시작하여 현재까지의 초
    t = localtime(&timer);

    cout << t->tm_year + 1900 << '\n';
    cout << t->tm_mon + 1 << '\n';
    cout << t->tm_mday << '\n';
    return 0;
}