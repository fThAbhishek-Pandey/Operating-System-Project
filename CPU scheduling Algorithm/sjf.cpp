#include <iostream>
#include<algorithm>
#include<vector>
#include<unordered_set>
#include<queue>
using namespace std ;
bool cmp(vector<int> arr1,vector<int> arr2){
    return arr1[1]<arr2[1];
}
int main() {
     cout<<"enter the number of process : ";
     int n;
     cin>>n;
     vector<vector<int>>Timearr(n,vector<int>(3));
     // Timerr[i][0]---. brust time
     // Timearr[i][1] --> arrival time 
     // Timearr[i][2] -->  id
     // Timearr[i][3]--> completion time
     for (int i=0;i<n;i++){
        Timearr[i][2]=i+1;// giving process id
        cout<<"enter brust time for P"<<i+1<<" : ";
        cin>>Timearr[i][0];
        cout<<"Enter arrival time for P"<<i+1<<" : ";
        cin>>Timearr[i][1];
     }
      // sort the Time arr  wrt arrival time
      sort ( Timearr.begin(), Timearr.end(),cmp);
         int   absTime =0;// creating an Absolute Time
         vector<vector<int>> stor(n,vector<int>(4));
         /*
         stor[i][0] = brust time
         stor[i][1] = arrival time
         stor[i][2] = Proccess ID 
         stor[i][3] =  Comletion time
         */
        /*
         1. completion Time -> CT
         2. Tern Around Time -> TAT
         3. Waiting Time -> WT
         4. Avarage TAT -> ATAT
         5. Avarage WT -> AWT
        */
          priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;// for selecting lowest  brust time
         int j=0;
        for (int i = 0; i < Timearr.size()&&j<Timearr.size();) {
             while (absTime >= Timearr[i][1]) {
                 pq.push(Timearr[i]);
                 i++;
                 if (i >= Timearr.size()) break;       
                }
            if (!pq.empty()) {
              vector<int> curr = pq.top();
              pq.pop();
              absTime =absTime+ curr[0]; // Absolute Time + BT
              stor[j][0]=curr[0];
              stor[j][1]=curr[1];
              stor[j][2]=curr[2];
              stor[j][3]=absTime;
              j++;
           }
         else {
            absTime = Timearr[i][1] + Timearr[i][0];// Arrival time + brust time
            stor[j][0]=Timearr[i][0];
            stor[j][1]=Timearr[i][1];
            stor[j][2]=Timearr[i][2];
            stor[j][3]=absTime;
            i++;
            j++;
          }
       }
while (!pq.empty()){
  vector<int> curr = pq.top();
  pq.pop();
  if(absTime>=curr[1])  absTime += curr[0]; // absTime+BT
  else  absTime = curr[1]+curr[0];
  stor[j][0]=curr[0];
  stor[j][1]=curr[1];
  stor[j][2]=curr[2];
  stor[j][3]=absTime;
  j++;        
}
       vector<int> TAT(n);
       vector<int> WT(n);
       float aTAT= 0;
       float aWT=0;
       for(int i=0;i<n;i++){
        TAT[i]= stor[i][3]-stor[i][1];// CT -AT
        WT[i]= TAT[i]- stor[i][0];// TAT - BT
        aTAT += TAT[i];
        aWT  += WT[i];
       }
       aTAT /=n;// avarage Turn Around Time
       aWT /=n; // avarage Waiting Time
       cout<<"Avarage Turn Around Time = "<<aTAT<<endl;
       cout<<"Avarage Waiting Time = "<<aTAT<<endl;
       cout<<"ID  BT AT CT TAT WT"<<endl;
       for(int i=0;i<stor.size();i++){
       cout<<"p"<<stor[i][2]<<"  "<<stor[i][0]<<"  "<<stor[i][1]<<"  "<<stor[i][3]<<"  "<<TAT[i]<<"   "<<WT[i]<<endl;
       }
    return 0; 
}
