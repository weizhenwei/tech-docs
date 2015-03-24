#include <stdio.h>
#include <string.h>

class CMyString {
 public:
     CMyString() : m_pData(NULL), a(0), b('\0') {}
     CMyString(const char *pData, int a, char b);
     CMyString(const CMyString& str);
     ~CMyString(void);
     CMyString& operator=(const CMyString &str);

     char *data() {return m_pData;}
     int aa() {return a;}
     char bb() {return b;}

 private:
     char *m_pData;
     int a;
     char b;
};

CMyString::CMyString(const char *pData, int a, char b) {
    // must remember to judge the NULL pointer;
    if (pData == NULL) {
        this->m_pData = NULL;
    } else {
        m_pData = new char[strlen(pData)+1];
        strcpy(m_pData, pData);
    }
    this->a = a;
    this->b = b;
}

CMyString::~CMyString(void) {
    if (m_pData) {
        delete []m_pData;
    }
    m_pData = NULL;
}

CMyString::CMyString(const CMyString& str) {
    // no this fucking judgement!
    // valgrind says no leaks here!
    // at this time, m_pData's value is random address, which is so-called “野指针”!
    // then it's obviously fucking error to delete it!
    // this is really a fucking stupid debug;
    // if (m_pData) {
    //     delete []m_pData;
    // }
    m_pData = NULL;

    // remember the NULL judgement!
    if (str.m_pData == NULL) {
        this->m_pData = NULL;
    } else {
        m_pData = new char[strlen(str.m_pData)+1];
        strcpy(this->m_pData, str.m_pData);
    }
    this->a = str.a;
    this->b = str.b;
}

CMyString& CMyString::operator=(const CMyString &str) {
    if (this != &str) {
        CMyString strTemp(str);

        char *pTemp = strTemp.m_pData;
        strTemp.m_pData = m_pData;
        m_pData = pTemp;
    }
    this->a = str.a;
    this->b = str.b;

    return *this;
}

#if 0
CMyString& CMyString::operator=(const CMyString &str) {
    if (this == &str) {
        return *this;
    }

    delete []m_pData;

    m_pData = NULL;
    if (str.m_pData == NULL) {
        this->m_pData = NULL;
    } else {
        m_pData = new char[strlen(str.m_pData)+1];
        strcpy(this->m_pData, str.m_pData);
    }
    this->a = str.a;
    this->b = str.b;

    return *this;
}
#endif

static void print_MyString(CMyString &str) {
    printf("CMyString.m_pData = %s\n", str.data());
    printf("CMyString.a = %d\n", str.aa());
    printf("CMyString.b = %c\n", str.bb());
}

// study the c++ reference;
static void test_reference(void){
    int i = 5;
    int j = 6;
    int &k = i;  // i = 5, j = 6;
    printf("i = %d, j = %d\n", i, j);
    k = j;  // i = 6, j = 6;
    printf("i = %d, j = %d\n", i, j);
    k++;  // i = 7, j = 6;
    printf("i = %d, j = %d\n", i, j);
}

int main(int argc, char *argv[]) {
    CMyString str1("hello", 1, 'a');  // call the constructor;
    CMyString str2(str1); // call the copy constructor;

    print_MyString(str1);
    print_MyString(str2);

    CMyString str3;  // call the default constructor;
    // CMyString str4 = str3;  // call the copy constructor;
    CMyString str4;
    str4 = str3;  // call the assignment operator function;
    print_MyString(str3);
    print_MyString(str4);

    test_reference();

    return 0;
}






