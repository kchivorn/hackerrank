#include <map>
#include <iostream>
#include <utility>
#include <vector>
#include <cmath>
using namespace std;

void printout(vector <pair <int, int> >& ans) {
  for (auto i = ans.begin(); i != ans.end()-1; i++) {
    for (auto j = i + 1; j != ans.end() ; j++) {
      cout <<"(" << i -> first << ", " << i -> second << ") ";
      cout <<"(" << j -> first << ", " << j -> second << ")" << endl;
    }
  }
}

int main(){
  int a, b, c, d;
  long long val;
  map < pair <int,int>, long long > hash;
  map < long long, vector < pair <int, int> > > ans;
  for (int i= 1; i < 1000; i++){
    for (int j= 1; j< 1000; j++){
      pair <int, int> p = make_pair(i, j);

      if (hash[p] != 0) continue;
      val = pow(i, 3) + pow(j, 3);
      ans[val].push_back(p);
      hash[p] = val;

      if (i !=j) {
        pair <int, int> rev = make_pair(j,i);
        hash[rev] = val;
      }
    }
  }

  for (auto it : ans) {
    printout(it.second);
  }

  return 0;
}
