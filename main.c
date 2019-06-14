#include <stdio.h>
int main(int argc, char* argv[]) {
	// ./a.out filename params
	FILE* f = fopen(argv[1],"r");
	if(!f) return 0;
	int params = atoi(argv[2]);
	int weights[params];
	for(int i=0;i<params;i++) weights[i]=0;
	while(1) {
		int input[params];
		int flag = 0;
			for(int i=0;i<params;i++)
				if(EOF == fscanf(f,"%d",&input[i]))
					flag = 1;
		if(flag) break;
		int output;
		if(EOF == fscanf(f,"%d",&output)) break;
		if(output) {
			for(int j = 0; j < params; j++)
				if(input[j])
					weights[j]++;//*=1.1;
				else
					weights[j]--;//*=0.9;
		}
		if(!output) {
			for(int j = 0; j < params; j++)
				if(!input[j])
					weights[j]++;//*=1.1;
				else
					weights[j]--;//*=0.9;
		}
	}
	for(int i = 0; i < params-1; i++)
		printf("%d ",weights[i]);
	printf("%d\n",weights[params-1]);
}
