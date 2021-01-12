#ifndef _SELFSTRING_H_
#define _SELFSTRING_H_

#include<stdlib.h>
#include<iostream>
#include<string>
using namespace std;

namespace util
{
class String {
public:
    char *m_data;
    int m_size;
    // 普通构造函数
    String(const char* str){
        if(str == NULL) {
            m_data = new char[1];
            m_data[0] = '\0';
            m_size = 0;
        }else {
            int length = strlen(str);
            m_data = new char[lenght + 1];
            strcpy(m_data, str);
        }
    }

    // 析构函数
    ~String() {
        delete[] m_data;
    }

    // 拷贝构造
    String(const String &rhs){
        m_data = new char[strlen(rhs.m_data) + 1];
        strcpy(m_data, rhs.m_data);
    }

    // 拷贝赋值函数 v1
    String& operator=(const String &rhs){
        if(this != &rhs) {
            delete[] m_data;
            m_data = new char[strlen(rhs.m_data) + 1];
            strcpy(m_data, rhs.m_data);
        }
        return *this;
    }

    // 拷贝赋值函数 v2 怀疑不应该加const
    String& operator=(const String rhs){
        swap(*this, rhs);
        return *this;
    }
    // 拷贝复制函数 v3
    String& operator=(String rhs){
        swap(m_data, rhs.m_data);
        return *this;
    }

    // 移动构造函数
    String(String &&rhs) {
        m_data = rhs.m_data;
        rhs.m_data = nullptr;//为啥不用delete rhs.m_data?
        //因为源对象会被自动销毁，我们只要保证它处于可析构状态
    }

    // 移动赋值函数
    String& operator=(Sting &&rhs){
        if(this != &rhs) {
            delete[] m_data;
            m_data = rhs.m_data;
            rhs.m_data = nullptr;
        }
    }

    // +重载，返回是值
    String operator+(const String& rhs) {
        String newStr;
        delete[] newStr.m_data;// 释放原有空间？有必要？
        int left_len = strlen(m_data);
        int right_len = strlen(rhs.m_data);
        newString.m_data = new char[left_len + right_len + 1];
        strcpy(newStr.m_data, m_data);
        strcpy(newStr.m_data + left_len, rhs.m_data);//偏移量，学到了
        return newStr;
    }

    bool operator==(const String& rhs) {
        return strcmp(m_data, rhs.m_data) == 0; //?
    }

    int length() {
        return strlen(m_data);
    }

    // 返回的是值
    String substr(int start, int n) {
        String newStr;
        delete[] newStr.m_data;
        newStr.m_data = new char[n + 1];
        int total_len = strlen(m_data);
        for (int i = 0; i < n && start + i < total_len; ++i){
            newStr.m_data[i] = m_data[start + i];
        }
        newStr.m_data[n] = '\0';
        return newStr;
    }

    friend ostream& operator<<(opstream& o, const String &rhs) {
        o << rhs.m_data;
        return o;
    }
};
} // namespace util

#endif