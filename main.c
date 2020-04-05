#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define N_SAMPLES 10000
#define F_ORDER 419
#define O_LEN (N_SAMPLES+F_ORDER-1)

void readCoefficients(float * pDstArray)
{
    FILE *fcoeff=fopen("filter/bpf_coeff.txt","r");
    char str[15];
    int i=0;
    float a;
    while(fgets(str,15,fcoeff)!=NULL)
    {
        a=strtof(str,NULL);
        pDstArray[i]=a;
        i++;
    }
    fclose(fcoeff);
}

void convolve(float *pSrcA,int lenA,float *pSrcB,int lenB,float *pDest)
{
    int lenY=lenA+lenB-1,i,i2,j;
    float sum=0.0f;
    for (i = 0; i < lenY; i++)
    {
        sum=0.0f;
        i2=i;
        for(j = 0;j < lenB; j++)
        {
            if((i2 >= 0) && (i2<lenA))
            {
                sum+=pSrcA[i2]*pSrcB[j];
            }
            i2--;
            pDest[i]=sum;
        }
    }
}
void displayArray(float *pDisplayed,unsigned int lenpDisplayed)
{
    for (size_t i = 0; i < lenpDisplayed; i++)
    {
        printf("%d %.8f  \n",i,pDisplayed[i]);
    }
}
void InitRandomArray(float *pSrcArray)
{
    srand(time(0));
    int i;
    for(i=0;i<N_SAMPLES;i++)
    {
        pSrcArray[i]=(float)rand()/RAND_MAX;
    }
}

int main()
{
    FILE *fnoise=fopen("datas/filterednoise.txt","w");
    FILE *ufnoise=fopen("datas/unfilterednoise.txt","w");
    float noise[N_SAMPLES];
    float filter[F_ORDER];
    float filterednoise[O_LEN];
    InitRandomArray(noise);
    readCoefficients(filter);
    convolve(noise,N_SAMPLES,filter,F_ORDER,filterednoise);
    //displayArray(filterednoise,O_LEN);
    for (size_t i = 0; i < O_LEN; i++)
    {
        fprintf(fnoise,"%.8f\n",filterednoise[i]);
    }
    for (size_t i = 0; i < N_SAMPLES; i++)
    {
        fprintf(ufnoise,"%.8f\n",noise[i]);
    }
    fclose(ufnoise);
    fclose(fnoise);
    return 0;
}
