#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include "config.hpp"
#include "io_means.hpp"
#include "parser.hpp"

int main(int argc, char* argv[]){

    std::cout<<"App name: "<<argv[0]<<std::endl;
    std::string input_fn{""};

    if(argc>=2){
        input_fn=std::string(argv[1]);
        std::cout<<"Input: "<<input_fn<<std::endl;
    }
    else{
        std::cout<<"Enter a path to the file: ";
        std::getline(std::cin, input_fn, '\n');
    }

    std::string output_fn;
    std::cout<<"Enter a file name to output: ";
    std::getline(std::cin, output_fn, '\n');

    std::string answer{"Y"};
    long line_result{0};
    
    do{
        std::cout<<"Read the line? (Y/N) ";
        std::getline(std::cin, answer, '\n');
        std::string str_to_parse=read_line(input_fn).value_or("");
        if(!str_to_parse.empty()){
            line_result=parser(str_to_parse);
        }
        else break;
        std::cout<<"Result: "<<line_result<<";"<<std::endl;
        write(line_result, output_fn);
    }
    while(answer=="Y" || answer=="y");
    

}