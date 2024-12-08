void filenameExtractPathAndExtension(const char *fname, char *pathBuff, int pathSize, char *extBuff, int extSize)
{
    // Minimal Filename Extraction Of Path And Extention
    // Brian Khuu 2021
    // https://gist.github.com/mofosyne/21587a9b68ea212ab976150ca3525664/edit
    int i = 0;
    int end = 0;
    int exti = 0;
    for (end = 0; fname[end] != '\0'; end++)
    {
        if ((fname[end] == '/') || (fname[end] == '\\'))
        {
            exti = 0;
        }
        else if (fname[end] == '.')
        {
            exti = end;
        }
    }

    if (exti == 0)
    {
        exti = end;
    }

    // Copy PathName
    if (pathBuff)
    {
        for (i = 0; i < (pathSize - 1); i++)
        {
            if (!(i < exti))
            {
                break;
            }
            pathBuff[i] = fname[i];
        }
        pathBuff[i] = '\0';
    }

    // Copy Extention
    if (extBuff)
    {
        for (i = 0; i < (extSize - 1); i++)
        {
            if (!(i < (end - exti - 1)))
            {
                break;
            }
            extBuff[i] = fname[exti + i + 1];
        }
        extBuff[i] = '\0';
    }
}
