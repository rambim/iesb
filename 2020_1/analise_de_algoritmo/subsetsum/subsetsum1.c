#include <stdio.h> 
  
// Returns true if there is a subset of set[] with sum equal to given sum 
int isSubsetSum(int set[], int n, int sum) 
{ 
    printf("\n Entrei funcao n = %d e sum = %d",n,sum);
    // Base Cases 
    if (sum == 0) 
        return 1; 
    if (n == 0 && sum != 0) 
        return 0; 
  
    
    // printf("\n Teste se o último é maior que o sum");
    // printf("\n Ultimo: %d Sum : %d",set[n-1],sum );
    if (set[n - 1] > sum) 
    {
        return isSubsetSum(set, n - 1, sum); 
        printf("\n vou chamar A");

    }
        // printf("\n ultimo maior que sum, Chama funcao sem considerar ele");
  
    
      printf("\n vou chamar B");
    return isSubsetSum(set, n - 1, sum) ||  // inclui ultimo elemento
           isSubsetSum(set, n - 1, sum - set[n - 1]); // exclui ultimo elemento
} 
  
// Driver program to test above function 
int main() 
{ 
    int set[] = { 3, 34, 4, 12, 5, 2 }; 
    int sum = 9; 
    int n = sizeof(set) / sizeof(set[0]); 
    if (isSubsetSum(set, n, sum) == 1) 
        printf("Found a subset with given sum"); 
    else
        printf("No subset with given sum"); 
    return 0; 
} 