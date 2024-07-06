#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;

class Process {
    public:
    int pid;
    int arrival_time;
    int burst_time;
    int start_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
    int response_time;
    Process (){
             
             pid=0;
             arrival_time=0;
             burst_time= 0;
             start_time=0;
             completion_time=0;
             turnaround_time=0;
             waiting_time=0;
             response_time=0;
    }
};

int main() {

    int n;//no of process
    vector<Process> pss;
    int total_turnaround_time = 0;
    int total_waiting_time = 0;
    int total_response_time = 0;
    int total_idle_time = 0;
    vector<int>  burst_remaining;
    vector<bool> is_completed;
    cout<<"Enter the number of processes: ";
    cin>>n;
      pss.resize(n);
      burst_remaining.resize(n);
      is_completed.resize(n,false);
    for(int i = 0; i < n; i++) {
        cout<<"Enter arrival time of process "<<i+1<<": ";
        cin>>pss[i].arrival_time;
        cout<<"Enter burst time of process "<<i+1<<": ";
        cin>>pss[i].burst_time;
        pss[i].pid = i+1;
        burst_remaining[i] = pss[i].burst_time;
        cout<<endl;
    }

    int current_time = 0;// for tracking current time
    int completed = 0; // no of process which completed
    int prev = 0;// previous completed prossess

    while(completed != n) {
        int idx = -1;
        int mini = INT16_MAX;
        for(int i = 0; i < n; i++) { 
            if(pss[i].arrival_time <= current_time && !is_completed[i]) {
                if(burst_remaining[i] < mini) {
                   mini = burst_remaining[i];
                    idx = i;
                }
                if(burst_remaining[i] == mini) {
                    if(pss[i].arrival_time < pss[idx].arrival_time) {
                        mini = burst_remaining[i];
                        idx = i;
                    }
                }
            }
        }

        if(idx != -1) {
            if(burst_remaining[idx] == pss[idx].burst_time) {
                pss[idx].start_time = current_time;
                total_idle_time += pss[idx].start_time - prev;
            }
            burst_remaining[idx] -= 1;
            current_time++;
            prev = current_time;
            
            if(burst_remaining[idx] == 0) {
                pss[idx].completion_time = current_time;
                pss[idx].turnaround_time = pss[idx].completion_time - pss[idx].arrival_time;
                pss[idx].waiting_time = pss[idx].turnaround_time - pss[idx].burst_time;
                pss[idx].response_time = pss[idx].start_time - pss[idx].arrival_time;

                total_turnaround_time += pss[idx].turnaround_time;
                total_waiting_time += pss[idx].waiting_time;
                total_response_time += pss[idx].response_time;

                is_completed[idx] = 1;
                completed++;
            }
        }
        else {
             current_time++;
        }  
    }
    
    int min_arrival_time = INT16_MAX;
    int max_completion_time = -1;
    for(int i = 0; i < n; i++) {
        min_arrival_time = min(min_arrival_time,pss[i].arrival_time);
        max_completion_time = max(max_completion_time,pss[i].completion_time);
    }
   float  avg_turnaround_time = (float) total_turnaround_time / n;
   float avg_waiting_time = (float) total_waiting_time / n;
   float avg_response_time = (float) total_response_time / n;
   float cpu_utilisation = ((max_completion_time - total_idle_time) / (float) max_completion_time )*100;
   float  throughput = float(n) / (max_completion_time - min_arrival_time);

    cout<<endl<<endl;

    cout<<"#P\t"<<"AT\t"<<"BT\t"<<"ST\t"<<"CT\t"<<"TAT\t"<<"WT\t"<<"RT\t"<<"\n"<<endl;

    for(int i = 0; i < n; i++) {
        cout<<pss[i].pid<<"\t"<<pss[i].arrival_time<<"\t"<<pss[i].burst_time<<"\t"<<pss[i].start_time<<"\t"<<pss[i].completion_time<<"\t"<<pss[i].turnaround_time<<"\t"<<pss[i].waiting_time<<"\t"<<pss[i].response_time<<"\t"<<"\n"<<endl;
    }
    cout<<"Average Turnaround Time = "<<avg_turnaround_time<<endl;
    cout<<"Average Waiting Time = "<<avg_waiting_time<<endl;
    cout<<"Average Response Time = "<<avg_response_time<<endl;
    cout<<"CPU Utilization = "<<cpu_utilisation<<"%"<<endl;
    cout<<"Throughput = "<<throughput<<" process/unit time"<<endl;


}

/*

AT - Arrival Time of the process
BT - Burst time of the process
ST - Start time of the process
CT - Completion time of the process
TAT - Turnaround time of the process
WT - Waiting time of the process
RT - Response time of the process

Formulas used:

TAT = CT - AT
WT = TAT - BT
RT = ST - AT

*/