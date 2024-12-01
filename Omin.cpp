#include "pch.h"
#include "Omin.h"    

void Omin::draw(CClientDC* pdc)
{
    CHcn::draw(pdc); // Vẽ đối tượng cơ sở
    if (dong == 0)
    {
        int xmoi = (x1 + x2) / 2 - 15; // Tọa độ trung tâm (x)
        int ymoi = (y1 + y2) / 2 - 15; // Tọa độ trung tâm (y)

        if (thuyen == 1)
        {
            // Vẽ hình ảnh đầu tiên thay cho dấu "X"
            drawImage(pdc, _T("C:\\Users\\HOME\\Downloads\\z6084860898936_7c60e1b5afab1536ab6e865ffefc9740.jpg"), xmoi, ymoi);
        }
        else
        {
            // Nếu số lượng (sl) là 1 thì vẽ hình ảnh thứ hai lên tọa độ riêng
            if (sl == 1)
            {
                drawImage(pdc, _T("C:\\Users\\HOME\\Downloads\\z6085085143883_5631244ae0b6971d488df564164a0ade.jpg"), xmoi, ymoi);
            }
            else
            {
                // Vẽ số lượng (hoặc dấu "0")
                pdc->SetBkMode(TRANSPARENT);
                pdc->SetTextColor(RGB(255, 0, 0)); // Màu đỏ
                CString str;
                str.Format(_T("%d"), sl);
                pdc->TextOutW(xmoi + 10, ymoi + 10, str); // Đẩy chữ xuống để không đè lên ảnh
            }
        }
    }
}

void Omin::draw(CPaintDC* pdc)
{
    CHcn::draw(pdc); // Vẽ đối tượng cơ sở
    if (dong == 0)
    {
        int xmoi = (x1 + x2) / 2 - 15; // Tọa độ trung tâm (x)
        int ymoi = (y1 + y2) / 2 - 15; // Tọa độ trung tâm (y)

        if (thuyen == 1)
        {
            // Vẽ hình ảnh đầu tiên thay cho dấu "X"
            drawImage(pdc, _T("C:\\Users\\HOME\\Downloads\\z6084860898936_7c60e1b5afab1536ab6e865ffefc9740.jpg"), xmoi, ymoi);
        }
        else
        {
            // Vẽ số lượng (hoặc dấu "0")
            pdc->SetBkMode(TRANSPARENT);
            pdc->SetTextColor(RGB(255, 0, 0)); // Màu đỏ
            CString str;
            str.Format(_T("%d"), sl);
            pdc->TextOutW(xmoi + 10, ymoi + 10, str); // Đẩy chữ xuống để không đè lên ảnh
        }
    }
}

// Hàm vẽ hình ảnh bằng CImage
void Omin::drawImage(CDC* pdc, const CString& imagePath, int x, int y)
{
    CImage image;
    HRESULT hr = image.Load(imagePath); // Tải ảnh từ đường dẫn
    if (SUCCEEDED(hr))
    {
        image.Draw(pdc->m_hDC, x, y, 30, 30); // Vẽ ảnh với kích thước 30x30 tại tọa độ (x, y)
    }
    else
    {
        // Nếu không tải được ảnh, hiển thị lỗi
        pdc->SetTextColor(RGB(255, 0, 0)); // Màu chữ đỏ
        pdc->TextOutW(x, y, _T("Image Load Failed"));
    }
}

// Hàm vẽ hình ảnh chồng lên số "1"
void Omin::drawImageOverText(CDC* pdc, const CString& imagePath, int x, int y)
{
    // Tạo đối tượng CImage và tải ảnh
    CImage image;
    HRESULT hr = image.Load(imagePath);
    if (SUCCEEDED(hr))
    {
        // Xóa nền trước khi vẽ ảnh
        CRect rect(x, y, x + 30, y + 30); // Kích thước ô
        pdc->FillSolidRect(rect, RGB(255, 255, 255)); // Điền màu trắng làm nền

        // Vẽ hình ảnh lên vị trí "1"
        image.Draw(pdc->m_hDC, x, y, 30, 30);
    }
    else
    {
        // Nếu không tải được ảnh, hiển thị thông báo lỗi
        pdc->SetTextColor(RGB(255, 0, 0)); // Màu đỏ
        pdc->TextOutW(x, y, _T("Image Load Failed"));
    }
}