#from libc import *


int fib(n) {
    switch(n){
        case 0 : return 1
            break;
        case 1 : return 1
            break;
        case > 2 : return fib(n-1) + fib(n-2)
            break;
    
    return 0
        
    }
    
}

int main() {
    printf(fib(3))
    
    
    return 0;
}
