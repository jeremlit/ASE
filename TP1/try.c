#include "try.h"

int try(struct ctx_s *pctx, func_t *f, int arg){
    pctx->ctx_magic = CTX_MAGIC;
    asm("movl %%esp, %0": "=r"(pctx->ctx_esp):);
    asm("movl %%ebp, %0": "=r"(pctx->ctx_ebp):);
    return f(arg);
}

int throw (struct ctx_s *pctx, int r){
    assert(pctx->ctx_magic == CTX_MAGIC);
    static int throw_r;
    throw_r = r;
    asm("movl %0, %%esp"::"r"(pctx->ctx_esp));
    asm("movl %0, %%ebp"::"r"(pctx->ctx_ebp));
    return throw_r;
}
