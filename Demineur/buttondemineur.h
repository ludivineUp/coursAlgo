#ifndef BUTTONDEMINEUR_H
#define BUTTONDEMINEUR_H

#include <QPushButton>

class ButtonDemineur : public QPushButton
{
public:
    ButtonDemineur(int x, int y);
    int getI();
    int getJ();
signals:
    void click(int i, int j);
public slots:
    void buttonClicked();
private:
    int i;
    int j;
};

#endif // BUTTONDEMINEUR_H
