#include "gen.hpp"

Gen::Gen(const string& value,Gen *prewg,Gen *nextg )
{
    this->value=value;
    this->prewg=prewg;
    this->nextg=nextg;
} 



string Gen::getValue()
{
    return value;
}

void Gen::setValue(const string& value) {
            this->value = value;
        }

Gen* Gen::getPrewg() {
            return prewg;
        }

Gen* Gen::getNextg() {
            return nextg;
        }

void Gen::setPrewg(Gen* prewg) {
            this->prewg = prewg;
        }

void Gen::setNextg(Gen* nextg) {
            this->nextg = nextg;
        }







