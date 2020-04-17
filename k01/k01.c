#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

extern double ave_online(double val,double ave,int i);
extern double var_online(double val, double ave, double square_ave,int i);

int main(void)
{
    double val;
    char fname[FILENAME_MAX];
    char buf[256];
    FILE* fp;
    int N=0;
    double ave,sum=0,sum2=0,bN=0,square_ave;

    printf("input the filename of sample:");
    fgets(fname,sizeof(fname),stdin);
    fname[strlen(fname)-1] = '\0';
    printf("the filename of sample: %s\n",fname);

    fp = fopen(fname,"r");
    if(fp==NULL){
        fputs("File open error\n",stderr);
        exit(EXIT_FAILURE);
    }

    while(fgets(buf,sizeof(buf),fp) != NULL){
        sscanf(buf,"%lf",&val);
        sum=sum+bN;
        ave=sum/N;
        sum2=sum2+pow(bN,2.0);
        square_ave=sum2/N;
        bN=val;
        N++;
    }

    ave_online(val,ave,N);
    var_online(val,ave,square_ave,N);

    if(fclose(fp) == EOF){
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    }
    return 0;
}

double ave_online(double val,double ave,int i)
{
    double average;
    average=((i-1)*ave/i)+(val/i);
    printf("%f\n",average);
}

double var_online(double val,double ave,double square_ave,int i)
{
    double variance;
    variance=((i-1)*square_ave/i)+(pow(val,2.0)/i)-pow(((i-1)*ave/i)+(val/i),2.0);
    printf("%f\n",variance);
}