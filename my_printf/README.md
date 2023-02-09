# Welcome to My Printf
***

## Task
this function produces output according to a format as described below. The my_printf() functions write output to stdout, the standard output stream;

This function writes the output under the control of a format string that specifies how subsequent arguments (or arguments accessed via the variable-length argument facilities of stdarg(3)) are converted for output.

The format string is composed of zero or more directives: ordinary characters (not PERCENT), which are copied unchanged to the output stream; and conversion specifications, each of which results in fetching zero or more subsequent arguments.

Each conversion specification is introduced by the PERCENT character. The arguments must correspond properly (after type promotion) with the conversion specifier. After the PERCENT, the following appear in sequence:

doux The int (or appropriate variant) argument is converted to signed decimal (d). unsigned octal (o), unsigned decimal (u), unsigned hexadecimal (x).
c The int argument is converted to an unsigned char, and the resulting character is written.
s The char * argument is expected to be a pointer to an array of character type (pointer to a string). Characters from the array are written up to (but not including) a terminating NUL character.
p The void * pointer argument is printed in hexadecimal.
## Description
I had to learn a lot of new things to build the printf function. 
That is, I learned about variadic functions, argument lists, va_list , va_args, hexadecimal, octal, number systems, and unsigned 
I had to learn more about decimal, void * pointer arguments, etc.
I declared my_printf function and called this function int main and when I call it,
I put arguments into it and its p1 is a string, variadic function is such a function because through it we can use variable number of arguments and it gives flexibility to our program.
And also this task deepened my knowledge about printf.

## Installation
I did not use any Installation in this project  

## Usage
I made Makefile to use my programm and to check I write make and  my_printf 
 to terminal then my project will start

### The Core Team


<span><i>Made at <a href='https://qwasar.io'>Qwasar Silicon Valley</a></i></span>
<span><img alt='Qwasar Silicon Valley Logo' src='https://storage.googleapis.com/qwasar-public/qwasar-logo_50x50.png' width='20px'></span>
