#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura que representa uma sala (nó da árvore binária)
typedef struct Sala {
    char nome[50];
    struct Sala *esquerda;
    struct Sala *direita;
} Sala;

/**
 * Função: criarSala
 * ------------------
 * Cria dinamicamente uma nova sala, atribuindo um nome a ela.
 *
 * nome: string com o nome da sala
 *
 * retorna: ponteiro para a sala criada
 */
Sala* criarSala(const char *nome) {
    Sala *nova = (Sala*) malloc(sizeof(Sala));
    if (nova == NULL) {
        printf("Erro ao alocar memória!\n");
        exit(1);
    }
    strcpy(nova->nome, nome);
    nova->esquerda = NULL;
    nova->direita = NULL;
    return nova;
}

/**
 * Função: explorarSalas
 * ----------------------
 * Permite a navegação do jogador pela mansão a partir de uma sala.
 * O jogador escolhe 'e' (esquerda), 'd' (direita) ou 's' (sair).
 *
 * atual: ponteiro para a sala atual
 */
void explorarSalas(Sala *atual) {
    char escolha;

    while (atual != NULL) {
        printf("\nVocê está na %s.\n", atual->nome);

        // Verifica se é um nó-folha (não tem caminhos)
        if (atual->esquerda == NULL && atual->direita == NULL) {
            printf("Este cômodo não possui mais saídas. Fim da exploração!\n");
            break;
        }

        printf("Escolha um caminho: (e) esquerda, (d) direita, (s) sair: ");
        scanf(" %c", &escolha);

        if (escolha == 'e') {
            if (atual->esquerda != NULL) {
                atual = atual->esquerda;
            } else {
                printf("Não há caminho à esquerda!\n");
            }
        } else if (escolha == 'd') {
            if (atual->direita != NULL) {
                atual = atual->direita;
            } else {
                printf("Não há caminho à direita!\n");
            }
        } else if (escolha == 's') {
            printf("Você decidiu sair da exploração.\n");
            break;
        } else {
            printf("Opção inválida! Tente novamente.\n");
        }
    }
}

/**
 * Função: main
 * -------------
 * Monta manualmente o mapa da mansão como uma árvore binária
 * e inicia a exploração a partir do Hall de entrada.
 */
int main() {
    // Criando as salas
    Sala *hall = criarSala("Hall de Entrada");
    Sala *salaEstar = criarSala("Sala de Estar");
    Sala *cozinha = criarSala("Cozinha");
    Sala *biblioteca = criarSala("Biblioteca");
    Sala *jardim = criarSala("Jardim");
    Sala *porao = criarSala("Porão");
    Sala *quarto = criarSala("Quarto");

    // Montando a árvore da mansão
    hall->esquerda = salaEstar;
    hall->direita = cozinha;
    salaEstar->esquerda = biblioteca;
    salaEstar->direita = jardim;
    cozinha->esquerda = porao;
    cozinha->direita = quarto;

    // Iniciando a exploração a partir do Hall
    printf("Bem-vindo(a) à mansão misteriosa!\n");
    explorarSalas(hall);

    return 0;
}