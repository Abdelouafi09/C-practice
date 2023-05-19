#include <stdio.h>
#include <stdlib.h>
struct node
{
	int name;
	struct node *link;
};
int main(void)
{
	struct node *head = malloc(sizeof(struct node));
	head->name = 10;
	head->link = NULL;

	struct node *curr = malloc(sizeof(struct node));
	curr->name = 20;
	curr->link = NULL;
	head->link = curr;

	printf("head: %p\nname1: %d its addresse: %p and its link: %p\nname2: %d its addresse: %p and its link: %p\n", head, head->name, head, head->link, head->link->name, head->link, head->link->link);
	return (0);
}
