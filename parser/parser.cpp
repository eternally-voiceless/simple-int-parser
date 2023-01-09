#include "parser.hpp"

long multiply(const std::string& expr="1*1*1");
long subtract(const std::string& expr="12-7-4");
long sum(const std::string& expr="1+1");


std::vector<std::string> split(const std::string& str, char delimiter){
    std::vector<std::string> result;
    std::string current_expr{};

    for(auto ch: str){
        if(ch!=delimiter){
            current_expr+=ch;
        }
        else{
            if(!current_expr.empty()){
                result.push_back(current_expr);
                current_expr.clear();
            }
        }
    }

    if(!str.ends_with(delimiter)){
        result.push_back(current_expr);
    }

    return result;
}

long multiply(const std::string& expr){
    //string: expr*expr*expr... ---> long: calculated value
    long result{1};
    std::vector<std::string> multipliers=split(expr, '*');

    for(auto factor: multipliers){
        result*=std::stol(factor);
    }

    return result;
}

long subtract(const std::string& expr){
    //string: expr-expr-expr... or -expr-expr-expr... ---> long: calculated value
    long result{0};
    std::vector<std::string> terms=split(expr, '-');

    if(expr.starts_with('-')){
        for(auto term: terms){
            result-=multiply(term);
        }
    }
    else{
        result=multiply(terms[0]);
        for(std::size_t i{1}; i<terms.size(); ++i){
            result-=multiply(terms[i]);
        }
    }

    return result;
}


long sum(const std::string& expr){
    //string: expr+expr+expr... ---> long: calculated value
    long result{0};
    std::vector<std::string> terms=split(expr, '+');

    for(auto term: terms){
        result+=subtract(term);
    }

    return result;
}

long parser(const std::string& expr){
    return sum(expr);
}