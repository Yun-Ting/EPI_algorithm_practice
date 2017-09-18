// Example program
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> findPairsWithGivenDifference(const vector<int>& arr, int k) 
{
  sort(arr.begin(), arr.end());
  vector<vector<int>> answer;
  int first = 0;
  int last = 0;
  while (last < arr.size() && first < arr.size()) {
    if (first != last && arr[last] - arr[first] == k) {
      vector<int> temp({arr[last], arr[first]});
      answer.push_back(temp);
    }
    else if (arr[last] - arr[first] < k) {
      ++last;
    }
    else {
      ++first;
    }
  }
  return answer;
}

int main() {
  vector<int> myVec({0, -1, -2, 2, 1})     
  findPairsWithGivenDifference(myVec, 1);
  return 0;
}
