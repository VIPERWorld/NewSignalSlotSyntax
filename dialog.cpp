#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    setWindowTitle("New Signal Slot Syntax");

    // New syntax: using function pointers
    connect(ui->slider, &QSlider::valueChanged,
            ui->bar, &QProgressBar::setValue);

    // Connecting to any function
    connect(ui->slider, &QSlider::valueChanged,
            sliderMoved);

    // C++11 lambda
    connect(ui->slider, &QSlider::valueChanged, [](const int newValue)    {
        qDebug() << "using lambda: " << newValue;
    });
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::sliderMoved()
{
    qDebug() << "sliderMoved";
}
