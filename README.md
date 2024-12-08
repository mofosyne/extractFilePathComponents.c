# extractFilePathComponents.c

![CI/CD Status Badge](https://github.com/mofosyne/extractFilePathComponents.c/actions/workflows/ci.yml/badge.svg)

Extract Directory, Filename And Extension from filepath

## install

```sh
$ clib install mofosyne/extractFilePathComponents.c
```

## usage

```c
char *path = "./hello/test.exp";
char dir[200] = {0};
char name[200] = {0};
char ext[200] = {0};
extractFilePathComponents(path, dir, sizeof(dir), name, sizeof(name), ext, sizeof(ext));
```

## license

GPL-3.0-or-later
