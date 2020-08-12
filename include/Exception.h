#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <string>
#include <future>

enum ExceptionType {
    CreateWindow_Fail,
};

class Exception {
public:
    Exception(ExceptionType&&);
    const ExceptionType& GetType();
    const std::string& GetMsg();
private:
    void SetMsg();
    ExceptionType _type;
    std::string _msg;
    std::mutex mtx;
    static const std::string CreateWindow_Fail_Msg;
};

#endif