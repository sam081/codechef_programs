#include <pthread.h>
#include <stdio.h>
int sum,sub,mult; /* this data is shared by the thread(s) */
void *summation(int arg[]);
void *multiplication(int arg[]);
void *substraction(int arg[]);

int main()
{
    int arg[2],i;
    printf("Enter first number: \n");
    scanf("%d",&arg[0]);
    printf("Enter second number: \n");
    scanf("%d",&arg[1]);
    pthread_t tid[3];
    pthread_attr_t attr;
    pthread_attr_init (&attr) ;

    pthread_create(&tid[0],&attr,summation,arg);
    pthread_create(&tid[1],&attr,multiplication,arg);
    pthread_create(&tid[2],&attr,substraction,arg);
    for(i=0;i<3;i++)
        pthread_join(tid[i], NULL);
    printf("summation = %d\n",sum);
    printf("multiplication = %d\n",mult);
    printf("substraction = %d\n",sub);
    return 0;
}

void *summation(int arg[])
{
    sum=arg[0]+arg[1];
    pthread_exit(0);
}
void *multiplication(int arg[])
{
    mult=arg[0]*arg[1];
    pthread_exit(0);
}
void *substraction(int arg[])
{
    sub=arg[0]-arg[1];
    pthread_exit(0);
}
