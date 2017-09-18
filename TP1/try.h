#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define CTX_MAGIC 0xCAFEBABE

struct ctx_s{
    void * ctx_esp;
    void * ctx_ebp;
    unsigned int ctx_magic;
};

typedef int (func_t)(int); /* a function that returns an int from an int */

int try(struct ctx_s *pctx, func_t *f, int arg);

int throw(struct ctx_s *pctx, int r);
