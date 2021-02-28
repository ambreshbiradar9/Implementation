#include<iostream>
#include<limits.h>
#include<vector>
#include<chrono> 
#include<algorithm>
using namespace std;
using namespace std::chrono;
bool comp(int a,int b)
{
    return (a<b);
}

int function(vector<vector<int>> matrix,int i,int j,int R,int C,vector<vector<int>> &result)
{
    int left=INT_MAX/2;
    int right=INT_MAX/2; 
    int bottom=INT_MAX/2;
    int top=INT_MAX/2;
    int check=0;
   
    if(result[i][j]!=-2)
    {
        return result[i][j];
    }
    if(matrix[i][j]==9)
    {
        return 0;
    }
    matrix[i][j]=0;
    if((i+1<R)&&(matrix[i+1][j]!=0))
    {
        bottom=1+function(matrix,i+1,j,R,C,result);
        check++;
    }    
    if((i-1>=0)&&(matrix[i-1][j]!=0))
    {
        top=1+function(matrix,i-1,j,R,C,result);
        check++;
    }
    if((j-1>=0)&&(matrix[i][j-1]!=0))
    {
        left=1+function(matrix,i,j-1,R,C,result);
        check++;
    }
    if((j+1<C)&&(matrix[i][j+1]!=0))
    {
        right=1+function(matrix,i,j+1,R,C,result);
        check++;
    }

    return result[i][j]=min({right,left,bottom,top},comp);
}




int main()
{
    vector<vector<int>> matrix={{1,0,1,1,1,1,1,1},{0,0,0,0,0,0,0,1},{1,1,1,1,1,1,1,1},{1,0,0,0,0,0,0,0},{1,1,0,9,0,0,0,0}};
    /*for(int i=0;i<matrix.size();i++)
    {
        for(int j=0;j<matrix[0].size();j++)
        {
            cout<<matrix[i][j]<<"  ";
        }
        cout<<endl;
    }*/
    int R=matrix.size();
    int C=matrix[0].size();
    vector<vector<int>> result(R,vector<int>(C,-2));
        auto start = high_resolution_clock::now();
        if(function(matrix,0,0,R,C,result)<INT_MAX/2)
        {
            cout<<function(matrix,0,0,R,C,result)<<endl;
        }
        else
        {
            cout<<-1<<endl;
        }
        

    auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<microseconds>(stop - start); 
    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl; 
}