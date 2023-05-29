
#include <stdio.h>
#include <stdlib.h>

int main() {
    int codigo, quantidade, parcelas, opcao_pagamento;// variaveis com numeros inteiros
    float valor_unitario, valor_total, valor_pago, valor_desconto, valor_acrescimo, troco, valor_recebido,valor_parcela; //variaveis que possuem numeros decimais

    //Menu

    printf("\n \t PADARIA DA BERENICE \n");
    printf("\n Itens disponiveis para venda: \n");
    printf("\n COD\t ITEM \t \t \t  VALOR \n");
    printf("\n 1. \tPao de Forma - \t\t R$ 7,50 \n");
    printf("\n 2. \tPao de Centeio - \t R$ 8,69 \n");
    printf("\n 3. \tBroa de Milho - \t R$ 5,00 \n");
    printf("\n 4. \tSonho - \t \t R$ 4,50 \n");
    printf("\n 5. \tTubaina -\t\t R$ 3.25 \n\n");


    printf("\n Digite o codigo do item desejado: \n"); //selecione primeiramente o codigo
    scanf("%d", &codigo);
    getchar();

    switch(codigo) { //selecao de comandos do item
        case 1: // funcao de cada numero escrito
            valor_unitario = 7.50;
            break;
        case 2:
            valor_unitario = 8.69;
            break;
        case 3:
            valor_unitario = 5.00;
            break;
        case 4:
            valor_unitario = 4.50;
            break;
        case 5:
            valor_unitario = 3.25;
            break;
        default:
            printf("Codigo de item invalido!\n"); //caso o numero desejado for 0, menor que zero ou maior que 5. O codigo sera invalido
            exit (0);
    }
            printf("\n Digite a quantidade desejada: \n"); // em segundo passo a selecione a quantidade
            scanf("%d", &quantidade);
            getchar();

    if (quantidade <=0){
            printf("\n Quantidade invalida! \n"); //caso a quantidade seja 0 ou menor que zero. O codigo sera invalido

            exit (0); //comando para o programa entender que o codigo terminou. Nesse contexto o codigo é pra ser invalido por conta da quantidade digitada, se o numero for negativo ou zero, o codigo termina.

}

    valor_total = valor_unitario * quantidade; //calculo do valor do item + a quantidade

            printf("Valor total da venda: R$ %.2f\n", valor_total); //aparece no display o valor total da venda

    // aparece no display as opcoes de pagamento

            printf("\n Opcoes de pagamento:\n");
            printf("\n 1. A vista com desconto \n");
            printf("\n 2. A prazo \n");
            printf("\n Digite a opcao de pagamento desejada: \n ");
            scanf("%d", &opcao_pagamento);
            getchar();
    if (opcao_pagamento <=0 || opcao_pagamento >= 3){
            printf("\n Opcao de pagamento invalida \n"); // caso a opcao selecionada for menor que 0 ou maior que 3, aparecera no display a seguinte mensagem dita anteriormente

            exit (0);
            }



    switch(opcao_pagamento) { // o calculo realizado na opcao avista, calcular o desconto
        case 1: //opcao avista
            if (valor_total > 0 && valor_total <= 50.0 ) {
                valor_desconto = valor_total * 0.05;// 100/5= 0.05 total de 5% de desconto;
            }  else if (valor_total > 50 && valor_total< 100.0) {
                    valor_desconto = valor_total * 0.1; // se for maior que 50 reias ou menor que 100 reais, o desconto sera de 10%
            }    else {
                    valor_desconto = valor_total * 0.18; // se for acima de 100 reais, sera 18 % de desconto
            }
            valor_pago = valor_total - valor_desconto; // formula do valor pago

            printf("\n Valor a ser pago: R$ %.2f\n", valor_pago); //mostra no display o valor a ser pago
            printf("\n Digite o valor recebido: \n ");
            scanf("%f", &valor_recebido);
            getchar();
            printf("\n Valor Recebido: %.2f\n", valor_recebido);

            if ( valor_recebido >= valor_pago){ // IF PARA DIZER SE O VALOR DE TROCO ESTA CERTO

               troco = (valor_recebido - valor_pago); //formula do troco

            printf("\n Troco: R$ %.2f \n", troco);

            }

            else { // ELSE PARA CASO O VALOR DADO SEJA MENOR PARA NAO HAVER PREJUIZO

                printf("\n valor invalido \n");
            }


            break;
        case 2: //calculo da opcao a prazo, calculo dos acrescimos
            printf("\n Digite o numero de parcelas (ate 10): \n ");
            scanf("%d", &parcelas);
            getchar();

            if (parcelas <= 3) {
                valor_acrescimo = valor_total * 0.05;//se for até 3 parcelas é para ter um acréscimo de 5% ou 5/100= 0.05
            } else {
                valor_acrescimo = valor_total * 0.08;// se for maior que 3 parcelas é para ter um acréscimo de 8% ou 8/100= 0.08
            }
            if (parcelas <=0 || parcelas >= 11){
            printf("\n Opcao selecionada invalida \n"); // caso o numero de parcelas seja menor ou igual a 0 ou maior e igual 11, opcao sera invalida

        exit (0);
            }

            valor_pago = valor_total + valor_acrescimo; //formula do acrescimo

            printf("Valor a ser pago: R$ %.2f\n", valor_pago);
            valor_parcela= valor_pago / parcelas;
            printf("\n Valor da parcela= %.2f \n",valor_parcela);
            break;
        default:
            exit(0);

    }


    return 0;
}
