/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QPlainTextEdit *recvEdit;
    QHBoxLayout *horizontalLayout_7;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *ipEdit;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout_6;
    QHBoxLayout *horizontalLayout_5;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *portEdit;
    QSpacerItem *horizontalSpacer_3;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *sendEdit;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *openbt;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *closebt;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *sendbt;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(450, 600);
        gridLayout = new QGridLayout(Widget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        groupBox = new QGroupBox(Widget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        recvEdit = new QPlainTextEdit(groupBox);
        recvEdit->setObjectName(QStringLiteral("recvEdit"));

        verticalLayout->addWidget(recvEdit);


        verticalLayout_3->addWidget(groupBox);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(Widget);
        label->setObjectName(QStringLiteral("label"));
        label->setLayoutDirection(Qt::LeftToRight);

        horizontalLayout->addWidget(label);


        horizontalLayout_4->addLayout(horizontalLayout);

        ipEdit = new QLineEdit(Widget);
        ipEdit->setObjectName(QStringLiteral("ipEdit"));
        ipEdit->setReadOnly(false);

        horizontalLayout_4->addWidget(ipEdit);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_6);


        horizontalLayout_7->addLayout(horizontalLayout_4);


        verticalLayout_3->addLayout(horizontalLayout_7);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));

        horizontalLayout_5->addLayout(horizontalLayout_2);

        label_2 = new QLabel(Widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_5->addWidget(label_2);

        portEdit = new QLineEdit(Widget);
        portEdit->setObjectName(QStringLiteral("portEdit"));

        horizontalLayout_5->addWidget(portEdit);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);


        horizontalLayout_6->addLayout(horizontalLayout_5);


        verticalLayout_3->addLayout(horizontalLayout_6);

        groupBox_2 = new QGroupBox(Widget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        sendEdit = new QLineEdit(groupBox_2);
        sendEdit->setObjectName(QStringLiteral("sendEdit"));

        verticalLayout_2->addWidget(sendEdit);


        verticalLayout_3->addWidget(groupBox_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        openbt = new QPushButton(Widget);
        openbt->setObjectName(QStringLiteral("openbt"));

        horizontalLayout_3->addWidget(openbt);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        closebt = new QPushButton(Widget);
        closebt->setObjectName(QStringLiteral("closebt"));

        horizontalLayout_3->addWidget(closebt);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        sendbt = new QPushButton(Widget);
        sendbt->setObjectName(QStringLiteral("sendbt"));

        horizontalLayout_3->addWidget(sendbt);


        verticalLayout_3->addLayout(horizontalLayout_3);


        gridLayout->addLayout(verticalLayout_3, 0, 0, 1, 1);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "\351\225\277\345\256\211\346\240\241\351\252\214\346\234\215\345\212\241\345\231\250", 0));
        groupBox->setTitle(QApplication::translate("Widget", "\346\211\223\345\215\260\347\252\227\345\217\243", 0));
        label->setText(QApplication::translate("Widget", "ip\357\274\232", 0));
        ipEdit->setText(QString());
        label_2->setText(QApplication::translate("Widget", "\347\253\257\345\217\243\345\217\267\357\274\232", 0));
        groupBox_2->setTitle(QApplication::translate("Widget", "\345\217\221\351\200\201\347\252\227\345\217\243", 0));
        openbt->setText(QApplication::translate("Widget", "\346\211\223\345\274\200\346\234\215\345\212\241\345\231\250", 0));
        closebt->setText(QApplication::translate("Widget", "\345\205\263\351\227\255\346\234\215\345\212\241\345\231\250", 0));
        sendbt->setText(QApplication::translate("Widget", "\345\217\221\351\200\201", 0));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
