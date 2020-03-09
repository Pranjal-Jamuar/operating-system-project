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
