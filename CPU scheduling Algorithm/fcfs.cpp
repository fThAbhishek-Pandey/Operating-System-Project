#include <iostream>
#include<algorithm>
#include<vector>
using namespace std ;

int main() {
     cout<<"enter the number of process : ";
     int n;
     cin>>n;
     vector<vector<int>>Timearr(n,vector<int>(3));
      // Timerr[i][0]---.arrival time 
     // Timearr[i][1] --> brust time
     // Timearr[i][2] -->  id
     for (int i=0;i<n;i++){
         Timearr[i][2];// giving process id
        cout<<"enter arrival time for P"<<i+1<<" : ";
        cin>>Timearr[i][0];
        cout<<"Enter brust time for P"<<i+1<<" : ";
        cin>>Timearr[i][1];
     }
      // sort the array b  id time 
      sort ( Timearr.begin(), Timearr.end());
      // culculation 
      vector<int> abscompletionTime (n+1);
      abscompletionTime[0] =0;
      vector<int>waiting_time(n);
      vector<int> Tern_around_time(n);
      float tot_TAT=0;
      float tot_waiting_time=0;
      for (int i=0;i<n;i++){
          if (Timearr[i][0]>abscompletionTime[i]){
               abscompletionTime[i+1] = Timearr[i][0] +Timearr[i][1]; 
               waiting_time[i]=0;
               Tern_around_time[i]=Timearr[i][1];// tern_around_time = brust time
               tot_TAT += Tern_around_time[i];
          }
          else{
                 abscompletionTime[i+1] = abscompletionTime[i] + Timearr[i][1];
                 waiting_time[i]= abscompletionTime[i]-Timearr[i][0];
                 tot_waiting_time +=waiting_time[i];
                 Tern_around_time[i]= abscompletionTime[i] + Timearr[i][1] - Timearr[i][0];
          }
      }
       /*
       AT = Arrival time
       BT = brust Time
       CT = Completion time
       Wt = waiting time
       TAT = Turn around time
       */
      cout<<"id "<<"AT "<<"BT "<<"CT "<<"WT "<<"TAT " <<endl;
      for(int i=0;i<n;i++){
        cout<<"P"<<Timearr[i][2]<<" "<<Timearr[i][0]<<"  "<<Timearr[i][1]<<"  "<<abscompletionTime[i+1]<<"  "<<waiting_time[i]<<"  "<<Tern_around_time[i]<<endl;
      }
      cout<<"Average waiting Time : "<<tot_waiting_time/n<<endl;
      cout<<"Average TAT Time : "<<tot_TAT/n<<endl;
    return 0; 
}