#include <iostream> 
#include <stdlib.h> 
#include <pthread.h> 

using namespace std;

void *funcThread1(void *vargp){
    cout << "Thread1 \n";
}

void *funcThread2(void *vargp){
    cout << "Thread2 \n";
}
   
int main(){ 
    pthread_t thread1_id, thread2_id; 
    pthread_create(&thread1_id, NULL, funcThread1, NULL);
    pthread_create(&thread2_id, NULL, funcThread2, NULL);
    pthread_join(thread1_id, NULL);
    pthread_join(thread2_id, NULL); 
    return 0;
}

