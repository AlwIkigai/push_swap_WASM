// emit.c
#include "emit.h"
#include "push_swap.h" // your existing printf implementation
#include "emit_op.h"

static void (*emit_fn)(const char *) = 0;

void set_emit_fn(void (*fn)(const char *))
{
	emit_fn = fn;
}

void emit(const char *msg)
{
	if (emit_fn)
		emit_fn(msg);
	else
		ft_printf("%s\n", msg);
}

// Central op emission function for all operations
void emit_op(const char *op)
{
	emit(op);
}
