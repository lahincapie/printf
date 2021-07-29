# 0x11. C - printf
#### Low-level programming & Algorithm

This project simulates the behavior of the printf function of the c language, to print strings of characters and the formats corresponding to %c, %d, %s and %i.

To clone the repository use:
`$ git clone git@github.com:lahincapie/printf.git`

You can compile the code using:
`$ gcc -Wall -Wextra -Werror -pedantic -std=gnu89 -Wno-format *.c`

Use `./a-out` to run the code.

You will get output similar to the following.

```sh
Let`'`s try to printf a simple sentence.
Let`'`s try to printf a simple sentence.
Length:[39, 39]
Length:[39, 39]
Negative:[-762534]
Negative:[-762534]
Unsigned:[%u]
Unsigned:[2147484671]
Unsigned octal:[%o]
Unsigned octal:[20000001777]
Unsigned hexadecimal:[%x, %X]
Unsigned hexadecimal:[800003ff, 800003FF]
Character:[H]
Character:[H]
String:[I am a string !]
String:[I am a string !]
Address:[%p]
Address:[0x7ffe637541f0]
Percent:[%]
Percent:[%]
Len:[12]
Len:[12]
Unknown:[%r]
Unknown:[r]
```

### Analysis


In the analysis of the problem, the following diagrams were proposed as a starting point to implement the code.

![_printf function](https://live.staticflickr.com/65535/51343072298_675213a106_b.jpg)


The _printf function looks for the special character% within the parameters sent from the main function, to determine the sharing of the program.

-------------

![print_string](https://live.staticflickr.com/65535/51343072303_1212872891_z.jpg)

The print_string function loops through the argument and prints a text string.

-------------

![](https://live.staticflickr.com/65535/51343072273_16ab5ae32d_z.jpg)

The count characters function counts the digits of a number.

-------------

![](https://live.staticflickr.com/65535/51343865615_bc55cf6ae7_z.jpg)

The print_integer function prints the digits of a number.

-------------

![](https://i.blogs.es/389033/programming/1366_2000.jpg)
