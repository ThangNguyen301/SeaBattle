#pragma once
#include "CHcn.h"
//#include <atlimage.h> // Thư viện để sử dụng CImage

class Omin : public CHcn
{
public:
    int thuyen;
    int sl;
    int dong;
    Omin() : CHcn()
    {
        thuyen = 0;
        dong = 1;
        // dong = 0; // Dùng để test
    }
    void draw(CClientDC* pdc);
    void draw(CPaintDC* pdc);
    void drawImage(CDC* pdc, const CString& imagePath, int x, int y);
    void drawImageOverText(CDC* pdc, const CString& imagePath, int x, int y);

};