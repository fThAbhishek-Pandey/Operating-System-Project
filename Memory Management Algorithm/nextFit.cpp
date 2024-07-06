#include <iostream>
#include<vector>
using namespace std ;

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
     cout<<"your memory is "<<RAMsize<<" byte please devide it fixed partition ."<<endl;
     cout<<"enter 0 to exit.";
     vector<vector<int>> RAM;
     
    int i=0;
     while (true) {
            int k;
            if(!k) break;
            cout<<"enter memory  for particiton "<<i<<" : ";
            cin>>k;
            RAM.push_back({k,0});
             i++;
     }
     vector<vector<int>> myMemory;
       int useRAM =0;
       i=0;
       int j=0;
       int m= RAM.size();
      while (i<n){// n is total number of process
             useRAM += RAM[i][0];
             cout<<"love";
             if(useRAM>RAMsize) break;
             while(true){
              
                if (!RAM[j][1]&& RAM[j][0]>=process[i]){
                     myMemory.push_back({i,process[i],RAM[j][0]});
                     RAM[j][1]=1;
                     break;
                }
                j= (j+1)%m;

            }
            i++;
      }
      cout<<"\nID\tPcssSize\tPartitionSize\n";
      for(int r =0;r<myMemory.size();r++){
        cout<<myMemory[r][0]<<"\t"<<myMemory[r][1]<<"\t"<<myMemory[r][2]<<"\t"<<endl;
      }
    return 0;
}