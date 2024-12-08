#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "extractFilePathComponents.h"

bool test(char *path, char *exp_dir, char *exp_name, char *exp_ext)
{
    char dir[200] = {0};
    char name[200] = {0};
    char ext[200] = {0};

    extractFilePathComponents(path, dir, sizeof(dir), name, sizeof(name), ext, sizeof(ext));

    printf("assert(test(\"%s\", \"%s\", \"%s\", \"%s\"));\r\n", path, dir, name, ext);

    if (strcmp(dir, exp_dir) != 0)
    {
        return false;
    }

    if (strcmp(name, exp_name) != 0)
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
    printf("TESTING extractFilePathComponents\r\n");
    assert(test(NULL, "", "", ""));
    assert(test("", "", "", ""));
    assert(test("test", "", "test", ""));
    assert(test("test.", "", "test", ""));
    assert(test("test.exp", "", "test", "exp"));
    assert(test("./hello/test.exp", "./hello/", "test", "exp"));
    printf("\r\nPASSED extractFilePathComponents\r\n");
    return 0;
}
