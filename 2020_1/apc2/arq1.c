
#include <stdio.h>
#include <stdlib.h>

int main()
{   
    FILE * ptr;

    ptr = fopen("arquivo1.txt","w");

    if ( ptr == NULL)
    {
        printf("\n Problema na abertura do arquivo");
    }
    else
    {
        fprintf(ptr,"Lourenco Rodrigues\n");
        fclose(ptr);

    }
    
    

    return 0;
}




