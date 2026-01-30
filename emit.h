// emit.h
#ifndef EMIT_H
# define EMIT_H

void set_emit_fn(void (*fn)(const char *));
void emit(const char *msg);

#endif
