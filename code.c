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
