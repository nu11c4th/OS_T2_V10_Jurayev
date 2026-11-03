#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define QATOR 5
#define USTUN 6

int main(void) {
    /* Avval satrlar uchun pointerlar massivi */
    int **m = malloc(QATOR * sizeof(int *));
    if (m == NULL) {
        printf("Xotira ajratilmadi\n");
        return 1;
    }

    /* Keyin har bir satr uchun alohida xotira */
    for (int i = 0; i < QATOR; i++) {
        *(m + i) = malloc(USTUN * sizeof(int));
        if (*(m + i) == NULL) {
            printf("Xotira ajratilmadi\n");
            return 1;
        }
    }

    /* To'ldiramiz va chiqaramiz */
    srand(time(NULL));
    for (int i = 0; i < QATOR; i++) {
        for (int j = 0; j < USTUN; j++) {
            *(*(m + i) + j) = rand() % 101 - 50;
            printf("%4d", *(*(m + i) + j));
        }
        printf("\n");
    }

    /* Perimetr: birinchi/oxirgi satr va birinchi/oxirgi ustun */
    int yigindi = 0;
    for (int i = 0; i < QATOR; i++) {
        for (int j = 0; j < USTUN; j++) {
            if (i == 0 || i == QATOR - 1 || j == 0 || j == USTUN - 1) {
                yigindi += *(*(m + i) + j);
            }
        }
    }
    printf("Perimetr elementlari yig'indisi: %d\n", yigindi);

    /* Avval har bir satrni, keyin satrlar massivini free qilamiz */
    for (int i = 0; i < QATOR; i++) {
        free(*(m + i));
    }
    free(m);
    return 0;
}
