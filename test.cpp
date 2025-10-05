#include <iostream>
#include <fstream>

bool CompareStringPrefix(const char* str, const char* prefix) {
    int i = 0;
    while (prefix[i] != '\0') {
        if (str[i] != prefix[i]) {
            return false;
        }
        i++;
    }
    return true;
}

struct Files {
    char* DataKeys[100000];
    char* DataValues[100000];
};

int main(int argc, char* argv[]){
    std::ifstream TemplateFile;
    std::ifstream DataFile;
    char* TemplatePath;
    char* DataPath;
    char* OutputPath;
    bool bTemplate = false;
    bool bData = false;
    for (int i = 1; i < argc; ++i){
        if (CompareStringPrefix(argv[i], "-t")){
            if (i + 1 < argc){
                TemplatePath = argv[++i];
                bTemplate = true;
            }
            else {
                return 2;
            }
        }
        else if (CompareStringPrefix(argv[i], "-d")){
            if (i + 1 < argc){
                DataPath = argv[++i];
                bData = true;
            }
            else {
                return 2;
            }
        }
        else if (CompareStringPrefix(argv[i], "-o")){
            if (i + 1 < argc){
                OutputPath = argv[++i];
            }
            else {
                return 2;
            }
        }
        else if (CompareStringPrefix(argv[i], "--template=")){
            TemplatePath = argv[i] + 11;
            bTemplate = true;
        }
        else if (CompareStringPrefix(argv[i], "--data=")){
            DataPath = argv[i] + 7;
            bData = true;
        }
        else if (CompareStringPrefix(argv[i], "--output=")){
            OutputPath = argv[i] + 9;
        }
        else {
            return 2;
        }
    }
    std::cout << "Template: " << TemplatePath << '\n';
    std::cout << "Data: " << DataPath << '\n';
    std::cout << "Output: " << OutputPath << '\n';
    if (!bTemplate || !bData){
        std::cout << "2";
        return 2;
    }
    DataFile.open(DataPath);
    
}