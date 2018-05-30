# Programming Pearls in Action

[![Build Status]](https://travis-ci.org/keinohguchi/pearls-in-action)

The amazing book, [Programming Pearls] by [John Bentley], in Action!

[Build Status]: https://travis-ci.org/keinohguchi/pearls-in-action.svg
[Programming Pearls]: https://dl.acm.org/citation.cfm?id=318199
[John Bentley]: https://dl.acm.org/author_page.cfm?id=81100143310

## make check

### C

```sh
air1$ make check | tail -16
 46) test_find_first_flat     : single entry in the front                    PASS
 47) test_find_first_flat     : double entries in the front                  PASS
 48) test_find_first_flat     : triple entries in the front                  PASS
 49) test_find_first_flat     : quad entries in the front                    PASS
 50) test_find_first_flat     : five entries in the front                    PASS
 51) test_find_first_flat     : single entry in the back                     PASS
 52) test_find_first_flat     : double entries in the back                   PASS
 53) test_find_first_flat     : triple entries in the back                   PASS
 54) test_find_first_flat     : quad entries in the back                     PASS
 55) test_find_first_flat     : five entries in the back                     PASS
 56) test_find_first_flat     : single entry in the middle                   PASS
 57) test_find_first_flat     : double entries in the middle                 PASS
 58) test_find_first_flat     : triple entries in the middle                 PASS
 59) test_find_first_flat     : quad entries in the middle                   PASS
 60) test_find_first_flat     : five entries in the middle                   PASS
make[1]: Leaving directory '/home/kei/git/pearls/0x9'
air1$
```

To demonstrate the comparisons among multiple sorting
algorithms/implementations, `make check -C 0xb` will show the run time
of each implementations, as shown in [isort1.c], [isort2.c], [isort3.c],
[qsort1.c], [qsort2.c], and [qsort3.c] files:

[isort1.c]: 0xb/isort1.c
[isort2.c]: 0xb/isort2.c
[isort3.c]: 0xb/isort3.c
[qsort1.c]: 0xb/qsort1.c
[qsort2.c]: 0xb/qsort2.c
[qsort3.c]: 0xb/qsort3.c

```sh
air1$ make check | grep 131072
 16) test_isort1_random   : 131072 entries                     PASS:  5.441844sec
 32) test_isort2_random   : 131072 entries                     PASS:  5.482489sec
 48) test_isort3_random   : 131072 entries                     PASS:  1.738310sec
 64) test_qsort1_random   : 131072 entries                     PASS:  0.008484sec
 80) test_qsort2_random   : 131072 entries                     PASS:  0.008297sec
 96) test_qsort3_random   : 131072 entries                     PASS:  0.008470sec
112) test_isort1_identical: 131072 entries                     PASS:  0.000100sec
128) test_isort2_identical: 131072 entries                     PASS:  0.000083sec
144) test_isort3_identical: 131072 entries                     PASS:  0.000096sec
160) test_qsort1_identical: 131072 entries                     PASS:  5.483466sec
176) test_qsort2_identical: 131072 entries                     PASS:  5.448950sec
192) test_qsort3_identical: 131072 entries                     PASS:  0.002300sec
208) test_isort1_sorted   : 131072 entries                     PASS:  0.000119sec
224) test_isort2_sorted   : 131072 entries                     PASS:  0.000089sec
240) test_isort3_sorted   : 131072 entries                     PASS:  0.000096sec
256) test_qsort1_sorted   : 131072 entries                     PASS:  5.486417sec
272) test_qsort2_sorted   : 131072 entries                     PASS:  5.499130sec
288) test_qsort3_sorted   : 131072 entries                     PASS:  4.373180sec
air1$
```

### Go

```sh
air1$ make go-check | tail -10
=== RUN   TestBSearchIntWithTryOn1024/first_entry_out_of_1024_elements
=== RUN   TestBSearchIntWithTryOn1024/last_entry_out_of_1024_elements
=== RUN   TestBSearchIntWithTryOn1024/middle_entry_out_of_1024_elements
--- PASS: TestBSearchIntWithTryOn1024 (0.00s)
    --- PASS: TestBSearchIntWithTryOn1024/first_entry_out_of_1024_elements (0.00s)
    --- PASS: TestBSearchIntWithTryOn1024/last_entry_out_of_1024_elements (0.00s)
    --- PASS: TestBSearchIntWithTryOn1024/middle_entry_out_of_1024_elements (0.00s)
PASS
ok      _/home/kei/git/pearls/0x4/bsearch       0.001s
make[1]: Leaving directory '/home/kei/git/pearls/0x4'
air1$
```

Happy Hackin!
