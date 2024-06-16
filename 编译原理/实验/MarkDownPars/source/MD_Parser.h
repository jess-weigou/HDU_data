#include"constant.h"

struct node{
    int type;
    vector<node*> son;
    node *fa;
    string elem[3];//三个属性, elem[0] 保存了要显示的内容，[1]存了链接,[2]存了 title
    node(int _type, node *f) : type(_type), fa(f) {}
};


class MarkDownParser{
private:
    string content;
    node *root, *now;
    char s[MAXLEN];
    std::ifstream FileIn;
    vector<int> TableType;//判断表格类型，是文字偏左还是居中还是偏右

public:
    MarkDownParser(const string &filename){
        /*
         * 构造函数初始化
         * 处理段落、代码块、标题、表格、有序/无序列表等
        */
        FileIn.open(filename);
        root = new node(nul, nullptr);
        now = root;
        bool NewPara = false; //是否是新段落 为True时新起一段
        bool InBlock = false; //是否在代码块内
        int InTable = 0; //1是否在表格头，2是表格体
        int CntTitle = 0;     //标题深度
        int CntList = 0;      //列表深度
        while(!FileIn.eof()){

            //从文件中读取一行
            FileIn.getline(s, MAXLEN);
            if(InTable == 1){
                InTable++;
                continue;
            }
            //处理不在代码块内且需要换行的情况
            if (!InBlock && IsCutLine(s)){//IsCutLine==true表示需要添加分割线
                now = root;
                now->son.push_back(new node(hr, now));//hr表示分割线
                NewPara = false;
                continue;//这一行处理好了，重新读取一行
            }

            //int为空格数和Tab数，char*指向正文内容
            std::pair<int, char *> Space = SkipSpace(s);

            //如果没有位于代码块中，且没有统计到空格和Tab,则直接读取下一行
            if(Space.second == nullptr){     //这一行为空
                if(InBlock){
                    now->son.back()->elem[0] += string(s) + '\n';//把空格也加进去，同时再回车
                }
                else{
                    now = root;
                    NewPara = true;
                    InTable = 0;
                }
                continue;
            }

            //如果在表格中且此行开头为 |
            //在表格中用|来分隔不同单元格，用一行的---来分隔表头和其他行
            if(InTable != 0 && Space.second[0] == '|'){
                char *ch = Space.second + 1;
                if(InTable == 2)
                    now->son.push_back(new node(tbody, now));//若表格很长，则分段显示
                InTable++;
                now = now->son.back();
                now->son.push_back(new node(tr, now));//表格中的一行
                now = now->son.back();
                int len = strlen(ch), cnt = 0;
                string tmp;
                for(int i = 0; i < len; i++){
                    if(ch[i] == '|'){
                        now->son.push_back(new node(th + 3 + TableType[cnt++], now));
                        
                        now->son.back()->elem[0] += trim(tmp);//保存单元格中的内容
                        tmp.clear();
                        continue;
                    }
                    tmp += ch[i];
                }
                continue;
            }
            
            //分析该行文本的类型，int是文本类型，char*指向文本正文
            std::pair<int, char *> TJ = JudgeType(Space.second);

            //如果是代码块类型
            if(TJ.first == blockcode){
                //如果位于代码块中，则push一个空类型的节点
                //若不在代码块中，曾push一个代码块节点
                InBlock ? now->son.push_back(new node(nul, now)) : now->son.push_back(new node(blockcode, now));
                InBlock = !InBlock;//把是否处于代码块中的标识符置反
                continue;
            }

            //如果在代码块中，直接将内容拼接到当前节点中
            if(InBlock){
                now->son.back()->elem[0] += string(s) + '\n';
                continue;
            }

            //如果是段落则直接添加到末尾。
            if(TJ.first == paragraph){
                if(NewPara==true){  //标识符为true，表示要新起一段，插入一个段落类型的节点
                    now = root;
                    now->son.push_back(new node(paragraph, now));
                }
                else{
                    now = FindNode(root);
                }
                insert(now->son.back(), string(TJ.second));//在该正文节点中继续插入剩下的文本
                NewPara = false;
                continue;
            }

            //如果是标题则添加到root的末尾
            if(TJ.first >= h1 && TJ.first <= h6){
                root->son.push_back(new node(TJ.first, root));
                root->son.back()->elem[0] = "tag" + to_string(++CntTitle);
                insert(root->son.back(), string(TJ.second));
                continue;
            }

            //如果是无序列表
            if(TJ.first == ul){
                //列表的阶为行首空格/4
                int lvl = Space.first/4;
                now = root;
                pair<bool, node*> tmp = FindList(lvl, now);//找到lvl级列表所需要连接的节点
                if(tmp.first==true){
                    //无序表
                    now = tmp.second;
                    if(now->son.back()->type != ul){
                        now->son.push_back(new node(ul, now));
                    }
                    now = now->son.back();
                    now->son.push_back(new node(li, now));//li列表，包装有序列表和无序列表
                    now = now->son.back();
                    now->son.push_back(new node(paragraph, now));
                    insert(now->son.back(), string(TJ.second));
                }else if(NewPara){
                    //认为是代码块
                    now = FindNode(root);
                    now->son.push_back(new node(paragraph, now));
                    insert(now->son.back(), '`' + string(TJ.second));
                }else{
                    now = FindNode(root);
                    insert(now->son.back(), string(TJ.second));
                }
            }

            //如果是有序列表
            if(TJ.first == ol){
                int lvl = Space.first/4;
                now = root;
                pair<bool, node*> tmp = FindList(lvl, now);
                if(tmp.first){
                    //有序表
                    now = tmp.second;
                    if(now->son.back()->type != ol){
                        now->son.push_back(new node(ol, now));
                    }
                    now = now->son.back();
                    now->son.push_back(new node(li, now));
                    now = now->son.back();
                    now->son.push_back(new node(paragraph, now));
                    insert(now->son.back(), string(TJ.second));
                }else if(NewPara){
                    //认为是代码块
                    now = FindNode(root);
                    now->son.push_back(new node(paragraph, now));
                    insert(now->son.back(), '`' + string(TJ.second));
                }else{
                    now = FindNode(root);
                    insert(now->son.back(), string(TJ.second));
                }
            }

            //如果是表格（头）
            if(TJ.first == table){
                InTable = 1;
                now = root;
                now->son.push_back(new node(table, now));
                now = now->son.back();
                now->son.push_back(new node(thead, now));//表头颜色？？
                now = now->son.back();
                now->son.push_back(new node(tr, now));
                now = now->son.back();
                char *p = TJ.second;
                int cnt = 0 ;//第几列
                int  len = strlen(p);
                string tmp;
                for(int i = 0; i < len; i++){
                    if(p[i] == '|') {
                        now->son.push_back(new node(th + TableType[cnt++], now));//第几列是什么对齐方式
                        now->son.back()->elem[0] += trim(tmp);
                        tmp.clear();
                        continue;
                    }
                    tmp += p[i];
                }
                now = now->fa; now = now->fa;
                continue;
            }
        }
        FileIn.close();
        dfs(root);
    }

