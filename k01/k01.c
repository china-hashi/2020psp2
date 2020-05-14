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
    int N=0,i=0;
    double ave[8],square_ave[8],var,S,U,e;

    printf("input the filename of sample:");
    fgets(fname,sizeof(fname),stdin);
    fname[strlen(fname)-1] = '\0';
    printf("the filename of sample: %s\n",fname);

    fp = fopen(fname,"r");
    if(fp==NULL){
        fputs("File open error\n",stderr);
        exit(EXIT_FAILURE);
    }

    ave[0]=0;
    square_ave[0]=0;
    while(fgets(buf,sizeof(buf),fp) != NULL){
        sscanf(buf,"%lf",&val);
        N++;
        i++;
        ave[i]=ave_online(val,ave[i-1],N);
        square_ave[i]=ave_online(pow(val,2.0),square_ave[i-1],N);
        var=var_online(val,ave[i-1],square_ave[i-1],N);
    }

    printf("sample mean:%.2f\n",ave[i]);
    printf("sample variance:%.2f\n",var);

    S=square_ave[i]-pow(ave[i],2.0);
    U=S*N/(N-1);
    e=sqrt(U/N);
    printf("population mean (estimated):%.2f±%.2f\n",ave[i],e);
    printf("population variance (estimated):%.2f\n",U);

    if(fclose(fp) == EOF){
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    }
    return 0;
}

double ave_online(double val,double ave,int N)
{
    double average;
    average=((N-1)*ave/N)+(val/N);
    return average;
}

double var_online(double val,double ave,double square_ave,int N)
{
    double variance;
    variance=((N-1)*square_ave/N)+(pow(val,2.0)/N)-pow(((N-1)*ave/N)+(val/N),2.0);
    return variance;
}