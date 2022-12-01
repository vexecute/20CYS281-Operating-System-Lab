#include<stdio.h>
void waitingtime(int processes[], int n,  int bt[], int wt[])
{
    wt[0] = 0;
    for (int  i = 1; i < n ; i++ )
        wt[i] =  bt[i-1] + wt[i-1] ;
}
void turnaroundtime( int processes[], int n, 
                  int bt[], int wt[], int tat[])
{
    for (int  i = 0; i < n ; i++)
        tat[i] = bt[i] + wt[i];
}
void avgtime( int processes[], int n, int bt[])
{
    int wt[n], tat[n], total_wt = 0, total_tat = 0;
    waitingtime(processes, n, bt, wt);
    turnaroundtime(processes, n, bt, wt, tat);
    printf("Processes   Burst time   Waiting time   Turn around time\n");
    for (int  i=0; i<n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        printf("   %d ",(i+1));
        printf("       %d\t ", bt[i] );
        printf("       %d\t",wt[i] );
        printf("       %d\t\n",tat[i] );
    }
    int s=(float)total_wt / (float)n;
    int t=(float)total_tat / (float)n;
    printf("Average waiting time = %d",s);
    printf("\n");
    printf("Average turn around time = %d ",t);
}
int main()
{
int b,z;
int processes[3]; 
int  burst_time[3];

    printf("enter the processes: \n");
    for(b=0;b<3;b++)
    {
       scanf("%d",&processes[b]);
     }
    int n = sizeof processes / sizeof processes[0];
    printf("enter the burst time: \n");
    for(z=0;z<3;z++)
    {
       scanf("%d",&burst_time[z]);
     }

    avgtime(processes, n,  burst_time);
    return 0;
}