#include "serialassistant.h"
#include <QApplication>
#include <QTranslator>

int main(int argc, char *argv[])
{
    /* 高分辨率屏自适应 */
#if (QT_VERSION >= QT_VERSION_CHECK(5, 6, 0))
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QApplication a(argc, argv);
    SerialAssistant w;
    QSize size = w.size();
    w.show();
    w.resize(size.width(), size.height()*2/3);// 调整初始页面大小

    w.setTitle( QString::fromLocal8Bit( argv[0]) );
    return a.exec();
}
