#pragma once
#include "std_lib_facilities.h"
#include <cctype>
#include <string>

struct Quary {
    std::string question;
    std::string answer;

    Quary(std::string q, std::string a){
        question = q;
        answer = a;
    }
};
/*
Quary::Quary(std::string q, std::string a){
    question = q;
    answer = a;
}*/
