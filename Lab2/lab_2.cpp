// Lab 2 Skeleton
// Author: Tanner Hart

#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

/**************************
 * Your solutions go here *
 * ************************/
int triangleNum(int n){
  return (n == 1) ? 1 : n + triangleNum(n-1);
}

int rFib(int n){
  return (n<=1) ? n : rFib(n-1) + rFib(n-2);
}

int rSumHelper(const vector<int> &v, int i){
  return (i == v.size()) ? 0 : v[i] + rSumHelper(v, i+1);
}

int rSum(const vector<int> &v){
  return rSumHelper(v,0);
}

int rMaxHelper(const vector<int> &v, int start){
  return (start == v.size()) ? INT_MIN : max(v[start], rMaxHelper(v, start + 1));
}

int rMax(const vector<int> &v){
   return (v.size() == 0) ? INT_MIN : rMaxHelper(v, 0);
}

bool isSorted(const vector<int> &v, int start, int end){
  if (v.size() < end) return true;
  if (start >= end || start >=v.size() - 1) return true;
  if (v.at(start) > v.at(start + 1)) return false;
  return isSorted(v, start + 1, end);
}

bool isPalindromeHelper(string s, int start, int end){
    char startChar = tolower(s[start]);
    char endChar = tolower(s[end]);
    if (start >= end) return true;
    if (startChar == endChar) return isPalindromeHelper(s, start + 1, end - 1);
    return false;
}

bool isPalindrome(string s){
  return (s.empty()) ? true : isPalindromeHelper(s, 0, s.length() - 1);
}

int rBinarySearch(const vector<int> &v, int low, int high, int target){
  if (low > high) return -1;
  int mid = low + (high - low) / 2;
  if (v.at(mid) == target) return mid;
  if (target < v.at(mid)) return rBinarySearch(v, low, mid - 1, target);
  return rBinarySearch(v, mid + 1, high, target);
}

bool rSubsetSum(const vector<int> &v, int start, int target){
  if (target == 0) return true;
  if (start == v.size() || start < 0) return false;
  if (v.at(start) <= target) {
     if (rSubsetSum(v,start+1, target - v.at(start))) return true;
  }
  return rSubsetSum(v,start+1, target);
}

/***********************************************
 * Main and helper functions for quick testing *
 * *********************************************/
void readIntVector(vector<int> &v, int n);

int main(){
  int question = -1;
  cout << "Question: ";
  cin >> question;

  int n = 0, start = 0, end = 0;
  vector<int> v;
  string s = "";
  switch (question){
    case 1: //triangleNum
      cout << "Triangle Number n: ";
      cin >> n;
      cout << triangleNum(n) << endl;
      break;
    case 2: //rFib
      cout << "Nth Fibonacci Number: ";
      cin >> n;
      cout << rFib(n) << endl;
      break;
    case 3: //rSum
      cout << "Recursive Sum Vector Size: ";
      cin >> n;
      cout << "Values: ";
      readIntVector(v, n);
      cout << rSum(v) << endl;
      break;
    case 4: //rMax
      cout << "Recursive Max Vector Size: ";
      cin >> n;
      cout << "Values: ";
      readIntVector(v, n);
      cout << rMax(v) << endl;
      break;
    case 5: //isSorted
      cout << "isSorted Vector Size: ";
      cin >> n;
      cout << "Start and End: ";
      cin >> start >> end;
      cout << "Values: ";
      readIntVector(v, n);
      cout << isSorted(v, start, end) << endl;
      break;
    case 6: //isPalindrome
      cout << "String: ";
      cin >> s;
      cout << isPalindrome(s) << endl;
      break;
    case 7: //rBinarySearch
      cout << "Binary Search Vector Size: ";
      cin >> n;
      cout << "Target: ";
      cin >> end;
      cout << "Values: ";
      readIntVector(v, n);
      cout << rBinarySearch(v, 0, v.size()-1, end) << endl;
      break;
    case 8: //rSubsetSum
      cout << "Subset Sum Vector Size: ";
      cin >> n;
      cout << "Target: ";
      cin >> end;
      cout << "Values: ";
      readIntVector(v, n);
      cout << rSubsetSum(v, 0, end) << endl;
      break;
  }

  return 0;
}

/**************************************************
 * Read a vector of integers in from cin          *
 * v - vector<int> & - the integer vector to fill *
 * n - int - the number of integers to read       *
 * ************************************************/
void readIntVector(vector<int> &v, int n){
  int m = 0;
  for (int i = 0; i < n; i++){
    cin >> m;
    v.push_back(m);
  }
}
