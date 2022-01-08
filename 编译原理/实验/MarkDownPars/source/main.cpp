#include <iostream>
#include "MD_Parser.h"//需要实现的markdown解析类
#include "head.h"
using namespace std;



int main(){
    MarkDownParser transformer("Test.md");//装载构造markdown文件

    std::string contents = transformer.getContents();//获取markdown转成HTML后的内容，即目标代码生成。编译的过程是词法分析+语法分析

    std::string head = Get_Head(), end = Get_End();//准备写入HTML文件的头尾信息

    std::ofstream out;//将结果写入到文件

    out.open("Test.html");//

    out << head << contents << end << endl;
}
