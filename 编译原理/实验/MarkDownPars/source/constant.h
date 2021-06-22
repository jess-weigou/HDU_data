#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <utility>
#include <cctype>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXLEN 10000
//词法关键字枚举
enum
{
    nul = 0,//开始
    paragraph = 1,//段落
    href = 2,//超链接
    ul = 3, //无序列表
    ol = 4, //有序列表
    li = 5,//列表，包装上面3，4的列表形式
    em = 6,//斜体
    strong = 7,//强调
    hr = 8,//水平分割线
    br = 9,//换行
    image = 10,//图片
    quote = 11,//引用
    h1 = 12,//标题
    h2 = 13,
    h3 = 14,
    h4 = 15,
    h5 = 16,
    h6 = 17,
    blockcode = 18,//代码段
    code = 19,
    table = 20,
    thead = 21,  //改变表头的颜色
    tbody = 22,  //若表格很长，用tbody分段
    th = 23,    //表头
    thl = 24,
    thr = 25,
    thm = 26,
    tdl = 27,   //表单元格
    tdr = 28,
    tdm = 29,
    tr = 30     //表格中的一行
};
//HTML前置标签
const std::string frontTag[] = {
    "", "<p>", "", "<ul>", "<ol>", "<li>", "<em>", "<strong>",
    "<hr color=#CCCCCC size=1 />", "<br />",
    "", "<blockquote>",
    "<h1 ", "<h2 ", "<h3 ", "<h4 ", "<h5 ", "<h6 ", //右边的尖括号预留给添加其他的标签属性, 如 id
    "<pre><code>", "<code>", "<table>","<thead>", "<hbody>",
    "th", "<th style=\"text-align:left\">", "<th style=\"text-align:right\">",
    "<th style=\"text-align:center\">", "<td style=\"text-align:left\">", "<td style=\"text-align:right\">",
    "<td style=\"text-align:center\">", "<tr>"};

//HTML后置标签
const std::string backTag[] = {
    "", "</p>", "", "</ul>", "</ol>", "</li>", "</em>", "</strong>",
    "", "", "", "</blockquote>",
    "</h1>", "</h2>", "</h3>", "</h4>", "</h5>", "</h6>",
    "</code></pre>", "</code>", "</table>","</thead>", "</hbody>",
    "/th", "</th>", "</th>","</th>","</td>","</td>","</td>",
     "</tr>"};
