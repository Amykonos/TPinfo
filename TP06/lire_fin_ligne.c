#include "lire_fin_ligne.h"
#include <ctype.h>
int lire_fin_ligne() {
    int count = 0;
    scanf("");
    while(1) {
        int a = getchar();
        if(a == '\n'){
            
            break; 
            
        } else {
            if (!isspace(a)) 
            count += 1;
        }
        
        
    };
    
    return count;
    
}
