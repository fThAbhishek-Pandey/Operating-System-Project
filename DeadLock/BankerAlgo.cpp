#include <iostream>
#include<vector>
using namespace std ;
bool isFulfil(vector<int> &remaining, vector<int> &curr){
    
      for(int i=0;i<remaining.size();i++){
        if(curr[i]==-1) return false;
        if (remaining[i]<curr[i]) return false;
      }
      return true;
}
int main() {
    int n,m;
    cout<<"enter the number of Process : ";
    cin>>n;
    cout<<"enter the number of resourses : ";
    cin>>m;
    cout<<"enter current totle  resourse of system : ";
    vector<int> totleResourse ;
    for(int i=0;i<m;i++){
           int ele;
           cin>>ele;
           totleResourse.push_back(ele);
    }
    vector<int> currAllocatedResourse(m,0);
    vector<vector<vector<int>>> store;
    for(int i=0;i<n;i++){
        vector<vector<int>> bigHelper;
        bigHelper.push_back({i});
        cout<<"enter resourse allocated for process : P"<<i<<endl;
        vector<int> help;
        for(int j=0;j<m;j++){
             int ele;
             cin>>ele;
             help.push_back(ele);
             currAllocatedResourse[j] +=ele;
        }
        bigHelper.push_back(help); 
           help= {};
        cout<<"enter maximum need for process : P"<<i<<endl;
        for(int j=0;j<m;j++){
            int ele;
             cin>>ele;
             ele -= bigHelper[1][j];
             help.push_back(ele); 
        }
        bigHelper.push_back(help); 
        store.push_back(bigHelper);
    }
    vector<int> remainingResourse (m);
    for(int i=0;i<m;i++){
        remainingResourse[i] = totleResourse[i]- currAllocatedResourse[i];

    }
    vector<vector<vector<int>>> processInfo;
    int count =0;
    while (count<n){
    for(int i=0;i<n;i++){
       if (isFulfil( remainingResourse, store[i][2])){
               processInfo.push_back({{i},store[i][1],store[i][2]});
              for (int j = 0; j <m; j++)
              {
                  remainingResourse[j] += store[i][1][j];
                  store[i][2][j]=-1;
              }
                processInfo.push_back({remainingResourse});
            
       }
      } 
       count++;  
    }

    return 0;
}