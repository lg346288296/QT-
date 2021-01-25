#include "widget.h"
#include "ui_widget.h"
#include"HAT_AD_cType.h"
#include"HAT_AD_pcpt_interface.h"
#include<QDebug>
#include<QDir>
#include <QFile>
#include <QDataStream>
#include<QDateTime>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget),
    tcpSocket(nullptr),
    tcpServer(nullptr),
    Type(0),
    Length(0)
{
    ui->setupUi(this);

    tcpServer= new QTcpServer(this);
    connect(tcpServer,SIGNAL(newConnection()),this,SLOT(newConnection_Slot()));
}

Widget::~Widget()
{
    delete ui;
}
void Widget::newConnection_Slot()
{
    if(nullptr==tcpSocket){
        //获得已连接的socket套接字
        tcpSocket=tcpServer->nextPendingConnection();
        //获取对方ip和端口
        QString ip=tcpSocket->peerAddress().toString();
        qint16 port=tcpSocket->peerPort();
        QString temp=QString("[%1:%2]:成功与客户端连接!!!!!!!!").arg(ip).arg(port);
        ui->recvEdit->appendPlainText(temp);
        connect(tcpSocket,SIGNAL(readyRead()),this,SLOT(readyRead_slot()));
    }


}

void Widget::on_openbt_clicked()
{
    //开启监听
    tcpServer->listen(QHostAddress::Any,ui->portEdit->text().toUInt());
    std::string temp="监听!!!!!!!";
    ui->recvEdit->appendPlainText(QString::fromStdString(temp));

}

