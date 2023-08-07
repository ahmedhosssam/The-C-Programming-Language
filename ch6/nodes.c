#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100
#define BUFSIZE 1000

struct tnode *addtree(struct tnode *, char *);
struct tnode *talloc(void);
void treeprint(struct tnode *);
int getword(char *, int);

struct tnode {
	char *word;
	int count;
	struct tnode *left;
	struct tnode *right;
};

char buf[BUFSIZE];  // Buffer for "ungetting" characters
int buf_index = 0;  // Current index in the buffer

// Function to push a character back into the buffer
void ungetch(int c) {
    if (buf_index < BUFSIZE) {
        buf[buf_index++] = c;
    } else {
        printf("Error: Buffer is full, cannot ungetch.\n");
    }
}

int main() {
	struct tnode *root;
	char word[MAXWORD];
	char *arr = "Hello\0";

	root = NULL;
	while (getword(word, MAXWORD) != EOF)
		if(isalpha(word[0]))
			root = addtree(root, word);
	treeprint(root);
	return 0;
}

int getword(char *word, int lim) {
	int c;
	char *w = word;

	while (isspace(c = getchar()))
	;
	
	if (c != EOF || c != '\n') {
		*w++ = c;
	}
	if (!isalpha(c)) {
		*w = '\0';
		return c;
	}
	for ( ; --lim > 0; ++w)
		if (!isalnum(*w = getchar())) {
			ungetch(*w);
			break;
		}
	*w = '\0';
	return word[0];
}

/* addtree: add a node with w, at or below p */
struct tnode *addtree(struct tnode *p, char *w) {
	int cond;

	if (p == NULL) {
		p = talloc();
		p->word = strdup(w);
		p->count = 1;
		p->left = p->right = NULL;
	} else if ((cond = strcmp(w, p->word)) == 0) {
		p->count++;
	} else if (cond < 0) {
		p->left = addtree(p->left, w);
	} else {
		p->right = addtree(p->right, w);
	}

	return p;
}

void treeprint(struct tnode*p) {
	if (p != NULL) {
		treeprint(p->left);
		printf("%d -- %s\n", p-> count, p->word);
		treeprint(p->right);
	}
}

struct tnode *talloc(void) {
	return (struct tnode *) malloc(sizeof(struct tnode));
}
