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
    // ��ͨ���캯��
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

    // ��������
    ~String() {
        delete[] m_data;
    }

    // ��������
    String(const String &rhs){
        m_data = new char[strlen(rhs.m_data) + 1];
        strcpy(m_data, rhs.m_data);
    }

    // ������ֵ���� v1
    String& operator=(const String &rhs){
        if(this != &rhs) {
            delete[] m_data;
            m_data = new char[strlen(rhs.m_data) + 1];
            strcpy(m_data, rhs.m_data);
        }
        return *this;
    }

    // ������ֵ���� v2 ���ɲ�Ӧ�ü�const
    String& operator=(const String rhs){
        swap(*this, rhs);
        return *this;
    }
    // �������ƺ��� v3
    String& operator=(String rhs){
        swap(m_data, rhs.m_data);
        return *this;
    }

    // �ƶ����캯��
    String(String &&rhs) {
        m_data = rhs.m_data;
        rhs.m_data = nullptr;//Ϊɶ����delete rhs.m_data?
        //��ΪԴ����ᱻ�Զ����٣�����ֻҪ��֤�����ڿ�����״̬
    }

    // �ƶ���ֵ����
    String& operator=(Sting &&rhs){
        if(this != &rhs) {
            delete[] m_data;
            m_data = rhs.m_data;
            rhs.m_data = nullptr;
        }
    }

    // +���أ�������ֵ
    String operator+(const String& rhs) {
        String newStr;
        delete[] newStr.m_data;// �ͷ�ԭ�пռ䣿�б�Ҫ��
        int left_len = strlen(m_data);
        int right_len = strlen(rhs.m_data);
        newString.m_data = new char[left_len + right_len + 1];
        strcpy(newStr.m_data, m_data);
        strcpy(newStr.m_data + left_len, rhs.m_data);//ƫ������ѧ����
        return newStr;
    }

    bool operator==(const String& rhs) {
        return strcmp(m_data, rhs.m_data) == 0; //?
    }

    int length() {
        return strlen(m_data);
    }

    // ���ص���ֵ
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