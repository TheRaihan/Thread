#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

struct kid
{
    int low;
    int high;
};

void *prime(void *p)
{
    struct kid *k = (struct kid*)p;
    int low, high,i, flag,counter=0;
    low = k->low;
    high = k->high;

    while (low < high)
    {
        flag = 0;

        for(i = 2; i*i <= low; ++i)
        {
            if(low % i == 0)
            {
                flag = 1;
                break;
            }
        }

        if (flag == 0)
            counter ++;

        ++low;
    }

    return counter;
}

int main()
{
    pthread_t kid1, kid2,kid3, kid4;
    struct kid ob1,ob2,ob3,ob4;
    int count1,count2,count3,count4;

    ob1.low=3;
    ob1.high=250;
    ob2.low=251;
    ob2.high=500;
    ob3.low=501;
    ob3.high=750;
    ob4.low=751;
    ob4.high=1000;

    pthread_create(&kid1,NULL,prime,&ob1);
    pthread_create(&kid2,NULL,prime,&ob2);
    pthread_create(&kid3,NULL,prime,&ob3);
    pthread_create(&kid4,NULL,prime,&ob4);


    pthread_join(kid1,&count1);
    printf("\nPrime numbers between 3 and 250 are: %d",count1);
    pthread_join(kid2,&count2);
    printf("\nPrime numbers between 251 and 500 are: %d",count2);
    pthread_join(kid3,&count3);
    printf("\nPrime numbers between 501 and 750 are: %d",count3);
    pthread_join(kid4,&count4);
    printf("\nPrime numbers between 751 and 1000 are: %d \n",count4);

    return 0;
}



