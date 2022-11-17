#include <stdio.h>
int main()
{
    int count, j, n, exittime, remain, flag = 0, time_quantum;
    int AT[6], BT[6], RT[6];
    float WT = 0, TAT = 0;
    printf("Enter Total Process:\t ");
    scanf("%d", &n);
    remain = n;

    for (count = 0; count < n; count++)
    {
        printf("Enter Arrival Time and Burst Time for Process Process Number %d :", count + 1);
        scanf("%d", &AT[count]);
        scanf("%d", &BT[count]);
        RT[count] = BT[count]; // remaining time
    }

    printf("Enter Time Quantum:\t");
    scanf("%d", &time_quantum);
    printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n");

    for (exittime = 0, count = 0; remain != 0;)
    {
        if (RT[count] <= time_quantum && RT[count] > 0)
        {
            exittime += RT[count];
            RT[count] = 0;
            flag = 1;
        }
        else if (RT[count] > 0)
        {
            RT[count] -= time_quantum;
            exittime += time_quantum;
        }

        if (RT[count] == 0 && flag == 1)
        {
            remain--;
            printf("P[%d]\t|\t%d\t|\t%d\n", count + 1, exittime - AT[count], exittime - AT[count] - BT[count]);
            WT += exittime - AT[count] - BT[count];
            TAT += exittime - AT[count];
            // 1wait_time+= TAT-BT[count];
            flag = 0;
        }
        if (count == n - 1)
            count = 0;
        else if (AT[count + 1] <= exittime)
            count++;
        else
            count = 0;
    }
    printf("\nAverage Waiting Time= %f\n", WT * 1.0 / n);
    printf("Avg Turnaround Time = %f", TAT * 1.0 / n);

    return 0;
}