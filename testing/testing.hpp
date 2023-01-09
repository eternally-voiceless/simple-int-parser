#pragma once
#include <iostream>
#include <iomanip>
#include <vector>

template<typename T=int> void print(const std::vector<T>& vec);

template<typename T> void print(const std::vector<T>& vec){
    std::cout<<"[\n";
    for(auto el: vec){
        std::cout<<"\t"<<el<<"\n";
    }
    std::cout<<"]"<<std::endl;
}