#ifndef WIDGET_H
#define WIDGET_H

#include<QTcpSocket>
#include<QTcpServer>
#include <QWidget>
#include<QString>
#include"HAT_AD_cType.h"
#include"HAT_AD_pcpt_interface.h"
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    QTcpServer *tcpServer;
    QTcpSocket *tcpSocket;
    UINT16 Type;
    UINT Length;
    int DataSave(unsigned int uType,char* pData, unsigned int uLen);
private slots:
    void newConnection_Slot();

    void on_openbt_clicked();

    void readyRead_slot();

    void on_closebt_clicked();

    void on_sendbt_clicked();

private:
    Ui::Widget *ui;

};

#endif // WIDGET_H
