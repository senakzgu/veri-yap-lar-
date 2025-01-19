#ifndef GEN_HPP
#define GEN_HPP
#include <iostream>
using namespace std;

class Gen
{
    private:

    string value;
    Gen *prewg;
    Gen *nextg;

    public:

Gen(const string& value= " ",Gen *prewg = NULL,Gen *nextg = NULL);
   string getValue();
   void setValue(const string& value);
   Gen* getPrewg();
   Gen* getNextg();
   void setPrewg(Gen* prewg);
   void setNextg(Gen* nextg);

};


#endif

