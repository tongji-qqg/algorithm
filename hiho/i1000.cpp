#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;


// hello world :)
int main(){
	int a, b;
	vector< int > vect;
	while(cin >> a >> b){
		vect.push_back(a+b);
	}
	for(int i=0;i<vect.size();i++){
		cout << vect[i] << "\n";
	}
	return 0;
}
