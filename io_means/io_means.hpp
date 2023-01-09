//implementation of input/output functionality for the program
#pragma once
#include <fstream>
#include <optional>
#include <filesystem>

std::optional<std::string> read_line(const std::string& file_name);
template<typename T=std::string> void write(const T& record, const std::string& file_name_to_record);

template<typename T> void write(const T& record, const std::string& file_name_to_record){
    std::string dir_name{"output"};
    if(!std::filesystem::is_directory(dir_name)){
        std::filesystem::create_directory(dir_name);
    }
    std::ofstream of_stream;
    of_stream.open(dir_name+"/"+file_name_to_record, std::ios_base::app);
    if(of_stream.is_open()){
        of_stream<<record<<std::endl;
    }
    of_stream.close();
}