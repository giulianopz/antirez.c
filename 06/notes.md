# Lesson 6

Curly braces are not necessary for single statements.

Curly braces denote a 'block'. Blocks can exist also outside a control statement like 'if'.

Variables declares in a block are bound to the block's scope.

Iteration can be implemented using:
- goto
- while
- recursion.

Nesting calls with recursion can waste too much memory:
```bash
:~$ gcc -Wall -W -O2 loop.c && ./a.out
0x7ffdb4d6fe4c 0x7ffdb4d6fe48
0
0x7ffdb4d6fe2c 0x7ffdb4d6fe28
1
0x7ffdb4d6fe0c 0x7ffdb4d6fe08
2
0x7ffdb4d6fdec 0x7ffdb4d6fde8
3
0x7ffdb4d6fdcc 0x7ffdb4d6fdc8
4
0x7ffdb4d6fdac 0x7ffdb4d6fda8
5
0x7ffdb4d6fd8c 0x7ffdb4d6fd88
6
0x7ffdb4d6fd6c 0x7ffdb4d6fd68
7
0x7ffdb4d6fd4c 0x7ffdb4d6fd48
8
0x7ffdb4d6fd2c 0x7ffdb4d6fd28
9
0x7ffdb4d6fd0c 0x7ffdb4d6fd08
:~$ bc
bc 1.07.1
ibase=16
# FD08 are the last two hexadecimal number of 'end' at the end of the recursion
# FE48 the last two hexadecimal number of 'end' at beginning of the recursion
FE48-FD08
320
# 320 bytes
```

This is similar to what functional programming does.

---

References:

- [Lesson 6](https://www.youtube.com/watch?v=lc7aYXNl1T8)
