#include <iostream>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    map<string,float> tree;
    float x;
    float cnt=0;
    string str;
    
    while(getline(cin, str)){
      cnt++;
      if(tree.find(str) == tree.end())
        tree.insert({str,1});
      else
        tree[str]++;
    }

    cout << fixed;
    cout.precision(4);
    //백분율 = (각 트리 개수/전체 트리 개수)*100
    for(auto iter = tree.begin(); iter != tree.end(); ++iter){
      x = (iter->second/cnt)*100;
      cout << iter->first << " " << x << '\n';
      x = 0;
    }
    return 0;
}
