#include <iostream>
#include <string>
#include <fstream>

int main(){
    std::ifstream inputFile; // в переменной inputFile будет хранится ссылка на входной файл
    std::ofstream outputFile; // в переменной ofstrream будет хранится ссылка на выходной файл
    inputFile.open(""); /* в аргументе open() указать путь входного файла (если указать 
                            только файл, будет найден файл в текущем пути (если он существует)) */
    outputFile.open(""); /* в аргументе open() указать путь выходного файла (если указать 
                            только файл, будет найден файл в текущем пути (если он существует)) */
    std::string s;
    while (getline(inputFile, s)){ // пока в входном файле не закончились строки
        outputFile << s << '\n';
    }
    inputFile.close(); // закрытие входного файла
    outputFile.close(); // закрытие выходного файла
}
