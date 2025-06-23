#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
	int x = arr1.size();
	int y = arr1[0].size();
	int z = arr2[0].size();
    vector<vector<int>> answer(x, vector<int>(z,0));

	for(int i=0; i<x; ++i)
	{
		for(int j=0; j<y; ++j)
		{
			for(int k=0; k<z; ++k)
			{
				answer[i][k]+=arr1[i][j]*arr2[j][k];
			}
		}
	}
    return answer;
}