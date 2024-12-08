#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "filenameExtractPathAndExtension.h"

bool test(char *fname, char *exp_path, char *exp_ext)
{
    char path[200] = {0};
    char ext[200] = {0};
    filenameExtractPathAndExtension(fname, path, sizeof(path), ext, sizeof(ext));
    printf("%s, %s, %s\r\n", fname, path, ext);

    // printf("assert(test(\"%s\", \"%s\", \"%s\"));\r\n", fname, path, ext);

    if (strcmp(path, exp_path) != 0)
    {
        return false;
    }
    if (strcmp(ext, exp_ext) != 0)
    {
        return false;
    }
    return true;
}

int main(void)
{
    assert(test("test", "test", ""));
    assert(test("test.", "test", ""));
    assert(test("test.exp", "test", "exp"));
    assert(test("./hello/test.exp", "./hello/test", "exp"));

    printf("\r\nfilenameExtractPathAndExtension OK\r\n");
    return 0;
}
