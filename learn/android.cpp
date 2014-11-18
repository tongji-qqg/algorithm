#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

class Permutation{
private:
	vector<int> arr;
	vector<vector<int> > result;
	int size;
	int range;
	int count;
	int total;
	void generate(vector<int> &all, vector<int>&select, int level){
		if( level > 0){
			for(int i=0;i<size;i++){
				if( all[i] == -1) continue;
				int tmp = all[i];
				all[i] = -1;
				select[range - level] = tmp;
				generate(all, select, level - 1);
				all[i] = tmp;
			}
		}
		else{
			result.push_back( select );
		}
	}
public:
	Permutation(int min, int max){
		arr.clear();
		size = max - min + 1;
		for( int i=0;i<size;i++ )
			arr.push_back( min + i );
	}
	const vector<vector<int> >& get(int r){
		if( r > size ) r = size;
		result.clear();
		count = 0;
		total = 1;
		range = r;
		vector<int> select;
		for( int i=0;i<range;i++){
			total = total * (size -i);
			select.push_back(0);
		}

		vector<int> all(arr);
		generate(all, select, range);
		return result;
	}
	
	void print(){
		for(int i=0;i<result.size();i++){
			for(int j=0;j<range;j++)
				cout << result[i][j] << " ";
			cout << "\n";
		}
	}
};
class AndroidLock{
private:
	int invalid[10][10];
	double ruler[6];
	double ref[6];
	int distance[10][10];
	void init(){
		for(int i=0;i<10;i++)
			for(int j=0;j<10;j++)
				invalid[i][j] = 0;
		invalid[1][3] = 2;
		invalid[4][6] = 5;
		invalid[7][9] = 8;
		invalid[1][7] = 4;
		invalid[2][8] = 5;
		invalid[3][9] = 6;
		invalid[3][7] = 5;
		invalid[1][9] = 5;

		invalid[3][1] = 2;
		invalid[6][4] = 5;
		invalid[9][7] = 8;
		invalid[7][1] = 4;
		invalid[8][2] = 5;
		invalid[9][3] = 6;
		invalid[7][3] = 5;
		invalid[9][1] = 5;

		int x[10] = {
			0,0,0,0,1,1,1,2,2,2
		};
		int y[10] = {
			0,0,1,2,0,1,2,0,1,2
		};
		for( int i=0;i<10;i++)
			for(int j=0;j<10;j++)
				distance[i][j] = -1;
		for( int i=1;i<10;i++){
			for(int j=1;j<10;j++){
				int a = x[i] - x[j];
				a = a * a;
				int b = y[i] - y[j];
				b = b * b;
				distance[i][j] = getRulerIndex(a + b);
			}
		}
		ruler[0] = 0;
		ruler[1] = 1;
		ruler[2] = sqrt(2);
		ruler[3] = 2;
		ruler[4] = sqrt(5);
		ruler[5] = sqrt(8);
	}
	int getRulerIndex(int sum){
		switch(sum){
			case 1: return 1;
			case 2: return 2;
			case 4: return 3;
			case 5: return 4;
			case 8: return 5;
			default: return 0;
		}
	}
	bool validPath(const vector<int> & v){
		if(v.size() < 2) return true;
		for(int j=0,k=1; k<v.size(); j++,k++){
			int x = invalid[v[j]][v[k]];
			if( x > 0 ){
				bool flag = true;
				for(int i=0;i<j;i++)
					if(v[i] == x)
						flag = false;
				if(flag) return false;
			}
		}
		return true;
	}
	double calculatePath(const vector<int> &v){
		if( v.size() < 2) return 0;
		double r = 0;
		for( int j=0,k=1;k<v.size();j++,k++){
			r += ruler[distance[v[j]][v[k]]];
		}
		return r;
	}
public:
	AndroidLock(){
		init();
	}
	void totalPath(){
		Permutation p(1,9);
		int total = 0;
		for( int i=4;i<=9;i++){
			const vector<vector<int> > set = p.get(i);
			for( int j=0;j<set.size();j++){
				if( validPath( set[j] ) )
					total++;
			}
		}
		cout << total << "\n";
	}

	void maxPath(){
		Permutation p(1,9);
		double max = 0;
		for( int i=9;i<=9;i++){
			const vector<vector<int> > set = p.get(i);
			for( int j=0;j<set.size();j++){
				if( validPath( set[j] ) ){
					double d = calculatePath( set[j] );
					if( d > max ){ max = d; }
				}
			}
		}
		cout << max << "\n";
	}
};
int main(int argc, const char* argv[]){
	// assume basic distance is 1 :)
	AndroidLock a;
	a.maxPath();
	return 0;
}
