#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class MultiSort{
private:
	vector<int> origin;
	vector<int> result;
	vector<int> range;
	vector< vector<int>* > table;
	int level;
public:
	MultiSort(int *arr, int size){
		origin(arr,size);
		for(int i=0;i<size;i++)
			range.push_back(1);
		table.push_back( &origin );
		level = 1;
	}
	~MultiSort(){
		for(int i=0;i<table.size();i++)
			delete table[i];
	}
	int sortTo( int index ){
	}
};
int main(int argc, const char* argv[]){
	int input[] = {2,3,5};
	int target  = 8;
	MultiSort ms(input, 3);
	int result = ms.sortTo( 8 );
	cout << result << endl;
	return 0;
}
