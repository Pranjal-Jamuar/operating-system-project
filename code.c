	void Q2()  // Priority Schedulling Algorithm
	    {
	        printf("\nPriority Scheduling Algorithm\n");
	        int i,j,c,position,t,avg_wait,avg_turn;
	        int Tot=0,bur1[20],p1[20],wait1[20],turn1[20],pr1[20];
	        printf("Enter Total Number of Processes:");
	        scanf("%d",&c);
	        printf("\nEnter Burst Time and Priority:\n");
	        for(i=0;i<c;i++)
	        {
	            printf("\nP[%d]\n",c+1);
	            printf("The Burst Time is:");
	            scanf("%d",&bur1[i]);
	            printf("Priority is:");
	            scanf("%d",&pr1[i]);
	            p1[i]=c+1;           //It contains Process Number
	        }
	        //sorting burst time, priority and process number in ascending order using selection sort
	        for(i=0;i<c;i++)
	        {
	            position=c;
	            for(j=i+1;j<c;j++)
	            {
	                if(pr1[j]<pr1[position])
	                    position=j;
	            }
	            t=pr1[c];
	            pr1[c]=pr1[position];
	            pr1[position]=t;
	            t=bur1[c];
	            bur1[c]=bur1[position];
	            bur1[position]=t;
	            t=p1[c];
	            p1[c]=p1[position];
	            p1[position]=t;
	        }
	        wait1[0]=0;	//waiting time for first process is zero
	        //calculate waiting time
	        for(i=1;i<c;i++)
	        {
	            wait1[i]=0;
	            for(j=0;j<i;j++)
	                wait1[i]+=bur1[j];
	            Tot+=wait1[i];
	        }
	        avg_wait=Tot/c;      //average waiting time
	        Tot=0;
	        printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time");
	        for(i=0;i<c;i++)
	        {
	            turn1[i]=bur1[i]+wait1[i];     //calculate turnaround time
	            Tot+=turn1[i];
	            printf("\nP[%d]\t\t  %d\t\t    %d\t\t\t%d",p1[i],bur1[i],wait1[i],turn1[i]);
	        }
	        avg_turn=Tot/c;     //average turnaround time
	        printf("\n\nAverage Waiting Time=%d",avg_wait);
	        printf("\nAverage Turnaround Time=%d\n",avg_turn);
	    }
