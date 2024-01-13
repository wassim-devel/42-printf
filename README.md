# 42-printf

ft_printf project at 42 School.

This project, from the common core of 42 School, aims to be a minimal implementation of the printf function, that we can use in further projects at 42.
It is far from being a complete reimplementation of printf, the printf original function uses a buffer and have more possible parameters.

The Makefile produce a library that can be used in other projects

This function is written entirely in C, uses va_list to have variable arguments and uses write POSIX system call
Only some functions were authorized, (You can imagine that I can't use the printf function in a reimplementation of printf), you can find them in the subject: 
[Full subject](https://cdn.intra.42.fr/pdf/pdf/115728/en.subject.pdf)

Organization of files, readability of code and/or the names of functions and variables can seem awful, because of the 42 Norm that limits the length of a line to 80, number of functions in a file to 5, and number of lines in a function to 25.

