//#include "stdafx.h"
#include <baseapi.h> // ���������� ������������ ����� ���������, ��������� � tesseract
#include <allheaders.h>
#include <iostream> // ���������� ������� �����/������


using namespace std; // ��� ������ ����� ����� �� ������ std

int _tmain(int argc, char* argv[])
{
    FILE* f; // ��������� �������� ����������
    tesseract::TessBaseAPI* myOCR =
        new tesseract::TessBaseAPI();
    myOCR->Init(NULL, "eng"); //����� ������������ ������ �� ���������� �����
    Pix* pix = pixRead("c:\\2.jpg"); // ��������� �������� � ������� � ����� 

    myOCR->SetImage(pix);

    // ����� ����������� ������������� ������ � ����
    f = fopen("text.txt", "w");
    fprintf(f, "OCR output:\n\n");
    fprintf(f, myOCR->GetUTF8Text());
    //return 0;
}