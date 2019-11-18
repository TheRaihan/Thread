#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

void* myturn(void * arg){
    int i;
    for(i=0;i<8;i++)
    {
        sleep(1);
        printf("MyTurn\n");

    }
    return NULL;
}

void* yourturn(){
    int i;
    for(i=0;i<3;i++)
    {
        sleep(1);
        printf("YourTurn\n");

    }
    return NULL;
}
void* turn(void * arg){
    int i;
    for(i=0;i<5;i++)
    {
        sleep(1);
        printf("Turn\n");

    }
    return NULL;
}



int main()
{
    pthread_t thread1,thread2;

    pthread_create(&thread1,NULL,myturn,NULL);
    yourturn();
    // pthread_create(&thread2,NULL,turn,NULL);


    // pthread_create(&thread2,NULL,yourturn,NULL);


    pthread_join(thread1, NULL);
}