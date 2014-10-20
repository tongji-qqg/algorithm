#include<iostream>
#include<vector>
#include<cstring>
#include<string>
#include<algorithm>

// http://hihocoder.com/problemset/problem/1039
// here use brute force, 
// suppose input string size is x
// then there is 3(x + 1) kinds of cases to consider
// enumnate all cases 
// and find the string length after eliminate
//
// here use string and vector while eliminate
// for easy understand
//
// also can use char[], 
// and mark all eliminated char to 'D', or something else
// faster and smaller, but a little hard

using namespace std;

/////////////////////////////////////////////////
// second implementation

int getNextPos(char * buffer, int start){
	for(int i=start;buffer[i] != '\0';i++){
		if(buffer[i] != 'D')
			return i;
	}
	return 1000;
}
int eliminate(string text){
	int length = text.size();
	char buffer[102];
	strcpy(buffer, text.c_str());
	bool flag = true;
	do{
		flag = false;
		int pos = getNextPos(buffer,0);
		if(pos > length)break;
		for(int i=pos;i<length;){
			char x = buffer[i];
			int y = getNextPos(buffer, i+1);
			if( y > length) break;
			if( buffer[y] == x){
				flag =true;
				buffer[i] = 'D';
				while(1){
					if(buffer[y] == x)
						buffer[y] = 'D';
					else break;
					int tmp = getNextPos(buffer, y+1);
					if(y > length)break;
					y = tmp;
				}
			}
			i = getNextPos(buffer, y);
		}
	}while(flag);
	int result = length;
	for(int i=0;i<length;i++)
		if(buffer[i] == 'D')
			result--;
	return result;
}
/////////////////////////////////////////////////
// first impl

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
				//int length = process( test );
				int length = eliminate( test );
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
