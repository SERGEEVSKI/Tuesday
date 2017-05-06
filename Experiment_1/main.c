#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <malloc.h>
#include "bstree.h"

double wtime()
{
	struct timeval t;
	gettimeofday(&t, NULL);
	return (double)t.tv_sec + (double)t.tv_usec * 1E-6;
}

int getrand(int min, int max)
{
    return (double)rand() / (RAND_MAX + 1.0) * (max - min) + min;
}

int main()
{
	int n = 0, j = 0, i = 0;
	double t;
	char **words;
	words = (char**)calloc(51203,sizeof(char*));
	for(i = 0; i < 51203; i++)
	{
		words[i] = (char*)calloc(60,sizeof(char));
	}
	int w;
	struct bstree *tree, *node;
	FILE *exp1 = fopen("Dictionary.txt", "r");
	for(n = 0; n < 51203; n++)
	{
		fgets(words[n], 10000, exp1);
	}
	fclose(exp1);
	tree = bstree_create(words[0], 0);
	system("clear");
	printf("Binary Search Tree: \n\n");
	for(i = 1; i <= 51203; i++)
	{
  		bstree_add(tree,words[i-1],i-1);
		if((i+1) % 5000 == 0)
		{
  				w = getrand(0,i-1);
				t = wtime();
				node = bstree_lookup(tree, w);
				t = wtime() - t;
  		}
  		printf("n = %d; Elapsed time: %.lf sec.\n", i, t);
	}
	return 0;
}
