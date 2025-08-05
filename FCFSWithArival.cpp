#include<bits/stdc++.h>
using namespace std;

struct FCFSWithArival
{
    int pId;
    int ArrivalTime;
    int BrustTime;
    int completionTime;
    int TrunATime;
    int WaitingTime;

};

bool Comparison(FCFSWithArival a,FCFSWithArival b){
     return a.ArrivalTime<b.ArrivalTime;
}


int main(){
    
    int p;
    cout<<"Enter Numer of Proccess: ";
    cin>>p;

    vector<FCFSWithArival>v(p);

    for(int i=0;i<p;i++){
        v[i].pId=i;
        cout<<"Enter Arrival time for P"<<v[i].pId<<": ";
        cin>>v[i].ArrivalTime;
        cout<<"Enter Burst Time for p"<<v[i].pId<<": ";
        cin>>v[i].BrustTime;
    }

    sort(v.begin(),v.end(),Comparison);

    int currentTime=0,totalWaitingTime=0;

    for(int i=0;i<p;i++){
        if(currentTime<v[i].ArrivalTime){
            currentTime=v[i].ArrivalTime;
        }

        v[i].completionTime=currentTime+v[i].BrustTime;
        v[i].TrunATime=v[i].completionTime-v[i].ArrivalTime;
        v[i].WaitingTime=v[i].TrunATime-v[i].BrustTime;

        totalWaitingTime+=v[i].WaitingTime;
        currentTime+=v[i].BrustTime;
    }


    

    cout<<"Proccess\tArrival\tBurstTime\tcompletion\tTurnAround\tWaiting\n";
    for(int i=0;i<p;i++){
       cout<<"p"<<v[i].pId<<"\t"<<v[i].ArrivalTime<<"\t"<<v[i].BrustTime<<"\t"<<v[i].completionTime<<"\t"<<v[i].TrunATime<<"\t"<<v[i].WaitingTime<<'\n';
    }

    cout<<"Avarage Waiting Time="<<totalWaitingTime/p<<'\n';
  
    
}

//OK