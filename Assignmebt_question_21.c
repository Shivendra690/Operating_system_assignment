/*
Consider a scenario of demand paged memory. Page table is held in registers. It takes 8
milliseconds to service a page fault if an empty page is available or the replaced page is not
modified and 20 milliseconds if the replaced page is modified. Memory access time is 100
nanoseconds. Assume that the page to be replaced is modified 70 percent of the time. Generate a
solution to find maximum acceptable page-fault rate for access time that is not more than 200
nanoseconds.
*/

#include<stdlib.h>
#include<stdio.h>
#include<conio.h>


double page_fault_rate();
void userInput(void);

double service_page_fault_empty;
double service_page_fault_modified;
double mem_access_time;
double times_page_modified;
double effective_access_time;
double pageFaultRate;
double service_page_fault_empty_ns;
double service_page_fault_modified_ns;
double times_page_modified_per;
	

void main(){
	int choice;
	
	do{
	
	
	printf("Select the required option \n");
	printf("1.Find the PageFault Rate\n");
	printf("2.Exit\n");
	scanf("%d",&choice);
	switch(choice){
		case 1:userInput();break;
		case 2:exit(0);
	}
	printf("\n\n");

}while(choice<3);
}
void userInput(){
	
	
	printf("\nEnter service Page Fault when Replaced Page is not Modified in milliseconds =");
	scanf("%lf",&service_page_fault_empty);
	printf("Enter Service Page Fault when Replaced Page Modified  in milliseconds =");
	scanf("%lf",&service_page_fault_modified);
	printf("Enter Memory Access Time in nanoseconds =");
	scanf("%lf",&mem_access_time);
	printf("Enter Percentage of time the page to be replaced is modified =");
	scanf("%lf",&times_page_modified);
	printf("Enter Effective Access time in nanoseconds =");
	scanf("%lf",&effective_access_time);

	service_page_fault_empty_ns = (service_page_fault_empty*1000000);
	service_page_fault_modified_ns = (service_page_fault_modified*1000000);
	times_page_modified_per = (times_page_modified/100);   
	printf("\nPage Fault rate calculated For:\n");
	printf("Service Page FaultWhen Page Not Modified =%lf \n",service_page_fault_empty_ns);
	printf("Service Page Fault ,page Modified Page in nanoseconds = %lf \n",service_page_fault_modified_ns);
	printf("Memory Access Time in nanoseconds =%lf\n",mem_access_time);
	printf("Effective Access Time =%lf\n",effective_access_time);
    pageFaultRate =  page_fault_rate(service_page_fault_empty_ns,service_page_fault_modified_ns,mem_access_time,times_page_modified_per,effective_access_time);
	printf("\nMaximum Acceptable Page Fault rate = %.2e[exponential notation]",pageFaultRate);


}

double page_fault_rate(double servicePageFaultEmpty,double servicePageFaultMod,double memAccess,double timesPages,double effAccess){
	double assume,serve;
	double numErator,denOminator;
	double pageFault;
	 assume = (1- timesPages)*servicePageFaultEmpty;
	 serve = timesPages*servicePageFaultMod;
	 numErator = effAccess - memAccess;
     denOminator = (assume+serve);

	pageFault = numErator/denOminator;
	return pageFault;


}