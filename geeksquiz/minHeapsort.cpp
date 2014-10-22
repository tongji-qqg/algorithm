#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

void swap(int &a, int &b){int tmp = a; a = b; b = tmp;}

void printVector(vector< int > &v){
	for(int i=0; i<v.size(); i++)
		cout << v[i] << " "; 
}

void minHeapify(vector<int> &vect, int ids, int heapsize){
	int size = heapsize;
	if( heapsize > vect.size() ) size = vect.size();
	int min  = ids;
	int left = ids * 2 + 1;
	int right = (ids + 1) * 2;

	if(left < size && vect[left] < vect[min]) min = left;
	if(right < size && vect[right] < vect[min]) min = right;
	if(min != ids){
		swap(vect[min], vect[ids]);
		minHeapify(vect, min, size);
	}
}

void buildMinHeap(vector<int>& vect){
	for(int i=(vect.size()-2)/2;i >= 0; --i)
		minHeapify( vect, i, vect.size() );
}

void heapsort(vector<int>& v){

	buildMinHeap( v );

	for(int i=v.size() - 1; i >= 0; --i){
		swap(v[0], v[i]);
		minHeapify(v, 0, i);
	}
}

int main(int argc, const char* argv[]){
	int arr[] = {5,8,2,7,9,3,1,6,4};
	vector< int > v(arr, arr + sizeof(arr) / sizeof(int) );
	printVector( v );
	cout << "\n";
	heapsort( v );
	printVector( v );
	cout << "\n";
	return 0;
}
