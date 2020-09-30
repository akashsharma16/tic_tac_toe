#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int checkPos(vector<vector<char>> &a,int x,int y,char c){
    int cnt=0,m=0;
    for(int i=0;i<3;i++){
        if(a[i][y]==c){
            cnt++;
        }
    }
    if(cnt>m){
        m=cnt;
    }
    cnt=0;
    for(int i=0;i<3;i++){
        if(a[x][i]==c){
            cnt++;
        }
    }
    if(cnt>m){
        m=cnt;
    }
    cnt=0;
    int f=0;
    if(x==y){
        f=1;
    }
    else if((x==2 && y==0) || (x==0 && y==2)){
        f=1;
    }
    
    if(f==1){
        for(int i=0;i<3;i++){
            if(a[i][i]==c){
                cnt++;
            }
        }
        
        if(cnt>m){
            m=cnt;
        }
        cnt=0;
        
        for(int i=0,j=2;i<3 && j<3;i++,j--){
            if(a[i][j]==c){
                cnt++;
            }
        }
        
        if(cnt>m){
            m=cnt;
        }
        cnt=0;
    }
    return m;
}

void playMove(vector<vector<char>> &a,char c){
    int x=0,y=0,m=0;
    
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(a[i][j]=='.'){
                int c=checkPos(a,i,j,c);
                if(c>m){
                    m=c;
                    x=i;
                    y=j;
                }
            }
        }
    }
    
    if(c=='o'){
    a[x][y]='x';
    }
    else{
        a[x][y]='o';
    }
}

int placeMove(vector<vector<char>> &a,int x,int y,int t){
    if(a[x][y]=='.'){
        if(t==1)
            a[0][0]='x';
        else
            a[0][0]='o';
            
        return 1;
    }
    else{
        return 0;
    }
}

int main() {
	// your code goes here
	vector<vector<char>> a;
	for(int i=0;i<3;i++){
	    vector<char> v;
	    for(int j=0;j<3;j++){
	        v.push_back('.');
	    }
	    a.push_back(v);
	}
	cout<<"enter your player no. 1 = 'x' or player 2 'o':"<<endl;
	int p;
	cin>>p;
	if(p==2){
	    a[1][1]='x';
	}
	while(1){
	    cout<<"Enter your move no.:"<<endl;
	    int t;
	    cin>>t;
	    if(t<1 || t>9){
	        cout<<"Input is invalid"<<endl;
	        continue;
	    }
	    int f=0;
	    if(t==1){
	        f=placeMove(a,0,0,p);
	    }
	    else if(t==2){
	        f=placeMove(a,0,1,p);
	    }
	    else if(t==3){
	        f=placeMove(a,0,2,p);
	    }
	    else if(t==4){
	        f=placeMove(a,1,0,p);
	    }
	    else if(t==5){
	        f=placeMove(a,1,1,p);
	    }
	    else if(t==6){
	        f=placeMove(a,1,2,p);
	    }
	    else if(t==7){
	        f=placeMove(a,2,0,p);
	    }
	    else if(t==8){
	        f=placeMove(a,2,1,p);
	    }
	    else if(t==9){
	        f=placeMove(a,2,2,p);
	    }
	    
	    if(f==0){
	        cout<<"This position already acquired"<<endl;
	        continue;
	    }
	    
	    
	}
	return 0;
}
