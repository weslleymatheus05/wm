#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>


int main()
{
    //Reconhecer acentuação e caracteres especiais da língua portuguesa
    setlocale(LC_ALL,"Portuguese");

    int opcaoDigitada = 0;



    do{


        printf("\n\t\tSeja Bem-Vindo(a), escolha uma das opções do menu\n"
           "\tMenu\n"
           "[1] - Imprime na tela se o número digitado é par/impar.\n"
           "[2] - Potenciação de número de ponto flutuante, resulta em notação científica.\n"
           "[3] - Radiciação de número de ponto flutante, resultado em notação científica.\n"
           "[4] - Informa se o ano é bissexto ou não.\n"
           "[5] - Calcula a média ponderada das notas de 3 provas.\n"
           "[6] - Calcula a média aritmética das notas de 2 provas.\n"
           "[10] - Impreme seu nome e sua matrícula, mostra sua matrícula em hexadecimal.\n"
           "[7] - Lê um número e imprime o fatorial desse número.\n"
           "[8] - Lê um número e imprime se ele é primo ou não.\n"
           "[9] - Imprime os n primeiros números da sequência de Fibonacci, onde n é o valor informado por você.\n"
           "[0] - Sair do programa.\n");

        //system("cls || clear");

        scanf("%d", &opcaoDigitada);


        switch(opcaoDigitada){

            //Informa se o número é par/impar.
            case 1 :{

                int numDigitado = 0;

                printf("Digite um número inteiro para saber se ele é par/impar: ");
                scanf("%d", &numDigitado);

                if(numDigitado%2 == 0){
                    printf("\n O número %d é par.\n", numDigitado);
                } else{
                    printf("\n O número %d é impar.\n", numDigitado);
                }
                break;
            }
            //Calcula a potenciacão de números com ponto flutuante (vírgula).
            case 2 :{

                float baseA = 0;
                int expoenteB = 0;
                float resultado = 0;

                printf("Digite um número de ponto flutuante que irá representar a base da potência: ");
                scanf("%f", &baseA);
                printf("\nDigite um número inteiro que irá representar o expoente: ");
                scanf("%d", &expoenteB);

                resultado = pow(baseA, expoenteB);

                printf("\nResultado da potência em notação científica é: %.3E.", resultado);

                break;
            }
            //Calcula a raiz de números com ponto flutuante em qualquer índice (vírgula).
            case 3 :{

                float radicandoA = 0;
                int indiceB = 0;
                float resultado = 0;

                printf("Digite o número de ponto flutuante que será o radicando: ");
                scanf("%f", &radicandoA);
                printf("Digite o númerio inteiro que será o índice da raiz: ");
                scanf("%d", &indiceB);

                resultado = pow(radicandoA, 1./indiceB);

                printf("\nResultado da raiz em notação científica é: %.3E.", resultado);
                break;
            }
            //Calcula ano bissexto
            case 4 :{

                int ano = 0;

                printf("Digite um ano: ");
                scanf("%d", &ano);

                if(ano > 0){
                    if(ano%4 == 0){

                        printf("\nO ano de %d é bissexto.", ano);
                    } else{

                        printf("\nO ano de %d não é bissexto.", ano);
                    }
                } else {

                    printf("\nAno inválido.");
                }
                break;
            }
            //Calcula média ponderada de 3 notas.
            case 5 :{

                float nota1, nota2, nota3, mediaPonderada;

                printf("Digite a primeira nota: ");
                scanf("%f", &nota1);
                printf("\nDigite a segunda nota: ");
                scanf("%f", &nota2);
                printf("\nDigite a terceira nota: ");
                scanf("%f", &nota3);

                mediaPonderada = (1*nota1+1*nota2+2*nota3)/4;

                if(mediaPonderada >= 60){

                    printf("Aluno aprovado com média ponderada de: %.2f.", mediaPonderada);

                } else{

                    printf("Aluno reprovado com média ponderada de: %.2f.", mediaPonderada);
                }
                break;
            }
            //Calcula média aritmética de 2 notas.
            case 6 :{

                float nota1, nota2, mediaAritmetica;

                printf("Digite a primeira nota: ");
                scanf("%f", &nota1);
                printf("\nDigite a segunda nota: ");
                scanf("%f", &nota2);

                if(nota1 >= 0 && nota1 <= 10 && nota2 >= 0 && nota2 <= 10){

                    mediaAritmetica = (nota1+nota2)/2;

                    printf("Média das notas informadas é: %.2f", mediaAritmetica);

                } else{

                    printf("Média inválida, não está entre 0.0 e 10.0");
                }
                break;
            }
            //Calcula o fatorial
            case 7 :{

                int aux;
                int fat = 0;
                int numFat;

                printf("Digite um número inteiro e maior que zero: ");
                scanf("\n%d", &numFat);

                aux = numFat; //não alterar o valor de numFat

                if(aux > 0){
                    for(fat=1; aux>1; aux--){
                        fat=fat*aux;
                    }
                    printf("\nO fatorial de %d é: %d", numFat, fat);
                } else{
                    printf("\nErro, valor diferente do esperado.");
                }
                break;
            }
            //Calcula se o número é primo ou não
            case 8 :{
                int i, numPri, aux = 0;
                
                do{
                    printf("Digite o número que você deseja verificar se é primo: ");
                    scanf("%d", &numPri);
                    
                    if(numPri<=0){
                        printf("Número inválido\n");
                    }
                }while(numPri <= 0);
                
                for(i = 2; i<numPri/2; i++){
                    if(numPri%i == 0){
                        aux++;
                        break;
                    }
                }
                if(aux == 0){

                    printf("\nO número %d é primo.", numPri);
                } else{

                    printf("\nO número %d não é primo.", numPri);
                }
                break;
            }
            //Sequência de Fibonacci
            case 9 :{

                int i, indice, ant, prox, soma;

                printf("Digite a quantidade de elementos que você deseja imprimir na sequência de Fibonacci:");
                scanf("%d", &indice);

                ant = 0;
                prox = 1;

                if(indice >= 0){

                    printf("\nSérie de Fibonacci: %d", prox);

                }else if(indice <= 0){

                    printf("\nSérie de Fibonacci: %d", ant);
                }

                for(i = 2; i<=indice; i++){

                    soma = prox+ant;
                    ant = prox;
                    prox = soma;
                    printf("\n%d ", soma);
                }
                break;
            }
            //Imprime o nome e a matrícula em hexadecimal
            case 10 :{

                //char nome1 = ;
                string nome = "Kelion";
                int matricula = 0;

                printf("Digite sua matrícula: ");
                scanf("%d", &matricula);
                
                
                printf("\n Sua matrícula em hexadecimal é: %X, seu nome é %s", matricula, nome);
                break;
            }
            //Encerra o programa
            case 0 :{

                printf("\nVocê encerrou o Menu.");
                break;
            }
            //Caso o usuário digite algo difente de 0-10
            default :

                printf("\nVocê digitou uma opção inválida, tente novamente.");
                break;
        }

        system("cls || clear");

    }while(opcaoDigitada!=0);

    printf("\nGood Bye!\n"); //Aparece quando o usuário apertar a opção 0

    return 0;
}
