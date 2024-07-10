#include <iostream>
#include <string>
using namespace std;
class CScreen
{
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

int main(void)
{
    CScreen myScreen(5,5,'x');
    myScreen.move(4,0).set('#').display(cout);
    cout << "\n";
    myScreen.display(cout);
    return 0;
}