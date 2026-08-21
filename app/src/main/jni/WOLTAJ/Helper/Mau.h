uint32_t Colors[] = {0x9241EB, 0x9EFF00, 0x006EF4, 0xCA2876, 0x0A31DE, 0xBAA7FD, 0xCEDB3F, 0x286A45, 0x58F014, 0x45CAE6, 0x773702, 0xB0CEF0, 0x3C5F51, 0x453CD7, 0x364024, 0x439997, 0x4CB612, 0xC6B564, 0x17F250, 0xE41BC0, 0xAF8E27, 0x8E382E, 0x47A101, 0x9DAC33, 0x66F4CF, 0x59A9F0, 0x798D1A, 0x2EBB59, 0xBF66C3, 0x4BD8FB, 0xBBFA54, 0x6B9881, 0x144967, 0xBAA3AE, 0xE80B9D, 0x7BA552, 0x96A456, 0x17D7B4, 0x130C39, 0x3C06A8, 0x62737E, 0xA87E89, 0xB6D3E4, 0x66B77D, 0x66E304, 0x1B80E1, 0x7A06BC, 0xBFFB1B, 0x618506, 0x7E4D34};

uint32_t ColorsX[] = {0x8C3F42, 0x543D91, 0x8E4488, 0x4A6F93, 0x669546, 0x579775, 0xAE9F36, 0x46A47C/*, 0x58F014, 0x45CAE6, 0x773702, 0xB0CEF0, 0x3C5F51, 0x453CD7, 0x364024, 0x439997, 0x4CB612, 0xC6B564, 0x17F250, 0xE41BC0, 0xAF8E27, 0x8E382E, 0x47A101, 0x9DAC33, 0x66F4CF, 0x59A9F0, 0x798D1A, 0x2EBB59, 0xBF66C3, 0x4BD8FB, 0xBBFA54, 0x6B9881, 0x144967, 0xBAA3AE, 0xE80B9D, 0x7BA552, 0x96A456, 0x17D7B4, 0x130C39, 0x3C06A8, 0x62737E, 0xA87E89, 0xB6D3E4, 0x66B77D, 0x66E304, 0x1B80E1, 0x7A06BC, 0xBFFB1B, 0x618506, 0x7E4D34*/};

long GetRandomColorByIndex(int index) {
    srand(index);

    int a = 255;
    int r = ((Colors[rand() % sizeof(Colors)] & 0xFF0000) >> 16);
    int g = ((Colors[rand() % sizeof(Colors)] & 0x00FF00) >> 8);
    int b = (Colors[rand() % sizeof(Colors)] & 0x0000FF);

    return IM_COL32(r, g, b, a);
}

int skeletonByDistance(int distance, int Health){
    int _colorByDistance;
    if (distance < 500)
        _colorByDistance = 0xFF0096FF;
    if (distance < 100)
        _colorByDistance = IM_COL32(255, 0, 0, 255);
    if (Health == 0.0f)
        _colorByDistance = IM_COL32(255, 0, 255, 255);
    return _colorByDistance;
}

int boxByDistance(int distance, int Health){
    int _colorByDistance;
    if (distance < 500)
        _colorByDistance = 0x300096FF;
    if (distance < 100)
        _colorByDistance = IM_COL32(255, 0, 0, 30);
    if (Health == 0.0f)
        _colorByDistance = IM_COL32(255, 0, 255, 30);
    return _colorByDistance;
}

int skeletonByDistancebot(int distance, int Health){
    int _colorByDistance;
    if (distance < 500)
        _colorByDistance = IM_COL32(255, 255, 255, 255);
    if (Health == 0.0f)
        _colorByDistance = IM_COL32(255, 0, 255, 255);
    return _colorByDistance;
}
int boxByDistancebot(int distance, int Health){
    int _colorByDistance;
    if (distance < 500)
        _colorByDistance = IM_COL32(255, 255, 255, 30);
    if (Health == 0.0f)
        _colorByDistance = IM_COL32(255, 0, 255, 30);
    return _colorByDistance;
}


