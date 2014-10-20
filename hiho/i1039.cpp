#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int getFirstLetterNum(const string s, int index){
	if(s.size() == 0) return 0;
	char x = s[index];
	int  y = index + 1;
	for(;  y < s.size() && s[y] == x ; y++);
	return y - index;
}
int process(const string test){
	string s(test);
	bool have = true;
	do{
		have = false;
		if(s.size() == 0) return 0;
		vector< char > vect;
		for(int i=0;i<s.size();){
			int l = getFirstLetterNum( s, i );
			if(l == 1)vect.push_back(s[i++]);
			else {
				i+=l;
				have = true;
			}
		}
		s = string( vect.begin(), vect.end() );
	}while(have);
	return s.size();
}
int main(){
	int t;
	vector< int > result;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		int min = s.size();
		for(int i=0;i<=s.size();i++){
			for(char x='A'; x<'D';x++ ){
				string test = s.substr(0,i) + x + s.substr(i);
				//cout << test << endl;
				int length = process( test );
				if(min > length) min = length;
			}
		}
		result.push_back( s.size() - min + 1);
	}
	for(int i=0;i<result.size();i++){
		cout << result[i] << "\n";
	}
	return 0;
}
