#include<iostream>
#include<vector>
using namespace std;
bool weCanGo (int a,int b, vector<vector<int>>&grid){
    return (a<grid.size()&&b<grid.size()&&a>=0&&b>=0)&&grid[a][b]==1;
}
int f (int i,int j,vector<vector<int>> &grid){
      int n= grid.size();
      if (i==n-1&&j==n-1) {
         for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"--------\n";
        return 1;
        }
      int ans=0;
      grid[i][j]=2;
      if (weCanGo(i,j+1,grid)){// right
        ans+= f(i,j+1,grid);
      }
       if (weCanGo(i+1,j,grid)){// below
        ans+= f(i+1,j,grid);
      }      
       if (weCanGo(i,j-1,grid)){// left
        ans+= f(i,j-1,grid);
      }
       if (weCanGo(i-1,j,grid)){// above
        ans+= f(i-1,j,grid);
      }
      grid[i][j]=1;
      return ans;
}
int main (){
    int n;
    cout<<"enter the size of rectangle : ";
    cin>>n;
    vector<vector<int>> vec (n,vector<int> (n));
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cin>>vec[i][j];
        }
    }
    cout<<"the rat reach from source to distrint that way : "<<f(0,0,vec)<<endl;
    return 0;
}