# New syntax: using function pointers
```
connect(ui->slider, &QSlider::valueChanged,
        ui->bar, &QProgressBar::setValue);
```
# Connecting to any function
```
connect(ui->slider, &QSlider::valueChanged,
        sliderMoved);
```
# C++11 lambda
```
connect(ui->slider, &QSlider::valueChanged, [](const int newValue)    {
    qDebug() << "using lambda: " << newValue;
});
```
