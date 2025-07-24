#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
	vector<int> answer;
	int start = 0, end = 0, sum = 0;
	int len = 1000001;
	int a = 0, b = 0;
    
	while(end <= sequence.size())
	{
		if(sum>=k)
		{
			if(sum==k)
			{
				int comp = end - start;
				if(comp < len)
				{
					len = comp;
					a = start, b = end-1;
				}
			}
			sum-=sequence[start++];
		}
		// sum < k
		else
		{
			if(end>=sequence.size())
			{
				break;
			}
			sum+=sequence[end++];
		}
	}

	answer.push_back(a);
	answer.push_back(b);
    
	return answer;
}