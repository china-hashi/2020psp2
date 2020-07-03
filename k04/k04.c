#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct str {
    int ID;
	int gender;
    double height;
}data;

int main(void)
{
    double height;
    int gender;
    int ID;
    int iID;
    char fname[FILENAME_MAX];
    char buf[256];
    FILE* fp;
    int i;
    int n=0;
    data data[14];

    printf("Input the filename of sumple height:");
    fgets(fname,sizeof(fname),stdin);
    fname[strlen(fname)-1]='\0';

    fp=fopen(fname,"r");
    if(fp == NULL){
        fputs("File open error\n",stderr);
        exit(EXIT_FAILURE);
    }

    i=0;
    while(fgets(buf,sizeof(buf),fp)!=NULL){
        sscanf(buf,"%d,%lf",&gender,&height);
        data[i].gender=gender;
        data[i].height=height;
        i++;
    }

    printf("Input the filename of sumple ID:");
    fgets(fname,sizeof(fname),stdin);
    fname[strlen(fname)-1]='\0';

    fp=fopen(fname,"r");
    if(fp == NULL){
        fputs("File open error\n",stderr);
        exit(EXIT_FAILURE);
    }

    i=0;
    while(fgets(buf,sizeof(buf),fp)!=NULL){
        sscanf(buf,"%d",&ID);
        data[i].ID=ID;
        i++;
    }

    printf("Which ID's data do you want?:");
    scanf("%d",&iID);

    for(i=0;i<15;i++){
        if(iID==data[i].ID){
            if(data[i+1].gender==1){
                printf("ID : %d\n",iID);
                printf("gender : Male\n");
                printf("height : %.1f\n",data[i+1].height);
            }else if(data[i+1].gender==2){
                printf("ID : %d\n",iID);
                printf("gender : Female\n");
                printf("height : %.1f\n",data[i+1].height);
            }
            n=i;
        }
    }
    if(n==0){
        printf("No data\n");
    }
    return 0;
}