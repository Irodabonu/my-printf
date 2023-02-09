#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdarg.h>
#include<unistd.h>
#include <assert.h>
#include <stdint.h>

int my_strlen(char* p2)
{
    int compute =0;
    while(p2[compute])
    {
        compute++;
    }
    return compute;
}

int my_put_char(char c)
{
    int calculate = 0;

    write(1, &c, 1);

    calculate++;
    return calculate;
}


int my_put_str(char* p1)
{
    int count1 =0;
    for(int i = 0; p1[i]!='\0';i++)
    {
       count1 += my_put_char(p1[i]);
    }
    return count1;
}

char* cha_maker(int some_value)
{
    char* place= (char*)malloc(1000*sizeof(char));
    int y =0;
     while(some_value!=0)
    {
        place[y]= some_value % 10 + '0';
        some_value= some_value / 10;
        y++;
    }
    char* reversed_char=(char*)malloc((y + 1)*sizeof(char));  
    int ind1 =0;
  
    for(int ind = my_strlen(place)-1; ind >=0; ind--)
    {
        reversed_char[ind1]=place[ind];
        ind1++;
    }
    return reversed_char;
}

int int_to_char(int number)
{
    char* newD=(char*)malloc(1000*sizeof(char));
    int y =0;
    int count2 =0;
    int neg = 0;
    if(number == 0)
    {
        count2= my_put_char('0');
        return count2;
    }
     if(number<=0)
     {
         number=number *(-1);
     }
    if(number <0)
    {
        number= number * (-1);
        neg = 1;

    }
    while(number!=0)
    {
        newD[y]= number % 10 + '0';
        number= number / 10;
        y++;
    }
    char* reversed_char=(char*)malloc((y + 1)*sizeof(char));  
    int ind1 =0;
    int a =0;

    for(int ind = my_strlen(newD)-1; ind >=0; ind--)
    {
        reversed_char[ind1]=newD[ind];
        ind1++;
    }

    if(neg == 1)
    {
        a=my_put_char('-');
    }
    a += my_put_str(reversed_char);
    return a;
}

int my_octal(int number)
{
    char* newD=(char*)malloc(1000*sizeof(char));
    int y =0;
    int count2 =0;
    int neg = 0;
    if(number == 0){
        count2= my_put_char('0');
        return count2;
    }
    if(number <0)
    {
        number= number * (-1);
        neg = 1;

    }
    while(number!=0)
    {
        newD[y]= number % 8 + '0';
        number= number / 8;
        y++;
    }
    char* reversed_oct=(char*)malloc((y + 1)*sizeof(char));  
    int ind1 =0;
    int a =0;

    for(int ind = my_strlen(newD)-1; ind >=0; ind--)
    {
        reversed_oct[ind1]=newD[ind];
        ind1++;
    }
    if(neg == 1)
    {
        a =my_put_char('-');
    }
    a += my_put_str(reversed_oct);
    return a;
}

char* my_hexal_na_to_d(int quotient)
{
  int remainder;
    int i, j = 0;
    char* hexadecimalnum = (char*)malloc(100*sizeof(char));
    while (quotient != 0)
    {
        remainder = quotient % 16;
        if (remainder < 10){
            
            hexadecimalnum[j++] = 48 + remainder;
        }
        else
        {
            hexadecimalnum[j++] = 55 + remainder;
            quotient = quotient / 16;
        }
    }
    char* s;
    s=malloc(j+1);
    int d=0;
    for (i = j-1; i >= 0; i--)
    {
        s[d]=hexadecimalnum[i];
        d++;
    }
    return s;     
}

char* my_firest_file_adress( int long p)
{
    
    int count = 0;
    unsigned long n = p;
    while(n > 0)
    {
        n = n / 16;
        count++;
    }

    char *num = (char*)malloc(count * sizeof(char));
    count--;
   char* alpha = "0123456789abcdef";
    while(p > 0)
    {
        num[count] = alpha[p % 16];
        p = p / 16;
        count--;
    }
    return num;
}
int my_printf(char * p1, ...)
{
    va_list list;
    va_start(list, p1);
    int count = 0;
    char case_char;
    char* case_string;
    int case_decimal;
    int case_octal;
    int case_unsig_in;
    int case_hexal_na;
     intptr_t p;
     int my_adress_num =0;
     char* str;

    for(int i = 0; p1[i]!= '\0';i++)
    {
        if(p1[i]== '%')
        {
            i++;
            switch (p1[i]) 

            {
            case 'c':

                case_char = (char) va_arg(list, int);
                count +=my_put_char(case_char);

            break;

            case 's':
            
                case_string= va_arg(list, char*);
                if(case_string==NULL)
                {
                 case_string ="(null)";
                }
                 count += my_put_str(case_string);

            break;

            case 'd':
                case_decimal= va_arg(list, int);
                count += int_to_char(case_decimal);
            break;

            case 'o':

                case_octal= va_arg(list, int);
                count+= my_octal(case_octal);

            break;
            case 'u':

             case_unsig_in= va_arg(list, int);
             count+=int_to_char(case_unsig_in);

            break;

            case 'x':

                case_hexal_na= va_arg(list, int);
                count += my_put_str(my_hexal_na_to_d(case_hexal_na));

            break;

            case 'p':

                p =( unsigned long) va_arg(list,void*);
                count +=  my_put_str("0x");
                my_adress_num += 2;
                str = my_firest_file_adress(p);
                my_put_str(str);
                count += my_strlen(str);

            break;

            }
        }

        else
        {
            count += my_put_char(p1[i]);
           
        }
    }
     
    return count;
}
int main()
{
     int a=my_printf("%p!\n", "ihdefiw");
     my_printf("%d",a);

    return 0;
}