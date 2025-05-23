# Lesson 2

[[YT](https://www.youtube.com/watch?v=Z84vlG1RRtg)]

The discussion still dealt with the hello-world program introduced in the previous lesson. 

C enforces the type expression in each declaration.

The `gcc` options `-Wextra` (which superseds `-W`) and `-Wall` enables a number of warning flags that can ne helpful to spot different cases of improper use of the C language.

For example, they can detect common errors like the one in the modified hello-word [program](./hello_word_warn.c):
```bash
$ gcc -Wextra -Wall ./hello_word_warn.c 
./hello_word_warn.c: In function ‘main’:
./hello_word_warn.c:8:33: warning: format ‘%d’ expects a matching ‘int’ argument [-Wformat=]
    8 |         printf("Hello World %d %d\n", sum(10,20));
      |                                ~^
      |                                 |
      |                                 int
```

This kind of bugs are particularly nasty since the `gcc` compiler will nonetheless compile the program into a runnable binary that could caused undefined behaviour:
```
$ ./a.out 
Hello World 30 10
```

The second unwanted value may change across different builds and it could even make the program to crash. 

> note: modern compilers (e.g. `go` compiler) does not allow you to incur in such errors.

The lifetime of a local variable is bound to the function's scope which it was declared into. Accessing to such a variable through a pointer outside the function scope will result in an error.

The return value of the `main` function is the exit code of the program:
- `0` means a succesful execution of the program
- while any other codes mean a specific error (but most of the times only `1` is used in case of a failed execution).

This is useful in scripting where exit codes are used in boolean conditions to short circuit a long expression (e.g. in `./a.out && ls`, the second command won't be executed if the former fails).


> side note: in bash, zsh and other shells, `!<cmd>` re-executes the last occurence of the command in shell history, while `!!` re-executes the very last command in shell history (useful if you just forgot to prefix it with `sudo` since you can now do `sudo !!`). 


---

References:

- [Reading C type declarations](http://www.unixwiz.net/techtips/reading-cdecl.html)
- [Warning Options](https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html)
- [Bare metal printf - C standard library without OS](https://popovicu.com/posts/bare-metal-printf/)