long GetRandomColorByIndexX(int index , int alpha) {
    srand(index);

    int a = alpha;
    int r = ((ColorsX[rand()  % sizeof(ColorsX)] & 0xFFFFFF) >> 16);
    int g = ((ColorsX[rand() % sizeof(ColorsX)] & 0xFFFFFF) >> 8);
    int b = (ColorsX[rand() % sizeof(ColorsX)] & 0xFFFFFF);

    return IM_COL32(r, g, b, a);
}
uint32_t ColorsBack[] =
        {
                0x818181,
                0x0096FF,
                0xE91E63,
                0xFF00E1,
                0xAB00FF,
                0x6100FF,
                0x0051FF,
                0x00BCFF,
                0x00E4FF,
                0x00FFAE,
                0x00FF79,
                0x00FF31,
                0x8FFF00,
                0xE2FF00,
                0xE2FF00,
                0xFFC900,
                0xFF8000,
                0xB00082,
                0xA700B0,
                0x7600B0,
                0x4100B0,
                0x003EB0,
                0x0074B0,
                0x009BB0,
                0x00B07B,
                0x00B019,
                0x51B000,
                0x98B000,
                0xB08B00,
                0xB05800,

                0x818181,
                0x0096FF,
                0xE91E63,
                0xFF00E1,
                0xAB00FF,
                0x6100FF,
                0x0051FF,
                0x00BCFF,
                0x00E4FF,
                0x00FFAE,
                0x00FF79,
                0x00FF31,
                0x8FFF00,
                0xE2FF00,
                0xE2FF00,
                0xFFC900,
                0xFF8000,
                0xB00082,
                0xA700B0,
                0x7600B0,
                0x4100B0,
                0x003EB0,
                0x0074B0,
                0x009BB0,
                0x00B07B,
                0x00B019,
                0x51B000,
                0x98B000,
                0xB08B00,
                0xB05800,

                0x818181,
                0x0096FF,
                0xE91E63,
                0xFF00E1,
                0xAB00FF,
                0x6100FF,
                0x0051FF,
                0x00BCFF,
                0x00E4FF,
                0x00FFAE,
                0x00FF79,
                0x00FF31,
                0x8FFF00,
                0xE2FF00,
                0xE2FF00,
                0xFFC900,
                0xFF8000,
                0xB00082,
                0xA700B0,
                0x7600B0,
                0x4100B0,
                0x003EB0,
                0x0074B0,
                0x009BB0,
                0x00B07B,
                0x00B019,
                0x51B000,
                0x98B000,
                0xB08B00,
                0xB05800,

                0x818181,
                0x0096FF,
                0xE91E63,
                0xFF00E1,
                0xAB00FF,
                0x6100FF,
                0x0051FF,
                0x00BCFF,
                0x00E4FF,
                0x00FFAE,
                0x00FF79,
                0x00FF31,
                0x8FFF00,
                0xE2FF00,
                0xE2FF00,
                0xFFC900,
                0xFF8000,
                0xB00082,
                0xA700B0,
                0x7600B0,
                0x4100B0,
                0x003EB0,
                0x0074B0,
                0x009BB0,
                0x00B07B,
                0x00B019,
                0x51B000,
                0x98B000,
                0xB08B00,
                0xB05800,

                0x818181,
                0x0096FF,
                0xE91E63,
                0xFF00E1,
                0xAB00FF,
                0x6100FF,
                0x0051FF,
                0x00BCFF,
                0x00E4FF,
                0x00FFAE,
                0x00FF79,
                0x00FF31,
                0x8FFF00,
                0xE2FF00,
                0xE2FF00,
                0xFFC900,
                0xFF8000,
                0xB00082,
                0xA700B0,
                0x7600B0,
                0x4100B0,
                0x003EB0,
                0x0074B0,
                0x009BB0,
                0x00B07B,
                0x00B019,
                0x51B000,
                0x98B000,
                0xB08B00,
                0xB05800,

                0x818181,
                0x0096FF,
                0xE91E63,
                0xFF00E1,
                0xAB00FF,
                0x6100FF,
                0x0051FF,
                0x00BCFF,
                0x00E4FF,
                0x00FFAE,
                0x00FF79,
                0x00FF31,
                0x8FFF00,
                0xE2FF00,
                0xE2FF00,
                0xFFC900,
                0xFF8000,
                0xB00082,
                0xA700B0,
                0x7600B0,
                0x4100B0,
                0x003EB0,
                0x0074B0,
                0x009BB0,
                0x00B07B,
                0x00B019,
                0x51B000,
                0x98B000,
                0xB08B00,
                0xB05800,

                0x818181,
                0x0096FF,
                0xE91E63,
                0xFF00E1,
                0xAB00FF,
                0x6100FF,
                0x0051FF,
                0x00BCFF,
                0x00E4FF,
                0x00FFAE,
                0x00FF79,
                0x00FF31,
                0x8FFF00,
                0xE2FF00,
                0xE2FF00,
                0xFFC900,
                0xFF8000,
                0xB00082,
                0xA700B0,
                0x7600B0,
                0x4100B0,
                0x003EB0,
                0x0074B0,
                0x009BB0,
                0x00B07B,
                0x00B019,
                0x51B000,
                0x98B000,
                0xB08B00,
                0xB05800,

                0x818181,
                0x0096FF,
                0xE91E63,
                0xFF00E1,
                0xAB00FF,
                0x6100FF,
                0x0051FF,
                0x00BCFF,
                0x00E4FF,
                0x00FFAE,
                0x00FF79,
                0x00FF31,
                0x8FFF00,
                0xE2FF00,
                0xE2FF00,
                0xFFC900,
                0xFF8000,
                0xB00082,
                0xA700B0,
                0x7600B0,
                0x4100B0,
                0x003EB0,
                0x0074B0,
                0x009BB0,
                0x00B07B,
                0x00B019,
                0x51B000,
                0x98B000,
                0xB08B00,
                0xB05800,

                0x818181,
                0x0096FF,
                0xE91E63,
                0xFF00E1,
                0xAB00FF,
                0x6100FF,
                0x0051FF,
                0x00BCFF,
                0x00E4FF,
                0x00FFAE,
                0x00FF79,
                0x00FF31,
                0x8FFF00,
                0xE2FF00,
                0xE2FF00,
                0xFFC900,
                0xFF8000,
                0xB00082,
                0xA700B0,
                0x7600B0,
                0x4100B0,
                0x003EB0,
                0x0074B0,
                0x009BB0,
                0x00B07B,
                0x00B019,
                0x51B000,
                0x98B000,
                0xB08B00,
                0xB05800,

                0x818181,
                0x0096FF,
                0xE91E63,
                0xFF00E1,
                0xAB00FF,
                0x6100FF,
                0x0051FF,
                0x00BCFF,
                0x00E4FF,
                0x00FFAE,
                0x00FF79,
                0x00FF31,
                0x8FFF00,
                0xE2FF00,
                0xE2FF00,
                0xFFC900,
                0xFF8000,
                0xB00082,
                0xA700B0,
                0x7600B0,
                0x4100B0,
                0x003EB0,
                0x0074B0,
                0x009BB0,
                0x00B07B,
                0x00B019,
                0x51B000,
                0x98B000,
                0xB08B00,
                0xB05800,

                0x818181,
                0x0096FF,
                0xE91E63,
                0xFF00E1,
                0xAB00FF,
                0x6100FF,
                0x0051FF,
                0x00BCFF,
                0x00E4FF,
                0x00FFAE,
                0x00FF79,
                0x00FF31,
                0x8FFF00,
                0xE2FF00,
                0xE2FF00,
                0xFFC900,
                0xFF8000,
                0xB00082,
                0xA700B0,
                0x7600B0,
                0x4100B0,
                0x003EB0,
                0x0074B0,
                0x009BB0,
                0x00B07B,
                0x00B019,
                0x51B000,
                0x98B000,
                0xB08B00,
                0xB05800,

                0x818181,
                0x0096FF,
                0xE91E63,
                0xFF00E1,
                0xAB00FF,
                0x6100FF,
                0x0051FF,
                0x00BCFF,
                0x00E4FF,
                0x00FFAE,
                0x00FF79,
                0x00FF31,
                0x8FFF00,
                0xE2FF00,
                0xE2FF00,
                0xFFC900,
                0xFF8000,
                0xB00082,
                0xA700B0,
                0x7600B0,
                0x4100B0,
                0x003EB0,
                0x0074B0,
                0x009BB0,
                0x00B07B,
                0x00B019,
                0x51B000,
                0x98B000,
                0xB08B00,
                0xB05800,

                0x818181,
                0x0096FF,
                0xE91E63,
                0xFF00E1,
                0xAB00FF,
                0x6100FF,
                0x0051FF,
                0x00BCFF,
                0x00E4FF,
                0x00FFAE,
                0x00FF79,
                0x00FF31,
                0x8FFF00,
                0xE2FF00,
                0xE2FF00,
                0xFFC900,
                0xFF8000,
                0xB00082,
                0xA700B0,
                0x7600B0,
                0x4100B0,
                0x003EB0,
                0x0074B0,
                0x009BB0,
                0x00B07B,
                0x00B019,
                0x51B000,
                0x98B000,
                0xB08B00,
                0xB05800,

                0x818181,
                0x0096FF,
                0xE91E63,
                0xFF00E1,
                0xAB00FF,
                0x6100FF,
                0x0051FF,
                0x00BCFF,
                0x00E4FF,
                0x00FFAE,
                0x00FF79,
                0x00FF31,
                0x8FFF00,
                0xE2FF00,
                0xE2FF00,
                0xFFC900,
                0xFF8000,
                0xB00082,
                0xA700B0,
                0x7600B0,
                0x4100B0,
                0x003EB0,
                0x0074B0,
                0x009BB0,
                0x00B07B,
                0x00B019,
                0x51B000,
                0x98B000,
                0xB08B00,
                0xB05800,

                0x818181,
                0x0096FF,
                0xE91E63,
                0xFF00E1,
                0xAB00FF,
                0x6100FF,
                0x0051FF,
                0x00BCFF,
                0x00E4FF,
                0x00FFAE,
                0x00FF79,
                0x00FF31,
                0x8FFF00,
                0xE2FF00,
                0xE2FF00,
                0xFFC900,
                0xFF8000,
                0xB00082,
                0xA700B0,
                0x7600B0,
                0x4100B0,
                0x003EB0,
                0x0074B0,
                0x009BB0,
                0x00B07B,
                0x00B019,
                0x51B000,
                0x98B000,
                0xB08B00,
                0xB05800,

                0x818181,
                0x0096FF,
                0xE91E63,
                0xFF00E1,
                0xAB00FF,
                0x6100FF,
                0x0051FF,
                0x00BCFF,
                0x00E4FF,
                0x00FFAE,
                0x00FF79,
                0x00FF31,
                0x8FFF00,
                0xE2FF00,
                0xE2FF00,
                0xFFC900,
                0xFF8000,
                0xB00082,
                0xA700B0,
                0x7600B0,
                0x4100B0,
                0x003EB0,
                0x0074B0,
                0x009BB0,
                0x00B07B,
                0x00B019,
                0x51B000,
                0x98B000,
                0xB08B00,
                0xB05800,

                0x818181,
                0x0096FF,
                0xE91E63,
                0xFF00E1,
                0xAB00FF,
                0x6100FF,
                0x0051FF,
                0x00BCFF,
                0x00E4FF,
                0x00FFAE,
                0x00FF79,
                0x00FF31,
                0x8FFF00,
                0xE2FF00,
                0xE2FF00,
                0xFFC900,
                0xFF8000,
                0xB00082,
                0xA700B0,
                0x7600B0,
                0x4100B0,
                0x003EB0,
                0x0074B0,
                0x009BB0,
                0x00B07B,
                0x00B019,
                0x51B000,
                0x98B000,
                0xB08B00,
                0xB05800,

                0x818181,
                0x0096FF,
                0xE91E63,
                0xFF00E1,
                0xAB00FF,
                0x6100FF,
                0x0051FF,
                0x00BCFF,
                0x00E4FF,
                0x00FFAE,
                0x00FF79,
                0x00FF31,
                0x8FFF00,
                0xE2FF00,
                0xE2FF00,
                0xFFC900,
                0xFF8000,
                0xB00082,
                0xA700B0,
                0x7600B0,
                0x4100B0,
                0x003EB0,
                0x0074B0,
                0x009BB0,
                0x00B07B,
                0x00B019,
                0x51B000,
                0x98B000,
                0xB08B00,
                0xB05800,

                0x818181,
                0x0096FF,
                0xE91E63,
                0xFF00E1,
                0xAB00FF,
                0x6100FF,
                0x0051FF,
                0x00BCFF,
                0x00E4FF,
                0x00FFAE,
                0x00FF79,
                0x00FF31,
                0x8FFF00,
                0xE2FF00,
                0xE2FF00,
                0xFFC900,
                0xFF8000,
                0xB00082,
                0xA700B0,
                0x7600B0,
                0x4100B0,
                0x003EB0,
                0x0074B0,
                0x009BB0,
                0x00B07B,
                0x00B019,
                0x51B000,
                0x98B000,
                0xB08B00,
                0xB05800,

                0x818181,
                0x0096FF,
                0xE91E63,
                0xFF00E1,
                0xAB00FF,
                0x6100FF,
                0x0051FF,
                0x00BCFF,
                0x00E4FF,
                0x00FFAE,
                0x00FF79,
                0x00FF31,
                0x8FFF00,
                0xE2FF00,
                0xE2FF00,
                0xFFC900,
                0xFF8000,
                0xB00082,
                0xA700B0,
                0x7600B0,
                0x4100B0,
                0x003EB0,
                0x0074B0,
                0x009BB0,
                0x00B07B,
                0x00B019,
                0x51B000,
                0x98B000,
                0xB08B00,
                0xB05800,

                0x818181,
                0x0096FF,
                0xE91E63,
                0xFF00E1,
                0xAB00FF,
                0x6100FF,
                0x0051FF,
                0x00BCFF,
                0x00E4FF,
                0x00FFAE,
                0x00FF79,
                0x00FF31,
                0x8FFF00,
                0xE2FF00,
                0xE2FF00,
                0xFFC900,
                0xFF8000,
                0xB00082,
                0xA700B0,
                0x7600B0,
                0x4100B0,
                0x003EB0,
                0x0074B0,
                0x009BB0,
                0x00B07B,
                0x00B019,
                0x51B000,
                0x98B000,
                0xB08B00,
                0xB05800,

                0x818181,
                0x0096FF,
                0xE91E63,
                0xFF00E1,
                0xAB00FF,
                0x6100FF,
                0x0051FF,
                0x00BCFF,
                0x00E4FF,
                0x00FFAE,
                0x00FF79,
                0x00FF31,
                0x8FFF00,
                0xE2FF00,
                0xE2FF00,
                0xFFC900,
                0xFF8000,
                0xB00082,
                0xA700B0,
                0x7600B0,
                0x4100B0,
                0x003EB0,
                0x0074B0,
                0x009BB0,
                0x00B07B,
                0x00B019,
                0x51B000,
                0x98B000,
                0xB08B00,
                0xB05800,

                0x818181,
                0x0096FF,
                0xE91E63,
                0xFF00E1,
                0xAB00FF,
                0x6100FF,
                0x0051FF,
                0x00BCFF,
                0x00E4FF,
                0x00FFAE,
                0x00FF79,
                0x00FF31,
                0x8FFF00,
                0xE2FF00,
                0xE2FF00,
                0xFFC900,
                0xFF8000,
                0xB00082,
                0xA700B0,
                0x7600B0,
                0x4100B0,
                0x003EB0,
                0x0074B0,
                0x009BB0,
                0x00B07B,
                0x00B019,
                0x51B000,
                0x98B000,
                0xB08B00,
                0xB05800,

                0x818181,
                0x0096FF,
                0xE91E63,
                0xFF00E1,
                0xAB00FF,
                0x6100FF,
                0x0051FF,
                0x00BCFF,
                0x00E4FF,
                0x00FFAE,
                0x00FF79,
                0x00FF31,
                0x8FFF00,
                0xE2FF00,
                0xE2FF00,
                0xFFC900,
                0xFF8000,
                0xB00082,
                0xA700B0,
                0x7600B0,
                0x4100B0,
                0x003EB0,
                0x0074B0,
                0x009BB0,
                0x00B07B,
                0x00B019,
                0x51B000,
                0x98B000,
                0xB08B00,
                0xB05800,

                0x818181,
                0x0096FF,
                0xE91E63,
                0xFF00E1,
                0xAB00FF,
                0x6100FF,
                0x0051FF,
                0x00BCFF,
                0x00E4FF,
                0x00FFAE,
                0x00FF79,
                0x00FF31,
                0x8FFF00,
                0xE2FF00,
                0xE2FF00,
                0xFFC900,
                0xFF8000,
                0xB00082,
                0xA700B0,
                0x7600B0,
                0x4100B0,
                0x003EB0,
                0x0074B0,
                0x009BB0,
                0x00B07B,
                0x00B019,
                0x51B000,
                0x98B000,
                0xB08B00,
                0xB05800,

                0x818181,
                0x0096FF,
                0xE91E63,
                0xFF00E1,
                0xAB00FF,
                0x6100FF,
                0x0051FF,
                0x00BCFF,
                0x00E4FF,
                0x00FFAE,
                0x00FF79,
                0x00FF31,
                0x8FFF00,
                0xE2FF00,
                0xE2FF00,
                0xFFC900,
                0xFF8000,
                0xB00082,
                0xA700B0,
                0x7600B0,
                0x4100B0,
                0x003EB0,
                0x0074B0,
                0x009BB0,
                0x00B07B,
                0x00B019,
                0x51B000,
                0x98B000,
                0xB08B00,
                0xB05800,

                0x818181,
                0x0096FF,
                0xE91E63,
                0xFF00E1,
                0xAB00FF,
                0x6100FF,
                0x0051FF,
                0x00BCFF,
                0x00E4FF,
                0x00FFAE,
                0x00FF79,
                0x00FF31,
                0x8FFF00,
                0xE2FF00,
                0xE2FF00,
                0xFFC900,
                0xFF8000,
                0xB00082,
                0xA700B0,
                0x7600B0,
                0x4100B0,
                0x003EB0,
                0x0074B0,
                0x009BB0,
                0x00B07B,
                0x00B019,
                0x51B000,
                0x98B000,
                0xB08B00,
                0xB05800,

                0x818181,
                0x0096FF,
                0xE91E63,
                0xFF00E1,
                0xAB00FF,
                0x6100FF,
                0x0051FF,
                0x00BCFF,
                0x00E4FF,
                0x00FFAE,
                0x00FF79,
                0x00FF31,
                0x8FFF00,
                0xE2FF00,
                0xE2FF00,
                0xFFC900,
                0xFF8000,
                0xB00082,
                0xA700B0,
                0x7600B0,
                0x4100B0,
                0x003EB0,
                0x0074B0,
                0x009BB0,
                0x00B07B,
                0x00B019,
                0x51B000,
                0x98B000,
                0xB08B00,
                0xB05800,

                0x818181,
                0x0096FF,
                0xE91E63,
                0xFF00E1,
                0xAB00FF,
                0x6100FF,
                0x0051FF,
                0x00BCFF,
                0x00E4FF,
                0x00FFAE,
                0x00FF79,
                0x00FF31,
                0x8FFF00,
                0xE2FF00,
                0xE2FF00,
                0xFFC900,
                0xFF8000,
                0xB00082,
                0xA700B0,
                0x7600B0,
                0x4100B0,
                0x003EB0,
                0x0074B0,
                0x009BB0,
                0x00B07B,
                0x00B019,
                0x51B000,
                0x98B000,
                0xB08B00,
                0xB05800,

                0x818181,
                0x0096FF,
                0xE91E63,
                0xFF00E1,
                0xAB00FF,
                0x6100FF,
                0x0051FF,
                0x00BCFF,
                0x00E4FF,
                0x00FFAE,
                0x00FF79,
                0x00FF31,
                0x8FFF00,
                0xE2FF00,
                0xE2FF00,
                0xFFC900,
                0xFF8000,
                0xB00082,
                0xA700B0,
                0x7600B0,
                0x4100B0,
                0x003EB0,
                0x0074B0,
                0x009BB0,
                0x00B07B,
                0x00B019,
                0x51B000,
                0x98B000,
                0xB08B00,
                0xB05800,

                0x818181,
                0x0096FF,
                0xE91E63,
                0xFF00E1,
                0xAB00FF,
                0x6100FF,
                0x0051FF,
                0x00BCFF,
                0x00E4FF,
                0x00FFAE,
                0x00FF79,
                0x00FF31,
                0x8FFF00,
                0xE2FF00,
                0xE2FF00,
                0xFFC900,
                0xFF8000,
                0xB00082,
                0xA700B0,
                0x7600B0,
                0x4100B0,
                0x003EB0,
                0x0074B0,
                0x009BB0,
                0x00B07B,
                0x00B019,
                0x51B000,
                0x98B000,
                0xB08B00,
                0xB05800,

                0x818181,
                0x0096FF,
                0xE91E63,
                0xFF00E1,
                0xAB00FF,
                0x6100FF,
                0x0051FF,
                0x00BCFF,
                0x00E4FF,
                0x00FFAE,
                0x00FF79,
                0x00FF31,
                0x8FFF00,
                0xE2FF00,
                0xE2FF00,
                0xFFC900,
                0xFF8000,
                0xB00082,
                0xA700B0,
                0x7600B0,
                0x4100B0,
                0x003EB0,
                0x0074B0,
                0x009BB0,
                0x00B07B,
                0x00B019,
                0x51B000,
                0x98B000,
                0xB08B00,
                0xB05800,

                0x818181,
                0x0096FF,
                0xE91E63,
                0xFF00E1,
                0xAB00FF,
                0x6100FF,
                0x0051FF,
                0x00BCFF,
                0x00E4FF,
                0x00FFAE,
                0x00FF79,
                0x00FF31,
                0x8FFF00,
                0xE2FF00,
                0xE2FF00,
                0xFFC900,
                0xFF8000,
                0xB00082,
                0xA700B0,
                0x7600B0,
                0x4100B0,
                0x003EB0,
                0x0074B0,
                0x009BB0,
                0x00B07B,
                0x00B019,
                0x51B000,
                0x98B000,
                0xB08B00,
                0xB05800,

                0x818181,
                0x0096FF,
                0xE91E63,
                0xFF00E1,
                0xAB00FF,
                0x6100FF,
                0x0051FF,
                0x00BCFF,
                0x00E4FF,
                0x00FFAE,
                0x00FF79,
                0x00FF31,
                0x8FFF00,
                0xE2FF00,
                0xE2FF00,
                0xFFC900,
                0xFF8000,
                0xB00082,
                0xA700B0,
                0x7600B0,
                0x4100B0,
                0x003EB0,
                0x0074B0,
                0x009BB0,
                0x00B07B,
                0x00B019,
                0x51B000,
                0x98B000,
                0xB08B00,
                0xB05800,

                0x818181,
                0x0096FF,
                0xE91E63,
                0xFF00E1,
                0xAB00FF,
                0x6100FF,
                0x0051FF,
                0x00BCFF,
                0x00E4FF,
                0x00FFAE,
                0x00FF79,
                0x00FF31,
                0x8FFF00,
                0xE2FF00,
                0xE2FF00,
                0xFFC900,
                0xFF8000,
                0xB00082,
                0xA700B0,
                0x7600B0,
                0x4100B0,
                0x003EB0,
                0x0074B0,
                0x009BB0,
                0x00B07B,
                0x00B019,
                0x51B000,
                0x98B000,
                0xB08B00,
                0xB05800

        };