    std::string getContents() { return content; }

    ~MarkDownParser()
    {
        destroy<node>(root);
    }
    void insert(node *v, const string &src){
        int n = (int)src.size();
        bool incode = false, inem = false, instrong = false, inautolink = false;//超链接
        v->son.push_back(new node(nul, v));//在最开始先插入一个空节点，用来存放文段内容

        for (int i = 0; i < n; i++)
        {
            char ch = src[i];
            if (ch == '\\')//处理转义字符
            {
                ch = src[++i];
                v->son.back()->elem[0] += string(1, ch);
                continue;
            }
            //处理行内代码
            if (ch == '`' && !inautolink){//在超链接中不能包含代码
                incode ? v->son.push_back(new node(nul, v)) : v->son.push_back(new node(code, v));
                incode = !incode;
                continue;
            }
            //处理加粗
            if (ch == '*' && (i < n - 1 && (src[i + 1] == '*')) && !incode && !inautolink){
                ++i;
                instrong ? v->son.push_back(new node(nul, v)) : v->son.push_back(new node(strong, v));
                instrong = !instrong;
                continue;
            }
            //处理倾斜
            if (ch == '_' && !incode && !instrong && !inautolink){
                inem ? v->son.push_back(new node(nul, v)) : v->son.push_back(new node(em, v));
                inem = !inem;
                continue;
            }
            //处理超链接
            if (ch == '[' && !incode && !instrong && !inem && !inautolink)
            {
                v->son.push_back(new node(href, v));
                for (i += 1; i < n - 1 && src[i] != ']'; i++)
                    v->son.back()->elem[0] += string(1, src[i]);//[]中保存的是链接的名字
                i++;
                for (i++; i < n - 1 && src[i] != ' ' && src[i] != ')'; i++)
                    v->son.back()->elem[1] += string(1, src[i]);// ( 后是网址
                if (src[i] != ')')
                {
                    for (i++; i < n - 1 && src[i] != ')'; i++)
                    {
                        if (src[i] != '"')
                        {
                            v->son.back()->elem[2] += string(1, src[i]);//（）中的" "里是别名
                        }
                    }
                }
                v->son.push_back(new node(nul, v));
                continue;
            }
            
            v->son.back()->elem[0] += string(1, ch);
            if (inautolink)
                v->son.back()->elem[1] += string(1, ch);//存入链接部分
        }
        //处理行末有二空格时加入换行符
        if (src.size() >= 2)
        {
            if (src.at(src.size() - 1) == ' ' && src.at(src.size() - 2) == ' ')
                v->son.push_back(new node(br, v));
        }
    }
private:

