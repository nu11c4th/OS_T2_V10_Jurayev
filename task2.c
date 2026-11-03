#include <stdio.h>
#include <stdlib.h>

/* Satrdagi eng ko'p uchragan belgini va uning sonini topadi */
void eng_kop_belgi(char *s, char *belgi, int *son) {
    *belgi = '\0';
    *son = 0;
    for (char *a = s; *a != '\0'; a++) {
        int hisob = 0;
        for (char *b = s; *b != '\0'; b++) {
            if (*b == *a) {
                hisob++;
            }
        }
        if (hisob > *son) {
            *son = hisob;
            *belgi = *a;
        }
    }
}

int main(void) {
    int sigim = 8;      /* hozirgi xotira hajmi */
    int uzunlik = 0;    /* satrning hozirgi uzunligi */
    char *satr = malloc(sigim);
    if (satr == NULL) {
        printf("Xotira ajratilmadi\n");
        return 1;
    }
    *satr = '\0';

    printf("Satr kiriting: ");
    while (1) {
        /* fgets qolgan joyga o'qiydi */
        if (fgets(satr + uzunlik, sigim - uzunlik, stdin) == NULL) {
            break;
        }
        /* o'qilgan qismning oxirigacha boramiz */
        while (*(satr + uzunlik) != '\0') {
            uzunlik++;
        }
        /* Enter bosilgan bo'lsa, o'qish tugadi */
        if (uzunlik > 0 && *(satr + uzunlik - 1) == '\n') {
            *(satr + uzunlik - 1) = '\0';
            break;
        }
        /* joy yetmagan bo'lsa, xotirani 2 barobar oshiramiz */
        if (uzunlik == sigim - 1) {
            sigim = sigim * 2;
            char *yangi = realloc(satr, sigim);
            if (yangi == NULL) {
                printf("Xotira ajratilmadi\n");
                free(satr);
                return 1;
            }
            satr = yangi;
        } else {
            break;
        }
    }

    char belgi;
    int son;
    eng_kop_belgi(satr, &belgi, &son);
    if (son == 0) {
        printf("Satr bo'sh\n");
    } else {
        printf("Eng ko'p uchragan belgi: '%c', soni: %d\n", belgi, son);
    }

    free(satr);
    return 0;
}
