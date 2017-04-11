#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstring>

std::string secret =
"iVBORw0KGgoAAAANSUhEUgAAACAAAAAgCAMAAABEpIrGAAAAGXRFWHRTb2Z0d2Fy"
"ZQBBZG9iZSBJbWFnZVJlYWR5ccllPAAAAyRpVFh0WE1MOmNvbS5hZG9iZS54bXAA"
"AAAAADw/eHBhY2tldCBiZWdpbj0i77u/IiBpZD0iVzVNME1wQ2VoaUh6cmVTek5U"
"Y3prYzlkIj8+IDx4OnhtcG1ldGEgeG1sbnM6eD0iYWRvYmU6bnM6bWV0YS8iIHg6"
"eG1wdGs9IkFkb2JlIFhNUCBDb3JlIDUuMC1jMDYxIDY0LjE0MDk0OSwgMjAxMC8x"
"Mi8wNy0xMDo1NzowMSAgICAgICAgIj4gPHJkZjpSREYgeG1sbnM6cmRmPSJodHRw"
"Oi8vd3d3LnczLm9yZy8xOTk5LzAyLzIyLXJkZi1zeW50YXgtbnMjIj4gPHJkZjpE"
"ZXNjcmlwdGlvbiByZGY6YWJvdXQ9IiIgeG1sbnM6eG1wPSJodHRwOi8vbnMuYWRv"
"YmUuY29tL3hhcC8xLjAvIiB4bWxuczp4bXBNTT0iaHR0cDovL25zLmFkb2JlLmNv"
"bS94YXAvMS4wL21tLyIgeG1sbnM6c3RSZWY9Imh0dHA6Ly9ucy5hZG9iZS5jb20v"
"eGFwLzEuMC9zVHlwZS9SZXNvdXJjZVJlZiMiIHhtcDpDcmVhdG9yVG9vbD0iQWRv"
"YmUgUGhvdG9zaG9wIENTNS4xIE1hY2ludG9zaCIgeG1wTU06SW5zdGFuY2VJRD0i"
"eG1wLmlpZDoxQjI3QjdCRDA2MzUxMUU2Qjg2RkI2RUM4Mjk1QkY1QyIgeG1wTU06"
"RG9jdW1lbnRJRD0ieG1wLmRpZDoxQjI3QjdCRTA2MzUxMUU2Qjg2RkI2RUM4Mjk1"
"QkY1QyI+IDx4bXBNTTpEZXJpdmVkRnJvbSBzdFJlZjppbnN0YW5jZUlEPSJ4bXAu"
"aWlkOjFCMjdCN0JCMDYzNTExRTZCODZGQjZFQzgyOTVCRjVDIiBzdFJlZjpkb2N1"
"bWVudElEPSJ4bXAuZGlkOjFCMjdCN0JDMDYzNTExRTZCODZGQjZFQzgyOTVCRjVD"
"Ii8+IDwvcmRmOkRlc2NyaXB0aW9uPiA8L3JkZjpSREY+IDwveDp4bXBtZXRhPiA8"
"P3hwYWNrZXQgZW5kPSJyIj8+AfqKmAAAAYBQTFRFdHJq7O32qaqq8+ZNxcXJ4+Pj"
"pKSjvLzFpJ1JsaNx+fn5xLpHenp6urmt8uZQ8/P6tbWyzrp3lpeh2MN8mpZdh4eD"
"3d7klotmsqpM28Z/0shL+u1P1dXV0753uru82tvc1NXeysvU1cB7kpKRn5hN9ulS"
"e3RW8uZUq6VX/vJV8fHxn5BlsLCyi4Nj6ert/vFP+exRm5ub5dpNj4xt0dHRrKRK"
"koxT5OTro59m7uFKoaGgopxYa2pomJiU9+lMg31gqpttioVJzMJJs6tRi4RT8+VG"
"7uJR9vb3jINeVlZU4tdN9+pU+OpPmJJgx75S2s9L+fn+38qB7+/w8+hWnJho++5O"
"lZN2sK+mqqmWmZE8/Pz729FPYF5MubFWs7CUt7e8vLu0zLZsk5Sa9OdXoZ576txD"
"0NHX09TWe3dIj4xj1MlH2c1GjYVsv7+/+epIkJCV/vBMlZJvhIF0mpdonpliZGJL"
"sZ9k19fX5dlG8vP0qKeW5+fnq6qbqJhj/////v7+ktLKzwAAAhdJREFUeNps0+lz"
"0kAUAHBMQoBEQ7nvAmkggBASQqENtlwtUI4WqIjFA+8Dra2KYkVf/vUGZ6xjlped"
"5MP7bd7uzluD+jcAhOlmE0D9Pww3+aVRsduj0aKO3ID8VJK3EwnzV6wPawAspc16"
"LjkKXO7SD5vrgHDvSTfGMDiOj2gM1oBi4dNLRgucZ5i5G1BA1mKrtPbwsdeyFXQA"
"3Ds8jvO8NrRv12tCALGd5VezO6LIdMQfr4agK5F6kItp+e6Mpk/bdfnbQg9g78M+"
"w4u0gmE92dQnMAS4uVE3drwBAAShvZQl6M/hYFbvvrdSxglcTYTb2IYeDI+4x+1e"
"P3+UAjIsXGBpPVhuGarmhJsygts5lz+7hnpgxKact2aJ3BKeniRHhzIgJTA7F2js"
"lpzxqtdbN/9SdUCF9Fmjcyo+MvcslUrlrqTfpgphJ5cTj1sWh8+hDc9bQDrKVA2c"
"tHwONhRiWd/vNAoi5qy/5WNDrCPE+r6PJyjgkitgW0Xo+UcBdGuAc2/WnxnYMvFy"
"Jm748myi3+ZFeT/WKFgGIXZgKecBOQeFLPgPL2sFj83mGV8B0jBBUo38zHhnDfqg"
"8O4FhfQknKcBKOsmOU+0R6UpRiF/WOzlVZgAFNP3mVJ0Kw9IVwcVaaGRiRTd8buW"
"ZBg9ajWsKMGmVmp8docwBAG9vAALyeVKAfUGXASFXt4/htJmrqT6bw3XAgwAPTBz"
"7cfixY8AAAAASUVORK5CYII=";

