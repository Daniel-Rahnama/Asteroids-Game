#include "../include/Exception.h"

#include <future>

Exception::Exception(ExceptionType&& type) : _type(type) {
    std::async(&Exception::SetMsg, this);
}

const ExceptionType& Exception::GetType() {
    std::lock_guard<std::mutex> lock(mtx);
    return _type;
}

const std::string& Exception::GetMsg() {
    std::lock_guard<std::mutex> lock(mtx);
    return _msg;
}

void Exception::SetMsg() {
    std::lock_guard<std::mutex> lock(mtx);
    switch (_type) {
        case CreateWindow_Fail: _msg = CreateWindow_Fail_Msg; break;
    }
}

const std::string Exception::CreateWindow_Fail_Msg = "Fatal Exception: Unable to create window.";