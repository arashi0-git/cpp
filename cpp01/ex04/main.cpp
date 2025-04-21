#include <fstream>
#include <iostream>
#include <string>

std::string replaceString(const std::string &content, const std::string &s1, const std::string &s2){
    std::string result;
    size_t pos =0;
    size_t found;
    while((found = content.find(s1, pos)) != std::string::npos) {
        result += content.substr(pos, found-pos);
        result += s2;
        pos = found + s1.length();
    }

    result += content.substr(pos);
    return result;
}


int main(int ac, char **av) {
    if(ac!=4) {
        std::cerr << "Usage: ./replace <filename> <s1> <s2>" << std::endl;
        return 1;
    }
    std::string filename = av[1];
    std::string s1 = av[2];
    std::string s2 = av[3];

    if(s1.empty()) {
        std::cerr << "s1 cannot be empty" << std::endl;
        return 1;
    }
    std::ifstream inputfile(filename.c_str());
    if(!inputfile) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return 1;
    }
    std::string content((std::istreambuf_iterator<char>(inputfile)),
                        std::istreambuf_iterator<char>());
    inputfile.close();
    std::string newContent = replaceString(content, s1, s2);
    std::ofstream outputfile((filename + ".replace").c_str());
    if(!outputfile) {
        std::cerr << "Error creating file: " << filename + ".replace" << std::endl;
        return 1;
    }

    outputfile << newContent;
    outputfile.close();

    return 0;
}


