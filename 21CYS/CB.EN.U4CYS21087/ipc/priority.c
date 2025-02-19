#include <stdio.h>
 
//Function to swap two variables
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
int main()
{
    int n;
    printf("Enter Number of Processes: ");
    scanf("%d",&n);
 
    // b is array for burst time, p for priority and index for process id
    int b[n],p[n],index[n];
    for(int i=0;i<n;i++)
    {
        printf("Enter Burst Time and Priority Value for Process %d: ",i+1);
        scanf("%d %d",&b[i],&p[i]);
        index[i]=i+1;
    }
    for(int i=0;i<n;i++)
    {
        int a=p[i],m=i;
 
        //Finding out highest priority element and placing it at its desired position
        for(int j=i;j<n;j++)
        {
            if(p[j] > a)
            {
                a=p[j];
                m=j;
            }
        }
 
        //Swapping processes
        swap(&p[i], &p[m]);
        swap(&b[i], &b[m]);
        swap(&index[i],&index[m]);
    }
 
    // T stores the starting time of process
    int t=0;
 
    //Printing scheduled process
    printf("Order of process Execution is\n");
    for(int i=0;i<n;i++)
    {
        printf("P%d is executed from %d to %d\n",index[i],t,t+b[i]);
        t+=b[i];
    }
    printf("\n");
    printf("Process Id     Burst Time   Wait Time    TurnAround Time\n");
    int wait_time=0;
    for(int i=0;i<n;i++)
    {
        printf("P%d             %d              %d              %d\n",index[i],b[i],wait_time,wait_time + b[i]);
        wait_time += b[i];
    }
    return 0;
}

/*
explanation
----------------------------------------------------------------
1. First, enter the total number of processes and store it in variable n.
2. After that, provide the burst time and priority and store it in variable b and p.
3. Finding out highest priority element and placing it at its desired position.
4. Sort the processes on the basis of the priority.
5. After that print the processed with their time stamp (starting time and ending time).
   Variable T stores the starting time of process.
6. In the end, print the waiting time and turnaround time for each process. 
   Waiting time is the time spent in the ready queue, while turnaround time is the total time 
   taken by process (burst time + waiting time).
*/