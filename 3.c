// markov main: markov-chain random text generation without NONWORD separators
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXGEN 100
#define NPREP 2

struct Suffix {
    char *word;
    struct Suffix *next;
};

struct State {
    char *prefix[NPREP];
    struct Suffix *suf;
    struct State *next;
};

struct State *statetab = NULL;

struct State *lookup(char *prefix[NPREP], int create) {
    struct State *sp;
    for (sp = statetab; sp != NULL; sp = sp->next) {
        int match = 1;
        for (int i = 0; i < NPREP; i++) {
            if (strcmp(sp->prefix[i], prefix[i]) != 0) {
                match = 0;
                break;
            }
        }
        if (match) return sp;
    }
    if (create) {
        sp = (struct State *)malloc(sizeof(struct State));
        for (int i = 0; i < NPREP; i++) {
            sp->prefix[i] = strdup(prefix[i]);
        }
        sp->suf = NULL;
        sp->next = statetab;
        statetab = sp;
    }
    return sp;
}

void add(char *prefix[NPREP], char *word) {
    struct State *sp = lookup(prefix, 1);
    struct Suffix *suf = (struct Suffix *)malloc(sizeof(struct Suffix));
    suf->word = strdup(word);
    suf->next = sp->suf;
    sp->suf = suf;

    for (int i = 0; i < NPREP - 1; i++) {
        prefix[i] = prefix[i + 1];
    }
    prefix[NPREP - 1] = word;
}

void build(char *prefix[NPREP], FILE *file) {
    char buf[100];
    int words_read = 0;
    while (fscanf(file, "%99s", buf) == 1) {
        add(prefix, strdup(buf));
        words_read++;
    }
    if (words_read == 0) {
        prefix[0] = NULL;
    }
}

void generate(int nwords) {
    struct State *sp;
    struct Suffix *suf;
    char *prefix[NPREP];
    char *w;
    int i, nmatch;

    for (i = 0; i < NPREP; i++) {
        prefix[i] = NULL;
    }

    sp = statetab;
    if (!sp) {
        printf("No input data.\n");
        return;
    }

    for (i = 0; i < NPREP && sp->prefix[i]; i++) {
        prefix[i] = sp->prefix[i];
    }

    for (i = 0; i < nwords; i++) {
        sp = lookup(prefix, 0);
        if (!sp || !sp->suf) break;

        nmatch = 0;
        for (suf = sp->suf; suf; suf = suf->next) {
            if (rand() % ++nmatch == 0)
                w = suf->word;
        }

        if (!w) break;

        printf("%s\n", w);

        for (int j = 0; j < NPREP - 1; j++) {
            prefix[j] = prefix[j + 1];
        }
        prefix[NPREP - 1] = w;
    }
}

int main() {
    char *prefix[NPREP] = {NULL, NULL};

    FILE *file = fopen("brooks.txt", "r");
    if (file) {
        build(prefix, file);
        fclose(file);
    }

    generate(MAXGEN);
    return 0;
}
