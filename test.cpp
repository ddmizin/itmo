#include <iostream>
#include <fstream>

struct Data {
    char DataKey[100];
    char DataValue[100];
};

bool bCompareStringPrefix(const char* str, const char* prefix) {
    int i = 0;
    while (prefix[i] != '\0') {
        if (str[i] != prefix[i]) {
            return false;
        }
        i++;
    }
    return true;
}

bool bCompareString(const char* str1, const char* str2) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return false;
        }
        i++;
    }
    return true;
}

void CopyString(char* new_string, const char* source) {
    int i = 0;
    while (source[i] != '\0') {
        new_string[i] = source[i];
        i++;
    }
    new_string[i] = '\0';
}

int LengthString(const char* str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

bool bIsSpace(char c) {
    return c == ' ' || c == '\t'  || c == '\n';
}

bool bIsValidSymbol(char c) {
    return (c >= 'a' && c <= 'z') || 
           (c >= 'A' && c <= 'Z') || 
           (c >= '0' && c <= '9') || 
           (c == '_');
}

void DeleteSpaces(char* str) {
    if (str == nullptr) {
        return;
    }

    int l = LengthString(str);
    int start = 0;
    int end = l - 1;

    while (start < l && bIsSpace(str[start])) {
        start++;
    }

    while (end >= 0 && bIsSpace(str[end])) {
        end--;
    }

    int new_l = end - start + 1;
    if (new_l > 0) {
        for (int i = 0; i < new_l; ++i) {
            str[i] = str[start + i];
        }
    }
    str[new_l] = '\0';
}

const char* FindChar(const char* str, char c) {
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == c) {
            return str + i;
        }
        ++i;
    }
    return nullptr;
}

bool CommandLine(int argc, char* argv[], char*& TemplatePath, char*& DataPath, char*& OutputPath){
    bool bTemplate = false;
    bool bData = false;
    for (int i = 1; i < argc; ++i){
        if (bCompareString(argv[i], "-t")){
            if (i + 1 < argc){
                TemplatePath = argv[++i];
                bTemplate = true;
            }
            else {
                return false;
            }
        }
        else if (bCompareString(argv[i], "-d")){
            if (i + 1 < argc){
                DataPath = argv[++i];
                bData = true;
            }
            else {
                return false;
            }
        }
        else if (bCompareString(argv[i], "-o")){
            if (i + 1 < argc){
                OutputPath = argv[++i];
            }
            else {
                return false;
            }
        }
        else if (bCompareStringPrefix(argv[i], "--template=")){
            TemplatePath = argv[i] + 11;
            bTemplate = true;
        }
        else if (bCompareStringPrefix(argv[i], "--data=")){
            DataPath = argv[i] + 7;
            bData = true;
        }
        else if (bCompareStringPrefix(argv[i], "--output=")){
            OutputPath = argv[i] + 9;
        }
        else {
            return false;
        }
    }
    if (!bTemplate || !bData){
        return false;
    }
    return TemplatePath != nullptr && DataPath != nullptr;
}

int ReadData(const char* DataPath, Data* Data, int& data_count){
        std::ifstream DataFile(DataPath);
        if (!DataFile.is_open()){
            return 3;
        }
        char line[4096];
        data_count = 0;
}

int main(int argc, char* argv[]){
    char* TemplatePath = nullptr;
    char* DataPath = nullptr;
    char* OutputPath = nullptr;
    if (!CommandLine(argc, argv, TemplatePath, DataPath, OutputPath)){
        return 2;
    }
}