#include "io_means.hpp"

std::optional<std::string> read_line(const std::string& file_name){
    //this function returns the line written in file_name in the form of string
    if(file_name.empty()){
        return std::nullopt;
    }
    std::string result{""}, buffer{""};
    std::ifstream if_stream;
    static std::size_t line_number{1};

    if_stream.open(file_name, std::ios_base::in);
    if(if_stream.is_open()){
        for(std::size_t i{1}; i<line_number; ++i){
            std::getline(if_stream, buffer, '\n');
            buffer.clear();
        }
        std::getline(if_stream, result, '\n');
        if_stream.close();
    }
    
    ++line_number;

    return result;
}