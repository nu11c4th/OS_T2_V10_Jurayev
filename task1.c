#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 19

int main(void) {
    /* N ta butun son uchun xotira ajratamiz */
    int *p = malloc(N * sizeof(int));
    if (p == NULL) {
        printf("Xotira ajratilmadi\n");
        return 1;
    }

    /* [-50; 50] oraliqdagi tasodifiy sonlar bilan to'ldiramiz */
    srand(time(NULL));
    for (int i = 0; i < N; i++) {
        *(p + i) = rand() % 101 - 50;
        printf("%d ", *(p + i));
    }
    printf("\n");

    /* Takrorlanmas element - massivda faqat 1 marta uchragan element */
    int soni = 0;
    for (int i = 0; i < N; i++) {
        int uchradi = 0;
        for (int j = 0; j < N; j++) {
            if (*(p + j) == *(p + i)) {
                uchradi++;
            }
        }
        if (uchradi == 1) {
            soni++;
        }
    }
    printf("Takrorlanmas elementlar soni: %d\n", soni);

    free(p);
    return 0;
}
