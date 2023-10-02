#include<iostream> 
#include<vector>
using namespace std;
void permutation (vector<string>&ans,string str,int i){
     if (i==str.size()) {
        ans.push_back(str);
        return ;
     } 
     for (int j=i;j<str.size();j++){
        swap (str[i],str[j]);
        permutation(ans,str,i+1);
         swap (str[i],str[j]);
     }  
}
int main (){
    string str;
    cin>>str;
    vector<string> ans;
    permutation ( ans,str,0);
    cout<<ans.size()<<endl;
    for (int i=0;i<ans.size ();i++){
        cout<<ans[i]<<" ";
    }
}
