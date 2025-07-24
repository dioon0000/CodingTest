#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, m;
	int input;
	int start = 0, end = 0, sum = 0;
	int count = 0;
	cin >> n >> m;
	vector<int> v;

	for(int i=0; i<n; ++i) 
	{
		cin >> input;
		v.push_back(input);
	}

	while(end<=v.size())
	{
		if(sum>=m)
		{
			if(sum == m)
			{
				count++;
			}
			sum-=v[start++];
		}
		else
		{
			if(end>=v.size())
				break;
			sum+=v[end++];
		}
	}

	cout << count;
	return 0;
}