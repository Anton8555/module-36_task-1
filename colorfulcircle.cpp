#include "colorfulcircle.h"

ColorfulCircle::ColorfulCircle(QWidget *parent)
    : QWidget{parent}
{
    // the text of the hint when hovering over the mouse
    setToolTip("Кружёк");
    // the dimensions of the component must be fixed vertically and horizontally
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    // uploading images
    mYellowCircle = QPixmap(":/images/opt/YellowCircle.png");
    mRedCircle = QPixmap(":/images/opt/RedCircle.png");
    mGreenCircle = QPixmap(":/images/opt/GreenCircle.png");
    // setting the current image
    mCurrentCircle = &mGreenCircle;
    // setting the size of the component according to the size of the image
    setGeometry(mCurrentCircle->rect());
}

void ColorfulCircle::paintEvent(QPaintEvent *e)
{
    QPainter p(this);
    p.drawPixmap(e->rect(), *mCurrentCircle);
}

QSize ColorfulCircle::minimumSizeHint() const
{
    return QSize(100, 100);
}

void ColorfulCircle::setYellow() {
    mCurrentCircle = &mYellowCircle;
    update();
}

void ColorfulCircle::setRed() {
    mCurrentCircle = &mRedCircle;
    update();
}

void ColorfulCircle::setGreen() {
    mCurrentCircle = &mGreenCircle;
    update();
}
