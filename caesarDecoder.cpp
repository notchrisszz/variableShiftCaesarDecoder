#include <iostream>
#include <string>
#include <vector>
#include <sstream>

std::vector<std::string> rawToPhrase(const std::string& a);
std::string decode(const std::vector<std::string>&  a,const std::vector<std::string>&  b, int i);

int main(){
    std::string codedText, code;
    std::vector<std::string> decodedText;


    std::cout << "Please insert the phrase you want to decode.(Do not use special characters)\n";
    std::getline(std::cin,codedText);

    std::cout << "Please insert the code with the word gaps\n";
    std::getline(std::cin,code);

    auto phrase = rawToPhrase(codedText);
    auto code1 = rawToPhrase(code);
    
    for(int i = 0; i < phrase.size(); i++){
        auto stringAux = decode(phrase,code1,i);
        decodedText.push_back(stringAux);
    }

    
    for(const std::string& words : decodedText){
        std::cout << words << ' ' ;
    }

    return 0;
    
}

std::string decode(const std::vector<std::string>&  a,const std::vector<std::string>&  b, int i){
   std::string ret;
    
   for(int j = 0; j < a[i].size(); j++){
    char c = a[i][j];
    int shift = b[i][j]-'0';

    char decoded = ( c - 'a' - shift + 26 ) % 26 + 'a';

    ret.push_back(decoded);
   }
   return ret;
}

std::vector<std::string> rawToPhrase(const std::string& a){
    std::stringstream ss(a);
    std::vector<std::string> ret;
    std::string st; 
    while(ss >> st){
        ret.push_back(st);
    }
    return ret;
}