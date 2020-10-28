//#include "stdafx.h"
#include <baseapi.h> // подключаем заголовочные файлы библиотек, св€занных с tesseract
#include <allheaders.h>
#include <iostream> // подключаем функции ввода/вывода


using namespace std; // эта строка нужна чтобы не писать std

int _tmain(int argc, char* argv[])
{
    FILE* f; // объ€вл€ем файловую переменную
    tesseract::TessBaseAPI* myOCR =
        new tesseract::TessBaseAPI();
    myOCR->Init(NULL, "eng"); //будем распознавать тексты на английском €зыке
    Pix* pix = pixRead("c:\\2.jpg"); // загружаем картинку с текстом с диска 

    myOCR->SetImage(pix);

    // вывод результатов распознавани€ текста в файл
    f = fopen("text.txt", "w");
    fprintf(f, "OCR output:\n\n");
    fprintf(f, myOCR->GetUTF8Text());
    //return 0;
}