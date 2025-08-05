#include<bits/stdc++.h>
using namespace std;

struct FFS
{
   int pId;
   int BurstTime;
   int CompletionTime;
   int TurnAroundTime;
   int WaitingTime;
};



int main(){

    int p;
    cout<<"Enter Num of Proccess :";
    cin>>p;

    vector<FFS>v(p);
    for(int i=0;i<p;i++){
       v[i].pId=i;
       cout<<"Enter Burst Time for P"<<v[i].pId<<": ";
       cin>>v[i].BurstTime;


    }
    int currentTime=0,TotalTime=0;
    for (int i = 0; i <p; i++)
    {
        /* code */
        currentTime+=v[i].BurstTime;
        v[i].CompletionTime=currentTime;
        v[i].TurnAroundTime=v[i].CompletionTime;
        v[i].WaitingTime=v[i].TurnAroundTime-v[i].BurstTime;
         
        TotalTime+=v[i].WaitingTime;

    }
  cout<<"procces\tBurst\tcompletion\tTurnA\tWaiting\n";
    for(int i=0;i<p;i++){
       cout<<v[i].pId<<"\t"<<v[i].BurstTime<<"\t"<<v[i].CompletionTime<<'\t'<<v[i].TurnAroundTime<<'\t'<<v[i].WaitingTime<<'\n';

    }
    
    cout<<"Avarage Waiting Time:"<<TotalTime/p<<'\n';


    
    
  
    
}

//OK