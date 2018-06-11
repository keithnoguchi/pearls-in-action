# Programming Pearls in Action

[![CircleCI]](https://circleci.com/gh/keinohguchi/pearls-in-action)
[![TravisCI]](https://travis-ci.org/keinohguchi/pearls-in-action)

The amazing book, [Programming Pearls] by [John Bentley], in Action!

[CircleCI]: https://circleci.com/gh/keinohguchi/pearls-in-action.svg?style=svg
[TravisCI]: https://travis-ci.org/keinohguchi/pearls-in-action.svg
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
result with each implementations, as shown in [isort1.c], [isort2.c], [isort3.c],
[qsort1.c], [qsort2.c], [qsort3.c], [qsort4.c], [qsort5.c], and [qsort6.c] files:

[isort1.c]: 0xb/isort1.c
[isort2.c]: 0xb/isort2.c
[isort3.c]: 0xb/isort3.c
[qsort1.c]: 0xb/qsort1.c
[qsort2.c]: 0xb/qsort2.c
[qsort3.c]: 0xb/qsort3.c
[qsort4.c]: 0xb/qsort4.c
[qsort5.c]: 0xb/qsort5.c
[qsort6.c]: 0xb/qsort6.c

```sh
air1$ make check | grep 131072
 16) test_isort1_random   : 131072 entries                     PASS:  5.486252sec
 32) test_isort2_random   : 131072 entries                     PASS:  5.498509sec
 48) test_isort3_random   : 131072 entries                     PASS:  1.634501sec
 64) test_qsort1_random   : 131072 entries                     PASS:  0.008562sec
 80) test_qsort2_random   : 131072 entries                     PASS:  0.008136sec
 96) test_qsort3_random   : 131072 entries                     PASS:  0.010013sec
112) test_qsort4_random   : 131072 entries                     PASS:  0.008440sec
128) test_qsort5_random   : 131072 entries                     PASS:  0.008196sec
144) test_qsort6_random   : 131072 entries                     PASS:  0.009576sec
160) test_isort1_identical: 131072 entries                     PASS:  0.000097sec
176) test_isort2_identical: 131072 entries                     PASS:  0.000083sec
192) test_isort3_identical: 131072 entries                     PASS:  0.000096sec
208) test_qsort1_identical: 131072 entries                     PASS:  5.470704sec
224) test_qsort2_identical: 131072 entries                     PASS:  5.494373sec
240) test_qsort3_identical: 131072 entries                     PASS:  5.521532sec
256) test_qsort4_identical: 131072 entries                     PASS:  0.002322sec
272) test_qsort5_identical: 131072 entries                     PASS:  0.002076sec
288) test_qsort6_identical: 131072 entries                     PASS:  0.002898sec
304) test_isort1_sorted   : 131072 entries                     PASS:  0.000096sec
320) test_isort2_sorted   : 131072 entries                     PASS:  0.000107sec
336) test_isort3_sorted   : 131072 entries                     PASS:  0.000097sec
352) test_qsort1_sorted   : 131072 entries                     PASS:  5.512172sec
368) test_qsort2_sorted   : 131072 entries                     PASS:  5.492300sec
384) test_qsort3_sorted   : 131072 entries                     PASS:  0.005503sec
400) test_qsort4_sorted   : 131072 entries                     PASS:  4.850455sec
416) test_qsort5_sorted   : 131072 entries                     PASS:  4.785482sec
432) test_qsort6_sorted   : 131072 entries                     PASS:  0.004705sec
air1$
```

This give us [qsort6.c], better quick sort with the randomized pivot selector,
better run time execution in overall cases, random, identical, and sorted arrays.

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
