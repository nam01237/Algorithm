#include <stdio.h>
#include <stdlib.h>
int n;

typedef struct _node
{
	int c;
	int r;
	struct _node *before;

}Node;

typedef struct _stack
{
	Node *cur;
	int num;

}Stack;


void InitStack(Stack *stack)
{
	stack->num = 0;
	stack->cur = NULL;

}

void Push(Stack *stack, Node data)
{
	Node * node = (Node*)malloc(sizeof(Node));
	
	node->r = data.r;
	node->c = data.c;
	node->before = stack->cur;
	
	stack->cur = node;

	stack->num++;
}

Node Pop(Stack *stack)
{
	Node n;
	n.r = stack->cur->r;
	n.c = stack->cur->c;

	if (stack->num <= 0)
		exit(-1);

	Node *temp = stack->cur;
	stack->cur = stack->cur->before;
	free(temp);

	stack->num--;

	return n;

}


void Normal(int(*arr)[100], int r, int c)
{
	Stack stack;
	InitStack(&stack);


	int col = arr[r][c];

	arr[r][c] = 0;

	Node node;
	node.c = c;
	node.r = r;

	Push(&stack, node);


	int flag = 0;

	while (stack.num > 0)
	{
		node = *stack.cur;
		r = node.r;
		c = node.c;
		flag = 0;

		if (c < (n - 1) && (col == arr[r][c + 1]))
		{
			node.r = r;
			node.c = c + 1;
			Push(&stack, node);
			arr[r][c + 1] = 0;
			flag = 1;

		}
		else if (r < (n - 1) && (col == arr[r + 1][c]))
		{
			node.r = r + 1;
			node.c = c;
			Push(&stack, node);
			arr[r + 1][c] = 0;
			flag = 1;

		}
		else if (c > 0 && (col == arr[r][c - 1]))
		{
			node.r = r;
			node.c = c - 1;
			Push(&stack, node);
			arr[r][c - 1] = 0;
			flag = 1;

		}
		else if (r > 0 && (col == arr[r - 1][c]))
		{
			node.r = r - 1;
			node.c = c;
			Push(&stack, node);
			arr[r - 1][c] = 0;
			flag = 1;

		}

		if (flag == 0)
		{

			if (stack.num == 0)
				break;
			else
				Pop(&stack);

		}
	}

}

int main()
{
	int col = 0;
	int normal = 0;
	int bln = 0;

	int arr1[100][100];
	int arr2[100][100];

	scanf("%d", &n);

	char ch[101];

	for (int i = 0; i < n; i++)
	{
		scanf("%s", ch);

		for (int j = 0; j < n; j++)
		{
			if (ch[j] == 'R')
			{
				arr1[i][j] = 1;
				arr2[i][j] = 1;
			}
			else if (ch[j] == 'G')
			{
				arr1[i][j] = 2;
				arr2[i][j] = 1;
			}
			else if (ch[j] == 'B')
			{
				arr1[i][j] = 3;
				arr2[i][j] = 3;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr1[i][j] != 0)
			{
				normal++;
				Normal(arr1, i, j);
			}

			if (arr2[i][j] != 0)
			{
				bln++;
				Normal(arr2, i, j);
			}

		}
	}

	printf("%d %d\n", normal, bln);

}