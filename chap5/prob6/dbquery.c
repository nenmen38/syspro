#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include "student.h"

int main(int argc, char *argv[])
{
	int df, id;
	char c;
	struct student record;
	if(argc < 2){
		fprintf(stderr, "How to use : %s file\n", argv[0]);
		exit(1);
	}
	if((fd = open(argv[1], O_RDONLY)) == -1){
		perror(argv[1]);
		exit(2);
	}
	do{
		printf("\Enter StudentId to search : ");
		if(scanf("%d", &id) == 1){
			lseek(fd, (id-STAR_ID)*sizeof(record), SEEK_SET);
			if((read(fd, (char *) &record, sizeof(record)) > 0) && (record.id != 0))
				printf("Name : %s\t StulID : %d\t Score : %d\n", record.name, record.id, record.socre);
			else printf("Record %d Null\n", id);
		}else printf("Input Error");
		printf("Continue?(Y/N)");
		scanf(" %c", &c);
	} while(c == 'Y');
	close(fd);
	exit(0);
}
