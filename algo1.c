#include<stdio.h>
int main()
{
    int pid[15],bt[15];
    int n;
    printf("\nEnter number of processes:");
    scanf("%d",&n);
    printf("\nEnter the process ID of the process:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&pid[i]);
    }
    printf("\nEnter the burst time of the process:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&bt[i]);
    }
    int wt[n];
    wt[0]=0;
    for(int i=1;i<n;i++)
    {
        wt[i]=bt[i-1]+wt[i-1];
    }
    printf("Process ID\t\tBurst Time\t\tWaiting Time\t\tTurn around time");
    float twt=0.0;
    float ttat=0.0;
    for(int i=0;i<n;i++)
    {
        printf("\n%d",pid[i]);
        printf("\t\t\t%d",bt[i]);
        printf("\t\t\t%d",wt[i]);
        printf("\t\t\t%d",(bt[i]+wt[i]));
        twt=twt+wt[i];
        ttat=ttat+wt[i]+bt[i];
        printf("\n");
    }
    float awt,atat;
    awt=twt/n;
    atat=ttat/n;
    printf("\nAverage Waiting Time is : %f",awt);
    printf("\nAverage Turn Around Time is : %f",atat);
    return 0;
}
