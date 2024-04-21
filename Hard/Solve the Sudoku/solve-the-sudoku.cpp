//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


// } Driver Code Ends
class Solution 
{
    public:
    bool isValid(int grid[N][N],int x,int y,int k)
    {
        for(int i=0;i<9;i++) if(grid[x][i]==k) return false;
        for(int i=0;i<9;i++) if(grid[i][y]==k) return false;
        int rst = (x/3)*3;
        int cst = (y/3)*3;
        for(int i=rst;i<(rst+3);i++)
        {
            for(int j = cst;j<(cst+3);j++)
            {
                if(grid[i][j]==k) return false;
            }
        }
        return true;
    }
    
    // function to solve Sudoku
    bool SolveSudoku(int grid[N][N])  
    { 
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(grid[i][j]==0)
                {
                    for(int p=1;p<=9;p++)
                    {
                        if(isValid(grid,i,j,p))
                        {
                            grid[i][j] = p;
                            if(SolveSudoku(grid)) return true;
                            grid[i][j]=0;
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        for(int i=0;i<9;i++) for(int j=0;j<9;j++) cout<<grid[i][j]<<" ";
    }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}
// } Driver Code Ends