#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int isNumber( const char x ){
	if( x >= '0' && x <= '9')
		return x - '0';
	return -1;
}

int isOper( const char x){
	if( x == '+') return 1;
	if( x == '-') return 2;
	if( x == '*') return 3;
	return -1;
}

bool getNumberValue(const char* pstr, int ids, int& value, int& length){
	value = isNumber( pstr[ids] );
	length = 0;
	if( value < 0 )
		return false;
	for( length=1; ; length++){
		int x = isNumber( pstr[length + ids] );
		if( x < 0)
			break;
		value = value * 10 + x;
	}
	return true;
}

int eval(const string s){
	const char* p = s.c_str();
	int length = 0;
	int value = 0;
	if( !getNumberValue( p, 0, value, length) ) return -1;
	for(int i=length ; i<s.size(); ){
		char oper = *(p + i);
		int next;
		if( !getNumberValue( p, i + 1, next, length) ) return -1;

		if( oper == '+') value = value + next;
		else if( oper == '-') value = value - next;
		else if( oper == '*') value = value * next;
		else return -1;
		i = i + length + 1;
	}
	return value;
}

int main(int argc, const char* argv[]){
	string s;
	while( cin >> s){
		vector< char > v;
		for(int i=0;i<s.size();i++){
			if(s[i] != ' ')
				v.push_back( s[i] );
		}
		cout << eval( string(v.begin(), v.end() ) ) << endl;
	}
	return 0;
}
