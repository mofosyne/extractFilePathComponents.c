#ifndef __EXTRACTFILEPATHCOMPONENTS_H
#define __EXTRACTFILEPATHCOMPONENTS_H
#ifdef __cplusplus
extern "C"
{
#endif
void extractFilePathComponents(const char *path, char *dirBuff, int dirSize, char *nameBuff, int nameSize, char *extBuff, int extSize);
#ifdef __cplusplus
}
#endif
#endif
