#include <stdbool.h>
#include <stddef.h>

void extractFilePathComponents(const char *path, char *dirBuff, int dirSize, char *nameBuff, int nameSize, char *extBuff, int extSize)
{
    bool directoryFound = false;
    bool extensionFound = false;

    if (path == NULL)
    {
        return;
    }

    if (path[0] == '\0')
    {
        return;
    }

    // Grab Directory Position
    const char *pathStart = path;
    const char *pathEnd = path;
    while (*pathEnd)
    {
        pathEnd++;
    }

    // Set default filename Position
    const char *nameStart = pathStart;
    const char *nameEnd = pathEnd;

    // Grab Extention Position
    const char *extStart = NULL;
    for (const char *scan = pathEnd; scan > pathStart; scan--)
    {
        const char *scanAhead = scan - 1;
        if ((scanAhead > pathStart) && (*scanAhead == '.'))
        {
            extStart = scan;
            nameEnd = scanAhead;
            extensionFound = true;
            break;
        }
    }

    // Grab Directory Position
    const char *dirEnd = NULL;
    for (const char *scan = pathEnd; scan > pathStart; scan--)
    {
        const char *scanAhead = scan - 1;
        if ((scanAhead > pathStart) && (*scanAhead == '/' || *scanAhead == '\\'))
        {
            dirEnd = scan;
            nameStart = scan;
            directoryFound = true;
            break;
        }
    }

    // Copy Directory
    if (dirBuff && dirSize > 0)
    {
        if (!directoryFound)
        {
            dirBuff[0] = '\0';
        }
        else
        {
            int writeIndex = 0;
            for (const char *read = pathStart; read < dirEnd; read++)
            {
                if (!(writeIndex < (dirSize - 1)))
                {
                    break;
                }
                dirBuff[writeIndex] = *read;
                writeIndex++;
            }
            dirBuff[writeIndex] = '\0';
        }
    }

    // Copy Filename
    if (nameBuff && nameSize > 0)
    {
        int writeIndex = 0;
        for (const char *read = nameStart; read < nameEnd; read++)
        {
            if (!(writeIndex < (nameSize - 1)))
            {
                break;
            }
            nameBuff[writeIndex] = *read;
            writeIndex++;
        }
        nameBuff[writeIndex] = '\0';
    }

    // Copy Extention
    if (extBuff && extSize > 0)
    {
        if (!extensionFound)
        {
            dirBuff[0] = '\0';
        }
        else
        {
            int writeIndex = 0;
            for (const char *read = extStart; read < pathEnd; read++)
            {
                if (!(writeIndex < (extSize - 1)))
                {
                    break;
                }
                extBuff[writeIndex] = *read;
                writeIndex++;
            }
            extBuff[writeIndex] = '\0';
        }
    }

    return;
}
