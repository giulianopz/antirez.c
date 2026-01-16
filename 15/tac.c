// toy implementation of tac GNU utility: https://man7.org/linux/man-pages/man1/tac.1.html

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// use a linked list to save file lines in reverse order
struct line
{
    char *s;
    struct line *prev;
};

/*
    **argv represents the memory address where an array of mem addresses are stored,
    each one corresponding to a char array (i.e. a string):
    1000: foo
    2000: bar
    3000: [1000, 2000]
 */
int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("missing file name\n");
        return 1;
    }

    // warn: not memory efficient
    // since it loads the whole file into memory
    // FILE is a typedef, an alias that makes easier using a more complex type
    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL)
    {
        printf("file does not exist\n");
        return 1;
    }

    // warn: lines get be longer than 1024 bytes
    char buf[1024];
    struct line *head = NULL;
    while (fgets(buf, sizeof(buf), fp) != NULL)
    {
        // allocate 16 bytes for the two pointers in the struct
        struct line *l = malloc(sizeof(struct line));
        size_t linelen = strlen(buf);
        // allocate the bytes accumulated in the buffer for the current line + 1 byte for the string terminator
        l->s = malloc(linelen + 1);
        // could be replaced with memcpy
        for (size_t j = 0; j <= linelen; j++)
        {
            l->s[j] = buf[j];
        }
        l->prev = head;
        head = l;
    }
    fclose(fp);

    while (head != NULL)
    {
        printf("%s", head->s);
        head = head->prev;
    }

    return 0;
}