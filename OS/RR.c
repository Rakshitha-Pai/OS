#include<stdio.h>  
1.	#include<conio.h>  
2.	  
3.	void main()  
4.	{  
5.	    // initlialize the variable name  
6.	    int i, NOP, sum=0,count=0, y, quant, wt=0, tat=0, at[10], bt[10], temp[10];  
7.	    float avg_wt, avg_tat;  
8.	    printf(" Total number of process in the system: ");  
9.	    scanf("%d", &NOP);  
10.	    y = NOP; // Assign the number of process to variable y  
11.	  
12.	// Use for loop to enter the details of the process like Arrival time and the Burst Time  
13.	for(i=0; i<NOP; i++)  
14.	{  
15.	printf("\n Enter the Arrival and Burst time of the Process[%d]\n", i+1);  
16.	printf(" Arrival time is: \t");  // Accept arrival time  
17.	scanf("%d", &at[i]);  
18.	printf(" \nBurst time is: \t"); // Accept the Burst time  
19.	scanf("%d", &bt[i]);  
20.	temp[i] = bt[i]; // store the burst time in temp array  
21.	}  
22.	// Accept the Time qunat  
23.	printf("Enter the Time Quantum for the process: \t");  
24.	scanf("%d", &quant);  
25.	// Display the process No, burst time, Turn Around Time and the waiting time  
26.	printf("\n Process No \t\t Burst Time \t\t TAT \t\t Waiting Time ");  
27.	for(sum=0, i = 0; y!=0; )  
28.	{  
29.	if(temp[i] <= quant && temp[i] > 0) // define the conditions   
30.	{  
31.	    sum = sum + temp[i];  
32.	    temp[i] = 0;  
33.	    count=1;  
34.	    }     
35.	    else if(temp[i] > 0)  
36.	    {  
37.	        temp[i] = temp[i] - quant;  
38.	        sum = sum + quant;    
39.	    }  
40.	    if(temp[i]==0 && count==1)  
41.	    {  
42.	        y--; //decrement the process no.  
43.	        printf("\nProcess No[%d] \t\t %d\t\t\t\t %d\t\t\t %d", i+1, bt[i], sum-at[i], sum-at[i]-bt[i]);  
44.	        wt = wt+sum-at[i]-bt[i];  
45.	        tat = tat+sum-at[i];  
46.	        count =0;     
47.	    }  
48.	    if(i==NOP-1)  
49.	    {  
50.	        i=0;  
51.	    }  
	    else if(at[i+1]<=sum)  
    {  
	        i++;  
    }  
    else  
	    {  
	        i=0;  
	    }  
	}  
	// represents the average waiting time and Turn Around time  
	avg_wt = wt * 1.0/NOP;  
	avg_tat = tat * 1.0/NOP;  
	printf("\n Average Turn Around Time: \t%f", avg_wt);  
	printf("\n Average Waiting Time: \t%f", avg_tat);  
	getch();  
	}  
/*output:
Total number of process in the system: 5

 Enter the Arrival and Burst time of the Process[1]
 Arrival time is:       0
 
Burst time is:  5

 Enter the Arrival and Burst time of the Process[2]
 Arrival time is:       1
 
Burst time is:  3

 Enter the Arrival and Burst time of the Process[3]
 Arrival time is:       2
 
Burst time is:  1

 Enter the Arrival and Burst time of the Process[4]
 Arrival time is:       3
 
Burst time is:  2

 Enter the Arrival and Burst time of the Process[5]
 Arrival time is:       4
 
Burst time is:  3
Enter the Time Quantum for the process:         2

 Process No              Burst Time              TAT             Waiting Time 
Process No[3]            1                               3                       2
Process No[4]            2                               4                       2
Process No[2]            3                               11                      8
Process No[5]            3                               9                       6
Process No[1]            5                               14                      9
 Average Turn Around Time:      5.400000
 Average Waiting Time:  8.200000[1] + Done           */
