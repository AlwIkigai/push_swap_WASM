#include "push_swap.h"
#include <stdlib.h>
#include <string.h>
#include <emscripten/emscripten.h>

#define OUTPUT_CAPACITY 8192
static char   output_buffer[OUTPUT_CAPACITY];
static size_t output_offset = 0;

static void capture_output(const char *op)
{
    size_t len = strlen(op);
    if (output_offset + len + 2 < OUTPUT_CAPACITY)
    {
        memcpy(&output_buffer[output_offset], op, len);
        output_offset += len;
        output_buffer[output_offset++] = '\n';
        output_buffer[output_offset] = '\0';
    }
}

static const char *push_swap_run_internal(const char *input)
{
    output_offset = 0;
    output_buffer[0] = '\0';

    if (!input || !*input)
        return output_buffer;

    char *copy = strdup(input);
    if (!copy)
        return output_buffer;

    char *argv[513 + 1];
    int   argc = 1;
    argv[0] = (char *)"push_swap";

    char *tok = strtok(copy, " \t\r\n");
    while (tok && argc < 513)
    {
        argv[argc++] = tok;
        tok = strtok(NULL, " \t\r\n");
    }

    init_push_swap(argc, argv, capture_output);

    free(copy);
    return output_buffer;
}

EMSCRIPTEN_KEEPALIVE
char *wasm_entry(const char *input)
{
    const char *out = push_swap_run_internal(input);
    size_t n = strlen(out);

    char *heap = (char *)malloc(n + 1);
    if (!heap) return NULL;

    memcpy(heap, out, n + 1);
    return heap; // JS must free
}
