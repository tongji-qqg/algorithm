#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<sstream>
#include<iterator>

// http://hihocoder.com/problemset/problem/1051
// one thing for sure, all card must use continuously to have the longest time
// n holes, and m cards,
// need O(n - m + 1) to calculate the max time 

using namespace std;


void print(vector<int> vect){
	int end = vect.size() - 1;
	for(int i=0;i<end;i++)
		cout << vect[i] << "\n";
	cout<<vect[end];
}
int process(){
	int n,m;
	vector< int > vect;
	string input;
	cin >> n >> m;
	getline(cin, input);
	getline(cin, input);
	istringstream ss(input);
	if(n <= m) return 100;
	copy(istream_iterator<int>(ss),
	     istream_iterator<int>(),
		 back_inserter(vect) );
	vect.push_back(101);
	int max = vect[m] - 1;
	for(int i=m + 1;i<=n;i++){
		int tmp = vect[i] - vect[i-m - 1] - 1;
		if(tmp > max) max = tmp;
	}
	return max;
}
int main(int argc, const char* argv[]){
	int t;
	vector< int > result;
	cin >> t;
	while(t--)
		result.push_back(process());
	print(result);
	return 0;
}
