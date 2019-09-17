#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>


int main()
{
    //Reconhecer acentua��o e caracteres especiais da l�ngua portuguesa
    setlocale(LC_ALL,"Portuguese");

    int opcaoDigitada = 0;



    do{


        printf("\n\t\tSeja Bem-Vindo(a), escolha uma das op��es do menu\n"
           "\tMenu\n"
           "[1] - Imprime na tela se o n�mero digitado � par/impar.\n"
           "[2] - Potencia��o de n�mero de ponto flutuante, resulta em nota��o cient�fica.\n"
           "[3] - Radicia��o de n�mero de ponto flutante, resultado em nota��o cient�fica.\n"
           "[4] - Informa se o ano � bissexto ou n�o.\n"
           "[5] - Calcula a m�dia ponderada das notas de 3 provas.\n"
           "[6] - Calcula a m�dia aritm�tica das notas de 2 provas.\n"
           "[10] - Impreme seu nome e sua matr�cula, mostra sua matr�cula em hexadecimal.\n"
           "[7] - L� um n�mero e imprime o fatorial desse n�mero.\n"
           "[8] - L� um n�mero e imprime se ele � primo ou n�o.\n"
           "[9] - Imprime os n primeiros n�meros da sequ�ncia de Fibonacci, onde n � o valor informado por voc�.\n"
           "[0] - Sair do programa.\n");

        //system("cls || clear");

        scanf("%d", &opcaoDigitada);


        switch(opcaoDigitada){

            //Informa se o n�mero � par/impar.
            case 1 :{

                int numDigitado = 0;

                printf("Digite um n�mero inteiro para saber se ele � par/impar: ");
                scanf("%d", &numDigitado);

                if(numDigitado%2 == 0){
                    printf("\n O n�mero %d � par.\n", numDigitado);
                } else{
                    printf("\n O n�mero %d � impar.\n", numDigitado);
                }
                break;
            }
            //Calcula a potenciac�o de n�meros com ponto flutuante (v�rgula).
            case 2 :{

                float baseA = 0;
                int expoenteB = 0;
                float resultado = 0;

                printf("Digite um n�mero de ponto flutuante que ir� representar a base da pot�ncia: ");
                scanf("%f", &baseA);
                printf("\nDigite um n�mero inteiro que ir� representar o expoente: ");
                scanf("%d", &expoenteB);

                resultado = pow(baseA, expoenteB);

                printf("\nResultado da pot�ncia em nota��o cient�fica �: %.3E.", resultado);

                break;
            }
            //Calcula a raiz de n�meros com ponto flutuante em qualquer �ndice (v�rgula).
            case 3 :{

                float radicandoA = 0;
                int indiceB = 0;
                float resultado = 0;

                printf("Digite o n�mero de ponto flutuante que ser� o radicando: ");
                scanf("%f", &radicandoA);
                printf("Digite o n�merio inteiro que ser� o �ndice da raiz: ");
                scanf("%d", &indiceB);

                resultado = pow(radicandoA, 1./indiceB);

                printf("\nResultado da raiz em nota��o cient�fica �: %.3E.", resultado);
                break;
            }
            //Calcula ano bissexto
            case 4 :{

                int ano = 0;

                printf("Digite um ano: ");
                scanf("%d", &ano);

                if(ano > 0){
                    if(ano%4 == 0){

                        printf("\nO ano de %d � bissexto.", ano);
                    } else{

                        printf("\nO ano de %d n�o � bissexto.", ano);
                    }
                } else {

                    printf("\nAno inv�lido.");
                }
                break;
            }
            //Calcula m�dia ponderada de 3 notas.
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

                    printf("Aluno aprovado com m�dia ponderada de: %.2f.", mediaPonderada);

                } else{

                    printf("Aluno reprovado com m�dia ponderada de: %.2f.", mediaPonderada);
                }
                break;
            }
            //Calcula m�dia aritm�tica de 2 notas.
            case 6 :{

                float nota1, nota2, mediaAritmetica;

                printf("Digite a primeira nota: ");
                scanf("%f", &nota1);
                printf("\nDigite a segunda nota: ");
                scanf("%f", &nota2);

                if(nota1 >= 0 && nota1 <= 10 && nota2 >= 0 && nota2 <= 10){

                    mediaAritmetica = (nota1+nota2)/2;

                    printf("M�dia das notas informadas �: %.2f", mediaAritmetica);

                } else{

                    printf("M�dia inv�lida, n�o est� entre 0.0 e 10.0");
                }
                break;
            }
            //Calcula o fatorial
            case 7 :{

                int aux;
                int fat = 0;
                int numFat;

                printf("Digite um n�mero inteiro e maior que zero: ");
                scanf("\n%d", &numFat);

                aux = numFat; //n�o alterar o valor de numFat

                if(aux > 0){
                    for(fat=1; aux>1; aux--){
                        fat=fat*aux;
                    }
                    printf("\nO fatorial de %d �: %d", numFat, fat);
                } else{
                    printf("\nErro, valor diferente do esperado.");
                }
                break;
            }
            //Calcula se o n�mero � primo ou n�o
            case 8 :{
                int i, numPri, aux = 0;

                printf("Digite o n�mero que voc� deseja verificar se � primo: ");
                scanf("%d", &numPri);

                for(i = 2; i<numPri; i++){

                    if(numPri%i == 0){

                        aux++;
                    }
                }

                if(aux == 0){

                    printf("\nO n�mero %d � primo.", numPri);
                } else{

                    printf("\nO n�mero %d n�o � primo.", numPri);
                }
                break;
            }
            //Sequ�ncia de Fibonacci
            case 9 :{

                int i, indice, ant, prox, soma;

                printf("Digite a quantidade de elementos que voc� deseja imprimir na sequ�ncia de Fibonacci:");
                scanf("%d", &indice);

                ant = 0;
                prox = 1;

                if(indice >= 0){

                    printf("\nS�rie de Fibonacci: %d", prox);

                }else if(indice <= 0){

                    printf("\nS�rie de Fibonacci: %d", ant);
                }

                for(i = 2; i<=indice; i++){

                    soma = prox+ant;
                    ant = prox;
                    prox = soma;
                    printf("\n%d ", soma);
                }
                break;
            }
            //Imprime o nome e a matr�cula em hexadecimal
            case 10 :{

                //char nome1 = ;
                int matricula = 0;

                printf("Digite sua matr�cula: ");
                scanf("%d", &matricula);

                printf("\n Sua matr�cula em hexadecimal �: %X", matricula);
                break;
            }
            //Encerra o programa
            case 0 :{

                printf("\nVoc� encerrou o Menu.");
                break;
            }
            //Caso o usu�rio digite algo difente de 0-10
            default :

                printf("\nVoc� digitou uma op��o inv�lida, tente novamente.");
                break;
        }

        system("cls || clear");

    }while(opcaoDigitada!=0);

    printf("\nGood Bye!\n"); //Aparece quando o usu�rio apertar a op��o 0

    return 0;
}
