C numeric types are not consisent across different architecture. The C language was conceived to be portable to virtually all the systems available in the '60 and the specifications does not dictate how many bits a given type uses (and so the range of values it can assume).

The size of a type can be tested with `sizeof`.

Although a common standard on numeric types does not exist, values for 64-bits processor are quite stable.

Numeric types are useful for performing pointer arithmretic.

`stdint.h` allows to define the size of a specific type. `intptr_t` can be used to store a memory address. Note that this type has a sign, since we could perform a subtraction between memoty addresses.

An array of `char` represents a string.

A 64-bit cannot overflow for most apps, since it can represent  2^64/(1000000 * 3600 * 24 * 365) = 584 years.

ANSI escape codes alter the terminal as other programs do, see the following section to understand how to capture the codes to clear the page:
```bash
clear | hexdump -C
00000000  1b 5b 48 1b 5b 32 4a 1b  5b 33 4a                 |.[H.[2J.[3J|
0000000b
```

`\033` in octale or `\1b` in hexadecimal marks the beginning of a ANSI escape code: type `man ascii` to consult an ascii table.

The `printf` func is optimized to delay the flush to disk by keeping objects in memory.

Indentation is not crucial for a C program.

---

References:
- [Want to create a TUI application? - The Basics of "Uncooked" Terminal IO](https://zig.news/lhp/want-to-create-a-tui-application-the-basics-of-uncooked-terminal-io-17gm)