    string to_string(int n){
        string s;
        while(n){
            s+=n%10+'0';
            n/=10;
        }
        reverse(s.begin(), s.end());
        return s;
    }

    //判断是否要换行
    bool IsCutLine(char *src){
        int cnt = 0;
        char *ptr = src;
        while (*ptr)
        {
            //如果不是 空格、tab、-或者*，那么不需要换行
            if (*ptr != ' ' && *ptr != '\t' && *ptr != '-')
                return false;
            if (*ptr == '-')
                cnt++;
            ptr++;
        }
        //如果出现 --- 则需要增加一个分割线，这时需要换行
        return (cnt >= 3);

    }

    string trim(string &s){
        if(s.empty()) return s;
        s.erase(0,s.find_first_not_of(" "));
        s.erase(s.find_last_not_of(" ") + 1);
        return s;
    }
    
    pair<int, char*> SkipSpace(char *src){
        //如果该行内容k为空，则直接返回
        if ((int)strlen(src) == 0)
            return make_pair(0, nullptr);
        //统计空格键和Tab键的个数
        int cntspace = 0, cnttab = 0;
        //从该行的第一个字符读取，统计空格键和Tab键
        //当遇到不是空格和Tab时，立即停止
        for (int i = 0; src[i] != '\0'; i++)
        {
            if (src[i] == ' ')
                cntspace++;
            else if (src[i] == '\t')
                cnttab++;
            //如果内容前有空格和Tab，那么将其统一按Tab的个数处理
            //其中，一个Tab = 四个空格
            else
                return make_pair(cnttab*4 + cntspace, src + i);
        }
        //全为空格
        return make_pair(cnttab*4 + cntspace, nullptr);
    }
    

    //用于查找当前文段需要连接在哪个节点上
    node* FindNode(node *root){
        node *p = root;
        while(!p->son.empty() && p->son.back()->type != nul)
            p = p->son.back();
        p = p->fa;
        return p;
    }

    pair<bool, node*> FindList(int lvl, node *root){
        for(int i = 0; i < lvl; i++){
            if(root->son.back()->type == ul || root->son.back()->type == ol)
                root = root->son.back();
            else
                return make_pair(false, root);
        }
        return make_pair(true, root);
    }
    
    
    
