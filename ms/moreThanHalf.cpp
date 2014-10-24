#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

// problem an array of many int,
// assume there are more than half number of same int in this array
// like 2 in [2, 14 , 2 , 3 , 4 , 2 , 2 , 2 , 2 , 14]
// design a algorithm to find this number in O(n)

// the solution is quiet clever 
// cause the target x is more than half,
// so fetch tow different number one time,
// finally the left number will be all same and be the target

using namespace std;

class VStack{
	int m_size;
	int m_top;
public:
	VStack(){
		m_size = 0;
		m_top  = 0;
	}
	void push(int x){
		if(m_size == 0)
			m_top = x;
		m_size++;
	}
	void pop(){
		if(m_size > 0)
			m_size--;
	}
	int top(){
		if(m_size > 0)
			return m_top;
		return 0;
	}
	int size(){
		return m_size;
	}	
	void print(){
		cout << "size: " << m_size << " top: " << m_top;
	}
};

int main(int argc, const char* argv[]){
	VStack s;
	int arr[] = {2, 14 , 2 , 3 , 4 , 2 , 2 , 2 , 2 , 14};
	int size = sizeof(arr) / sizeof(int);
	for( int i=0;i<size;i++){
		if(s.size() == 0)s.push( arr[i] );	
		else if( s.top() == arr[i]) s.push( arr[i] );
		else s.pop();
	}
	if( s.size() > 0)
	cout << "The number is " << s.top() << endl;
	return 0;
}
