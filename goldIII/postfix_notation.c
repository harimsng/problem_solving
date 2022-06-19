#include <unistd.h>

typedef struct s_stack
{
	char		stack[101];
	size_t		height;
}				t_stack;

static void		stack_push(t_stack *stack, char c);
static char		stack_pop(t_stack *stack);
static char		stack_top(t_stack *stack);
static void		inside_bracket(void);

t_stack		postfix;
t_stack		operator;

static char	*g_infixptr;

int	main(void)
{
	char	infix[200] = {0, };
	size_t	idx = 0;

	g_infixptr = infix;
	g_postfix_stack = postfix_stack;
	g_operator_stack = operator_stack;
	idx = read(0, infix, 100);
	if (infix[idx - 1] == '\n')
		infix[idx - 1] = 0;
	inside_bracket();
	write(1, postfix.stack, postfix.height);
}

// when this recursive functions return, g_infixptr is incremented by one.
// so infix array should have additional space filled with null characters.
void	inside_bracket(void)
{
	char	temp;

	while (*g_infixptr!= 0)
	{
		switch (*g_infixptr)
		{
			case '(':
				stack_push(operator, *g_infixptr);
				++g_infixptr;
				inside_bracket();
				continue;
			case ')':
				while ((temp = stack_pop(operator)) != '(')
					stack_push(postfix, temp);
				return;
			case '*':
			case '/':
				temp = stack_top(operator);
				if (
				if (temp == '*' || temp == '/')
					stack_push(postfix, stack_pop(operator));
				break;
			case '+':
			case '-':
				temp = stack_top(operator);
				if (temp == '*' || temp == '/' || temp == '+' || temp == '-')
					stack_push(postfix, stack_pop(operator));
				stack_push(operator, *g_infixptr);
				break;
			case 'a':
			case 'b':
			case 'c':
			case 'd':
			case 'e':
			case 'f':
			case 'g':
			case 'h':
			case 'i':
			case 'j':
			case 'k':
			case 'l':
			case 'm':
			case 'n':
			case 'o':
			case 'p':
			case 'q':
			case 'r':
			case 's':
			case 't':
			case 'u':
			case 'v':
			case 'w':
			case 'x':
			case 'y':
			case 'z':
				stack_push(postfix, *g_infixptr);
				break;
			default:
				fprintf(stderr, "wrong input\n");
				break;
		}
		++g_infixptr;
	}
}

static void		stack_push(t_stack *stack, char c)
{
	stack->stack[stack.height++] = c;
}

static char		stack_pop(t_stack *stack)
{
	return (stack->stack[--stack->height]);
}

static char		stack_top(t_stack *stack)
{
	return (stack->stack[stack->height - 1]);
}

/*
1 + ((2 * 3) - 4) * (5 + 6 - 7 * 8 / 9) - 10 * (11 + 12)
1 + 86 / 9 - 230 .= 10.5 - 230 = -219.5
a + ((b * c) - d) * (e + f - g * h / i) - j * (k + l)
abc*d-ef+gh*i/-*+jkl+*-
abc*d-ef+gh*i/-*+jkl+*-
abc*d-ef+
+*-

a * ((b * c) - d) + (e + f - g * h / i) - j * (k + l)
abc*d-*
+

abc*d-ef+gh*i/-
+*

a + b * c

abc*+
+*

(a + b) * c
ab+c*

a * b + c
ab
*

a * b / c
ab*
/
*/
