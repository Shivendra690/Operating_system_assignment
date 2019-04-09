#include<stdio.h>

void main()
{
    /* 
        Initialization step
        bt[] = array for burst time which will be used to stores burst time of all processes,
        similarly p[] array to store process number of each process, 
        wt[] to store waiting time of each process,
        tat[] array to store turn around time of each process, 
        a[] array to store arrival time of each process,
        avg_wt = average waiting time
        avg_tat = average turn around time
    */
    int bt[20],p[20],wt[20],tat[20],pr[20],i,j,n,total=0,pos,temp,avg_wt,avg_tat,a[10];

    //Ask the user to Enter total number of processes
    printf("Enter Total Number of Process:");
    scanf("%d",&n);
     
    //Ask the user to Enter Arrival time  of each processes
    printf("Enter Arrival time for each process\n");
    for(i=0;i<n;i++)
    {
        printf("Arrival Time:");
        scanf("%d",&a[i]);
    }
    
    //Ask the user to Enter Burst time of each process
    printf("\nEnter Burst Time and Priority\n");
    for(i=0;i<n;i++)
    {
        printf("\nP[%d]\n",i+1);
        printf("Burst Time:");
        scanf("%d",&bt[i]);
        printf("Priority:");
        scanf("%d",&pr[i]);
        p[i]=i+1;           
        //contains process number
    }

    //sorting burst time, priority arrival time and process number in ascending order using selection sort
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(pr[j]<pr[pos])
                pos=j;
        }
        // for priority
        temp=pr[i];
        pr[i]=pr[pos];
        pr[pos]=temp;
        
        //for burst time
        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;
        
        //for processes
        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
        
        // for arrival time
        temp=a[i];
        a[i]=a[pos];
        a[pos]=temp;
    }

    wt[0]=0;            
    //waiting time for first process is zero

    //calculate waiting time
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]=bt[j];

        total+=wt[i];
    }

    avg_wt=total/n;      
    //average waiting time

    total=0;

    printf("\nProcess\t   Arrival Time\t   Burst Time   \tWaiting Time\tTurnaround Time");
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i]; 

        //calculate turnaround time
        total+=tat[i];

        // print the table on the screen

        printf("\nP[%d]\t\t  %d\t\t  %d\t\t   %d\t\t\t%d",p[i],a[i],bt[i],wt[i],tat[i]);
    }

    avg_tat=total/n;     
    //average turnaround time

    printf("\n\nAverage Waiting Time=%d",avg_wt);
    printf("\nAverage Turnaround Time=%d\n",avg_tat);

}