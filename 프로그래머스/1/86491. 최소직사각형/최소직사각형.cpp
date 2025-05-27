#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int ans=0;
    int width=0;
    int height=0;
    int swap=0;

    for(int i=0; i<sizes.size(); ++i){
        if(sizes[i][0] < sizes[i][1]){
            swap = sizes[i][0];
            sizes[i][0] = sizes[i][1];
            sizes[i][1] = swap;
        }
    }

    for(int i=0; i<2; ++i){
        for(int j=0; j<sizes.size(); ++j){
            if(i==0){
                if(sizes[j][i]>width)
                    width = sizes[j][i];
            }
            else{
                if(sizes[j][i]>height)
                    height = sizes[j][i];
            }
        }
    }

    ans = height * width;
    return ans;
}