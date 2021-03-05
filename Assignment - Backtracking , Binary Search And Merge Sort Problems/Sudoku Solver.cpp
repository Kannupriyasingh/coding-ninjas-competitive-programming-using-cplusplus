/*Given a 9*9 sudoku board, in which some entries are filled and others are 0 (0 indicates that the cell is empty), you need to find out whether the Sudoku puzzle can be solved or not i.e. return true or false.
Input Format :
9 Lines where ith line contains ith row elements separated by space
Output Format :
 true or false
Sample Input :
9 0 0 0 2 0 7 5 0 
6 0 0 0 5 0 0 4 0 
0 2 0 4 0 0 0 1 0 
2 0 8 0 0 0 0 0 0 
0 7 0 5 0 9 0 6 0 
0 0 0 0 0 0 4 0 1 
0 1 0 0 0 5 0 8 0 
0 9 0 0 7 0 0 0 4 
0 8 2 0 4 0 0 0 6
Sample Output :
true
*/


#include<iostream>
using namespace std;

bool isSafeToPut(int mat[][9],int i,int j,int n,int number)
{
	for(int k=0;k<n;k++)
	{
		if(mat[i][k]==number || mat[k][j]==number)
		{
			return false;
		}
	}

	int starti=(i/3)*3;
	int startj=(j/3)*3;

	for(int k=starti;k<starti+3;k++)
	{
		for(int l=startj;l<startj+3;l++)
		{
			if(mat[k][l]==number)
			{
				return false;
			}
		}
	}

	return true;

}


bool sudoku(int mat[][9],int n,int i,int j)
{
	if(i==n)
	{
		return true;
	}

	if(j==n)
	{
		return sudoku(mat,n,i+1,0);
	}

	if(mat[i][j]!=0)
	{
		return sudoku(mat,n,i,j+1);
	}

	for(int number=1;number<=n;number++)
	{
		if(isSafeToPut(mat,i,j,n,number))
		{
			mat[i][j]=number;
			bool KyaSbSHiRaha=sudoku(mat,n,i,j+1);
			if(KyaSbSHiRaha)
			{
				return true;
			}
			mat[i][j]=0;
		}
	}
	return false;
}



bool sudokuSolver(int board[][9]){

  /* Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Don't print output and return output as specified in the question
  */
	return sudoku(board,9,0,0);

}


/*define N 9
bool emptylocation(int board[][9], int &row, int &col)
{
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
        {
            if(board[i][j] == 0)
            {
                row = i;
                col = j;
                return true;
            }
        }
    return false;
}
bool issafeinrow(int board[][9], int row, int num)
{
   for(int i = 0; i < N; i++)
        if(board[row][i] == num)
            return false;
    
    return true;
}
bool issafeincol(int board[][9], int col, int num)
{
    for(int i = 0; i < N; i++)
        if(board[i][col] == num)
            return false;
    
    return true;
}
bool issafeingrid(int board[][9], int row, int col, int num)
{
     int rowfactor = row - (row % 3);
   int colfactor = col - (col % 3);
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
        {
            if(board[i + rowfactor][j + colfactor] == num)
                return false;
        }
 return true;
    
}
bool issafe(int board[][9], int row, int col, int i)
{ 
    if(issafeinrow(board,row,i) && issafeincol(board,col,i) && issafeingrid(board,row,col,i))
        return true;
    return false;
}
bool sudokuSolver(int board[][9]){

 
    int row, col;
    if(!emptylocation(board,row,col))
        return true;
    for(int i = 1; i <= N; i++)
    {
        if(issafe(board,row,col,i)){
            board[row][col] = 1;
            if(sudokuSolver(board))
                return true;
            board[row][col] = 0;
        }
    }
    return false;

}*/


#include<iostream>
using namespace std;
#include "Solution.h"

int main(){

  int n = 9; 
  int board[9][9];
  for(int i = 0; i < n ;i++){
	for(int j = 0; j < n; j++){
        	cin >> board[i][j];
        }		
  }
  if(sudokuSolver(board)){
	cout << "true";	
  }else{
	cout << "false";	
  }
}


