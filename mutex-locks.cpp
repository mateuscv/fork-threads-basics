#include <iostream> 
#include <stdlib.h> 
#include <pthread.h> 
using namespace std;

pthread_mutex_t lock;

void *funcThread1(void *vargp){
    pthread_mutex_lock(&lock);
    cout << "Thread1 \n";
    pthread_mutex_unlock(&lock);
}

void *funcThread2(void *vargp){
    pthread_mutex_lock(&lock);
    cout << "Thread2 \n";
    pthread_mutex_unlock(&lock);
}
   
int main(){ 
    pthread_t thread1_id, thread2_id;
    if (pthread_mutex_init(&lock, NULL) != 0)
    {
        printf("\n Falha em inicializar a trava!\n");
        return 1;
    }
    pthread_create(&thread1_id, NULL, funcThread1, NULL);
    pthread_create(&thread2_id, NULL, funcThread2, NULL);
    pthread_join(thread1_id, NULL);
    pthread_join(thread2_id, NULL);
    pthread_mutex_destroy(&lock);
    return 0;
}

