# Lesson 2

The hello-world program introduced in the previous lesson shows how C enforces the type expression in each declaration.

The `gcc` options `-Wextra` (which superseds `-W`) and `-Wall` enables a number of warning flags that can be helpful to spot different cases of improper use of the C language.

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

This kind of bugs are particularly nasty since the `gcc` compiler will nonetheless compile the program into a runnable binary that could cause undefined behaviour:
```
$ ./a.out 
Hello World 30 10
```

The second unwanted value may change across different builds and it could even make the program to crash. 

> note: modern compilers (e.g. `go` compiler) does not allow you to incur in such errors.

The lifetime of a local variable is bound to the function's scope which it was declared into. Accessing to such a variable through a pointer outside the function scope will result in an error.

In C there is no garbage collector: to have a good mental model of how memory is managed in C, it can be helpful to understand what happens inside a microprocessor. Indeed local variables can be better understood when interpreted as the values stored in the 'registries', small memory areas manipulated by the processor with a special set of instructions that can be way more quick than main memory. 

This can be seen in action in the following assembly program written for the [6502](https://en.wikipedia.org/wiki/MOS_Technology_6502) that can be run on the [Easy 6502](https://skilldrick.github.io/easy6502/) booksite:
```assembly
START:              ; entrypoint
  LDA #50           ; load 50 in registry A
  JSR FILL_FIVE     ; jump to func FILL_FIVE
  BRK               ; break

FILL_FIVE:          
  TAX               ; move value in A to X
  BEQ DONE          ; if the value is equal to 0, exit
  LDY #$00          ; load 0 into Y
  LDA #$05          ; load 5 into A
LOOP:
  STA $0200,Y       ; store the value in A at the position 200 (hex) + Y (offset) 
  INY               ; increment Y, which is the cursor offset
  DEX               ; decrease X, wich is the loop index
  BNE LOOP          ; if not 0 continue with loop
DONE:
  RTS               ; otherwise, exit
```

The program prints 50 green pixels in the display, one after the other, since it is memory-mapped.

Note as the value in A is overridden in this small program, but only after moving it to another registry.

Similarly, in C the variables are stored in the stack when passing from a function's to scope to another func's scope, to be then restored when going back to the former.

A stack is a piece of computer memory organized in small chuncks when variables get stored. The stack pointer (SP) keeps a reference to the last inserted or removed variable with the push and pop instructions. 
The base pointer (BP) points to the base of a stack frame during function calls, instead.
The program counter (PC) registers keeps track of the execution path so that when `ret` is used the program is able to get back to the previous function call.

This can be seen with the following program:
```c
#include <stdio.h>

int sum(int a,int b ) {
    return a+b;
}

int main(void) {
	return sum(10,20);
}
```

assembled for the [i386](https://en.wikipedia.org/wiki/I386) processor on [Compiler Explorer](https://godbolt.org/) by selecting the compiler `x86 msvc v19.14 (WINE)`:
```assembly
_a$ = 8                                       ; size = 4 ; constant for the stack offset of the 'a' func arg
_b$ = 12                                                ; size = 4 ; constant for the stack offset of the 'b' func arg
int sum(int,int) PROC                                  ; sum
        push    ebp
        mov     ebp, esp
        mov     eax, DWORD PTR _a$[ebp]
        add     eax, DWORD PTR _b$[ebp]
        pop     ebp
        ret     0
int sum(int,int) ENDP                                  ; sum

_main   PROC
        push    ebp
        mov     ebp, esp
        push    20                                  ; 00000014H
        push    10                                  ; 0000000aH
        call    int sum(int,int)                     ; sum
        add     esp, 8
        pop     ebp
        ret     0
_main   ENDP
```

By looking at the assembly code we can infer the stack state before it unfolds as follows:
```asciiflow
+------------------+
|                  |
|                  |
|       EBP        |    0
|                  |
+------------------+
|                  |
|                  |
|       PC         |    4   (this is to return to line 18)
|                  |
+------------------+
|                  |
|                  |
|       10         |    8
|                  |
+------------------+
|                  |
|                  |
|       20         |    12
|                  |
+------------------+
|                  |
|                  |
|       EBP        |    16
|                  |
+------------------+
```

C has no real ABI, but rather a set of calling convenctions that most C compilers tend to respect.

The return value of the `main` function is the exit code of the program:
- `0` means a succesful execution of the program
- while any other codes mean a specific error (but most of the times only `1` is used in case of a failed execution).

This is useful in scripting where exit codes are used in boolean conditions to short circuit a long expression (e.g. in `./a.out && ls`, the second command won't be executed if the former fails).


> side note: in bash, zsh and other shells, `!<cmd>` re-executes the last occurence of the command in shell history, while `!!` re-executes the very last command in shell history (useful if you just forgot to prefix it with `sudo` since you can now do `sudo !!`). 


---

References:

- [Lesson 2](https://www.youtube.com/watch?v=Z84vlG1RRtg)
- [Appendix to Lesson 2](https://www.youtube.com/watch?v=r6mU_IHXEps&t=138s)
- [Reading C type declarations](http://www.unixwiz.net/techtips/reading-cdecl.html)
- [Warning Options](https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html)
- [Bare metal printf - C standard library without OS](https://popovicu.com/posts/bare-metal-printf/)