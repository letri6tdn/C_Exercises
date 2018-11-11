/*Submitting student: TRI NGUYEN
* Collaborating classmates: Changxin Zhan
* Other collaborators: NONE
* References (excluding textbook and lecture slides):
*/



#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define max(a,b) ((a)>(b)?(a):(b))//max(a,b)
int print_error() {
	printf("\nError in reading the instance!\n");
	exit(0);	
}
struct job{
	int id;
	int processingTime[3]; 
	int machineA; 
	int startTime[3]; //the start time on the three machines 1.A 2.B 3.C
	int lpt_next; //when unknown
	int johnson_next;
} ;

struct machine{
	int id;
	int remainingTime;
	int totalTime;
};

//the lpt function

int lpt(int j,int array[j][3],int t,int mc){
	int x,y,z,i;
	struct job temp;
	
	struct machine machines[mc];	//create machine list	
	struct job jobs[j];				//create job list
	
	//set the machine 
	for (i = 0;i < mc;++i){
		struct machine ma;
		ma.id = i + 1;
		ma.remainingTime = 0;
		ma.totalTime = t;
		machines[i] = ma;
	}	
	//set the new jobs
	for (i = 0;i < j;++i){			//fill the list
	
		struct job jb;
		jb.id = i + 1;
		for(x = 0;x < 3;++x){
		
			jb.processingTime[0] = array[i][0];
			jb.processingTime[1] = array[i][1];
			jb.processingTime[2] = array[i][2];
		}
		jobs[i] = jb;
	}
	//order the jobs
	for (x = 0;x < j;++x){
		for (y = x + 1;y < j;++y){		
			if (jobs[y].processingTime[0] > jobs[x].processingTime[0]){
				
				temp = jobs[x];
				jobs[x] = jobs[y];
				jobs[y] = temp;
			}
		}
	}
	//print out the lpt order
	printf("LPT order : ");
	for (i = 0;i < j;++i){
		printf("%d ,",jobs[i].id);
	}
	printf("\n");

	z = 0;
	while(z < j) {
			
		for(i = 0;i < mc;++i){		
			if (machines[i].remainingTime == 0 && z < j){//if there is machine is availble				
				jobs[z].machineA = machines[i].id;
				jobs[z].startTime[0] = machines[i].totalTime;
				machines[i].remainingTime = jobs[z].processingTime[0];
				machines[i].totalTime += jobs[z].processingTime[0];
				z++;
			}
		}
		for (x = 0;x < mc;++x){
		//for every iteration that minus 1 on the machine rest of processing time
			machines[x].remainingTime--;
		}
	}

	printf("\nJob information : \n");
	for (i = 0;i < j;++i){
		printf("Job %d is processed on A_%d starting %d;\n",jobs[i].id,jobs[i].machineA,jobs[i].startTime[0]);
	}

	printf("\nMachine information : \n");
	for (i = 0;i < mc;++i){
		printf("A_%d processes ",machines[i].id);
		for (x = 0;x < j;++x){
			if (jobs[x].machineA == machines[i].id){
			
				printf("job %d at %d, ",jobs[x].id,jobs[x].startTime[0]);
			}
		}
		printf("\n");
	}
	printf("\n");
	int T = machines[0].totalTime;
	printf("%d ",T);
	for (i = 0;i < mc;++i){
		if (machines[i].totalTime > T){
		
			T = machines[i].totalTime;
			printf("%d ",T);
		}
	}
	printf("The job processing time interval is [%d, %d], and the makespan is %d.\n",t,T,T-t);	
}

int main(int argc,char *argv[]) {
	
	int mc,j;
	int x,y;
	int m,n,z;
	int i;
	int t = 5;
	
	if (!strcmp(argv[1],"-i")) {
		
		printf("Enter the number of machines in stage 1 : ");
		if (!scanf("%d", &mc)){
			print_error();			
		}
		printf("Enter the number of jobs : ");
		if(!scanf("%d", &j)){
			print_error();
		}
		
		int array[j][3];
		
		printf("Enter in each line the processing times for a job:\n");
		
		for (x = 0; x < j; ++x) {			
		
			for (y = 0; y < 3; ++y) {			
				
				if (!scanf("%d", &array[x][y])) {
					
					print_error();
				}	
			}
		}
		
		printf("\n#instance%d_%d_1.txt\n", mc, j);
		printf("#number of stage 1 machines\n%d\n",mc);
		printf("#number of jobs\n%d\n",j);
		printf("#job processing times\n");
		
		for (x = 0; x < j; ++x) {
			
			for (y = 0; y < 3; ++y) {
				
				printf("%d ", array[x][y]);
			}
			printf("\n");
		}
		
		printf("#end of instance\n\n");
		lpt(j,array,t,mc);
	return 0;
	}
		
	if (!strcmp(argv[1],"-r")) {
	
		printf("Generating random instance ...\n");
		printf("Enter the number of machines in stage 1 : ");
		if(!scanf("%d", &mc)){
			print_error();
		}
		printf("Enter the number of jobs : ");
		if(!scanf("%d", &j)){
			print_error();
		}
		int array[j][3];
		
		printf("Enter the processing time interval [t_1, t_2]: ");
		if(!scanf("%d %d", &m, &n)){
			print_error();
		}
		printf("Enter the number of instances to be generated: ");
		if(!scanf("%d", &z)){
			print_error();
		}			
			
		for (i = 0; i < z; ++i) {
			
			printf("\n#instance%d_%d_%d.txt\n", mc, j, i+1);
			printf("#number of stage 1 machines\n%d\n",mc);
			printf("#number of jobs\n%d\n",j);	
			printf("#job processing times\n");
			
			for (x = 0; x < j; ++x) {
			
				for (y = 0; y < 3; ++y) {
					array[x][y] = rand()% (n-m+1)+m;	
					printf("%d ", array[x][y]);
				}
				printf("\n");
			}
			printf("#end of instance\n\n");
		}	
	return 0;
	}
	printf("\nmyprogram -i | -r\n");
	return 0;		
}
	

