#include<stdio.h>
void Q1();
void Q2();
void Q3();
	int main()
	{
		int i,j,s,N[30];
	        for(i=0;i<3;++i)
	        {
	            printf("Enter the Priority of the Queues:%d\n",i+1);
	            scanf("%d", &N[i]);
	        }
	        for(i=0;i<3;++i)
	        {
	            for(j=i+1;j<3;++j)
	            {
	                if(N[i]>N[j])
	                {
	                    s=N[i];
	                    N[i]=N[j];
	                    N[j]=s;
	                }
	            }
	        }
	        printf("Now the Queues are arranged in ascending order of their priorities\n");
	        for(i=0;i<3;++i)
	            printf("%d\n", N[i]);
	        int H=0;
	            H=N[0];
	        if(H>0)
	        {
	        Q1();
	        }
	        int middle=0;
	            middle=N[1];
	        if(middle>0)
	        {
	            Q2();
	        }
	        int lower=0;
	            lower=N[2];
	        if(lower>0)
	        {
	            Q3();
	        }
	        return 0;
	}
	      	void Q1()  //Round Robin Algorithm
	         {
	            printf("\nRound Robin Algorithm:\n");
	         	int i,a,n,m,s1=0,s2=0;
	            int B[10],req[10],pid[10],wait[10],turn[10],arr[10],bur[10],TimeQuant=4;
	            printf("Enter the number of Processes: ");
	            scanf("%d",&n);
	            int temp=n;
	            for(i=0;i<n;i++)
	            {
	                pid[i]=i;
	                printf("\nThe Arrival time of the Process P%d ",i+1);
	                scanf("%d",&arr[i]);
	                printf("\nThe Burst time of the Process P%d ",i+1);
	                scanf("%d",&bur[i]);
	            }
	            for(i=0;i<n;i++)
	            {
	                B[i]=bur[i];
	            }
	            int K=0;
	            while(1)
	            {
	                int d=1;
	                for(i=0;i<n;i++)
	                {
	                    if(B[i]>0)
	                    {
	                        d=0;
	                        if(B[i]>TimeQuant)
	                        {
	                            K=K+TimeQuant;
	                            B[i]=B[i]-TimeQuant;
	                        }
	                        else
	                        {
	                            K=K+B[i];
	                            wait[i]=K-B[i];
	                            B[i]=0;
	                        }
	                    }
	                }
	                if(d==1)
	                {
	                    break;
	                }
	            }
	            for(i=0;i<n;i++)
	            {
	                if(wait[i]==0)
	                {
	                    req[i]=pid[i];
	                }
	            }
	            printf("For Waiting time:\n");
	            for(i=0;i<n;i++)
	            {
	                printf("P%d ",i+1);
	                printf("%d\n",wait[i]);
	            }
	            for(i=0;i<n;i++)
	            {
	                turn[i]=bur[i]+wait[i];
	            }
	            printf("Turnaround Time\n");
	            for(i=0;i<n;i++)
	            {
	                printf("P%d ",i+1);
	                printf("%d\n",turn[i]);
	            }
	            for(i=0;i<n;i++)
	            {
	                s2=s2+wait[i];
	                s1=s1+turn[i];
	            }
	            printf("The Average Waiting Time is:\n");
	            printf("%f",(float)s2/(float)n);
	            printf("\nThe Average Turnaround Time is:\n");
	            printf("%f",(float)s1/(float)n);
	}
	
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
