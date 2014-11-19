#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>

using namespace std;

// this impl very smart
// i will study into it futher
class Kmp{
private:
	vector<int> next;
	const char* pattern;
	void print( vector<int>& v){
		for( int i=0;i<v.size();i++)
			cout << v[i] << " ";
		cout << "\n";
	}
public:
	Kmp(){}
	Kmp(const char* p){
		setOverlapPattern(p);
	}
	void setNormalPattern(const char* p){
		next.clear();
		pattern = p;
		if( p == NULL || *p =='\0') return;
		next.push_back( -1 );
		for(int i=0;p[i+1] != '\0';i++){
			int val = next[i] + 1;
			while( val > 0 && p[i] != p[val-1] )
				val = next[val-1] + 1;
			next.push_back( val );
		}
		next.push_back(0);
	}
	void setOverlapPattern( const char* p){
		next.clear();
		pattern = p;
		if( p == NULL || *p =='\0') return;
		next.push_back( -1 );
		for(int i=0;p[i] != '\0';i++){
			int val = next[i] + 1;
			while( val > 0 && p[i] != p[val-1] )
				val = next[val-1] + 1;
			next.push_back( val );
		}
	}
	int match(const char* str){
		if( str==NULL || *str == '\0')
			return 0;
		int r=0;
		int j=0;
		for( int i=0;str[i] != '\0';i++){
			while(1){
				if( str[i] == pattern[j] ){
					j++;
					if(j == next.size()-1 ){
						r++; j=next[j];
					}
					break;
				}else if(j == 0) break;
				else j = next[j];
			}
		}
		return r;
	}
};

int main(int argc, const char* argv[]){
	int n;
	char p[10001];
	char s[1000001];
	Kmp kmp;
	scanf("%d",&n);
	while( n-- > 0){
		scanf("%s",p);
		scanf("%s",s);
		kmp.setOverlapPattern( p );
		printf("%d \n", kmp.match( s ) );
	}
	return 0;
}
