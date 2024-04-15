#include <stdio.h>
#include <stdlib.h>

#define PRECO_REFEICAO_KG 35.00
#define PRECO_EMBALAGEM_QUENTINHA 0.50
#define PRECO_QUENTINHA 20.50
#define PRECO_BEBIDA 5.00

// Estrutura para representar uma venda
typedef struct {
    int dia;
    float peso_refeicao;
    int quantidade_bebida;
} Venda;

// Função para calcular o valor total de uma venda
float calcularTotal(Venda venda) {
    float total_refeicao = venda.peso_refeicao * PRECO_REFEICAO_KG;
    float total_bebida = venda.quantidade_bebida * PRECO_BEBIDA;
    return total_refeicao + total_bebida;
}

int main() {
    int dias_mes = 30; // Supondo um mês com 30 dias
    float vendas_mensais[dias_mes];
    float vendas_anuais[12] = {0};

    // Registro de vendas diárias
    for (int dia = 1; dia <= dias_mes; dia++) {
        float total_vendas_dia = 0;
        for (int venda = 0; venda < 100; venda++) {
            Venda nova_venda;
            nova_venda.dia = dia;
            nova_venda.peso_refeicao = 0.5; // Exemplo de peso de refeição
            nova_venda.quantidade_bebida = 2; // Exemplo de quantidade de bebida
            total_vendas_dia += calcularTotal(nova_venda);
        }
        vendas_mensais[dia - 1] = total_vendas_dia;
        vendas_anuais[dia / 3] += total_vendas_dia; // Agrupando vendas por trimestre
    }

    // Relatório diário
    printf("Relatório diário:\n");
    for (int dia = 0; dia < dias_mes; dia++) {
        printf("Dia %d: R$ %.2f\n", dia + 1, vendas_mensais[dia]);
    }

    // Relatório mensal
    printf("\nRelatório mensal:\n");
    float total_vendas_mensal = 0;
    for (int dia = 0; dia < dias_mes; dia++) {
        total_vendas_mensal += vendas_mensais[dia];
    }
    printf("Total vendido no mês: R$ %.2f\n", total_vendas_mensal);

    // Ordenar vendas anuais em ordem decrescente
    printf("\nRelatório anual em ordem decrescente:\n");
    for (int mes = 0; mes < 12; mes++) {
        int mes_max = 0;
        float max_vendas = 0;
        for (int i = 0; i < 12; i++) {
            if (vendas_anuais[i] > max_vendas) {
                max_vendas = vendas_anuais[i];
                mes_max = i;
            }
        }
        printf("Mês %d: R$ %.2f\n", mes_max + 1, vendas_anuais[mes_max]);
        vendas_anuais[mes_max] = -1; // Marcando o mês como já impresso
    }

    return 0;
}