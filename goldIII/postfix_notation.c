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
	char	postfix_stack[100] = {0, };
	char	operator_stack[100] = {0, };
	char	infix[102] = {0, };
	size_t	idx = 0;

	g_infixptr = infix;
	g_postfix_stack = postfix_stack;
	g_operator_stack = operator_stack;
	idx = read(0, infix, 100);
	if (infix[idx - 1] == '\n')
		infix[idx - 1] = 0;
	inside_bracket();
}

void	inside_bracket(void)
{
	char	temp;

	while (*g_infixptr!= 0)
	{
		switch (*g_infixptr)
		{
//			case '(':
//				break;
			case ')':
				stack_push(postfix, stack_pop(operator));
				return;
			case '*':
			case '/':
				temp = stack_top(operator);
				if (temp == '*' || temp == '/')
					stack_push(postfix, stack_pop(operator));
				else if (infix_ptr[1] == '(')
					inside_bracket(infix_ptr + 2);
				break;
			case '+':
			case '-':
				temp = stack_top(operator);
				if (temp == '+' || temp == '-')
					stack_push(postfix, stack_pop(operator));
				else if (infix_ptr[1] == '(')
					inside_bracket(infix_ptr + 2);
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
				break;
			default:
				fprintf(stderr, "wrong input\n");
				break;
		}
		++g_infixptr;
	}
}

1 + ((2 * 3) - 4) * (5 + 6 - 7 * 8 / 9) - 10 * (11 + 12)
1 + 86 / 9 - 230 .= 10.5 - 230 = -219.5
a + ((b * c) - d) * (e + f - g * h / i) - j * (k + l)
abc*d-ef+gh*i/-*+jkl+*-
abc*d-ef+gh*i/-*+jkl+*-
abc*d-ef+
+*-
