#include <stdio.h>

#define TAMANHO 10
#define AGUA 0
#define NAVIO 3
#define AREA_EFEITO 5
#define TAMANHO_HABILIDADE 5

int main() {
    int tabuleiro[TAMANHO][TAMANHO] = {0};
    int matrizCone[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE] = {0};
    int matrizCruz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE] = {0};
    int matrizOctaedro[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE] = {0};
    
    int pontoOrigemLinhaC = 2;
    int pontoOrigemColunaC = 4;
    
    int pontoOrigemLinhaCr = 5;
    int pontoOrigemColunaCr = 5;
    
    int pontoOrigemLinhaO = 7;
    int pontoOrigemColunaO = 7;
    
    tabuleiro[1][3] = NAVIO;
    tabuleiro[1][4] = NAVIO;
    tabuleiro[2][2] = NAVIO;
    tabuleiro[2][3] = NAVIO;
    tabuleiro[2][4] = NAVIO;
    tabuleiro[2][5] = NAVIO;
    tabuleiro[3][1] = NAVIO;
    tabuleiro[3][2] = NAVIO;
    tabuleiro[3][3] = NAVIO;
    tabuleiro[3][4] = NAVIO;
    tabuleiro[3][5] = NAVIO;
    
    tabuleiro[5][3] = NAVIO;
    tabuleiro[5][4] = NAVIO;
    tabuleiro[5][5] = NAVIO;
    tabuleiro[5][6] = NAVIO;
    tabuleiro[5][7] = NAVIO;
    tabuleiro[4][5] = NAVIO;
    tabuleiro[6][5] = NAVIO;
    tabuleiro[3][5] = NAVIO;
    tabuleiro[7][5] = NAVIO;
    
    tabuleiro[7][7] = NAVIO;
    tabuleiro[6][6] = NAVIO;
    tabuleiro[6][7] = NAVIO;
    tabuleiro[6][8] = NAVIO;
    tabuleiro[7][6] = NAVIO;
    tabuleiro[7][8] = NAVIO;
    tabuleiro[8][6] = NAVIO;
    tabuleiro[8][7] = NAVIO;
    tabuleiro[8][8] = NAVIO;
    
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (i <= j && i + j >= TAMANHO_HABILIDADE - 1) {
                matrizCone[i][j] = 1;
            }
        }
    }
    
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (i == TAMANHO_HABILIDADE / 2 || j == TAMANHO_HABILIDADE / 2) {
                matrizCruz[i][j] = 1;
            }
        }
    }
    
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (i + j >= TAMANHO_HABILIDADE / 2 && 
                i + j <= TAMANHO_HABILIDADE + TAMANHO_HABILIDADE / 2 - 1 && 
                i <= j + TAMANHO_HABILIDADE / 2 && 
                j <= i + TAMANHO_HABILIDADE / 2) {
                matrizOctaedro[i][j] = 1;
            }
        }
    }
    
    int tabuleiroComHabilidadeCone[TAMANHO][TAMANHO];
    int tabuleiroComHabilidadeCruz[TAMANHO][TAMANHO];
    int tabuleiroComHabilidadeOctaedro[TAMANHO][TAMANHO];
    
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiroComHabilidadeCone[i][j] = tabuleiro[i][j];
            tabuleiroComHabilidadeCruz[i][j] = tabuleiro[i][j];
            tabuleiroComHabilidadeOctaedro[i][j] = tabuleiro[i][j];
        }
    }
    
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            int linhaTab = pontoOrigemLinhaC - TAMANHO_HABILIDADE / 2 + i;
            int colunaTab = pontoOrigemColunaC - TAMANHO_HABILIDADE / 2 + j;
            
            if (linhaTab >= 0 && linhaTab < TAMANHO && colunaTab >= 0 && colunaTab < TAMANHO) {
                if (matrizCone[i][j] == 1) {
                    if (tabuleiroComHabilidadeCone[linhaTab][colunaTab] != NAVIO) {
                        tabuleiroComHabilidadeCone[linhaTab][colunaTab] = AREA_EFEITO;
                    }
                }
            }
        }
    }
    
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            int linhaTab = pontoOrigemLinhaCr - TAMANHO_HABILIDADE / 2 + i;
            int colunaTab = pontoOrigemColunaCr - TAMANHO_HABILIDADE / 2 + j;
            
            if (linhaTab >= 0 && linhaTab < TAMANHO && colunaTab >= 0 && colunaTab < TAMANHO) {
                if (matrizCruz[i][j] == 1) {
                    if (tabuleiroComHabilidadeCruz[linhaTab][colunaTab] != NAVIO) {
                        tabuleiroComHabilidadeCruz[linhaTab][colunaTab] = AREA_EFEITO;
                    }
                }
            }
        }
    }
    
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            int linhaTab = pontoOrigemLinhaO - TAMANHO_HABILIDADE / 2 + i;
            int colunaTab = pontoOrigemColunaO - TAMANHO_HABILIDADE / 2 + j;
            
            if (linhaTab >= 0 && linhaTab < TAMANHO && colunaTab >= 0 && colunaTab < TAMANHO) {
                if (matrizOctaedro[i][j] == 1) {
                    if (tabuleiroComHabilidadeOctaedro[linhaTab][colunaTab] != NAVIO) {
                        tabuleiroComHabilidadeOctaedro[linhaTab][colunaTab] = AREA_EFEITO;
                    }
                }
            }
        }
    }
    
    printf("Tabuleiro com Habilidade de Cone:\n");
    printf("  ");
    for (int j = 0; j < TAMANHO; j++) {
        printf("%d ", j);
    }
    printf("\n");
    
    for (int i = 0; i < TAMANHO; i++) {
        printf("%d ", i);
        for (int j = 0; j < TAMANHO; j++) {
            if (tabuleiroComHabilidadeCone[i][j] == AGUA) {
                printf("~ ");
            } else if (tabuleiroComHabilidadeCone[i][j] == NAVIO) {
                printf("N ");
            } else if (tabuleiroComHabilidadeCone[i][j] == AREA_EFEITO) {
                printf("X ");
            }
        }
        printf("\n");
    }
    
    printf("\nTabuleiro com Habilidade de Cruz:\n");
    printf("  ");
    for (int j = 0; j < TAMANHO; j++) {
        printf("%d ", j);
    }
    printf("\n");
    
    for (int i = 0; i < TAMANHO; i++) {
        printf("%d ", i);
        for (int j = 0; j < TAMANHO; j++) {
            if (tabuleiroComHabilidadeCruz[i][j] == AGUA) {
                printf("~ ");
            } else if (tabuleiroComHabilidadeCruz[i][j] == NAVIO) {
                printf("N ");
            } else if (tabuleiroComHabilidadeCruz[i][j] == AREA_EFEITO) {
                printf("X ");
            }
        }
        printf("\n");
    }
    
    printf("\nTabuleiro com Habilidade de Octaedro:\n");
    printf("  ");
    for (int j = 0; j < TAMANHO; j++) {
        printf("%d ", j);
    }
    printf("\n");
    
    for (int i = 0; i < TAMANHO; i++) {
        printf("%d ", i);
        for (int j = 0; j < TAMANHO; j++) {
            if (tabuleiroComHabilidadeOctaedro[i][j] == AGUA) {
                printf("~ ");
            } else if (tabuleiroComHabilidadeOctaedro[i][j] == NAVIO) {
                printf("N ");
            } else if (tabuleiroComHabilidadeOctaedro[i][j] == AREA_EFEITO) {
                printf("X ");
            }
        }
        printf("\n");
    }
    
    printf("\nMatriz da Habilidade Cone:\n");
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            printf("%d ", matrizCone[i][j]);
        }
        printf("\n");
    }
    
    printf("\nMatriz da Habilidade Cruz:\n");
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            printf("%d ", matrizCruz[i][j]);
        }
        printf("\n");
    }
    
    printf("\nMatriz da Habilidade Octaedro:\n");
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            printf("%d ", matrizOctaedro[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}