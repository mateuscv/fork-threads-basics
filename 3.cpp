#include <iostream> 
#include <stdlib.h> 
#include <pthread.h>

using namespace std;

int contador = 0;

void *funcThread1(void *vargp){
    while (contador<25000){
        contador++;
    }
}

void *funcThread2(void *vargp){
    while (contador<25000){
        cout << "contador = " << contador << "\n";
    }
}
   
int main(){ 
    pthread_t thread1_id, thread2_id;
    pthread_create(&thread1_id, NULL, funcThread1, NULL);
    pthread_create(&thread2_id, NULL, funcThread2, NULL);
    pthread_join(thread2_id, NULL); 
    return 0; 
}

