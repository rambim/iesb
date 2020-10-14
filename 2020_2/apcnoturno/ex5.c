#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x=2;
    int * ptr;
    int * * ptr2;
    int * * * ptr3;

    ptr = &x;
    ptr2 = &ptr;
    ptr3 = &ptr2;

    printf("\nConteudo de X = %d",x);
    printf("\nEndereço de X = %ls",&x);
    printf("\nConteudo de ptr = %ls",ptr);
    printf("\nEndereco de ptr = %ls",&ptr);
    printf("\nConteudo de ptr2 = %ls",ptr2);
    printf("\nEndereco de ptr2 = %ls",&ptr2);
    printf("\nConteudo de ptr3 = %ls",ptr3);
    printf("\nEndereco de ptr3 = %ls",&ptr3);
    printf("\n &ptr3 = %ls ",&ptr3);
    printf("\n ptr3 = %ls ",ptr3);
    printf("\n *ptr3 = %ls ",*ptr3);
    printf("\n **ptr3 = %ls ",**ptr3);
    printf("\n ***ptr3 = %d ",***ptr3);

}
