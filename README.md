# Programming Pearls in Action

[![Build Status]](https://travis-ci.org/keinohguchi/pearls-in-action)

The amazing book, [Programming Pearls] by [John Bentley], in Action!

[Programming Pearls]: https://dl.acm.org/citation.cfm?id=318199
[John Bentley]: https://dl.acm.org/author_page.cfm?id=81100143310
[Build Status]: https://travis-ci.org/keinohguchi/pearls-in-action.svg

## make check

### C

```sh
air1$ make check | tail -10
117) test_bsearch_recursive_with_try_1024    : first entry                   PASS
118) test_bsearch_recursive_with_try_1024    : last entry                    PASS
119) test_bsearch_recursive_with_try_1024    : middle entry                  PASS
120) test_bsearch_recursive_with_try_1024    : no entry                      PASS
121) test_bsearch_recursive_with_try_1024    : first entry                   PASS
122) test_bsearch_recursive_with_try_1024    : last entry                    PASS
123) test_bsearch_recursive_with_try_1024    : middle entry                  PASS
124) test_bsearch_recursive_with_try_1024    : no entry                      PASS

make[1]: Leaving directory '/home/kei/git/pearls/0x4'
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
