#include <iostream>  
#include <vector>  
#include <string.h>  
#define abs(a) (a<0?0-(a):a)  

// http://hihocoder.com/contest/mstest2015octpractice/problem/4
using namespace std;  
int tt[9][9];  
  
// cached tt[a][b]  
int get(int a,int b){  
    if(tt[a][b]!=-1) return tt[a][b];  
    int s=abs(a-b);  
    //// if a->b is a horse-path  
    // if(abs(a%3-b%3)==2&&abs(a/3-b/3)==1||  
    // abs(a/3-b/3)==1&&abs(a%3-b%3)==2)  
    // return -2;//a->b is impossible  
    int t=0;  
    if(a%3==b%3) {  
        if(s<6) t=-2;  
        else t=(a+b)/2;  
    }  
    else if(a/3==b/3){  
        if(s<2) t=-2;  
        else t=(a+b)/2;  
    }  
    else{  
        int x=min(a,b),y=max(a,b);//@error: x=max(a,b),y=min(a,b)  
        if(x==2&&y==6||x==0&&y==8) t=(x+y)/2;  
        else t=-2;  
    }  
    return tt[a][b]=t;  
}  
void init(){  
    memset(tt,-1,sizeof(tt));  
    for(int i=0;i<9;i++)  
    for(int j=0;j<9;j++)  
        get(i,j);  
}  
void dfs(int &cnt,int curCnt,vector<int> &path,bool map[][9],bool visit[],int depth,int idx){  
    if(curCnt==0){  
        //four points at least  
        if(depth>=4) cnt++;//a solution  
    }  
    if(depth==9){  
        //// debug  
        // if(curCnt==0){  
            // for(int i=0;i<9;i++){  
                // cout<<path[i]+1<<" ";  
            // }cout<<endl;  
        // }  
        return;  
    }  
  
    for(int j=0;j<9;j++){  
        if(visit[j]) continue;  
  
        int tmp=-1;  
        int preCnt=curCnt;  
        if(idx>=0){  
            tmp=get(idx,j);  
            if(tmp>=0){  
                if(!visit[tmp]) continue;//tmp not passed yet  
            }  
            if(map[idx][j]) curCnt--;  
        }  
        visit[j]=true;  
        path.push_back(j);  
  
        dfs(cnt,curCnt,path,map,visit,depth+1,j);  
  
        path.pop_back();  
        curCnt=preCnt;   
        visit[j]=false;  
    }  
}  
int main(int argc, const char* argv[]){
    int casen;cin>>casen;  
    bool map[9][9];bool visit[9];  
    init();  
    for(int casei=0;casei<casen;casei++){  
        memset(map,0,sizeof(map));  
        memset(visit,0,sizeof(visit));  
        int edgen;cin>>edgen;  
        for(int i=0;i<edgen;i++){  
            int a,b;cin>>a>>b;a--,b--;  
            map[a][b]=map[b][a]=true;  
        }  
        int cnt=0;  
        vector<int> path;  
        dfs(cnt,edgen,path,map,visit,0,-1);  
        cout<<cnt<<endl;  
    }  
}  
