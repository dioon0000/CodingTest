#include <string>
#include <vector>
#include <stack>

using namespace std;
int solution(string s)
{
    int ans = 0;
    for (int i = 0; i < s.length(); ++i)
    {
        stack<char> st;
        bool flag = false;
        for(int j=0; j<s.length(); ++j)
        {
            int idx = (j+i)%s.length();
            if (s[idx] == '[' || s[idx] == '(' || s[idx] == '{') { st.push(s[idx]); continue; }
            if (st.empty()) { flag = true; break; }
            else if (s[idx] == ']' && st.top() != '[') { flag = true; break; }
            else if (s[idx] == ')' && st.top() != '(') { flag = true; break; }
            else if (s[idx] == '}' && st.top() != '{') { flag = true; break; }
            else { st.pop(); }
        }
        if(!flag && st.empty()) ans++;
    }
    return ans;
}