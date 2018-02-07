# ERRATA Updates

Page 65 suggests that the application should be able to run.

First error in `mainwindow.cpp`:
```
C:\Users\stokern\Development\Qt\reimagined-tribble\ch02-sysinfo\mainwindow.cpp:14: error: invalid use of incomplete type 'class QLayout'
     ui->centralWidget->layout()->addWidget(&mCpuWidget);
                                ^
```
Adding the header
```
#include <QLayout>
```
gives the following errors:

* build-ch02-sysinfo-Desktop_Qt_5_10_0_MinGW_32bit-Debug\debug\mainwindow.o:-1: In function 'ZN9CpuWidgetD1Ev':
* ch02-sysinfo\cpuwidget.h:8: error: undefined reference to `vtable for CpuWidget`
* ch02-sysinfo\cpuwidget.h:8: error: undefined reference to `vtable for CpuWidget`
* build-ch02-sysinfo-Desktop_Qt_5_10_0_MinGW_32bit-Debug\debug\cpuwidget.o:-1: In function 'ZN9CpuWidgetC2EP7QWidget':
* ch02-sysinfo\cpuwidget.cpp:8: error: undefined reference to `vtable for CpuWidget`
* ch02-sysinfo\cpuwidget.cpp:8: error: undefined reference to `vtable for CpuWidget`
