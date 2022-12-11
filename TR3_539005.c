#include <stdio.h>
#include <stdlib.h>

int main(){
   
    unsigned int vetor[200];
   	
    printf("Digite números entre 0 e 5000 e printe-os com -1:\n");

    /* inicializando todas as posicoes do vetor com zero */
    for(int i = 0; i < 200; i++){
        vetor[i] = 0;
    }
    while(1){
        int numero = 0;
        scanf("%i", &numero);

        /* o programa para quando o usuario digitar menos um */
        if(numero == -1){
            break;

        /* retorna erro de saida se o usuario digitar numeros menores que zero, excluindo o menos 1, ou maiores que cinco mil */
        }else if(numero < 0 || numero > 5000){
            return EXIT_FAILURE;

        /* ocorre quando o usuario digita um numero entre 0 e 5000 */
        }else{
            int posicao = numero / 32; // posicao no vetor
            int deslocamento = numero % 32; // deslocamento no vetor

            vetor[posicao] = vetor[posicao] | 1 << deslocamento; // armazena os numeros no vetor de bits
        } 
    }
    for(int i = 0; i < 200; i++){

        for(int j = 0; j < 32; j++){
            int num = vetor[i] & (1 << j); // recupera os numeros armazenados 

            if(num){
                printf("%i ", (i * 32) + j); // printa um por um em ordem crescente
            }
        }
    }
    printf("\n");
    return 0;
}
