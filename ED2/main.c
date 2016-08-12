#include "avl.c"

int main(int argc, char **argv)
{
	tree *root = NULL;
	
	add(&root, 15);
	add(&root, 10);
	add(&root, 11);
	erd(root);
	
	return 0;
}
