#include <stdio.h>
#include "./lire_fin_ligne.h"
#include <lire_fin_ligne.c>





int main(int argc, char* argv[]) {
    
    printf("Ecrivez: Bonjour, monde !\n");
    scanf("Bonjour, monde !") ; 
    printf("Je vous ai compris!\n");
    
    
    while(1) {
        
        int a = getchar();
        if (a!='\n'){
        printf("%c",(char) a );
        } else {break;}
        
    }
    printf("\n");
    
    
    return 0;
}
