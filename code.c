void Q3()    //First Come First Serve Algorithm
	    {
	        printf("\nFirst come First Serve Alhorithm\n");
	        int n,bur2[20],wait2[20],turn2[20],avg_wait1=0,avg_turn1=0,i,j;
	        printf("Enter total number of processes(maximum 20):");
	        scanf("%d",&n);
	        printf("\nEnter Process Burst Time:\n");
	        for(i=0;i<n;i++)
	        {
	            printf("P[%d]:",i+1);
	            scanf("%d",&bur2[i]);
	        }
	        wait2[0]=0;    //waiting time for first process is 0
	        //calculating waiting time
	        for(i=1;i<n;i++)
	        {
	            wait2[i]=0;
	            for(j=0;j<i;j++)
	                wait2[i]+=bur2[j];
	        }
	        printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time");
	        //calculating turnaround time
	        for(i=0;i<n;i++)
	        {
	            turn2[i]=bur2[i]+wait2[i];
	            avg_wait1+=wait2[i];
	            avg_turn1+=turn2[i];
	            printf("\nP[%d]\t\t%d\t\t%d\t\t%d",i+1,bur2[i],wait2[i],turn2[i]);
	        }
	        avg_wait1/=i;
	        printf("\nThe Average Waiting Time is:%d",avg_wait1);
	        avg_turn1/=i;
	        printf("\nThe Average Turnaround Time is:%d",avg_turn1);
	    }
