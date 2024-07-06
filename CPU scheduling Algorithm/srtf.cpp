#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
// class Compare {
//     public:
//        bool operator()(vector<int> a, vector<int> b){
//            if(){
//                return true;
//            }
//            return false;
//       }
// };
bool cmp (vector<int>a, vector<int>  b){
    return a[1]<b[1];
}
int main(){
    int n;
    cout<<"enter the number of process : ";
    cin>>n;
    vector<vector<int>> data (n,vector<int>(3,0));
    
    for (int i=0;i<n;i++){
        cout<<"enter the brust time for process ID"<<i<<" : ";
        cin>>data[i][0];
        cout<<"enter the Arrival time for process ID"<<i<<" : ";
        cin>>data[i][1];
        data[i][2]=i;
    }
    sort( data.begin(),data.end(),cmp);
    priority_queue<vector<int>> pq;
    int absTime =0;
    vector<vector<int>> gantChart;
    int i=0;
    while (i<data.size()){
        cout<<"hi, I am in outer while loop\n";
        if (absTime < data[i][1]){
               pq.push(data[i]);
               i++;
               absTime = data[i][1];
        }
        else {
            while (absTime<=data[i][1]){
                  pq.push(data[i]);
                  i++; 
                }
           
           vector<int> run = pq.top();
           pq.pop();
           vector<int> next = pq.top();

           int exeTime = next[1]-run[1];
           if(run[0]>exeTime) {
                 absTime += exeTime;
                 run[0]-= exeTime;
                 gantChart.push_back({run[0],run[1],run[2],absTime});
                 pq.push(run);
           }
           else {
               absTime += run[0];
           }
          
        }   
    }
      cout<<"ID  "<<"BT "<<"AT "<<"Abs "<<endl;
      for(int i=0;i<gantChart.size();i++){
           cout<<gantChart[i][2]<<" "<<gantChart[i][0]<<" "<<gantChart[i][1]<<" "<<gantChart[i][3]<<endl;
      }
    return 0;
}