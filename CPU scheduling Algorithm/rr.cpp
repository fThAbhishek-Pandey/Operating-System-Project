#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std ;
bool cmpTrr(vector<int> arr1, vector<int> arr2){
        if(arr1[0]==arr2[0])   return arr1[2]<arr2[2];
          return arr1[0]<arr2[0];
}
bool cmpQS (vector<int> arr1, vector<int> arr2){
            return arr1[2]<arr2[2];
}
  vector<vector<int>> Timearr;
  queue<vector<int>> qu;
  int j=0;
  int absTime=0;
  void pulse (){
     while (j<Timearr.size()&&absTime>=Timearr[j][0]){
                qu.push(Timearr[j++]);
          }
  }
int main() {
    cout<<"enter the Number of process : ";
    int n;
    cin>>n;
     Timearr.resize(n,vector<int> (3));
     /*
     Timearr[i][2] --> process id declaration 
     Timearr[i][0] --> arrival time 
     Timearr[i][1] --> brust time
     */
      vector<int> BT(n);// storing brust time
     for(int i=0;i<n;i++){
        Timearr[i][2]=i+1;// process id declaration
        cout<<"Enter the arrival Time p"<<i+1<<" : ";
        cin>>Timearr[i][0];
        cout<<"Enter the brust time p"<<i+1<<" : ";
        cin>>Timearr[i][1];
        BT[i]=Timearr[i][1];
     }
     int tq;
     cout<<"enter Time Quantum : ";
     cin>>tq;
     vector<vector<int>>QuantStore;
     /*
     Quantstore[i][2] --> process id declaration 
     Quantstore[i][0] --> arrival time 
     Quantstore[i][1] --> brust time
     Quantstore[i][3] --> Context switching time
     */
     sort(Timearr.begin(),Timearr.end() ,cmpTrr);
     qu.push(Timearr[0]);
     j++;
     while (!qu.empty()|| j<Timearr.size()){
        {
          vector<int>curr = qu.front();
          qu.pop();
          if(curr[0] <= absTime) {
            if (curr[1]> tq) {
                absTime += tq;
                curr[1]-=tq;
                pulse();
                qu.push(curr);
            }
            else {
                absTime += curr[1];
                curr[1]=0;
            }
          }
          else {
               if (curr[1]> tq) {
                absTime = curr[0] + tq;
                curr[1]-=tq;
                pulse();
                qu.push(curr);
            }
            else {
                absTime =curr[0] + curr[1];
                curr[1]=0;
            }
          }
           curr.push_back(absTime);
           QuantStore.push_back(curr); 
      }
     }
    //  Gantt table 
    cout<<"ID AT BT GT"<<endl;
    for (int i=0;i<QuantStore.size();i++){
        cout<<"p"<<QuantStore[i][2]<<"  "<<QuantStore[i][0]<<"  "<<QuantStore[i][1]<<"  "<<QuantStore[i][3]<<endl;
    }
    /*
    culculation 
    1. Completion Time
    2. Turn Around Time
    3. Waiting Time
    4. Avarage TAT
    5. Avarage WT
    */
   vector<vector<int>> store;
   /*
     store[i][2] --> process id declaration 
     store[i][0] --> arrival time 
     store[i][1] --> brust time
     store[i][3] --> Context switching time
     store[i][4] --> TAT
     store[i][5] --> WT
     */
   for (int i=0;i<QuantStore.size();i++){
    if(!QuantStore[i][1]) {
        store.push_back(QuantStore[i]);
    }
   }   
    sort(store.begin(),store.end(),cmpQS);
    cout<<"ID AT BT CT"<<endl;
    for (int i=0;i<store.size();i++){
        store[i][1]=BT[i];
        cout<<"p"<<store[i][2]<<"  "<<store[i][0]<<"  "<<store[i][1]<<"  "<<store[i][3]<<endl;
    }
    /*
    2. Turn Around Time
    3. Waiting Time
    4.  TAT
    5.  WT
    */
    float avgTAT = 0;
    float avgWT =0;
    for (int i=0;i<n;i++){
        store[i].push_back(store[i][3]-store[i][0]);
        avgTAT += store[i].back();
        store[i].push_back(store[i].back()-store[i][1]);
        avgWT += store[i].back();
    }
 cout<<"ID AT BT CT TAT WT"<<endl;
    for (int i=0;i<store.size();i++){
        store[i][1]=BT[i];
        cout<<"p"<<store[i][2]<<"  "<<store[i][0]<<"  "<<store[i][1]<<"  "<<store[i][3]<<"  "<<store[i][4]<<"  "<<store[i][5]<<endl;
    }
    cout<<"avgTAT :"<<avgTAT/n<<endl;
    cout<<"avgWT : "<<avgWT/n<<endl;
    return 0;
}