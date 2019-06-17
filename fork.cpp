#include <iostream> 
#include <sys/types.h> 
#include <unistd.h> 

using namespace std;

int main(){
    int f = 0;
    f = fork();
    for (int i = 0; i < 14; i++){
        if (f == 0) 
            cout << "ProgB\n"; 
        else
            cout << "ProgA\n";  
    }
    return 0;
} 
