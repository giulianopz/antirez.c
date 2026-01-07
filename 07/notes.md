Tail-call optimization (TCO) helps to avoid allocating a new stack frame (into the call stack) because the calling function will simply return the value that it gets from the called function.
TCO allows procedure calls in tail position to be implemented as efficiently as goto statements.

Goto is not as much used as more common loop control statements: while, for, do-while, switch, etc...