long GetRandomColorByIndexBack(int index) {
    srand(index);

    int a = 250;
    int r = ((ColorsBack[rand() % sizeof(ColorsBack)] & 0xFF0000) >> 16);
    int g = ((ColorsBack[rand() % sizeof(ColorsBack)] & 0x00FF00) >> 8);
    int b = (ColorsBack[rand() % sizeof(ColorsBack)] & 0x0000FF);

    return IM_COL32(r, g, b, a);
}
long GetRandomColorByIndexAlpa(int index) {
    srand(index);

    int a = 220;
    int r = ((ColorsBack[rand() % sizeof(ColorsBack)] & 0xFF0000) >> 16);
    int g = ((ColorsBack[rand() % sizeof(ColorsBack)] & 0x00FF00) >> 8);
    int b = (ColorsBack[rand() % sizeof(ColorsBack)] & 0x0000FF);

    return IM_COL32(r, g, b, a);
}

long GetRandomColorByIndexLine(int index) {
    srand(index);

    int a = 255;
    int r = ((ColorsBack[rand() % sizeof(ColorsBack)] & 0xFF0000) >> 16);
    int g = ((ColorsBack[rand() % sizeof(ColorsBack)] & 0x00FF00) >> 8);
    int b = (ColorsBack[rand() % sizeof(ColorsBack)] & 0x0000FF);

    return IM_COL32(r, g, b, a);
}