void readFile(
    std::vector<unsigned char> & data,
    const char * filename
) {
    data.clear();

    // open the file:
    std::streampos fileSize;
    std::ifstream file(filename, std::ios::binary);

    if (!file.is_open()) return;

    // get its size:
    file.seekg(0, std::ios::end);
    fileSize = file.tellg();
    file.seekg(0, std::ios::beg);

    // read the data:
    data.resize(fileSize);
    file.read((char*)&data[0], fileSize);
}

void BGENCD(unsigned char *p, unsigned cnt, const unsigned char* s, unsigned se, unsigned sb) {
    if (cnt) do { *p++ ^= s[sb++ % se]; } while ( --cnt );
}

int main(int argc, char ** argv)  {
    std::cout << "BGENCD>> decryptor: (C) jsbot@ya.ru, 2017." << std::endl;
    if (argc < 2) {
        std::cout << "USAGE: " << argv[0] << " path/to/file" << std::endl;
        return EXIT_SUCCESS;
    }

    std::vector<unsigned char> data;
    readFile(data, argv[1]);

    if (data.size() <= 8) {
        std::cerr << "ERR: can't open file or it empty." << std::endl;
        return EXIT_FAILURE;
    }

    if (memcmp(data.data(), "BGENCD>>", 8)) {
        std::cerr << "ERR: this file not BGENCD>> file." << std::endl;
        return EXIT_FAILURE;
    }

    BGENCD( data.data() + 8,
            data.size() - 8,
            (const unsigned char*)secret.c_str(),
            secret.size(),
            (~(data.size()-8) & 0x1039498u) % secret.size());
    data.push_back('\0');

    if (data[8] == 0xef) {
        std::cout << data.data()+8+3 << std::endl;
    } else {
        std::cerr << "ERR: something wrong." << std::endl;
    }
} 
