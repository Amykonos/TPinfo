#include <stdlib.h>
#include <stdio.h>

struct Graphe{
    
    int nb_sommets;
    int** matrice_adjacence;
    int** matrice_poids;
        
};

typedef struct Graphe * graphe;

graphe nouveau_graphe(int n){
    
    if(n<=0) return NULL;
    
    graphe G;
    G = malloc(sizeof(struct Graphe));
    G-> nb_sommets = n;
    G-> matrice_adjacence = malloc(n*sizeof(int*));
    G-> matrice_poids = malloc(n*sizeof(int*));
    
    for (int i = 0; i<n; i++){
        
        G->matrice_adjacence[i] = malloc(n*sizeof(int));
        G-> matrice_poids[i] = malloc(n*sizeof(int));
        
        for (int j = 0; j<n; j++) {
            G-> matrice_adjacence[i][j] = 0;
            G-> matrice_poids[i][j] = 0;
                       
        };
    
    };
    return G;
};

void nouveau_arc(int i,int j,int p,graphe G) {
    if(i< G->nb_sommets || j< G->nb_sommets){
        G->matrice_adjacence[i][j] = 1;
        G-> matrice_poids[i][j] = p;
    
    } else {};
    
};

void print_graph_dict(graphe G){
    
    for (int i = 0; i < G-> nb_sommets; i++){
     
        printf("%d : ",i);
        
        for (int j = 0; j<G-> nb_sommets; j++){
            if((G->matrice_adjacence[i][j]) == 1)
            printf("%d ; ",j);
            
        }
        
        printf("\n");
        
    }
    
}

graphe copie(graphe G){
    
    graphe H;
    H = malloc(sizeof(struct Graphe));
    H-> nb_sommets = G-> nb_sommets;
    
    H-> matrice_adjacence = malloc(G-> nb_sommets*sizeof(int*));
    H-> matrice_poids = malloc(G-> nb_sommets*sizeof(int*));
    
    for (int i = 0; i<G-> nb_sommets; i++){
        
        H->matrice_adjacence[i] = malloc(G-> nb_sommets*sizeof(int));
        H-> matrice_poids[i] = malloc(G-> nb_sommets*sizeof(int));
        
        for (int j = 0; j<G-> nb_sommets; j++) {
            H-> matrice_adjacence[i][j]=G->matrice_adjacence[i][j];
            H-> matrice_poids[i][j] = G-> matrice_poids[i][j];
                       
        };
    
    };
    return H;
        
}

void enleve_orient(graphe G){
    
    for (int i = 0; i<G->nb_sommets; i++){
        for (int j = 0; j<G->nb_sommets; j++) {
            if(G->matrice_poids[i][j]>0 && G->matrice_poids[j][i]){
                if(G->matrice_poids[i][j]>G->matrice_poids[j][i]){
                    G->matrice_poids[i][j] = 0;
                    G->matrice_adjacence[i][j] = 0;
                } else {
                    G->matrice_poids[j][i] = 0
                    G->matrice_adjacence[j][i] = 0
                }
                
            }
            if(i>j){
                if(G->matrice_adjacence[j][i] = 1){
                    G->matrice_adjacence[i][j] = 1
                    G->matrice_adjacence[j][i] = 0
                    G->matrice_poids[i][j] = G->matrice_poids[j][i]
                    G->matrice_poids[j][i] = 0
                    
                }
            }
            
        }
        
        
    }
    
}

void free_graph(graphe G){
    for(int i =0; i<G->nb_sommets; i++){
        free(G->matrice_poids[i]);
        free(G_>matrice_adjacence[i]);
    }
    free(G->matrice_poids)
    free(G->matrice_adjacence)
    free(G)
}


int main(){
    
    
    struct Graphe* G = nouveau_graphe(5);
    nouveau_arc(0,1,6,G);
    nouveau_arc(0,2,3,G);
    nouveau_arc(1,4,12,G);
    nouveau_arc(1,3,4,G);
    nouveau_arc(1,2,1,G);
    nouveau_arc(2,1,2,G);
    nouveau_arc(2,3,7,G);
    nouveau_arc(3,4,3,G);
    
    print_graph_dict(G);
       
    
    
    
    
    return 0;
}
