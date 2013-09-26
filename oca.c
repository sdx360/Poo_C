#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
int players[2];
char accion[25];
int aux = 0, inicial = 0;

void imprimir_tablero(int player) {

    int x, cont = 0;
    char pos[3];


    do {
        for (x = 1 + cont; x <= 12 + cont; x++) {

            if (players[0] == x && players[1] == x) {
                strcpy(pos, "#%");

            } else if (players[1] > 0 && players[1] == x) {
                strcpy(pos, "%");
            } else if (players[0] == x) {
                strcpy(pos, "#");
            } else {
                itoa(x, pos, 10);
            }

            if (x == 7 || x == 11 || x == 15) {
                printf("\t+[%s%s", pos, "]");

            } else if (x == 13 || x == 20) {
                printf("\t-[%s%s", pos, "]");
            } else if (x == 23) {
                printf("\t![%s%s", pos, "]");
            } else if (x == 24) {
                printf("\t<%s%s", pos, ">");
            } else {
                printf("\t[%s%s", pos, "]");
            }

        }
        printf("\n");
        cont += 12;
    } while (cont <= 12);
    return 0;
}

int lanzar_dado(int player) {

    short D1, D2;
    D1 = rand() % 6 + 1;
    D2 = rand() % 6 + 1;
    printf("\n%d\t%d\n", D1, D2);
    inicial = players[player];
    players[player] += D1 + D2;
    if (players[player] > 24) {

        int temp = 24 - (players[player] - 24);
        aux = temp;
    } else {
        aux = players[player];
    }


    return D1 + D2;

}

int comprobar(int dado, int player) {
    int temp = 0;
    if (players[player] == 7 || players[player] == 11 || players[player] == 15) {

        players[player] += dado;
        strcpy(accion, "AVANZAR ");
        if (players[player] == 13 || players[player] == 20) {
            temp = dado;
        } else {
            temp = dado * 2;
        }

        if (players[player] > 24) {

            players[player] = 24 - (players[player] - 24);
            temp = 24 - players[player];
            strcpy(accion, "RETOCERDER POR EXCESO ");

        }
        printf("\n\n\tEl resultado de los dados: %d%s%s%d%s%d%s", dado, "\tAccion: ", accion, temp, "\tCasilla Actual: ", players[player], "\n\n");
        imprimir_tablero(1);
        if (players[player] == 13 || players[player] == 20 || players[player] == 7 || players[player] == 11 || players[player] == 15 || players[player] == 23) {
            if (aux == players[player]) {
                printf("\n\n\tCaso Especial bucle. Se volvera a lanzar dados: \n");
                players[player] = inicial;
                return 2;
            }
            return 0;
        } else {
            return 1;
        }

    } else if (players[player] == 13 || players[player] == 20) {

        players[player] -= dado;
        strcpy(accion, "RETOCERDER ");
        printf("\n\n\tEl resultado de los dados: %d%s%s%d%s%d%s", dado, "\tAccion: ", accion, dado, "\tCasilla Actual: ", players[player], "\n\n");
        imprimir_tablero(1);
        if (players[player] == 13 || players[player] == 20 || players[player] == 7 || players[player] == 11 || players[player] == 15 || players[player] == 23) {
            if (aux == players[player]) {
                printf("\n\n\tCaso Especial bucle. Se volvera a lanzar dados: \n");
                players[player] = inicial;
                return 2;
            }
            return 0;
        } else {
            return 1;
        }

    } else if (players[player] == 23) {
        players[player] = 1;
        strcpy(accion, "REGRESAR AL PRINCIPIO ");
        printf("\n\n\tEl resultado de los dados: %d%s%s%s%d%s", dado, "\tAccion: ", accion, "\tCasilla Actual: ", players[player], "\n\n");
        imprimir_tablero(1);
        return 1;
    } else {

        strcpy(accion, "AVANZAR ");
        if (players[player] > 24) {
            players[player] = 24 - (players[player] - 24);
            strcpy(accion, "RETOCERDER POR EXCESO ");
            printf("\n\n\tEl resultado de los dados: %d%s%s%d%s%d%s", dado, "\tAccion: ", accion, 24 - players[player], "\tCasilla Actual: ", players[player], "\n\n");
            imprimir_tablero(1);
            if (players[player] == 13 || players[player] == 20 || players[player] == 7 || players[player] == 11 || players[player] == 15 || players[player] == 23) {

                return 0;
            }
        } else {
            printf("\n\n\tEl resultado de los dados: %d%s%s%d%s%d%s", dado, "\tAccion: ", accion, dado, "\tCasilla Actual: ", players[player], "\n\n");
            imprimir_tablero(1);
        }
        return 1;
    }
}

int main() {
    int opc = 0, flag = 0, flag2 = 0, flag3 = 0, dado = 0, y = 0;

    srand(time(NULL));
    system("cls");

    do {
        flag = 0;
        flag2 = 0;
        flag3 = 0;
        printf("Elegir numero de jugador [1-2]!-------------Presione 0 para salir\n");
        scanf("%i", &opc);
        while (getchar() != '\n');
        if (opc == 2) {
            players[1] = 1;
        }
        players[0] = 1;
        if (opc == 1 || opc == 2) {
            imprimir_tablero(opc);
            do {

                for (y = 0; y < opc; y++) {
                    char tecla = 'a';
                    printf("\n\n\nTurno de jugador %d%s%i%s", y + 1, " Casilla actual ", players[y], "  ... Presione <Enter> para continuar");
                    scanf("%c", &tecla);
                    flag3 = 1;
                    dado = lanzar_dado(y);
                    do {
                        flag3 = comprobar(dado, y);
                        if (flag3 == 2) {
                            dado = lanzar_dado(y);
                        }
                        if (players[y] == 24) {


                            printf("\n\n\n-----------------------Game Over Jugador %d%s", y + 1, " Gana-----------------------------\n\n\n");
                            flag2 = 1;
                            flag3 = 1;
                            y = 2;
                            aux = 0;
                            inicial = 0;

                        }

                    } while (flag3 != 1);

                }


            } while (flag2 != 1);


        } else if (opc == 0) {
            flag = 1;
        } else {
            printf("Opcion invalida\n\n///////////////////////////////////////////////////////////////////////\n\n");
        }

    } while (flag != 1);

    return 0;
}
