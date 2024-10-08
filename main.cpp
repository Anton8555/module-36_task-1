#include "mainwindow.h"

#include <QApplication>

#include <QVBoxLayout>
#include <QSlider>
#include "colorfulcircle.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();

    // creating a window where the components will be located
    QWidget *window = new QWidget;
    // the components themselves
    ColorfulCircle *circle = new ColorfulCircle(nullptr);
    QSlider *slider = new QSlider(Qt::Horizontal);
    // creating a component for a vertically ordered arrangement of components
    auto *layout = new QVBoxLayout(window);
    // and adding components to it
    layout->addWidget(circle);
    layout->addWidget(slider);
    // configuring component sizes
    circle->setFixedSize(180, 180);
    slider->setFixedSize(180, 40);
    window->setFixedSize(200, 250);
    window->move(500, 500);
    // binding to the corresponding lambda expression signal
    QObject::connect(
        slider,
        &QSlider::valueChanged,
        [&slider, &circle](int newValue)
        {
            // Here you can check the range and set the color of the circle
            if(newValue <= 33)
                circle->setGreen();
            else if(newValue <= 66)
                circle->setYellow();
            else
                circle->setRed();
        }
    );
    // display a window
    window->show();


    return a.exec();
}
