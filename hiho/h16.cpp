#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class Query{
public:
	int li;
	int ri;
};

int mi[25];
int N,Q;
int tableRow;
vector< Query > querys;
vector< int > table[25];

void printTable(){
	cout << "There are " << tableRow << " row in table\n";
	for(int i=0;i<tableRow;i++){
		for(int j=0;j<table[i].size();j++){
			cout << table[i][j] << " ";
		}
		cout << endl;
	}
}

void init(){
	// read input
	int tmpi;
	Query tmpq;
	for(int i=0;i<25;i++)
		mi[i] = 1 << i;
	cin >> N;
	for(int i=0;i<N;i++){
		cin >> tmpi;
		table[0].push_back( tmpi );	
	}
	cin >> Q;
	for(int i=0;i<Q;i++){
		cin >> tmpq.li >> tmpq.ri;
		querys.push_back( tmpq );
	}
	//analysis input
	for(tableRow = 0;tableRow<25;tableRow++){ //2 ^ 24 = 16777216, 10^7
		if( N > mi[tableRow] ) break;
	}
	for(int i=1;i<tableRow;i++){
		vector< int > & pre = table[i-1];
		vector< int > & cur = table[i];
		int end = pre.size();
		if(end % 2 == 0){
			for(int j=0;j<end;j+=2){
				cur.push_back( max( pre[j], pre[j+1] ) );
			}
		}
		else{
			end --;
			for(int j=0;j<end;j+=2){
				cur.push_back( max( pre[j], pre[j+1] ) );
			}
			cur.push_back( pre[end] );
		}
	}
}

int main(int argc, const char* argv[]){
	init();
	printTable();
	return 0;
}