void Widget::readyRead_slot()
{
        //拿出缓存区数据
        QByteArray Data=tcpSocket->readAll();
        char* pData=Data.data();
        int DataSize=Data.size();
        if(!Data.isEmpty()){

            if(DataSize==sizeof(HAT_MDL_ETH_MSG_INFO)){ //如果是数据头
                HAT_MDL_ETH_MSG_INFO *msg_info=(HAT_MDL_ETH_MSG_INFO *)pData;
                this->Type=msg_info->type;
                this->Length=msg_info->msg_len;
            }else{//如果是数据包
                DataSave(Type,pData,DataSize);
            }
             ui->recvEdit->appendPlainText(Data);
        }




}
int Widget::DataSave(unsigned int uType,char* pData, unsigned int uLen)
{
    //数据包校验
        if (nullptr == pData)
        {
            ui->recvEdit->appendPlainText("空句柄!!!!!!!!!!!!!!!");
            return ERR_INVALID_PARAM;
        }
        if(uLen!=sizeof(HAT_OUT_LOC_FUSION_DATA)&&uLen!=sizeof(HAT_OUT_FREESPACE_DATA)&&uLen!=sizeof(HAT_OUT_PCPT_BARRIER_DATA)
                &&uLen!=sizeof(HAT_OUT_PCPT_PSD_DATA)&&uLen!=sizeof(HAT_OUT_GLOBAL_PATH_DATA)&&uLen!=sizeof(HAT_OUT_PCPT_HEADER))
        {
            ui->recvEdit->appendPlainText("文件传送有破损!!!!!!!!!!!!!!!!!!!!");
            return ERR_INVALID_PARAM;
        }

        switch (uType)
        {
        case ETH_D_TYPE_HEART:

            ui->recvEdit->appendPlainText("心跳心跳心跳心跳心跳");
            ui->recvEdit->appendPlainText("心跳心跳心跳心跳心跳");
            ui->recvEdit->appendPlainText("心跳心跳心跳心跳心跳");
            ui->recvEdit->appendPlainText("心跳心跳心跳心跳心跳");
            ui->recvEdit->appendPlainText("心跳心跳心跳心跳心跳");
            break;

        case ETH_D_TYPE_LOC_FUSION:
            {
            ui->recvEdit->appendPlainText("fusion开始保存!!!!!!!!!!!!!!!!!!!!");

            //创建目录
            QDir dir;
            //获取当前目录
            QString currentpath=dir.currentPath();
            ui->recvEdit->appendPlainText(currentpath);

            QString Path=currentpath+"./融合定位";
            if(!dir.exists(Path)){
                dir.mkdir(Path);
            }
            //获取当前时间
            QDateTime current_date_time =QDateTime::currentDateTime();
            QString current_date =current_date_time.toString("yyyy-MM-dd hh-mm-ss");

            //创建文件对象
            QString path=Path+current_date+".bin";
            QFile file(path);
             //打开文件
             bool isOK=file.open(QIODevice::WriteOnly|QIODevice::ReadOnly);
             if(isOK)
             {
                 //创建数据流，和file文件关联
                 QDataStream stream(&file);

                 stream.setVersion(QDataStream::Qt_5_5);

                 stream.writeRawData(pData,sizeof(HAT_OUT_LOC_FUSION_DATA));

             }

             //关闭文件
             file.close();

             ui->recvEdit->appendPlainText("fusion保存结束!!!!!!!!!!!!!!!!!!!!");
            break;
            }
        case ETH_D_TYPE_PCPT_FREESPACE:
            {
             ui->recvEdit->appendPlainText("freespace开始保存!!!!!!!!!!!!!!!!!!!!");
             //创建目录
             QDir dir;
             //获取当前目录
             QString currentpath=dir.currentPath();
             ui->recvEdit->appendPlainText(currentpath);

             QString Path=currentpath+"./freespace";
             if(!dir.exists(Path)){
                 dir.mkdir(Path);
             }
            //获取当前时间
            QDateTime current_date_time =QDateTime::currentDateTime();
            QString current_date =current_date_time.toString("yyyy-MM-dd hh-mm-ss");

            //创建文件对象
            QString path=Path+current_date+".bin";
            QFile file(path);
             //打开文件
             bool isOK=file.open(QIODevice::WriteOnly|QIODevice::ReadOnly);
             if(isOK)
             {
                 //创建数据流，和file文件关联
                 QDataStream stream(&file);

                 stream.setVersion(QDataStream::Qt_5_5);

                 stream.writeRawData(pData,sizeof(HAT_OUT_FREESPACE_DATA));

             }

             //关闭文件
             file.close();
             ui->recvEdit->appendPlainText("freespace保存结束!!!!!!!!!!!!!!!!!!!!");
            break;
             }

        case ETH_D_TYPE_PCPT_BARRIER:
        {
            ui->recvEdit->appendPlainText("barrier开始保存!!!!!!!!!!!!!!!!!!!!");
            //创建目录
            QDir dir;
            //获取当前目录
            QString currentpath=dir.currentPath();
            ui->recvEdit->appendPlainText(currentpath);

            QString Path=currentpath+"./barrier";
            if(!dir.exists(Path)){
                dir.mkdir(Path);
            }
        //获取当前时间
        QDateTime current_date_time =QDateTime::currentDateTime();
        QString current_date =current_date_time.toString("yyyy-MM-dd hh-mm-ss");

        //创建文件对象
        QString path=Path+current_date+".bin";
        QFile file(path);
         //打开文件
         bool isOK=file.open(QIODevice::WriteOnly|QIODevice::ReadOnly);
         if(isOK)
         {
             //创建数据流，和file文件关联
             QDataStream stream(&file);

             stream.setVersion(QDataStream::Qt_5_5);

             stream.writeRawData(pData,sizeof(HAT_OUT_PCPT_BARRIER_DATA));

         }

         //关闭文件
         file.close();
          ui->recvEdit->appendPlainText("barrier保存结束!!!!!!!!!!!!!!!!!!!!");
        break;
         }
        case ETH_D_TYPE_PCPT_PSD:
        {
            ui->recvEdit->appendPlainText("psd开始保存!!!!!!!!!!!!!!!!!!!!");
            //创建目录
            QDir dir;
            //获取当前目录
            QString currentpath=dir.currentPath();
            ui->recvEdit->appendPlainText(currentpath);

            QString Path=currentpath+"./psd";
            if(!dir.exists(Path)){
                dir.mkdir(Path);
            }
            //获取当前时间
            QDateTime current_date_time =QDateTime::currentDateTime();
            QString current_date =current_date_time.toString("yyyy-MM-dd hh-mm-ss");

            //创建文件对象
            QString path=Path+current_date+".dat";
            QFile file(path);
             //打开文件
             bool isOK=file.open(QIODevice::WriteOnly|QIODevice::ReadOnly);
             if(isOK)
             {
                 //创建数据流，和file文件关联
                 QDataStream stream(&file);

                 stream.setVersion(QDataStream::Qt_5_5);

                 stream.writeRawData(pData,sizeof(HAT_OUT_LOC_FUSION_DATA));

             }

             //关闭文件
             file.close();

             ui->recvEdit->appendPlainText("psd保存结束!!!!!!!!!!!!!!!!!!!!");
            break;

         }
        case ETH_D_TYPE_GLOBALP_PATH:
        {
            ui->recvEdit->appendPlainText("全局路径开始保存!!!!!!!!!!!!!!!!!!!!");
            //创建目录
            QDir dir;
            //获取当前目录
            QString currentpath=dir.currentPath();
            ui->recvEdit->appendPlainText(currentpath);

            QString Path=currentpath+"./globalpath";
            if(!dir.exists(Path)){
                dir.mkdir(Path);
            }
        //获取当前时间
        QDateTime current_date_time =QDateTime::currentDateTime();
        QString current_date =current_date_time.toString("yyyy-MM-dd hh-mm-ss");

        //创建文件对象
        QString path=Path+current_date+".dat";
        QFile file(path);
         //打开文件
         bool isOK=file.open(QIODevice::WriteOnly|QIODevice::ReadOnly);
         if(isOK)
         {
             //创建数据流，和file文件关联
             QDataStream stream(&file);

             stream.setVersion(QDataStream::Qt_5_5);

             stream.writeRawData(pData,sizeof(HAT_OUT_GLOBAL_PATH_DATA));

         }

         //关闭文件
         file.close();
         ui->recvEdit->appendPlainText("全局路径保存结束!!!!!!!!!!!!!!!!!!!!");
         break;
        }
        default:
            ui->recvEdit->appendPlainText("未保存!!!!!!!!!!!!!!!!!!!!");
            break;
        }
        return 1;

}

void Widget::on_closebt_clicked()
{
    if(nullptr==tcpSocket){
      ui->recvEdit->appendPlainText(QString("未建立连接!!!!!!"));
      return;
    }
    //主动和客户端断开连接
    tcpSocket->disconnectFromHost();
    qDebug("4");
    tcpServer->close();
    ui->recvEdit->appendPlainText("主动与客户端断开连接!!!!!!!");
    tcpSocket=nullptr;
}

void Widget::on_sendbt_clicked()
{

    if(nullptr==tcpSocket){
      ui->recvEdit->appendPlainText("未建立连接!!!");
      return;
    }
    tcpSocket->write(ui->sendEdit->text().toUtf8().data());
    ui->recvEdit->appendPlainText("send sucess!!!");
}
