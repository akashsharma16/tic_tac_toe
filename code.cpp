#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// A function that returns true if any of the row 
// is crossed with the same player's move 
bool rowCrossed(vector<vector<char>> board) 
{ 
    for (int i=0; i<3; i++) 
    { 
        if (board[i][0] == board[i][1] && 
            board[i][1] == board[i][2] &&  
            board[i][0] != '.') 
            return (true); 
    } 
    return(false); 
} 
  
// A function that returns true if any of the column 
// is crossed with the same player's move 
bool columnCrossed(vector<vector<char>> board) 
{ 
    for (int i=0; i<3; i++) 
    { 
        if (board[0][i] == board[1][i] && 
            board[1][i] == board[2][i] &&  
            board[0][i] != '.') 
            return (true); 
    } 
    return(false); 
} 
  
// A function that returns true if any of the diagonal 
// is crossed with the same player's move 
bool diagonalCrossed(vector<vector<char>> board) 
{ 
    if (board[0][0] == board[1][1] && 
        board[1][1] == board[2][2] &&  
        board[0][0] != '.') 
        return(true); 
          
    if (board[0][2] == board[1][1] && 
        board[1][1] == board[2][0] && 
         board[0][2] != '.') 
        return(true); 
  
    return(false); 
} 
  
// A function that returns true if the game is over 
// else it returns a false 
bool gameOver(vector<vector<char>> board) 
{ 
    return(rowCrossed(board) || columnCrossed(board) 
            || diagonalCrossed(board) ); 
} 

void showBoard(vector<vector<char>> board) 
{ 
    printf("\n\n"); 
    cout<<"----------------------------------------------------------------"<<endl;
    printf("\t\t\t  %c | %c  | %c  \n", board[0][0], 
                             board[0][1], board[0][2]); 
    printf("\t\t\t--------------\n"); 
    printf("\t\t\t  %c | %c  | %c  \n", board[1][0], 
                             board[1][1], board[1][2]); 
    printf("\t\t\t--------------\n"); 
    printf("\t\t\t  %c | %c  | %c  \n\n", board[2][0], 
                             board[2][1], board[2][2]); 
   cout<<"----------------------------------------------------------------"<<endl;
    return; 
} 

int diagonalPosCheckLeft(vector<vector<char>> &v, char c) 
{
    int cnt=0;
    if(v[1][1] == c){
        cnt++;
    }
    if(v[0][2] == c){
        cnt++;
    }
    if (v[2][0] == c){
        cnt++;
    }
    return cnt;
}

int diagonalPosCheckRight(vector<vector<char>> &v, char c) 
{
    int cnt=0;
    if (v[0][0] == c){
        cnt++;
    }
    if(v[1][1] == c){
        cnt++;
    }
    if (v[2][2] == c){
        cnt++;
    }
    return cnt;
}

int checkPos(vector<vector<char>> &a,int x,int y,char c){
    int cnt=0,m=0;
    //counting human's move in column of y
    for(int i=0;i<3;i++){
        if(a[i][y]==c){
            cnt++;
        }
    }
    if(cnt>m){
        m=cnt;
    }
    cnt=0;
    //counting human's move in row of x
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
    //count human's move in both left and right diagonal 
    if(f==1){
        cnt = diagonalPosCheckLeft(a,c);
        //cout<<"diagonal LEFT cnt for x = "<<x<<" and y = "<<y<<" is : "<<cnt<<endl;
        m=max(cnt,m);
        cnt= diagonalPosCheckRight(a,c);
        m=max(cnt,m);
        //cout<<"diagonal RIGHT cnt for x = "<<x<<" and y = "<<y<<" is : "<<cnt<<endl;
        cnt=0;
    }
    return m;
}

//placing computer's move 
void playMove(vector<vector<char>> &a,char c){
    int x=0,y=0,m=INT_MIN;
    //cout<<"============> PLACE MOVE :"<<c<<endl;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(a[i][j]=='.'){
                int cnt=checkPos(a,i,j,c);
                // cout<<" -----------> Count for move at x= "<<i<<" and y= "<<j<<" is :: "<<cnt<<endl;
                
                if(cnt>m){
                    m=cnt;
                    //storing the position of x and y for which the count of row , column or diagonal moves of human is maximum
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

//placing human's move
int placeMove(vector<vector<char>> &a,int x,int y,int t){
    if(a[x][y]=='.'){
        if(t==1)
            a[x][y]='x';
        else
            a[x][y]='o';
            
        return 1;
    }
    return 0;
}

int main() {

while(1){
	vector<vector<char>> a;
	for(int i=0;i<3;i++){
	    vector<char> v;
	    for(int j=0;j<3;j++){
	        v.push_back('.');
	    }
	    a.push_back(v);
	}
	cout<<"enter your player no. 1 for 'x' or player 2 for 'o':"<<endl;
	int p;
	cin>>p;
	int human = 0;
	char humanMove;
	int movesCnt=0;
	if(p==1){
	    human = 0;
	    humanMove = 'x';
	}
	else{
	    human = 1;
	    humanMove = 'o';
	}
	if(p==2){
	    a[1][1]='x';
	    movesCnt++;
	}
	int anyOneWon =0 ;
	while(movesCnt < 9 ){
	    if(movesCnt % 2 == human){
	    cout<<"Present state of board : "<<endl;
	    showBoard(a);
	    cout<<"Enter your move no.:"<<endl;
	    int t;
	    cin>>t;
	    if(t<1 || t>9){
	        cout<<"Input is invalid"<<endl;
	        continue;
	    }
	    int f=0;
	    int x=(t-1)/3,y=(t-1)%3;
	    f=placeMove(a,x,y,p);
	    if(f==0){
    	   cout<<"This position already acquired"<<endl;
    	   continue;
    	}
	    cout<<"Human move placed at x="<<x<<" and y="<<y<<endl;
	    showBoard(a);
	    if(gameOver(a)){
	        cout<<"Human won this game"<<endl;
	        showBoard(a);
	        anyOneWon =1;
	        break;
	    }
	    }
	    else{
	        playMove(a,humanMove);
	        if(gameOver(a)){
	            cout<<"Computer won this game"<<endl;
	            showBoard(a);
	            anyOneWon = 1;
	            break;
	        }
	    }
	    movesCnt++;
	}


    if(anyOneWon == 0){
        showBoard(a);
        cout<<" THIS GAME IS A DRAW "<<endl;
    }
    cout<<" ========= xxxxx ========== "<<endl;
    cout<<"         THIS IS GAME OVER          "<<endl;
    
    cout<<" Do you want to play once more ?"<<endl;
    cout<<" Enter 1 if yes or 0 if no:"<<endl;
    int e=0;
    cin>>e;
    if(e==0){
        break;
    }
}
	return 0;
}

