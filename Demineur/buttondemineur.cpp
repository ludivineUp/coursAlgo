#include "buttondemineur.h"

ButtonDemineur::ButtonDemineur(int x, int y): QPushButton(),i(x),j(y)
{
}
int ButtonDemineur::getI(){return i;}
int ButtonDemineur::getJ(){return j;}
