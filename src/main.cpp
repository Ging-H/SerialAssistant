#include "serialassistant.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SerialAssistant w;
    w.show();

    return a.exec();
}
