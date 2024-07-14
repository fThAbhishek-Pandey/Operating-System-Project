#include <iostream>
#include<vector>
#include<algorithm>
using namespace std ;
bool cmp ( vector<int> a,vector<int> b){
     return a[0]>b[0];
}
int main() {
    // I love Abhishek ji 
     int n;
     cout<<"enter the number of process : ";
     cin>>n;
     vector<int> process(n);
     for(int i=0;i<n;i++){
        cout<<"enter the size of process "<<i<<" : ";
        cin>>process[i];
     }
     int RAMsize = 128;
     cout<<"enter RAM size in byte : ";
     cin>>RAMsize;
     cout<<"your memory is "<<RAMsize<<" byte please devide it fixed partition ."<<endl;
     cout<<"enter 0 to exit.";
     vector<vector<int>> RAM;
     
    int i=0;
     while (true) {
            int k;
            cout<<"enter memory  for particiton "<<i<<" : ";
            cin>>k;
            if(!k) break;
            RAM.push_back({k,0});
             i++;
     }
   
     sort(RAM.begin(),RAM.end(),cmp);
     vector<vector<int>> myMemory;
       int useRAM =0;
       i=0;
       int j=0;
      while (i<n){// n is total number of process
             cout<<"hello\n";
             if(useRAM>RAMsize){
                   cout<<"Cross Ram size. Request Memory :  "<<useRAM<<"Current memory RAM in Byte : "<<RAMsize<<endl;
                   break;
             } 
             cout<<i<<"--> "<<RAM[j][0]<<"  "<<process[i]<<endl;
             if (RAM[j][0]>=process[i]){
                useRAM += RAM[j][0];
                myMemory.push_back({i, process[i],RAM[j][0]});
                j++;
             }
            i++;
      }
      cout<<myMemory.size()<<endl;
      cout<<"ID\tProcessSize\tPartitionSize\n";
      
      for(int r =0;r<myMemory.size();r++){
        cout<<myMemory[r][0]<<"\t"<<myMemory[r][1]<<"\t"<<myMemory[r][2]<<"\t"<<endl;
      }
    return 0;
}