#ifndef COLORFULCIRCLE_H
#define COLORFULCIRCLE_H

#include <QWidget>

#include <QPaintEvent>
#include <QPixmap>   // working with pictures
#include <QPainter>  // painting

class ColorfulCircle : public QWidget
{
    Q_OBJECT
public:
    // constructors
    ColorfulCircle() = default;
    explicit ColorfulCircle(QWidget *parent = nullptr);

    // overloading the component redrawing method
    void paintEvent(QPaintEvent *e) override;
    // overloading the minimum component size
    QSize minimumSizeHint() const override;
    // methods for installing images on a component
    void setYellow();
    void setRed();
    void setGreen();
private:
    QPixmap *mCurrentCircle;  // the current image of the component
    QPixmap mYellowCircle;    // the image of the yellow circle
    QPixmap mRedCircle;       // the image of the red circle
    QPixmap mGreenCircle;     // the image of the green circle
};

#endif // COLORFULCIRCLE_H
