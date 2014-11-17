#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// for 2,3,5 input 
// int 598+ overflow will impact result
template<typename type>
class Generator{
private:
	vector<type> origin;
	vector<type> result;
	vector<type> range;
	vector< vector<type>* > table;
	void nextRange(){
		int size = origin.size();
		for(int i=0;i<size;i++){
			type k = 0;
			for(int j=i;j<size;j++)
				k += range[j];
			range[i] = k;
		}
	}
	void nextLevel(){
		nextRange();
		vector<type> &upper = *(table[table.size() - 1]);
		vector<type> *vect = new vector<type>();
		int size = origin.size();
		type count = 0;
		for(int i=0;i<size;i++){
			type n = range[i];
			for(int j=0;j<n;j++){
				vect->push_back(upper[count+j] * origin[i]);
			}
			if( n != 1)
				n = range[i] - range[i+1];
			count += n;
		}
		table.push_back( vect );
		generate();
	}
	void generate(){
		type min = result[ result.size() - 1 ];
		type max = (*table[ table.size() - 1 ])[0] * origin[0];
		for(int i=0;i<table.size();i++){
			vector<type> &vect = *table[i];
			for( int j=0;j<vect.size();j++){
				if( vect[j] > min && vect[j] < max )
					result.push_back( vect[j] );
			}
		}
		result.push_back( max );
		sort(result.begin(), result.end());
		//print();
	}
	void printTbl(){
		cout << "table " << endl;
		for(int i=0;i<table.size();i++){
			vector<type> &vect = *table[i];
			for(int j=0;j<vect.size();j++)
				cout<< vect[j] << " ";
			cout << "\n";
		}
		cout << "\n";
	}
public:
	Generator(int *arr, int size):origin(arr,arr+size){
		// suppose all number different
		// suppose all number positive
		// the init arr should be sorted 
		sort(origin.begin(), origin.end()); 
		for(int i=0;i<size;i++)
			range.push_back(1);
		table.push_back( &origin );
		if( origin.size() > 0)
			result.push_back( origin[0] );  // smallest input must be the smallest among all
	}
	~Generator(){
		for(int i=table.size()-1;i>0;i--)
			delete table[i];
	}
	int sortTo( int index ){
		while(this->result.size() < index)
			nextLevel();
		return this->result[index - 1];
	}
	void print(){
		printTbl();
		for(int i=0;i<result.size();i++)
			cout << result[i] << " ";
		cout << endl;
	}
};

int main(int argc, const char* argv[]){
	int input[] = {2,3,5};
	Generator<long long> ms(input, sizeof(input)/sizeof(int) );
	Generator<int> msi(input, sizeof(input)/sizeof(int) );
	//for(int i=598;i<600;i+=3){
		//cout << i << " \n";
		//cout << ms.sortTo( i ) << "\n";
		//ms.print();
		//cout << msi.sortTo(i) << "\n";
		//msi.print();
		//cout << "\n";
	//}
	cout << ms.sortTo(8);
	return 0;
}
