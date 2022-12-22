#include <stdio.h>
int main()
{
    int pid[15];
    int bt[15];
    int n;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
 
    printf("Enter process id of all the processes: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&pid[i]);
    }
 
    printf("Enter burst time of all the processes: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&bt[i]);
    }
 
    int i, wt[n];
    wt[0]=0;
 
    //for calculating waiting time of each process
    for(i=1; i<n; i++)
    {
        wt[i]= bt[i-1]+ wt[i-1];
    }
 
    printf("Process ID     Burst Time     Waiting Time     TurnAround Time\n");
    float twt=0.0;
    float tat= 0.0;
    for(i=0; i<n; i++)
    {
        printf("%d\t\t", pid[i]);
        printf("%d\t\t", bt[i]);
        printf("%d\t\t", wt[i]);
 
        //calculating and printing turnaround time of each process
        printf("%d\t\t", bt[i]+wt[i]);
        printf("\n");
 
        //for calculating total waiting time
        twt += wt[i];
 
        //for calculating total turnaround time
        tat += (wt[i]+bt[i]);
    }
    float att,awt;
 
    //for calculating average waiting time
    awt = twt/n;
 
    //for calculating average turnaround time
    att = tat/n;
    printf("Avg. waiting time= %f\n",awt);
    printf("Avg. turnaround time= %f",att);
}

/*
explanation:
----------------------------------------------------------------
1. Initialize two array pid[] and bt[] of size 15.
2. Ask the user for number of processes n.
3. Ask the user for process id and burst time for all n processes and store them into pid[] and bt[] respectively.
4. Calculate waiting time of each process by the formula wt[i] = wt[i-1] + bt[i-1].
5. Print Process Id, Burst Time, waiting time and Turnaround time of each process in tabular manner.
6. Calculate and print turnaround time of each process = bt[i] + wt[i].
7. Add waiting time of all the processes and store it in the variable twt.
8. Add turnaround time of all the processes and store it in the variable tat.
9. Calculate average waiting time as awt = twt/n.
10. Calculate average turnaround time as att = tat/n;
11. Print average waiting time and average turnaround time.
12. Exit.

*/