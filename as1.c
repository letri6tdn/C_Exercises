#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	if (argc != 2 || (strcmp(argv[1],"-i") != 0 && strcmp(argv[1],"-r") != 0)) {
		printf("myprogram -i | -r\n");
		exit(0);
	}
	else {
		if (strcmp(argv[1],"-i") == 0) { //option -i to read an instance
			int stage1, jobs, t1, t2, t3;
			printf("Enter the number of machines in stage 1: ");
			scanf("%d", &stage1);
			printf("Enter the number of jobs: ");
			scanf("%d", &jobs);
			printf("Enter in each line the processing times for a job: ");
			int a[3][jobs];
			for (int i = 0; (i<jobs); i++) {
				scanf("%d %d %d", &t1, &t2, &t3);
				a[0][i] = t1;
				a[1][i] = t2;
				a[2][i] = t3;
			}
			
			printf("#number of machines in stage 1\n%d", stage1);
			printf("\n#number of jobs\n%d", jobs);
			printf("\n#jobs processing time");
			for (int i = 0; (i<jobs); i++) 
				printf("\n%d %d %d", a[0][i], a[1][i], a[2][i]);
			printf("#end of instance\n");
		}		
		
		if (strcmp(argv[1], "-r") == 0) {
			int user1, userJobs, t_1, t_2, userIns;
			printf("Generating random intances ...\n");
			printf("Enter the number of machines in stage 1: ");
			scanf("%d", &user1);
			printf("Enter the number of jobs: ");
			scanf("%d", &userJobs);
			printf("Enter the processing time interval [t_1, t_2]: ");
			scanf("%d %d", &t_1, &t_2);
			printf("Enter the number of instanc3es to be generated: ");
			scanf("%d", &userIns);
			int a[user1][userJobs];
			for (int i = 0; (i<userJobs); i++) {
				for (int u = 0; (u<3); u++) 
					a[u][i] = t_1 + rand() / (RAND_MAX / (t_2 - t_1 + 1) + 1);
			}
			for (int i = 1; (i<=userIns); i++) {
				printf("#instance%d_%d_%d.txt\n", user1, userJobs, i);
				printf("#number of machines in stage 1\n");
				printf("%d\n", user1);
				printf("#number of jobs\n");
				printf("%d\n", userJobs);
				printf("#job processing times\n");
				for (int u = 0; (u<userJobs); i++) 
					printf("%d %d %d\n", a[0][i], a[1][i], a[2][i]);
				printf("#end of instance\n");
				printf("\n");
			}
		}
	}
	
	return 0;
}
	
	
