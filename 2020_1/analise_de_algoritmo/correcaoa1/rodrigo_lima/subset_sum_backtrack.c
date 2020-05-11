#include <stdio.h>
#include <stdlib.h>


/*
# =============================================================================
# - Rodrigo Touriño Machado de Oliveira Lima
# - 1722130070
# - Análise de Algoritmos
# - 2020-04-21
# - Soma dos subconjuntos: Backtracking
# =============================================================================
*/


void print_subset(int subset[], int subset_length);
void subset_sum(int set[], int subset[], int set_length, int subset_length, int sum, int pivot, int capacity);
void get_subsets(int set[], int size, int capacity);

static int call_count = 0;

int main() 
{  
	int set[] = {7, 17, 2, 9, 12, 14, 11}; 
    int set_length = sizeof(set) / sizeof(int);
    
    get_subsets(set, set_length, 40);
    
    printf("\nn: %d\t Quantidade de chamadas: %d\n", set_length, call_count);

    return 0; 
}


void print_subset(int subset[], int subset_length)
{ 
	int i;
	
	printf("======================================================================\n");
	printf("Subconjunto:");
    for(i = 0; i < subset_length; i++){
        printf(" %d", subset[i]);
    }
    printf("\n");
}


void subset_sum(int set[], int subset[], int set_length, int subset_length, int sum, int pivot, int capacity)
{
	int i;
	call_count++;
	
    if(sum == capacity){
        print_subset(subset, subset_length); 
        subset_sum(set, subset, set_length, subset_length - 1, sum - set[pivot], pivot + 1, capacity); 
        return; 
    } else{
        for(i = pivot; i < set_length; i++){
            subset[subset_length] = set[i];
            subset_sum(set, subset, set_length, subset_length + 1, sum + set[i], i + 1, capacity);
        }
    }
}


void get_subsets(int set[], int size, int capacity)
{
	printf("C = %d\n", capacity);
	
    int *subset = (int *) malloc(size * sizeof(int));

    subset_sum(set, subset, size, 0, 0, 0, capacity);

    free(subset);
}