int GetTeamIDColor(int TeamID) {
    int clrID;
    if (TeamID == 0) {
        clrID = IM_COL32(243, 0, 255, 255);
    } else if (TeamID == 1) {
        clrID = IM_COL32(243, 0, 255, 255);
    } else if (TeamID == 2) {
        clrID = IM_COL32(170, 0, 255, 255);
    } else if (TeamID == 3) {
        clrID = IM_COL32(243, 0, 255, 255);
    } else if (TeamID == 4) {
        clrID = IM_COL32(128, 255, 0, 255);
    } else if (TeamID == 5) {
        clrID = IM_COL32(255, 0, 255, 255);
    } else if (TeamID == 6) {
        clrID = IM_COL32(160, 13, 13, 255);
    } else if (TeamID == 7) {
        clrID = IM_COL32(255, 255, 255, 255);
    } else if (TeamID == 8) {
        clrID = IM_COL32(102, 102, 255, 255);
    } else if (TeamID == 9) {
        clrID = IM_COL32(153, 255, 255, 255);
    } else if (TeamID == 10) {
        clrID = IM_COL32(102, 255, 255, 255);
    } else if (TeamID == 11) {
        clrID = IM_COL32(255, 128, 0, 255);
    } else if (TeamID == 12) {
        clrID = IM_COL32(255, 0, 0, 255);
    } else if (TeamID == 13) {
        clrID = IM_COL32(0, 0, 255, 255);
    } else if (TeamID == 14) {
        clrID = IM_COL32(128, 255, 0, 255);
    } else if (TeamID == 15) {
        clrID = IM_COL32(255, 0, 255, 255);
    } else if (TeamID == 16) {
        clrID = IM_COL32(160, 13, 13, 255);
    } else if (TeamID == 17) {
        clrID = IM_COL32(255, 255, 255, 255);
    } else if (TeamID == 18) {
        clrID = IM_COL32(102, 102, 255, 255);
    } else if (TeamID == 19) {
        clrID = IM_COL32(153, 255, 255, 255);
    } else if (TeamID == 20) {
        clrID = IM_COL32(102, 255, 255, 255);
    } else if (TeamID == 21) {
        clrID = IM_COL32(255, 128, 0, 255);
    } else if (TeamID == 22) {
        clrID = IM_COL32(255, 0, 0, 255);
    } else if (TeamID == 23) {
        clrID = IM_COL32(0, 0, 255, 255);
    } else if (TeamID == 24) {
        clrID = IM_COL32(128, 255, 0, 255);
    } else if (TeamID == 25) {
        clrID = IM_COL32(255, 0, 255, 255);
    } else if (TeamID == 26) {
        clrID = IM_COL32(160, 13, 13, 255);
    } else if (TeamID == 27) {
        clrID = IM_COL32(255, 255, 255, 255);
    } else if (TeamID == 28) {
        clrID = IM_COL32(102, 102, 255, 255);
    } else if (TeamID == 29) {
        clrID = IM_COL32(153, 255, 255, 255);
    } else if (TeamID == 30) {
        clrID = IM_COL32(102, 255, 255, 255);
    } else if (TeamID == 31) {
        clrID = IM_COL32(255, 128, 0, 255);
    } else if (TeamID == 32) {
        clrID = IM_COL32(255, 0, 0, 255);
    } else if (TeamID == 33) {
        clrID = IM_COL32(0, 0, 255, 255);
    } else if (TeamID == 34) {
        clrID = IM_COL32(128, 255, 0, 255);
    } else if (TeamID == 35) {
        clrID = IM_COL32(255, 0, 255, 255);
    } else if (TeamID == 36) {
        clrID = IM_COL32(160, 13, 13, 255);
    } else if (TeamID == 37) {
        clrID = IM_COL32(255, 255, 255, 255);
    } else if (TeamID == 38) {
        clrID = IM_COL32(102, 102, 255, 255);
    } else if (TeamID == 39) {
        clrID = IM_COL32(153, 255, 255, 255);
    } else if (TeamID == 40) {
        clrID = IM_COL32(102, 255, 255, 255);
    } else if (TeamID == 41) {
        clrID = IM_COL32(255, 128, 0, 255);
    } else if (TeamID == 42) {
        clrID = IM_COL32(255, 0, 0, 255);
    } else if (TeamID == 43) {
        clrID = IM_COL32(0, 0, 255, 255);
    } else if (TeamID == 44) {
        clrID = IM_COL32(128, 255, 0, 255);
    } else if (TeamID == 45) {
        clrID = IM_COL32(255, 0, 255, 255);
    } else if (TeamID == 46) {
        clrID = IM_COL32(160, 13, 13, 255);
    } else if (TeamID == 47) {
        clrID = IM_COL32(255, 255, 255, 255);
    } else if (TeamID == 48) {
        clrID = IM_COL32(102, 102, 255, 255);
    } else if (TeamID == 49) {
        clrID = IM_COL32(153, 255, 255, 255);
    } else if (TeamID == 50) {
        clrID = IM_COL32(102, 255, 255, 255);
    } else if (TeamID == 51) {
        clrID = IM_COL32(255, 128, 0, 255);
    } else if (TeamID == 52) {
        clrID = IM_COL32(255, 0, 0, 255);
    } else if (TeamID == 53) {
        clrID = IM_COL32(0, 0, 255, 255);
    } else if (TeamID == 54) {
        clrID = IM_COL32(128, 255, 0, 255);
    } else if (TeamID == 55) {
        clrID = IM_COL32(255, 0, 255, 255);
    } else if (TeamID == 56) {
        clrID = IM_COL32(160, 13, 13, 255);
    } else if (TeamID == 57) {
        clrID = IM_COL32(255, 255, 255, 255);
    } else if (TeamID == 58) {
        clrID = IM_COL32(102, 102, 255, 255);
    } else if (TeamID == 59) {
        clrID = IM_COL32(153, 255, 255, 255);
    } else if (TeamID == 60) {
        clrID = IM_COL32(102, 255, 255, 255);
    } else if (TeamID == 61) {
        clrID = IM_COL32(255, 128, 0, 255);
    } else if (TeamID == 62) {
        clrID = IM_COL32(255, 0, 0, 255);
    } else if (TeamID == 63) {
        clrID = IM_COL32(0, 0, 255, 255);
    } else if (TeamID == 64) {
        clrID = IM_COL32(128, 255, 0, 255);
    } else if (TeamID == 65) {
        clrID = IM_COL32(255, 0, 255, 255);
    } else if (TeamID == 66) {
        clrID = IM_COL32(160, 13, 13, 255);
    } else if (TeamID == 67) {
        clrID = IM_COL32(255, 255, 255, 255);
    } else if (TeamID == 68) {
        clrID = IM_COL32(102, 102, 255, 255);
    } else if (TeamID == 69) {
        clrID = IM_COL32(153, 255, 255, 255);
    } else if (TeamID == 70) {
        clrID = IM_COL32(102, 255, 255, 255);
    } else if (TeamID == 71) {
        clrID = IM_COL32(255, 128, 0, 255);
    } else if (TeamID == 72) {
        clrID = IM_COL32(255, 0, 0, 255);
    } else if (TeamID == 73) {
        clrID = IM_COL32(0, 0, 255, 255);
    } else if (TeamID == 74) {
        clrID = IM_COL32(128, 255, 0, 255);
    } else if (TeamID == 75) {
        clrID = IM_COL32(255, 0, 255, 255);
    } else if (TeamID == 76) {
        clrID = IM_COL32(160, 13, 13, 255);
    } else if (TeamID == 77) {
        clrID = IM_COL32(255, 255, 255, 255);
    } else if (TeamID == 78) {
        clrID = IM_COL32(102, 102, 255, 255);
    } else if (TeamID == 79) {
        clrID = IM_COL32(153, 255, 255, 255);
    } else if (TeamID == 80) {
        clrID = IM_COL32(102, 255, 255, 255);
    } else if (TeamID == 81) {
        clrID = IM_COL32(255, 128, 0, 255);
    } else if (TeamID == 82) {
        clrID = IM_COL32(255, 0, 0, 255);
    } else if (TeamID == 83) {
        clrID = IM_COL32(0, 0, 255, 255);
    } else if (TeamID == 84) {
        clrID = IM_COL32(128, 255, 0, 255);
    } else if (TeamID == 85) {
        clrID = IM_COL32(255, 0, 255, 255);
    } else if (TeamID == 86) {
        clrID = IM_COL32(160, 13, 13, 255);
    } else if (TeamID == 87) {
        clrID = IM_COL32(255, 255, 255, 255);
    } else if (TeamID == 88) {
        clrID = IM_COL32(102, 102, 255, 255);
    } else if (TeamID == 89) {
        clrID = IM_COL32(153, 255, 255, 255);
    } else if (TeamID == 90) {
        clrID = IM_COL32(102, 255, 255, 255);
    } else if (TeamID == 91) {
        clrID = IM_COL32(255, 128, 0, 255);
    } else if (TeamID == 92) {
        clrID = IM_COL32(255, 0, 0, 255);
    } else if (TeamID == 93) {
        clrID = IM_COL32(0, 0, 255, 255);
    } else if (TeamID == 94) {
        clrID = IM_COL32(128, 255, 0, 255);
    } else if (TeamID == 95) {
        clrID = IM_COL32(255, 0, 255, 255);
    } else if (TeamID == 96) {
        clrID = IM_COL32(160, 13, 13, 255);
    } else if (TeamID == 97) {
        clrID = IM_COL32(255, 255, 255, 255);
    } else if (TeamID == 98) {
        clrID = IM_COL32(102, 102, 255, 255);
    } else if (TeamID == 99) {
        clrID = IM_COL32(153, 255, 255, 255);
    } else if (TeamID == 100) {
        clrID = IM_COL32(102, 255, 255, 255);
    } else if (TeamID == 101) {
        clrID = IM_COL32(255, 128, 0, 255);
    } else if (TeamID == 102) {
        clrID = IM_COL32(255, 0, 0, 255);
    } else if (TeamID == 103) {
        clrID = IM_COL32(0, 0, 255, 255);
    } else if (TeamID == 104) {
        clrID = IM_COL32(128, 255, 0, 255);
    } else if (TeamID == 105) {
        clrID = IM_COL32(255, 0, 255, 255);
    } else if (TeamID == 106) {
        clrID = IM_COL32(160, 13, 13, 255);
    } else if (TeamID == 107) {
        clrID = IM_COL32(255, 255, 255, 255);
    } else if (TeamID == 108) {
        clrID = IM_COL32(102, 102, 255, 255);
    } else if (TeamID == 109) {
        clrID = IM_COL32(153, 255, 255, 255);
    } else if (TeamID == 110) {
        clrID = IM_COL32(102, 255, 255, 255);
    } else if (TeamID == 111) {
        clrID = IM_COL32(255, 128, 0, 255);
    } else if (TeamID == 112) {
        clrID = IM_COL32(255, 0, 0, 255);
    } else if (TeamID == 113) {
        clrID = IM_COL32(0, 0, 255, 255);
    } else if (TeamID == 114) {
        clrID = IM_COL32(128, 255, 0, 255);
    } else if (TeamID == 115) {
        clrID = IM_COL32(255, 0, 255, 255);
    } else if (TeamID == 116) {
        clrID = IM_COL32(160, 13, 13, 255);
    } else if (TeamID == 117) {
        clrID = IM_COL32(255, 255, 255, 255);
    } else if (TeamID == 118) {
        clrID = IM_COL32(102, 102, 255, 255);
    } else if (TeamID == 119) {
        clrID = IM_COL32(153, 255, 255, 255);
    } else if (TeamID == 120) {
        clrID = IM_COL32(102, 255, 255, 255);
    } else if (TeamID == 121) {
        clrID = IM_COL32(255, 128, 0, 255);
    } else if (TeamID == 122) {
        clrID = IM_COL32(255, 0, 0, 255);
    } else if (TeamID == 123) {
        clrID = IM_COL32(0, 0, 255, 255);
    } else if (TeamID == 124) {
        clrID = IM_COL32(128, 255, 0, 255);
    } else if (TeamID == 125) {
        clrID = IM_COL32(255, 0, 255, 255);
    } else if (TeamID == 126) {
        clrID = IM_COL32(160, 13, 13, 255);
    } else if (TeamID == 127) {
        clrID = IM_COL32(255, 255, 255, 255);
    } else if (TeamID == 128) {
        clrID = IM_COL32(102, 102, 255, 255);
    } else if (TeamID == 129) {
        clrID = IM_COL32(153, 255, 255, 255);
    } else if (TeamID == 130) {
        clrID = IM_COL32(102, 255, 255, 255);
    } else if (TeamID == 131) {
        clrID = IM_COL32(255, 128, 0, 255);
    } else if (TeamID == 132) {
        clrID = IM_COL32(255, 0, 0, 255);
    } else if (TeamID == 133) {
        clrID = IM_COL32(0, 0, 255, 255);
    } else if (TeamID == 134) {
        clrID = IM_COL32(128, 255, 0, 255);
    } else if (TeamID == 135) {
        clrID = IM_COL32(255, 0, 255, 255);
    } else if (TeamID == 136) {
        clrID = IM_COL32(160, 13, 13, 255);
    } else if (TeamID == 137) {
        clrID = IM_COL32(255, 255, 255, 255);
    } else if (TeamID == 138) {
        clrID = IM_COL32(102, 102, 255, 255);
    } else if (TeamID == 139) {
        clrID = IM_COL32(153, 255, 255, 255);
    } else if (TeamID == 140) {
        clrID = IM_COL32(102, 255, 255, 255);
    } else if (TeamID == 141) {
        clrID = IM_COL32(255, 128, 0, 255);
    } else if (TeamID == 142) {
        clrID = IM_COL32(255, 0, 0, 255);
    } else if (TeamID == 143) {
        clrID = IM_COL32(0, 0, 255, 255);
    } else if (TeamID == 144) {
        clrID = IM_COL32(128, 255, 0, 255);
    } else if (TeamID == 145) {
        clrID = IM_COL32(255, 0, 255, 255);
    } else if (TeamID == 146) {
        clrID = IM_COL32(160, 13, 13, 255);
    } else if (TeamID == 147) {
        clrID = IM_COL32(255, 255, 255, 255);
    } else if (TeamID == 148) {
        clrID = IM_COL32(102, 102, 255, 255);
    } else if (TeamID == 149) {
        clrID = IM_COL32(153, 255, 255, 255);
    } else if (TeamID == 150) {
        clrID = IM_COL32(102, 255, 255, 255);
    } else if (TeamID == 151) {
        clrID = IM_COL32(255, 128, 0, 255);
    } else if (TeamID == 152) {
        clrID = IM_COL32(255, 0, 0, 255);
    } else if (TeamID == 153) {
        clrID = IM_COL32(0, 0, 255, 255);
    } else if (TeamID == 154) {
        clrID = IM_COL32(128, 255, 0, 255);
    } else if (TeamID == 155) {
        clrID = IM_COL32(255, 0, 255, 255);
    } else if (TeamID == 156) {
        clrID = IM_COL32(160, 13, 13, 255);
    } else if (TeamID == 157) {
        clrID = IM_COL32(255, 255, 255, 255);
    } else if (TeamID == 158) {
        clrID = IM_COL32(102, 102, 255, 255);
    } else if (TeamID == 159) {
        clrID = IM_COL32(153, 255, 255, 255);
    } else if (TeamID == 160) {
        clrID = IM_COL32(102, 255, 255, 255);
    } else if (TeamID == 161) {
        clrID = IM_COL32(255, 128, 0, 255);
    } else if (TeamID == 162) {
        clrID = IM_COL32(255, 0, 0, 255);
    } else if (TeamID == 163) {
        clrID = IM_COL32(0, 0, 255, 255);
    } else if (TeamID == 164) {
        clrID = IM_COL32(128, 255, 0, 255);
    } else if (TeamID == 165) {
        clrID = IM_COL32(255, 0, 255, 255);
    } else if (TeamID == 166) {
        clrID = IM_COL32(160, 13, 13, 255);
    } else if (TeamID == 167) {
        clrID = IM_COL32(255, 255, 255, 255);
    } else if (TeamID == 168) {
        clrID = IM_COL32(102, 102, 255, 255);
    } else if (TeamID == 169) {
        clrID = IM_COL32(153, 255, 255, 255);
    } else if (TeamID == 170) {
        clrID = IM_COL32(102, 255, 255, 255);
    } else if (TeamID == 171) {
        clrID = IM_COL32(255, 128, 0, 255);
    } else if (TeamID == 172) {
        clrID = IM_COL32(255, 0, 0, 255);
    } else if (TeamID == 173) {
        clrID = IM_COL32(0, 0, 255, 255);
    } else if (TeamID == 174) {
        clrID = IM_COL32(128, 255, 0, 255);
    } else if (TeamID == 175) {
        clrID = IM_COL32(255, 0, 255, 255);
    } else if (TeamID == 176) {
        clrID = IM_COL32(160, 13, 13, 255);
    } else if (TeamID == 177) {
        clrID = IM_COL32(255, 255, 255, 255);
    } else if (TeamID == 178) {
        clrID = IM_COL32(102, 102, 255, 255);
    } else if (TeamID == 179) {
        clrID = IM_COL32(153, 255, 255, 255);
    } else if (TeamID == 180) {
        clrID = IM_COL32(102, 255, 255, 255);
    } else if (TeamID == 181) {
        clrID = IM_COL32(255, 128, 0, 255);
    } else if (TeamID == 182) {
        clrID = IM_COL32(255, 0, 0, 255);
    } else if (TeamID == 183) {
        clrID = IM_COL32(0, 0, 255, 255);
    } else if (TeamID == 184) {
        clrID = IM_COL32(128, 255, 0, 255);
    } else if (TeamID == 185) {
        clrID = IM_COL32(255, 0, 255, 255);
    } else if (TeamID == 186) {
        clrID = IM_COL32(160, 13, 13, 255);
    } else if (TeamID == 187) {
        clrID = IM_COL32(255, 255, 255, 255);
    } else if (TeamID == 188) {
        clrID = IM_COL32(102, 102, 255, 255);
    } else if (TeamID == 189) {
        clrID = IM_COL32(153, 255, 255, 255);
    } else if (TeamID == 190) {
        clrID = IM_COL32(102, 255, 255, 255);
    } else if (TeamID == 191) {
        clrID = IM_COL32(255, 128, 0, 255);
    } else if (TeamID == 192) {
        clrID = IM_COL32(255, 0, 0, 255);
    } else if (TeamID == 193) {
        clrID = IM_COL32(0, 0, 255, 255);
    } else if (TeamID == 194) {
        clrID = IM_COL32(128, 255, 0, 255);
    } else if (TeamID == 195) {
        clrID = IM_COL32(255, 0, 255, 255);
    } else if (TeamID == 196) {
        clrID = IM_COL32(160, 13, 13, 255);
    } else if (TeamID == 197) {
        clrID = IM_COL32(255, 255, 255, 255);
    } else if (TeamID == 198) {
        clrID = IM_COL32(102, 102, 255, 255);
    } else if (TeamID == 199) {
        clrID = IM_COL32(153, 255, 255, 255);
    } else if (TeamID == 200) {
        clrID = IM_COL32(102, 255, 255, 255);
    } else if (TeamID == 201) {
        clrID = IM_COL32(255, 128, 0, 255);
    } else if (TeamID == 202) {
        clrID = IM_COL32(255, 0, 0, 255);
    } else if (TeamID == 203) {
        clrID = IM_COL32(0, 0, 255, 255);
    } else if (TeamID == 204) {
        clrID = IM_COL32(128, 255, 0, 255);
    } else if (TeamID == 205) {
        clrID = IM_COL32(255, 0, 255, 255);
    } else if (TeamID == 206) {
        clrID = IM_COL32(160, 13, 13, 255);
    } else if (TeamID == 207) {
        clrID = IM_COL32(255, 255, 255, 255);
    } else if (TeamID == 208) {
        clrID = IM_COL32(102, 102, 255, 255);
    } else if (TeamID == 209) {
        clrID = IM_COL32(153, 255, 255, 255);
    } else if (TeamID == 210) {
        clrID = IM_COL32(102, 255, 255, 255);
    } else if (TeamID == 211) {
        clrID = IM_COL32(255, 128, 0, 255);
    } else if (TeamID == 212) {
        clrID = IM_COL32(255, 0, 0, 255);
    } else if (TeamID == 213) {
        clrID = IM_COL32(0, 0, 255, 255);
    } else if (TeamID == 214) {
        clrID = IM_COL32(128, 255, 0, 255);
    } else if (TeamID == 215) {
        clrID = IM_COL32(255, 0, 255, 255);
    } else if (TeamID == 216) {
        clrID = IM_COL32(160, 13, 13, 255);
    } else if (TeamID == 217) {
        clrID = IM_COL32(255, 255, 255, 255);
    } else if (TeamID == 218) {
        clrID = IM_COL32(102, 102, 255, 255);
    } else if (TeamID == 219) {
        clrID = IM_COL32(153, 255, 255, 255);
    } else if (TeamID == 220) {
        clrID = IM_COL32(102, 255, 255, 255);
    } else if (TeamID == 221) {
        clrID = IM_COL32(255, 128, 0, 255);
    } else if (TeamID == 222) {
        clrID = IM_COL32(255, 0, 0, 255);
    } else if (TeamID == 223) {
        clrID = IM_COL32(0, 0, 255, 255);
    } else if (TeamID == 224) {
        clrID = IM_COL32(128, 255, 0, 255);
    } else if (TeamID == 225) {
        clrID = IM_COL32(255, 0, 255, 255);
    } else if (TeamID == 226) {
        clrID = IM_COL32(160, 13, 13, 255);
    } else if (TeamID == 227) {
        clrID = IM_COL32(255, 255, 255, 255);
    } else if (TeamID == 228) {
        clrID = IM_COL32(102, 102, 255, 255);
    } else if (TeamID == 229) {
        clrID = IM_COL32(153, 255, 255, 255);
    } else if (TeamID == 230) {
        clrID = IM_COL32(102, 255, 255, 255);
    } else if (TeamID == 231) {
        clrID = IM_COL32(255, 128, 0, 255);
    } else if (TeamID == 232) {
        clrID = IM_COL32(255, 0, 0, 255);
    } else if (TeamID == 233) {
        clrID = IM_COL32(0, 0, 255, 255);
    } else if (TeamID == 234) {
        clrID = IM_COL32(128, 255, 0, 255);
    } else if (TeamID == 235) {
        clrID = IM_COL32(255, 0, 255, 255);
    } else if (TeamID == 236) {
        clrID = IM_COL32(160, 13, 13, 255);
    } else if (TeamID == 237) {
        clrID = IM_COL32(255, 255, 255, 255);
    } else if (TeamID == 238) {
        clrID = IM_COL32(102, 102, 255, 255);
    } else if (TeamID == 239) {
        clrID = IM_COL32(153, 255, 255, 255);
    } else if (TeamID == 240) {
        clrID = IM_COL32(102, 255, 255, 255);
    } else if (TeamID == 241) {
        clrID = IM_COL32(255, 128, 0, 255);
    } else if (TeamID == 242) {
        clrID = IM_COL32(255, 0, 0, 255);
    } else if (TeamID == 243) {
        clrID = IM_COL32(0, 0, 255, 255);
    } else if (TeamID == 244) {
        clrID = IM_COL32(128, 255, 0, 255);
    } else if (TeamID == 245) {
        clrID = IM_COL32(255, 0, 255, 255);
    } else if (TeamID == 246) {
        clrID = IM_COL32(160, 13, 13, 255);
    } else if (TeamID == 247) {
        clrID = IM_COL32(255, 255, 255, 255);
    } else if (TeamID == 248) {
        clrID = IM_COL32(102, 102, 255, 255);
    } else if (TeamID == 249) {
        clrID = IM_COL32(153, 255, 255, 255);
    } else if (TeamID == 250) {
        clrID = IM_COL32(102, 255, 255, 255);
    } else if (TeamID == 251) {
        clrID = IM_COL32(255, 128, 0, 255);
    } else if (TeamID == 252) {
        clrID = IM_COL32(255, 0, 0, 255);
    } else if (TeamID == 253) {
        clrID = IM_COL32(0, 0, 255, 255);
    } else if (TeamID == 254) {
        clrID = IM_COL32(128, 255, 0, 255);
    } else if (TeamID == 255) {
        clrID = IM_COL32(255, 0, 255, 255);
    } else if (TeamID == 256) {
        clrID = IM_COL32(160, 13, 13, 255);
    } else if (TeamID == 257) {
        clrID = IM_COL32(255, 255, 255, 255);
    } else if (TeamID == 258) {
        clrID = IM_COL32(102, 102, 255, 255);
    } else if (TeamID == 259) {
        clrID = IM_COL32(153, 255, 255, 255);
    } else if (TeamID == 260) {
        clrID = IM_COL32(102, 255, 255, 255);
    } else if (TeamID == 261) {
        clrID = IM_COL32(255, 128, 0, 255);
    } else if (TeamID == 262) {
        clrID = IM_COL32(255, 0, 0, 255);
    } else if (TeamID == 263) {
        clrID = IM_COL32(0, 0, 255, 255);
    } else if (TeamID == 264) {
        clrID = IM_COL32(128, 255, 0, 255);
    } else if (TeamID == 265) {
        clrID = IM_COL32(255, 0, 255, 255);
    } else if (TeamID == 266) {
        clrID = IM_COL32(160, 13, 13, 255);
    } else if (TeamID == 267) {
        clrID = IM_COL32(255, 255, 255, 255);
    } else if (TeamID == 268) {
        clrID = IM_COL32(102, 102, 255, 255);
    } else if (TeamID == 269) {
        clrID = IM_COL32(153, 255, 255, 255);
    } else if (TeamID == 270) {
        clrID = IM_COL32(102, 255, 255, 255);
    } else if (TeamID == 271) {
        clrID = IM_COL32(255, 128, 0, 255);
    } else if (TeamID == 272) {
        clrID = IM_COL32(255, 0, 0, 255);
    } else if (TeamID == 273) {
        clrID = IM_COL32(0, 0, 255, 255);
    } else if (TeamID == 274) {
        clrID = IM_COL32(128, 255, 0, 255);
    } else if (TeamID == 275) {
        clrID = IM_COL32(255, 0, 255, 255);
    } else if (TeamID == 276) {
        clrID = IM_COL32(160, 13, 13, 255);
    } else if (TeamID == 277) {
        clrID = IM_COL32(255, 255, 255, 255);
    } else if (TeamID == 278) {
        clrID = IM_COL32(102, 102, 255, 255);
    } else if (TeamID == 279) {
        clrID = IM_COL32(153, 255, 255, 255);
    } else if (TeamID == 280) {
        clrID = IM_COL32(102, 255, 255, 255);
    } else if (TeamID == 281) {
        clrID = IM_COL32(255, 128, 0, 255);
    } else if (TeamID == 282) {
        clrID = IM_COL32(255, 0, 0, 255);
    } else if (TeamID == 283) {
        clrID = IM_COL32(0, 0, 255, 255);
    } else if (TeamID == 284) {
        clrID = IM_COL32(128, 255, 0, 255);
    } else if (TeamID == 285) {
        clrID = IM_COL32(255, 0, 255, 255);
    } else if (TeamID == 286) {
        clrID = IM_COL32(160, 13, 13, 255);
    } else if (TeamID == 287) {
        clrID = IM_COL32(255, 255, 255, 255);
    } else if (TeamID == 288) {
        clrID = IM_COL32(102, 102, 255, 255);
    } else if (TeamID == 289) {
        clrID = IM_COL32(153, 255, 255, 255);
    } else if (TeamID == 290) {
        clrID = IM_COL32(102, 255, 255, 255);
    } else if (TeamID == 291) {
        clrID = IM_COL32(255, 128, 0, 255);
    } else if (TeamID == 292) {
        clrID = IM_COL32(255, 0, 0, 255);
    } else if (TeamID == 293) {
        clrID = IM_COL32(0, 0, 255, 255);
    } else if (TeamID == 294) {
        clrID = IM_COL32(128, 255, 0, 255);
    } else if (TeamID == 295) {
        clrID = IM_COL32(255, 0, 255, 255);
    } else if (TeamID == 296) {
        clrID = IM_COL32(160, 13, 13, 255);
    } else if (TeamID == 297) {
        clrID = IM_COL32(255, 255, 255, 255);
    } else if (TeamID == 298) {
        clrID = IM_COL32(102, 102, 255, 255);
    } else if (TeamID == 299) {
        clrID = IM_COL32(153, 255, 255, 255);
    } else if (TeamID == 300) {
        clrID = IM_COL32(102, 255, 255, 255);
    } else if (TeamID == 301) {
        clrID = IM_COL32(255, 128, 0, 255);
    } else if (TeamID == 302) {
        clrID = IM_COL32(255, 0, 0, 255);
    } else if (TeamID == 303) {
        clrID = IM_COL32(0, 0, 255, 255);
    } else if (TeamID == 304) {
        clrID = IM_COL32(128, 255, 0, 255);
    } else if (TeamID == 305) {
        clrID = IM_COL32(255, 0, 255, 255);
    } else if (TeamID == 306) {
        clrID = IM_COL32(160, 13, 13, 255);
    } else if (TeamID == 307) {
        clrID = IM_COL32(255, 255, 255, 255);
    } else if (TeamID == 308) {
        clrID = IM_COL32(102, 102, 255, 255);
    } else if (TeamID == 309) {
        clrID = IM_COL32(153, 255, 255, 255);
    } else if (TeamID == 310) {
        clrID = IM_COL32(102, 255, 255, 255);
    } else if (TeamID == 311) {
        clrID = IM_COL32(255, 128, 0, 255);
    } else if (TeamID == 312) {
        clrID = IM_COL32(255, 0, 0, 255);
    } else if (TeamID == 313) {
        clrID = IM_COL32(0, 0, 255, 255);
    } else if (TeamID == 314) {
        clrID = IM_COL32(128, 255, 0, 255);
    } else if (TeamID == 315) {
        clrID = IM_COL32(255, 0, 255, 255);
    } else if (TeamID == 316) {
        clrID = IM_COL32(160, 13, 13, 255);
    } else if (TeamID == 317) {
        clrID = IM_COL32(255, 255, 255, 255);
    } else if (TeamID == 318) {
        clrID = IM_COL32(102, 102, 255, 255);
    } else if (TeamID == 319) {
        clrID = IM_COL32(153, 255, 255, 255);
    } else if (TeamID == 320) {
        clrID = IM_COL32(102, 255, 255, 255);
    } else if (TeamID == 321) {
        clrID = IM_COL32(255, 128, 0, 255);
    } else if (TeamID == 322) {
        clrID = IM_COL32(255, 0, 0, 255);
    } else if (TeamID == 323) {
        clrID = IM_COL32(0, 0, 255, 255);
    } else if (TeamID == 324) {
        clrID = IM_COL32(128, 255, 0, 255);
    } else if (TeamID == 325) {
        clrID = IM_COL32(255, 0, 255, 255);
    } else if (TeamID == 326) {
        clrID = IM_COL32(160, 13, 13, 255);
    } else if (TeamID == 327) {
        clrID = IM_COL32(255, 255, 255, 255);
    } else if (TeamID == 328) {
        clrID = IM_COL32(102, 102, 255, 255);
    } else if (TeamID == 329) {
        clrID = IM_COL32(153, 255, 255, 255);
    } else if (TeamID == 330) {
        clrID = IM_COL32(102, 255, 255, 255);
    } else if (TeamID == 331) {
        clrID = IM_COL32(255, 128, 0, 255);
    } else if (TeamID == 332) {
        clrID = IM_COL32(255, 0, 0, 255);
    } else if (TeamID == 333) {
        clrID = IM_COL32(0, 0, 255, 255);
    } else if (TeamID == 334) {
        clrID = IM_COL32(128, 255, 0, 255);
    } else if (TeamID == 335) {
        clrID = IM_COL32(255, 0, 255, 255);
    } else if (TeamID == 336) {
        clrID = IM_COL32(160, 13, 13, 255);
    } else if (TeamID == 337) {
        clrID = IM_COL32(255, 255, 255, 255);
    } else if (TeamID == 338) {
        clrID = IM_COL32(102, 102, 255, 255);
    } else if (TeamID == 339) {
        clrID = IM_COL32(153, 255, 255, 255);
    } else if (TeamID == 340) {
        clrID = IM_COL32(102, 255, 255, 255);
    } else if (TeamID == 341) {
        clrID = IM_COL32(255, 128, 0, 255);
    } else if (TeamID == 342) {
        clrID = IM_COL32(255, 0, 0, 255);
    } else if (TeamID == 343) {
        clrID = IM_COL32(0, 0, 255, 255);
    } else if (TeamID == 344) {
        clrID = IM_COL32(128, 255, 0, 255);
    } else if (TeamID == 345) {
        clrID = IM_COL32(255, 0, 255, 255);
    } else if (TeamID == 346) {
        clrID = IM_COL32(160, 13, 13, 255);
    } else if (TeamID == 347) {
        clrID = IM_COL32(255, 255, 255, 255);
    } else if (TeamID == 348) {
        clrID = IM_COL32(102, 102, 255, 255);
    } else if (TeamID == 349) {
        clrID = IM_COL32(153, 255, 255, 255);
    } else if (TeamID == 350) {
        clrID = IM_COL32(102, 255, 255, 255);
    } else if (TeamID == 351) {
        clrID = IM_COL32(255, 128, 0, 255);
    } else if (TeamID == 352) {
        clrID = IM_COL32(255, 0, 0, 255);
    } else if (TeamID == 353) {
        clrID = IM_COL32(0, 0, 255, 255);
    } else if (TeamID == 354) {
        clrID = IM_COL32(128, 255, 0, 255);
    } else if (TeamID == 355) {
        clrID = IM_COL32(255, 0, 255, 255);
    } else if (TeamID == 356) {
        clrID = IM_COL32(160, 13, 13, 255);
    } else if (TeamID == 357) {
        clrID = IM_COL32(255, 255, 255, 255);
    } else if (TeamID == 358) {
        clrID = IM_COL32(102, 102, 255, 255);
    } else if (TeamID == 359) {
        clrID = IM_COL32(153, 255, 255, 255);
    } else if (TeamID == 360) {
        clrID = IM_COL32(102, 255, 255, 255);
    } else if (TeamID == 361) {
        clrID = IM_COL32(255, 128, 0, 255);
    } else if (TeamID == 362) {
        clrID = IM_COL32(255, 0, 0, 255);
    } else if (TeamID == 363) {
        clrID = IM_COL32(0, 0, 255, 255);
    } else if (TeamID == 364) {
        clrID = IM_COL32(128, 255, 0, 255);
    } else if (TeamID == 365) {
        clrID = IM_COL32(255, 0, 255, 255);
    } else if (TeamID == 366) {
        clrID = IM_COL32(160, 13, 13, 255);
    } else if (TeamID == 367) {
        clrID = IM_COL32(255, 255, 255, 255);
    } else if (TeamID == 368) {
        clrID = IM_COL32(102, 102, 255, 255);
    } else if (TeamID == 369) {
        clrID = IM_COL32(153, 255, 255, 255);
    } else if (TeamID == 370) {
        clrID = IM_COL32(102, 255, 255, 255);
    } else if (TeamID == 371) {
        clrID = IM_COL32(255, 128, 0, 255);
    } else if (TeamID == 372) {
        clrID = IM_COL32(255, 0, 0, 255);
    } else if (TeamID == 373) {
        clrID = IM_COL32(0, 0, 255, 255);
    } else if (TeamID == 374) {
        clrID = IM_COL32(128, 255, 0, 255);
    } else if (TeamID == 375) {
        clrID = IM_COL32(255, 0, 255, 255);
    } else if (TeamID == 376) {
        clrID = IM_COL32(160, 13, 13, 255);
    } else if (TeamID == 377) {
        clrID = IM_COL32(255, 255, 255, 255);
    } else if (TeamID == 378) {
        clrID = IM_COL32(102, 102, 255, 255);
    } else if (TeamID == 379) {
        clrID = IM_COL32(153, 255, 255, 255);
    } else if (TeamID == 380) {
        clrID = IM_COL32(102, 255, 255, 255);
    } else if (TeamID == 381) {
        clrID = IM_COL32(255, 128, 0, 255);
    } else if (TeamID == 382) {
        clrID = IM_COL32(255, 0, 0, 255);
    } else if (TeamID == 383) {
        clrID = IM_COL32(0, 0, 255, 255);
    } else if (TeamID == 384) {
        clrID = IM_COL32(128, 255, 0, 255);
    } else if (TeamID == 385) {
        clrID = IM_COL32(255, 0, 255, 255);
    } else if (TeamID == 386) {
        clrID = IM_COL32(160, 13, 13, 255);
    } else if (TeamID == 387) {
        clrID = IM_COL32(255, 255, 255, 255);
    } else if (TeamID == 388) {
        clrID = IM_COL32(102, 102, 255, 255);
    } else if (TeamID == 389) {
        clrID = IM_COL32(153, 255, 255, 255);
    } else if (TeamID == 390) {
        clrID = IM_COL32(102, 255, 255, 255);
    } else if (TeamID == 391) {
        clrID = IM_COL32(255, 128, 0, 255);
    } else if (TeamID == 392) {
        clrID = IM_COL32(255, 0, 0, 255);
    } else if (TeamID == 393) {
        clrID = IM_COL32(0, 0, 255, 255);
    } else if (TeamID == 394) {
        clrID = IM_COL32(128, 255, 0, 255);
    } else if (TeamID == 395) {
        clrID = IM_COL32(255, 0, 255, 255);
    } else if (TeamID == 396) {
        clrID = IM_COL32(160, 13, 13, 255);
    } else if (TeamID == 397) {
        clrID = IM_COL32(255, 255, 255, 255);
    } else if (TeamID == 398) {
        clrID = IM_COL32(102, 102, 255, 255);
    } else if (TeamID == 399) {
        clrID = IM_COL32(153, 255, 255, 255);
    } else if (TeamID == 400) {
        clrID = IM_COL32(102, 255, 255, 255);
    } else if (TeamID == 401) {
        clrID = IM_COL32(255, 128, 0, 255);
    } else if (TeamID == 402) {
        clrID = IM_COL32(255, 0, 0, 255);
    } else if (TeamID == 403) {
        clrID = IM_COL32(0, 0, 255, 255);
    } else if (TeamID == 404) {
        clrID = IM_COL32(128, 255, 0, 255);
    } else if (TeamID == 405) {
        clrID = IM_COL32(255, 0, 255, 255);
    } else if (TeamID == 406) {
        clrID = IM_COL32(160, 13, 13, 255);
    } else if (TeamID == 407) {
        clrID = IM_COL32(255, 255, 255, 255);
    } else if (TeamID == 408) {
        clrID = IM_COL32(102, 102, 255, 255);
    } else if (TeamID == 409) {
        clrID = IM_COL32(153, 255, 255, 255);
    } else if (TeamID == 410) {
        clrID = IM_COL32(102, 255, 255, 255);
    } else if (TeamID == 411) {
        clrID = IM_COL32(255, 128, 0, 255);
    } else if (TeamID == 412) {
        clrID = IM_COL32(255, 0, 0, 255);
    } else if (TeamID == 413) {
        clrID = IM_COL32(0, 0, 255, 255);
    } else if (TeamID == 414) {
        clrID = IM_COL32(128, 255, 0, 255);
    } else if (TeamID == 415) {
        clrID = IM_COL32(255, 0, 255, 255);
    } else if (TeamID == 416) {
        clrID = IM_COL32(160, 13, 13, 255);
    } else if (TeamID == 417) {
        clrID = IM_COL32(255, 255, 255, 255);
    } else if (TeamID == 418) {
        clrID = IM_COL32(102, 102, 255, 255);
    } else if (TeamID == 419) {
        clrID = IM_COL32(153, 255, 255, 255);
    } else if (TeamID == 420) {
        clrID = IM_COL32(102, 255, 255, 255);
    } else if (TeamID == 421) {
        clrID = IM_COL32(255, 128, 0, 255);
    } else if (TeamID == 422) {
        clrID = IM_COL32(255, 0, 0, 255);
    } else if (TeamID == 423) {
        clrID = IM_COL32(0, 0, 255, 255);
    } else if (TeamID == 424) {
        clrID = IM_COL32(128, 255, 0, 255);
    } else if (TeamID == 425) {
        clrID = IM_COL32(255, 0, 255, 255);
    } else if (TeamID == 426) {
        clrID = IM_COL32(160, 13, 13, 255);
    } else if (TeamID == 427) {
        clrID = IM_COL32(255, 255, 255, 255);
    } else if (TeamID == 428) {
        clrID = IM_COL32(102, 102, 255, 255);
    } else if (TeamID == 429) {
        clrID = IM_COL32(153, 255, 255, 255);
    } else if (TeamID == 430) {
        clrID = IM_COL32(102, 255, 255, 255);
    } else if (TeamID == 431) {
        clrID = IM_COL32(255, 128, 0, 255);
    } else if (TeamID == 432) {
        clrID = IM_COL32(255, 0, 0, 255);
    } else if (TeamID == 433) {
        clrID = IM_COL32(0, 0, 255, 255);
    } else if (TeamID == 434) {
        clrID = IM_COL32(128, 255, 0, 255);
    } else if (TeamID == 435) {
        clrID = IM_COL32(255, 0, 255, 255);
    } else if (TeamID == 436) {
        clrID = IM_COL32(160, 13, 13, 255);
    } else if (TeamID == 437) {
        clrID = IM_COL32(255, 255, 255, 255);
    } else if (TeamID == 438) {
        clrID = IM_COL32(102, 102, 255, 255);
    } else if (TeamID == 439) {
        clrID = IM_COL32(153, 255, 255, 255);
    } else if (TeamID == 440) {
        clrID = IM_COL32(102, 255, 255, 255);
    } else if (TeamID == 441) {
        clrID = IM_COL32(255, 128, 0, 255);
    } else if (TeamID == 442) {
        clrID = IM_COL32(255, 0, 0, 255);
    } else if (TeamID == 443) {
        clrID = IM_COL32(0, 0, 255, 255);
    } else if (TeamID == 444) {
        clrID = IM_COL32(128, 255, 0, 255);
    } else if (TeamID == 445) {
        clrID = IM_COL32(255, 0, 255, 255);
    } else if (TeamID == 446) {
        clrID = IM_COL32(160, 13, 13, 255);
    } else if (TeamID == 447) {
        clrID = IM_COL32(255, 255, 255, 255);
    } else if (TeamID == 448) {
        clrID = IM_COL32(102, 102, 255, 255);
    } else if (TeamID == 449) {
        clrID = IM_COL32(153, 255, 255, 255);
    } else if (TeamID == 450) {
        clrID = IM_COL32(102, 255, 255, 255);
    } else if (TeamID == 451) {
        clrID = IM_COL32(255, 128, 0, 255);
    } else if (TeamID == 452) {
        clrID = IM_COL32(255, 0, 0, 255);
    } else if (TeamID == 453) {
        clrID = IM_COL32(0, 0, 255, 255);
    } else if (TeamID == 454) {
        clrID = IM_COL32(128, 255, 0, 255);
    } else if (TeamID == 455) {
        clrID = IM_COL32(255, 0, 255, 255);
    } else if (TeamID == 456) {
        clrID = IM_COL32(160, 13, 13, 255);
    } else if (TeamID == 457) {
        clrID = IM_COL32(255, 255, 255, 255);
    } else if (TeamID == 458) {
        clrID = IM_COL32(102, 102, 255, 255);
    } else if (TeamID == 459) {
        clrID = IM_COL32(153, 255, 255, 255);
    } else if (TeamID == 460) {
        clrID = IM_COL32(102, 255, 255, 255);
    } else if (TeamID == 461) {
        clrID = IM_COL32(255, 128, 0, 255);
    } else if (TeamID == 462) {
        clrID = IM_COL32(255, 0, 0, 255);
    } else if (TeamID == 463) {
        clrID = IM_COL32(0, 0, 255, 255);
    } else if (TeamID == 464) {
        clrID = IM_COL32(128, 255, 0, 255);
    } else if (TeamID == 465) {
        clrID = IM_COL32(255, 0, 255, 255);
    } else if (TeamID == 466) {
        clrID = IM_COL32(160, 13, 13, 255);
    } else if (TeamID == 467) {
        clrID = IM_COL32(255, 255, 255, 255);
    } else if (TeamID == 468) {
        clrID = IM_COL32(102, 102, 255, 255);
    } else if (TeamID == 469) {
        clrID = IM_COL32(153, 255, 255, 255);
    } else if (TeamID == 470) {
        clrID = IM_COL32(102, 255, 255, 255);
    } else if (TeamID == 471) {
        clrID = IM_COL32(255, 128, 0, 255);
    } else if (TeamID == 472) {
        clrID = IM_COL32(255, 0, 0, 255);
    } else if (TeamID == 473) {
        clrID = IM_COL32(0, 0, 255, 255);
    } else if (TeamID == 474) {
        clrID = IM_COL32(128, 255, 0, 255);
    } else if (TeamID == 475) {
        clrID = IM_COL32(255, 0, 255, 255);
    } else if (TeamID == 476) {
        clrID = IM_COL32(160, 13, 13, 255);
    } else if (TeamID == 477) {
        clrID = IM_COL32(255, 255, 255, 255);
    } else if (TeamID == 478) {
        clrID = IM_COL32(102, 102, 255, 255);
    } else if (TeamID == 479) {
        clrID = IM_COL32(153, 255, 255, 255);
    } else if (TeamID == 480) {
        clrID = IM_COL32(102, 255, 255, 255);
    } else if (TeamID == 481) {
        clrID = IM_COL32(255, 128, 0, 255);
    } else if (TeamID == 482) {
        clrID = IM_COL32(255, 0, 0, 255);
    } else if (TeamID == 483) {
        clrID = IM_COL32(0, 0, 255, 255);
    } else if (TeamID == 484) {
        clrID = IM_COL32(128, 255, 0, 255);
    } else if (TeamID == 485) {
        clrID = IM_COL32(255, 0, 255, 255);
    } else if (TeamID == 486) {
        clrID = IM_COL32(160, 13, 13, 255);
    } else if (TeamID == 487) {
        clrID = IM_COL32(255, 255, 255, 255);
    } else if (TeamID == 488) {
        clrID = IM_COL32(102, 102, 255, 255);
    } else if (TeamID == 489) {
        clrID = IM_COL32(153, 255, 255, 255);
    } else if (TeamID == 490) {
        clrID = IM_COL32(102, 255, 255, 255);
    } else if (TeamID == 491) {
        clrID = IM_COL32(255, 128, 0, 255);
    } else if (TeamID == 492) {
        clrID = IM_COL32(255, 0, 0, 255);
    } else if (TeamID == 493) {
        clrID = IM_COL32(0, 0, 255, 255);
    } else if (TeamID == 494) {
        clrID = IM_COL32(128, 255, 0, 255);
    } else if (TeamID == 495) {
        clrID = IM_COL32(255, 0, 255, 255);
    } else if (TeamID == 496) {
        clrID = IM_COL32(160, 13, 13, 255);
    } else if (TeamID == 497) {
        clrID = IM_COL32(255, 255, 255, 255);
    } else if (TeamID == 498) {
        clrID = IM_COL32(102, 102, 255, 255);
    } else if (TeamID == 499) {
        clrID = IM_COL32(153, 255, 255, 255);
    } else if (TeamID == 500) {
        clrID = IM_COL32(102, 255, 255, 255);
    } else if (TeamID == 501) {
        clrID = IM_COL32(255, 128, 0, 255);
    } else if (TeamID == 502) {
        clrID = IM_COL32(255, 0, 0, 255);
    } else if (TeamID == 503) {
        clrID = IM_COL32(0, 0, 255, 255);
    } else if (TeamID == 504) {
        clrID = IM_COL32(128, 255, 0, 255);
    } else if (TeamID == 505) {
        clrID = IM_COL32(255, 0, 255, 255);
    } else if (TeamID == 506) {
        clrID = IM_COL32(160, 13, 13, 255);
    } else if (TeamID == 507) {
        clrID = IM_COL32(255, 255, 255, 255);
    } else if (TeamID == 508) {
        clrID = IM_COL32(102, 102, 255, 255);
    } else if (TeamID == 509) {
        clrID = IM_COL32(153, 255, 255, 255);
    } else if (TeamID == 510) {
        clrID = IM_COL32(102, 255, 255, 255);
    } else if (TeamID == 511) {
        clrID = IM_COL32(255, 128, 0, 255);
    } else if (TeamID == 512) {
        clrID = IM_COL32(255, 0, 0, 255);
    } else if (TeamID == 513) {
        clrID = IM_COL32(0, 0, 255, 255);
    } else if (TeamID == 514) {
        clrID = IM_COL32(128, 255, 0, 255);
    } else if (TeamID == 515) {
        clrID = IM_COL32(255, 0, 255, 255);
    } else if (TeamID == 516) {
        clrID = IM_COL32(160, 13, 13, 255);
    } else if (TeamID == 517) {
        clrID = IM_COL32(255, 255, 255, 255);
    } else if (TeamID == 518) {
        clrID = IM_COL32(102, 102, 255, 255);
    } else if (TeamID == 519) {
        clrID = IM_COL32(153, 255, 255, 255);
    } else if (TeamID == 520) {
        clrID = IM_COL32(102, 255, 255, 255);
    } else if (TeamID == 521) {
        clrID = IM_COL32(255, 128, 0, 255);
    } else if (TeamID == 522) {
        clrID = IM_COL32(255, 0, 0, 255);
    } else if (TeamID == 523) {
        clrID = IM_COL32(0, 0, 255, 255);
    } else if (TeamID == 524) {
        clrID = IM_COL32(128, 255, 0, 255);
    } else if (TeamID == 525) {
        clrID = IM_COL32(255, 0, 255, 255);
    } else if (TeamID == 526) {
        clrID = IM_COL32(160, 13, 13, 255);
    } else if (TeamID == 527) {
        clrID = IM_COL32(255, 255, 255, 255);
    } else if (TeamID == 528) {
        clrID = IM_COL32(102, 102, 255, 255);
    } else if (TeamID == 529) {
        clrID = IM_COL32(153, 255, 255, 255);
    } else if (TeamID == 530) {
        clrID = IM_COL32(102, 255, 255, 255);
    } else if (TeamID == 531) {
        clrID = IM_COL32(255, 128, 0, 255);
    } else if (TeamID == 532) {
        clrID = IM_COL32(255, 0, 0, 255);
    } else if (TeamID == 533) {
        clrID = IM_COL32(0, 0, 255, 255);
    } else if (TeamID == 534) {
        clrID = IM_COL32(128, 255, 0, 255);
    } else if (TeamID == 535) {
        clrID = IM_COL32(255, 0, 255, 255);
    } else if (TeamID == 536) {
        clrID = IM_COL32(160, 13, 13, 255);
    } else if (TeamID == 537) {
        clrID = IM_COL32(255, 255, 255, 255);
    } else if (TeamID == 538) {
        clrID = IM_COL32(102, 102, 255, 255);
    } else if (TeamID == 539) {
        clrID = IM_COL32(153, 255, 255, 255);
    } else if (TeamID == 540) {
        clrID = IM_COL32(102, 255, 255, 255);
    } else if (TeamID == 541) {
        clrID = IM_COL32(255, 128, 0, 255);
    } else if (TeamID == 542) {
        clrID = IM_COL32(255, 0, 0, 255);
    } else if (TeamID == 543) {
        clrID = IM_COL32(0, 0, 255, 255);
    } else if (TeamID == 544) {
        clrID = IM_COL32(128, 255, 0, 255);
    } else if (TeamID == 545) {
        clrID = IM_COL32(255, 0, 255, 255);
    } else if (TeamID == 546) {
        clrID = IM_COL32(160, 13, 13, 255);
    } else if (TeamID == 547) {
        clrID = IM_COL32(255, 255, 255, 255);
    } else if (TeamID == 548) {
        clrID = IM_COL32(102, 102, 255, 255);
    } else if (TeamID == 549) {
        clrID = IM_COL32(153, 255, 255, 255);
    } else if (TeamID == 550) {
        clrID = IM_COL32(102, 255, 255, 255);
    } else if (TeamID == 551) {
        clrID = IM_COL32(255, 128, 0, 255);
    } else if (TeamID == 552) {
        clrID = IM_COL32(255, 0, 0, 255);
    } else if (TeamID == 553) {
        clrID = IM_COL32(0, 0, 255, 255);
    } else if (TeamID == 554) {
        clrID = IM_COL32(128, 255, 0, 255);
    } else if (TeamID == 555) {
        clrID = IM_COL32(255, 0, 255, 255);
    } else if (TeamID == 556) {
        clrID = IM_COL32(160, 13, 13, 255);
    } else if (TeamID == 557) {
        clrID = IM_COL32(255, 255, 255, 255);
    } else if (TeamID == 558) {
        clrID = IM_COL32(102, 102, 255, 255);
    } else if (TeamID == 559) {
        clrID = IM_COL32(153, 255, 255, 255);
    } else if (TeamID == 560) {
        clrID = IM_COL32(102, 255, 255, 255);
    } else if (TeamID == 561) {
        clrID = IM_COL32(255, 128, 0, 255);
    } else if (TeamID == 562) {
        clrID = IM_COL32(255, 0, 0, 255);
    } else if (TeamID == 563) {
        clrID = IM_COL32(0, 0, 255, 255);
    } else if (TeamID == 564) {
        clrID = IM_COL32(128, 255, 0, 255);
    } else if (TeamID == 565) {
        clrID = IM_COL32(255, 0, 255, 255);
    } else if (TeamID == 566) {
        clrID = IM_COL32(160, 13, 13, 255);
    } else if (TeamID == 567) {
        clrID = IM_COL32(255, 255, 255, 255);
    } else if (TeamID == 568) {
        clrID = IM_COL32(102, 102, 255, 255);
    } else if (TeamID == 569) {
        clrID = IM_COL32(153, 255, 255, 255);
    } else if (TeamID == 570) {
        clrID = IM_COL32(102, 255, 255, 255);
    } else if (TeamID == 571) {
        clrID = IM_COL32(255, 128, 0, 255);
    } else if (TeamID == 572) {
        clrID = IM_COL32(255, 0, 0, 255);
    } else if (TeamID == 573) {
        clrID = IM_COL32(0, 0, 255, 255);
    } else if (TeamID == 574) {
        clrID = IM_COL32(128, 255, 0, 255);
    } else if (TeamID == 575) {
        clrID = IM_COL32(255, 0, 255, 255);
    } else if (TeamID == 576) {
        clrID = IM_COL32(160, 13, 13, 255);
    } else if (TeamID == 577) {
        clrID = IM_COL32(255, 255, 255, 255);
    } else if (TeamID == 578) {
        clrID = IM_COL32(102, 102, 255, 255);
    } else if (TeamID == 579) {
        clrID = IM_COL32(153, 255, 255, 255);
    } else if (TeamID == 580) {
        clrID = IM_COL32(102, 255, 255, 255);
    } else if (TeamID == 581) {
        clrID = IM_COL32(255, 128, 0, 255);
    } else if (TeamID == 582) {
        clrID = IM_COL32(255, 0, 0, 255);
    } else if (TeamID == 583) {
        clrID = IM_COL32(0, 0, 255, 255);
    } else if (TeamID == 584) {
        clrID = IM_COL32(128, 255, 0, 255);
    } else if (TeamID == 585) {
        clrID = IM_COL32(255, 0, 255, 255);
    } else if (TeamID == 586) {
        clrID = IM_COL32(160, 13, 13, 255);
    } else if (TeamID == 587) {
        clrID = IM_COL32(255, 255, 255, 255);
    } else if (TeamID == 588) {
        clrID = IM_COL32(102, 102, 255, 255);
    } else if (TeamID == 589) {
        clrID = IM_COL32(153, 255, 255, 255);
    } else if (TeamID == 590) {
        clrID = IM_COL32(102, 255, 255, 255);
    } else if (TeamID == 591) {
        clrID = IM_COL32(255, 128, 0, 255);
    } else if (TeamID == 592) {
        clrID = IM_COL32(255, 0, 0, 255);
    } else if (TeamID == 593) {
        clrID = IM_COL32(0, 0, 255, 255);
    } else if (TeamID == 594) {
        clrID = IM_COL32(128, 255, 0, 255);
    } else if (TeamID == 595) {
        clrID = IM_COL32(255, 0, 255, 255);
    } else if (TeamID == 596) {
        clrID = IM_COL32(160, 13, 13, 255);
    } else if (TeamID == 597) {
        clrID = IM_COL32(255, 255, 255, 255);
    } else if (TeamID == 598) {
        clrID = IM_COL32(102, 102, 255, 255);
    } else if (TeamID == 599) {
        clrID = IM_COL32(153, 255, 255, 255);
    } else {
        clrID = IM_COL32(255, 128, 0, 255);
    }

    return clrID;
}