    pair<int, char*> JudgeType(char *src){
        char *ptr = src;
        while(*ptr == '#'){
            ptr++;
        }
        //如果出现空格，则说明是'<h>'标签
        if (ptr - src > 0 && *ptr == ' '){
            int len = strlen(ptr) - 1;
            //吃掉末尾的 #
            while(ptr[len] == '#') ptr[len] = '\0', len--;
            while(ptr[len] == ' ') ptr[len] = '\0', len--;
            return make_pair(ptr - src + h1 - 1, ptr + 1);
        }
            
        //重置分析位置
        ptr = src;
        //如果出现```则说明是代码块
        if (strncmp(ptr, "```", 3) == 0)
            return make_pair(blockcode, ptr + 3);
        //如果出现* + -.并且他们的下一个字符为空格，则说明是无序列表
        if ((ptr[0] == '-' || ptr[0] == '*' || ptr[0] == '+') && ptr[1] == ' ')//原来是strncmp(ptr, "-", 2) == 0 
            return make_pair(ul, ptr + 2);
        //如果出现 > 且下一字符为空格，则说明是引用
        if (*ptr == '>' && (ptr[1] == ' '))
            return make_pair(quote, ptr + 1);
        //如果出现的是数字，且下一个字符是 . 则说明是有序列表
        char *ptr1 = ptr;
        while (*ptr1 && (isdigit(*ptr1)))
            ptr1++;
        if (ptr1 != ptr && *ptr1 == '.' && ptr1[1] == ' ')
            return make_pair(ol, ptr1 + 1);
        //如果开头是 | ，且第二行为表格对齐方式则为表格
        if(ptr[0] == '|'){
            int t = FileIn.tellg();//
            int flag = 1;//在表格里
            string tmp;
            if(!FileIn.eof()) getline(FileIn, tmp);
            for(int i = 0; i < tmp.length(); i++){
                if(tmp[i] == '-' || tmp[i] == '|' || tmp[i] == ' ' || tmp[i] == ':');
                else flag = 0;
            }
            TableType.clear();
            GetTableType(TableType, tmp);
            FileIn.seekg(t);//
            if(flag==1)return make_pair(table, ptr + 1);
        }
        //否则就是普通段落
        return make_pair(paragraph, ptr);
    }

    
    void GetTableType(vector<int> &V, string s){
        int status = 0;
        //左对齐：1， 右对齐：2，居中：3
        s += ' ';
        for (int i = 0; i < s.length(); i++){
            if(s[i] == ' ') continue;
            if(s[i] == '|') {
                if(status)
                    V.push_back(status);
                status = 0;
            }
            if(s[i] == ':' && s[i + 1] == '-')
                status ^= 1;
            if(s[i] == '-' && s[i + 1] == ':')
                status ^= 2;   
        }

    }

    
    template <typename T> void destroy(T *v){
        for (int i = 0; i < (int)v->son.size(); i++)
        {
            destroy(v->son[i]);
        }
        delete v;
    }




    
    inline bool isHeading(node *root){
        return root->type >= h1 && root->type <= h6;
    }

    inline bool isHref(node *v){
        return (v->type == href);
    }

    //将DOM树结构转化为HTML文件
    void dfs(node *root){
        if (root->type == paragraph && root->elem[0].empty() && root->son.empty())
            return;
        content += frontTag[root->type];

        bool flag = true;

        if (isHeading(root))
        {
            content += "id=\"" + root->elem[0] + "\">";
            flag = false;
        }
        if (isHref(root))
        {
            content += "<a href=\"" + root->elem[1] + "\" title=\"" + root->elem[2] + "\">" + root->elem[0] + "</a>";
            flag = false;
        }
        if (flag==true)//表示这个节点存放的是正文内容，若不是正文，经过上面的判断之后flag会被置为false
        {
            content += root->elem[0];
            flag = false;
        }
        //递归遍历所有
        for (int i = 0; i < (int)root->son.size(); i++){
            dfs(root->son[i]);
        }
        //拼接为结束标签
        content += backTag[root->type] + '\n';
    }
};
