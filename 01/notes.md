# Lesson 1

The file [hello_world.c](./hello_world.c) is a traditional hello-world program.

> Fun Fact: it was indeed the [K&R book](https://en.wikipedia.org/wiki/The_C_Programming_Language) to establish this tradition in the programming community.

It can be compiled with `gcc` by simply running:
```bash
$ gcc hello_world.c
```

> Note: gcc and cland are the most used C compilers but many others exist in the wild: see [here](https://en.wikipedia.org/wiki/List_of_compilers#C_compilers).

By default, the compiler will generate a binary named `a.out`:
```bash
$ ./a.out 
Hello World
```

Use `-o` to change the name.

The `printf` function called in the program belongs to the C standard library (`libc`). It belongs to the `stdio` header included at first line of the file. The C preprocessor takes care of replacing the `include` directive with the content of the referenced header file.

> Note: glibc (GNU C Library) is the most used libc implementation. musl is a modern alternative. Many others exist, read [here](https://edu.chainguard.dev/chainguard/chainguard-images/about/images-compiled-programs/glibc-vs-musl/) for a comparison between glibc and musl.

Compiling with a higher level of optimization should replace `printf` with `puts` (but gcc on Linux use `puts` also when no flag is spexified), as can be seen from assembly code:
```bash
$ gcc -O2 -S hello_world.c
$ grep -P "(puts|printf)" hello_world.s
        call    puts@PLT
```

> Note: that `puts` removes the newline from the string constant since it inserts a newline itself by default.

If the prepocessor directive was substituded by the func signature (*prototype*), the program would run as before with no errors. The compiler is able to infer the func from the standard lib anyways.

To view the func docs, do as follows:
```bash
$ man 3 puts 
```

The preprocessor can even target other C files. You can verify it by using an include directive at the printf line to replace it with the content of another local file:
```c
#include <stdio.h>

int main(void) {
    #include <file.c>
	return 0;
}
```

Where the `file.c` simply contains:
```c
printf("Hello World\n");
```

Useful commands:
- `file` can determine file type (an [ELF](https://4zm.org/2024/12/25/a-simple-elf.html) binary in this case) beyond other info (e.g. satically/dynamically linked)
- `strip` removes debugging symbols and other metadata from the binary
- `hexdump` can be used to investigate what is inside a binary (more [here](https://opensource.com/article/19/8/dig-binary-files-hexdump)).

References:
- [Lesson 1](https://www.youtube.com/watch?v=HjXBXBgfKyk)