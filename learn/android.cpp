#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Permutation{
	vector<int> arr;
	vector<int> usage;
	vector<int> result;
	int size;
	int range;
	int count;
	void clean(){
		arr.clear();
		usage.clear();
		result.clear();
	}
public:
	void Permutation(int min, int max){
		clean();
		size = max - min + 1;
		for( int i=0;i<size;i++ )
			arr.push_back( min + i );
	}
	void prepare(int r){
		if( r > size ) r = size;
		usage.clear();
		result.clear();
		count = 0;
		range = r;
		for( int i=0;i<range;i++){
			usage.push_back( i );
			result.push_back( arr[i] );
		}
	}
	bool hasNext(){
		bool flag = false;
		for(int i=0;i<range;i++)
			if(usage[i] != size - i)  flag = true;
		return flag;
	}
	vector& next(){
		if( count != 0){

			count++;
		}
		return reuslt;
	}
};
class Android{
private:
	int invalid[9][9];
	void init(){
		for(int i=0;i<81;i++)
			**(invalid + i) = 0;
		invalid[0][2] = 1;
		invalid[3][5] = 4;
		invalid[6][8] = 7;
		invalid[0][6] = 3;
		invalid[1][7] = 4;
		invalid[2][8] = 5;
		invalid[0][8] = 4;
		invalid[2][6] = 4;

		invalid[2][0] = 1;
		invalid[5][3] = 4;
		invalid[8][6] = 7;
		invalid[6][0] = 3;
		invalid[7][1] = 4;
		invalid[8][2] = 5;
		invalid[8][0] = 4;
		invalid[6][2] = 4;
	}
public:
	Android(){
		init();
	}

	void print(){
		cout << sizeof(invalid) / sizeof(int) << endl;
	}
};
int main(int argc, const char* argv[]){
	Android a;
	a.print();
	return 0;
}
