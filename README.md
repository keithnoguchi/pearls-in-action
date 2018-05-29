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

As demonstrated in chapter 11, here is the comparison between three insertion sorts
[isort1], [isort2], and [isort3] implementations:

[isort1]: 0xb/isort1.c
[isort2]: 0xb/isort2.c
[isort3]: 0xb/isort3.c

```sh
air1$ make check | grep 131072
 16) test_isort1         : 131072 entries                      PASS:  5.488899sec
 32) test_isort2         : 131072 entries                      PASS:  5.450684sec
 48) test_isort3         : 131072 entries                      PASS:  2.280945sec
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
