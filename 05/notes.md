Chars and shorts get promoted to int when passed to printf.

A char can be declared as single character between apices (see, `man ascii`)

> Note: with `vi`, you can pass raw keystrokes by typing `ctrl-v` when using insert mode.

A string is just an array of chars. It must be terminated by a zero, the null terminator.

Declaring a length lesser than the bit space occupied will cause an error. This won't happen instead if the length is greater than real space.

`sizeof` is executed at compile time.

Omitting the null terminator can cause UB printing gibberish chars.

---

References:

- [ascii(7)](https://www.man7.org/linux/man-pages/man7/ascii.7.html)

