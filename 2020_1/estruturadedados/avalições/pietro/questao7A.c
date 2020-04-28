#include<stdlib.h>
#include<stdio.h>

#include<math.h>
#include<locale.h>
#include<string.h>

int main(){	 
	setlocale(LC_ALL, "Portuguese");
	char cod[50],inverso[50];
	int i,j;
	
	printf("Informe o c�digo: ");
	scanf("%s",&cod);
	j=strlen(cod)-1;
	
	for (i=0;i<j;i++){
		if(cod[i]!='A'){
			if(cod[i]!='B'){
				if(cod[i]!='C'){
					printf("C�digo inv�lido, utilize A, B e C\n");
					return 0;
				}
			}
			 
		}
	}
	
	
	/*for (i=0;cod[j]!='C';i++){	
		inverso[i]=cod[j];	
		j--;
		}*/
	
	i=0;
	while(cod[i] == cod[j]){

            if(cod[i] == 'C' && cod[j] == 'C'){
                printf("Equivale\n");
                break;
            }
            else{
                i++;
                j--;
            }
            if(cod[i] !=cod[j] ){
            	printf("N�o equivale\n");
            	break;
			}
    }
        
    
	
	
	/*j=strlen(cod)-1;
	
	for (i=0;i<j;i++){
		printf("%s ",cod[i]);
	} */
	
	//printf("\nfoi");
	getch();
}
