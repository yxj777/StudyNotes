#include <iostream>
#include <string>
#include <vector>
using namespace std;
class CScreen
{
    friend class CWindowMgr;
public:
    typedef string::size_type pos;
    CScreen()=default;
    CScreen(pos ht, pos wd):
        height(ht),
        width(wd),
        contents(ht*wd, ' ') 
    {}
    CScreen(pos ht, pos wd,char c):
        height(ht),
        width(wd),
        contents(ht*wd, c) 
    {}
    char get() const
        { return contents[cursor]; }
    const CScreen &display (ostream &os) const
    { 
        do_display(os);
        return *this;
    }
    CScreen &display (ostream &os)
    { 
        do_display(os);
        return *this;
    }
    CScreen &move(pos r, pos c)
    {
        cursor=r*width+c;
        return *this;
    }
    CScreen &set(pos c)
    {
        contents[cursor]=c;
        return *this;
    }
private:
    pos cursor=0;
    pos width=0, height=0;
    string contents;
    void do_display(ostream &os) const { os<< contents; }
};
class CWindowMgr
{
public:
    using ScreenIndex=vector<CScreen>::size_type;
    void clear(ScreenIndex);
    void add(CScreen s);
    void print();
private:
    vector<CScreen> screen{CScreen(3, 3, '0')};    
};
void CWindowMgr::clear(ScreenIndex i)
{    
    CScreen &s=screen[i];
    s.contents =string(s.height*s.width, ' ');
}
void CWindowMgr::add(CScreen s)
{    
    screen.push_back(s);
}
void CWindowMgr::print()
{    
    for(auto i=screen.begin();i<screen.end();++i)
    {
        i->display(cout);
        cout << endl;
    }
       
}
int main(void)
{
    CWindowMgr myWin;
    
    cout << "第一次打印：" << endl;
    myWin.print();
    myWin.add(CScreen(2, 2, 'X'));
    cout << "add打印：" << endl;
    myWin.print();    
    myWin.clear(1);
    cout << "clear打印：" << endl;
    myWin.print();
    return 0;
}