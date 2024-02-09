#include<iostream> 
#include<math.h>
using namespace std;
void Print(int board[][9],int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<board[i][j]<<' ';
		}
		cout<<"\n";
	}
}
bool isValid(int board[][9],int i,int j,int n,int num){
	// row and col check
	for(int x=0;x<n;x++){
		if(board[i][x]==num||board[x][j]==num)
		{
			return false;
		}
	}
	// sub matrix check
	int rn=sqrt(n);
	// i-i%sqrt(n) or (i/sqrt(n))*sqrt(n)
	int si=i-i%rn;
	int sj=j-j%rn;
	for(int x=si;x<si+rn;x++){
		for(int y=sj;y<sj+rn;y++){
			if(board[x][y]==num)return false;
		}
	}
	return true;
}
bool sudokuSolver(int i,int j,int board[][9],int n){
	if(i==n){
		Print(board,n);
		return true;
	}
	// if j moves to extreme right
	if(j==n){
		return sudokuSolver(i+1,0,board,n);
	}
	// if cell is already filled
	if(board[i][j]){
		return sudokuSolver(i,j+1,board,n);
	}
	for(int num=1;num<=9;num++){
		if(isValid(board,i,j,n,num)){
			board[i][j]=num;
			if(sudokuSolver(i,j+1,board,n))
				return true;
		}
		board[i][j]=0;
	}
	return false;
}
int main(){
	int n=9;
	int board[9][9]={
		{0,0,0,3,9,0,0,0,0},
		{1,0,0,0,0,6,0,0,9},
		{0,0,0,1,7,0,2,3,0},
		{2,0,4,0,0,0,0,0,6},
		{0,0,6,0,8,9,1,4,0},
		{7,9,0,6,0,0,3,0,0},
		{0,0,1,8,0,0,9,7,2},
		{0,7,0,9,2,0,4,6,0},
		{9,4,0,7,6,0,5,0,0}
	};
	sudokuSolver(0,0,board,n);
	return 0;
}