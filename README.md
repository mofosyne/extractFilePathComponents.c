# filenameExtractPathAndExtension.c

![CI/CD Status Badge](https://github.com/mofosyne/filenameExtractPathAndExtension.c/actions/workflows/ci.yml/badge.svg)

Minimal Filename Extraction Of Path And Extention

## install

```sh
$ clib install mofosyne/filenameExtractPathAndExtension.c
```

## usage

```c
char *fname = "./hello/test.exp";
char path[200] = {0};
char ext[200] = {0};
filenameExtractPathAndExtension(fname, path, sizeof(path), ext, sizeof(ext));
```

## license

GPL-3.0-or-later
