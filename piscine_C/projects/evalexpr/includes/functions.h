#ifndef FUNCTIONS_H
# define FUNCTIONS_H

char    *remove_whitespaces(char *str);
int        parse_parenthesis(char **str);
int        primary_expression(char **str);
int        multiplicate_expression(char **str);
int        eval_expr(char *str);
int        do_op(int nb1, int nb2, char op);
void    ft_putchar(char c);
int        ft_strlen(char *str);
void    ft_putnbr(int nbr);

#endif
