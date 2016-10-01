#include<stdio.h>

int main()
{
    int n,burst[20],wait[20],turnaround[20],avg_wait=0,avg_turnaround=0,i,j;
    printf("Enter number of processes: ");
    scanf("%d",&n);

    printf("\nEnter Process Burst Time\n");
    for(i=0;i<n;i++)
    {
        printf("P[%d]:",i+1);
        scanf("%d",&burst[i]);
    }

    wait[0]=0;    //waiting time for first process is 0

    //calculating waiting time
    for(i=1;i<n;i++)
    {
        wait[i]=0;
        for(j=0;j<i;j++)
            wait[i]+=burst[j];
    }

    printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time");

    //calculating turnaround time
    for(i=0;i<n;i++)
    {
        turnaround[i]=burst[i]+wait[i];
        avg_wait+=wait[i];
        avg_turnaround+=turnaround[i];
        printf("\nP[%d]\t\t%d\t\t%d\t\t%d",i+1,burst[i],wait[i],turnaround[i]);
    }

    avg_wait/=i;
    avg_turnaround/=i;
    printf("\n\nAverage Waiting Time:%d",avg_wait);
    printf("\nAverage Turnaround Time:%d",avg_turnaround);

    return 0;
}
