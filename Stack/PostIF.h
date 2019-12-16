/*FUNCTION IMPLEMENTATIONS FOR STACK BASED POSTFIX CONVERSION */


char *infixtoPostfix(char *str, Stack *s);
int evaluateExp(char *postfix, Stack *s);
int PrecedenceCheck(char op1);