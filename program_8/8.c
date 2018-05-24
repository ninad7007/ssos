#include<stdio.h>
struct pro{
    int all[20], max[20], need[20], finished, work[10], request[20];
}p[10];
int n, nor, avail[20], sseq[20], work[20], i,j,k;
int checkseq();
int main(){
	int pid;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the number of resources: ");
    scanf("%d", &nor);
    for(i=0;i<n;i++){
    	for(j=0;j<nor;j++){
    		if(i==0){
    			printf("Enter the availability of resource %d : ", j);
    			scanf("%d", &avail[j]);
    		}
    		p[i].all[j] = p[i].max[j] = p[i].need[j] = p[i].finished = p[i].work[j] = p[i].request[j] = 0;
    	}
    }
    printf("\nEnter max and allocated matrix:\n");
    for(i=0;i<n;i++){
    	printf("\nFor process %d\n", i);
    	for(j=0;j<nor;j++){
	    	printf("Enter the max for resource %d : ", j);    	
    		scanf("%d",&p[i].max[j]);
	    	printf("Enter the allocated for resource %d : ", j);
    		scanf("%d",&p[i].all[j]);
    		if(p[i].all[j] > p[i].max[j]) {
    			printf("\nAllocated should be less than or equal to max\n");
    			j--;
    		}
    		else
    			p[i].need[j] = p[i].max[j] - p[i].all[j];
    	}
    }
    if(checkseq() == 0)
    	printf("NOT IN SAFE STATE");
    A:
    printf("\nEnter the process id requesting : ");
    scanf("%d", &pid);
    int vc = 0, wc = 0;
    printf("\nEnter the request:\n");
    for(j=0;j<nor;j++){
    	printf("For resource %d : ", j);
    	scanf("%d",&p[pid].request[j]);
    }
    for(j=0;j<nor;j++){
    	if(p[pid].request[j] > avail[j])
    		wc = 1;
    	if(p[pid].request[j] > p[pid].need[j])
    		vc = 1;
    }
    if(wc == 1)
    	printf("Waiting check error");
    else if(vc == 1)
    	printf("Violation check error");
    else{
    	for(j=0;j<nor;j++){
    		p[pid].all[j] += p[pid].request[j];
    		p[pid].need[j] -= p[pid].request[j];
    		avail[j] -= p[pid].request[j];
    	}
    	if(checkseq() == 0){
			printf("Request not granted");
			for(j=0;j<nor;j++){
				p[pid].all[j] -= p[pid].request[j];
				p[pid].need[j] += p[pid].request[j];
				avail[j] += p[pid].request[j];
	    	}
    	}
    	else{
    		printf("Request granted");
    	}
    	goto A;
    }
}
int checkseq(){
	int check1=0, check2 =0, ss = 0;
	for(j=0;j<nor;j++)
		work[j] = avail[j];
	for(i=0;i<n;i++)
		p[i].finished = 0;
	for(k=0;k<nor;k++){
		for(i=0;i<n;i++){			
			if(p[i].finished == 0){
				check1=0;
				for(j=0;j<nor;j++)
					if(p[i].need[j] <= work[j])
						check1++;
				if(check1 == nor){
					for(j=0;j<nor;j++){
						work[j] += p[i].all[j];
						p[i].finished = 1;
					}
					sseq[ss] = i;
					ss++;
				}
			}
		}
	}
	check2 = 0;
	for(i=0;i<n;i++)
		if(p[i].finished == 1)
			check2++;
	if(check2 >= n){
		printf("\nSystem is in safe state\nSafe sequence is: \n");
		for(i=0;i<n;i++)
			printf("|%d|",sseq[i]); 
		return 1;
	}
	else
		return 0;
}

























