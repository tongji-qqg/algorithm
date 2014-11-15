#include<iostream>
#include<cstdio>
#include<cstring>

#define ALPHABET_SIZE 26
#define DICT_SIZE 1000000
// no. 1014 quiz of hiho coder
// at first i find it hard to store 
// all the word in memory,
// 26^26 is very large!
// but after i lookup others code in the website,
// i recognize that i dont need to store that large,
// what i need is to store 100000 words in dict
// words * word.length  nodes is all i need,
// after that, try tree is not so hard,
// here i reference the code i read, and use class CLZ{}poolDICT_SIZE[]
// to allocate all node at beginning of running. i think it good for no need to delete
// int node.next pointer to node can also work,
//
// ps, i try 3 times, always runtime error,
// finally i find that i miss 1 '0' in DICT_SIZE,
// yeah, dict size should be 5 '0', but i need 6 '0'
// be cautious next time !:)
using namespace std;
class Node{
public:
	int next[ALPHABET_SIZE];
	int weight;
	void init(){
		weight=0;
		memset(next,0,sizeof(next));
	}
}pool[DICT_SIZE];
class Tree{
public:
	int  count;
	void insert( const char* buf){
		const char *s = buf;
		int p = 0;
		if( s == NULL ) return; 
		while( *s ){
			int index = *s - 'a';
			int next  = pool[p].next[index];
			if( next <= 0 || next >= count){
				next = count++;
				pool[next].init();
				pool[p].next[index] = next;
			}
			p = next;
			pool[p].weight++;
			s++;
		}
	}
	int query(const char* buf){
		const char * s = buf;
		int p = 0;
		int result = 0;
		if( s == NULL ) return 0; 
		while( *s ){
			int index = *s - 'a';
			int next  = pool[p].next[index];
			if( next <= 0 || next >= count){ result = 0;break;}
			p = next;
			result = pool[next].weight;
			s++;
		}
		printf("%d\n", result);
		return result;
	}

	Tree(){
		count = 1;
	}
};

int main(){
	int n;
	char buf[20];
	Tree tree;
	scanf("%d",&n);
	while(n--){
		scanf("%s",buf);
		tree.insert(buf);
	}
	scanf("%d",&n);
	while(n--){
		scanf("%s",buf);
		tree.query( buf );
	}
	return 0;
}
