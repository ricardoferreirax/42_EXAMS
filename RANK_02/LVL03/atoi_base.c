
/* Assignment name  : ft_atoi_base
Expected files   : ft_atoi_base.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that converts the string argument str (base N <= 16)
to an integer (base 10) and returns it.

The characters recognized in the input are: 0123456789abcdef
Those are, of course, to be trimmed according to the requested base. For
example, base 4 recognizes "0123" and base 16 recognizes "0123456789abcdef".

Uppercase letters must also be recognized: "12fdb3" is the same as "12FDB3".

Minus signs ('-') are interpreted only if they are the first character of the
string.

Your function must be declared as follows: */

char ft_tolower(char c)
{
    if (c >= 'A' && c <= 'Z')
        return (c + 32);
    return c;
}

int gdigit(char c)
{
    if (c >= '0' && c <= '9')
        return (c - '0');
    if (c >= 'a' && c <= 'f')
        return (10 + c - 'a');
    return (-1);
}

int ft_atoi_base(const char *str, int base)
{
    int digit;
    int result = 0;
    int sign = 1;

    if (base < 2 || base > 16)
        return 0;
    if (*str == '-')
    {
        sign = -1;
        str++;
    }
    while (*str)
    {
        digit = gdigit(ft_tolower(*str));
        if (digit < 0 || digit >= base)
            break;
        result = result * base + digit;
        str++;
    }
    return (result * sign);
}