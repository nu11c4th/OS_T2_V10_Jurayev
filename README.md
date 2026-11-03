<div align="center">

# OPERATSION TIZIMLAR FANIDAN AMALIY TOPSHIRIQ

## 2-topshiriq

**Mavzu:** C dasturlash tilida xotira manzillarini boshqarish.
Pointerlar, `malloc()` va `free()` funksiyalaridan foydalanish.

</div>

---

| | |
|---|---|
| **Bajardi** | 316-24-guruh talabasi Jo'rayev Sardorbek |
| **Variant** | 10 |
| **Fan** | Operatsion tizimlar |
| **Til va muhit** | C (gcc), Linux |
| **Repozitoriy** | [github.com/nu11c4th/OS_T2_V10_Jurayev](https://github.com/nu11c4th/OS_T2_V10_Jurayev) |

---

## Umumiy talablar

- Har bir `malloc` natijasi `NULL` ga tekshiriladi.
- Ajratilgan xotira `free()` bilan qaytariladi.
- `valgrind --leak-check=full` da xotira oqishi bo'lmasligi kerak.

## Repozitoriy tarkibi

```
OS_T2_V10_Jurayev/
├── README.md
├── task1.c
├── task2.c
├── task3.c
└── screenshots/
    ├── task1.png
    ├── task2.png
    └── task3.png
```

---

## 1-masala. Takrorlanmas elementlar soni

**Fayl:** [`task1.c`](task1.c)

**Shart:** `n = 19` ta butun sonli massiv `malloc` yordamida ajratiladi va `[-50; 50]` oraliqdagi tasodifiy sonlar bilan to'ldirilib, ekranga chiqariladi. Elementlarga faqat pointer arifmetikasi (`*(p+i)`) orqali murojaat qilinadi, `p[i]` yozuvi ishlatilmaydi.

**Vazifa:** takrorlanmas elementlar sonini topish. Massivda aynan 1 marta uchragan element takrorlanmas hisoblanadi.

**Yechim:** har bir element uchun massiv boshidan oxirigacha o'tilib, shu qiymat necha marta uchrashi sanaladi. Hisob 1 ga teng bo'lsa, element takrorlanmas deb olinadi.

![task1 natijasi](screenshots/task1.png)

---

## 2-masala. Eng ko'p uchragan belgi

**Fayl:** [`task2.c`](task2.c)

**Shart:** foydalanuvchi kiritgan satr dinamik xotirada saqlanadi (`fgets` + `realloc`). Vazifa alohida funksiyada, faqat pointerlar yordamida va `string.h` dagi tayyor funksiyalarsiz bajariladi.

**Vazifa:** satrdagi eng ko'p uchragan belgini va uning sonini topish.

**Yechim:** `eng_kop_belgi()` funksiyasi satrning har bir belgisi uchun satrni boshidan oxirigacha o'qib, shu belgi necha marta uchrashini sanaydi va eng katta natijani saqlaydi. Satr uzun bo'lib, joy yetmasa, xotira `realloc` bilan 2 barobar kattalashtiriladi.

![task2 natijasi](screenshots/task2.png)

---

## 3-masala. Matritsa perimetri yig'indisi

**Fayl:** [`task3.c`](task3.c)

**Shart:** `5×6` o'lchamli `int **` matritsa `malloc` bilan yaratiladi, to'ldiriladi va chiqariladi. Oxirida avval har bir satr, so'ng satrlar massivi `free` qilinadi.

**Vazifa:** chegara (perimetr) elementlari yig'indisini topish.

**Yechim:** birinchi va oxirgi satr hamda birinchi va oxirgi ustundagi elementlar yig'indisi hisoblanadi, ichki elementlar hisobga olinmaydi.

![task3 natijasi](screenshots/task3.png)

---

## Kompilyatsiya va ishga tushirish

```bash
gcc -Wall -Wextra -g task1.c -o task1
./task1

gcc -Wall -Wextra -g task2.c -o task2
./task2

gcc -Wall -Wextra -g task3.c -o task3
./task3
```

## Xotira oqishini tekshirish

```bash
valgrind --leak-check=full ./task1
valgrind --leak-check=full ./task2
valgrind --leak-check=full ./task3
```

## Natijalar

| Dastur | Kompilyatsiya | Valgrind natijasi |
|--------|---------------|-------------------|
| `task1` | xatosiz | `All heap blocks were freed -- no leaks are possible`, 0 errors |
| `task2` | xatosiz | `All heap blocks were freed -- no leaks are possible`, 0 errors |
| `task3` | xatosiz | `All heap blocks were freed -- no leaks are possible`, 0 errors |
