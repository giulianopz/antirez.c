A global variable can be referenced (and manipulated) in the scope of any function.

A static variable can be referenced (and manipulated) **only** in the scope of the func it was declared to at each func call. As such, a static variable is not thread-safe and it should be protected by a mutex, for example.

C is a pass-by-value language, so result values must be returned or changed by means of pointers.

Passing a numeric data of the wrong type to `printf` will generate a warning, altough the compiler will not complain:
```
hello_world.c: In function ‘main’:
hello_world.c:16:17: warning: format ‘%d’ expects argument of type ‘int’, but argument 3 has type ‘double’ [-Wformat=]
   16 |     printf("%d %d\n",a,y);
      |                ~^      ~
      |                 |      |
      |                 int    double
      |                %f
10 -1073741824
```

From the warning, it is clear how C employs a promotion mechanism for data types.

Guarantess against overflow exist only for `unsigned integers`, for signed intergers there is still the possibility of having Undefined Behaviour (UB): it won't overflow but it will restart from 0 (`unsigned char c = 255; c++`).


---

References:
- [Onboarding floating-point](https://www.altdevarts.com/p/onboarding-floating-point)
- [Ascii Table](https://theasciicode.com.ar/)
