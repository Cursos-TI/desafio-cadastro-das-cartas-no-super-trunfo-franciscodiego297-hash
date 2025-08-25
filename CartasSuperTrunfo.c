#include <stdio.h>
#include <string.h>

// Estrutura para representar uma carta
typedef struct {
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidade;
} Carta;

// Função para exibir o menu de atributos
void mostrarMenu(int excluido) {
    printf("\nEscolha um atributo para comparar:\n");
    if (excluido != 1) printf("1 - População\n");
    if (excluido != 2) printf("2 - Área\n");
    if (excluido != 3) printf("3 - PIB\n");
    if (excluido != 4) printf("4 - Pontos turísticos\n");
    if (excluido != 5) printf("5 - Densidade demográfica\n");
    printf("Opção: ");
}

// Função que compara um atributo e retorna o "valor efetivo" usado na soma
float compararAtributo(int opcao, Carta c) {
    switch(opcao) {
        case 1: return (float)c.populacao;
        case 2: return c.area;
        case 3: return c.pib;
        case 4: return (float)c.pontosTuristicos;
        case 5: return c.densidade;
        default: return 0.0; 
    }
}

// Função para exibir nome do atributo (ajuda no resultado final)
const char* nomeAtributo(int opcao) {
    switch(opcao) {
        case 1: return "População";
        case 2: return "Área";
        case 3: return "PIB";
        case 4: return "Pontos turísticos";
        case 5: return "Densidade demográfica";
        default: return "Desconhecido";
    }
}

int main() {
    // Duas cartas de exemplo
    Carta carta1 = {"Brasil", 214000000, 8516000.0, 16000.5, 5, 214000000 / 8516000.0};
    Carta carta2 = {"Argentina", 46000000, 2780000.0, 6300.2, 4, 46000000 / 2780000.0};

    int opcao1, opcao2;

    printf("=== SUPER TRUNFO: Nível Mestre ===\n");
    printf("Comparando cartas: %s x %s\n", carta1.nome, carta2.nome);

    // Escolha do primeiro atributo
    mostrarMenu(-1);
    scanf("%d", &opcao1);

    // Escolha do segundo atributo (sem repetir o primeiro)
    mostrarMenu(opcao1);
    scanf("%d", &opcao2);

    // Valores de cada atributo
    float valor1c1 = compararAtributo(opcao1, carta1);
    float valor1c2 = compararAtributo(opcao1, carta2);
    float valor2c1 = compararAtributo(opcao2, carta1);
    float valor2c2 = compararAtributo(opcao2, carta2);

    // Comparação individual usando regra especial para densidade
    printf("\n--- Comparação de Atributos ---\n");

    // Primeiro atributo
    printf("%s:\n", nomeAtributo(opcao1));
    printf("  %s: %.2f\n", carta1.nome, valor1c1);
    printf("  %s: %.2f\n", carta2.nome, valor1c2);
    int vencedor1 = (opcao1 == 5) ? // densidade é invertida
        (valor1c1 < valor1c2 ? 1 : (valor1c2 < valor1c1 ? 2 : 0)) :
        (valor1c1 > valor1c2 ? 1 : (valor1c2 > valor1c1 ? 2 : 0));
    printf("Vencedor: %s\n\n", vencedor1 == 1 ? carta1.nome : vencedor1 == 2 ? carta2.nome : "Empate");

    // Segundo atributo
    printf("%s:\n", nomeAtributo(opcao2));
    printf("  %s: %.2f\n", carta1.nome, valor2c1);
    printf("  %s: %.2f\n", carta2.nome, valor2c2);
    int vencedor2 = (opcao2 == 5) ? 
        (valor2c1 < valor2c2 ? 1 : (valor2c2 < valor2c1 ? 2 : 0)) :
        (valor2c1 > valor2c2 ? 1 : (valor2c2 > valor2c1 ? 2 : 0));
    printf("Vencedor: %s\n\n", vencedor2 == 1 ? carta1.nome : vencedor2 == 2 ? carta2.nome : "Empate");

    // Soma dos valores (densidade continua invertida na regra da rodada)
    float soma1 = (opcao1 == 5 ? -valor1c1 : valor1c1) + (opcao2 == 5 ? -valor2c1 : valor2c1);
    float soma2 = (opcao1 == 5 ? -valor1c2 : valor1c2) + (opcao2 == 5 ? -valor2c2 : valor2c2);

    printf("=== Resultado Final ===\n");
    printf("%s - Soma: %.2f\n", carta1.nome, soma1);
    printf("%s - Soma: %.2f\n", carta2.nome, soma2);

    if (soma1 > soma2) {
        printf("Vencedor da rodada: %s\n", carta1.nome);
    } else if (soma2 > soma1) {
        printf("Vencedor da rodada: %s\n", carta2.nome);
    } else {
        printf("Empate!\n");
    }

    return 0;
}

