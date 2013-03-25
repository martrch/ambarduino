/********************************************************************************
** Form generated from reading UI file 'webcamget.ui'
**
** Created: Sun Mar 24 22:40:31 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WEBCAMGET_H
#define UI_WEBCAMGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_webcamGetClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QComboBox *comboBox;
    QCheckBox *smooth;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QSlider *saturation;
    QGroupBox *groupBox1;
    QHBoxLayout *horizontalLayout;
    QPushButton *saveButton;
    QPushButton *openButton;
    QLabel *label;

    void setupUi(QMainWindow *webcamGetClass)
    {
        if (webcamGetClass->objectName().isEmpty())
            webcamGetClass->setObjectName(QString::fromUtf8("webcamGetClass"));
        webcamGetClass->resize(480, 180);
        webcamGetClass->setMaximumSize(QSize(480, 180));
        centralWidget = new QWidget(webcamGetClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetMinimumSize);
        verticalLayout->setContentsMargins(4, -1, 4, -1);
        comboBox = new QComboBox(groupBox);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        verticalLayout->addWidget(comboBox);

        smooth = new QCheckBox(groupBox);
        smooth->setObjectName(QString::fromUtf8("smooth"));
        smooth->setChecked(true);

        verticalLayout->addWidget(smooth);

        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setMaximumSize(QSize(16777215, 52));
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(4, 4, 0, 0);
        saturation = new QSlider(groupBox_2);
        saturation->setObjectName(QString::fromUtf8("saturation"));
        saturation->setMaximum(100);
        saturation->setValue(0);
        saturation->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(saturation);


        verticalLayout->addWidget(groupBox_2);

        groupBox1 = new QGroupBox(groupBox);
        groupBox1->setObjectName(QString::fromUtf8("groupBox1"));
        groupBox1->setEnabled(false);
        groupBox1->setMaximumSize(QSize(154, 60));
        horizontalLayout = new QHBoxLayout(groupBox1);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        saveButton = new QPushButton(groupBox1);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));

        horizontalLayout->addWidget(saveButton);

        openButton = new QPushButton(groupBox1);
        openButton->setObjectName(QString::fromUtf8("openButton"));

        horizontalLayout->addWidget(openButton);


        verticalLayout->addWidget(groupBox1);


        gridLayout->addWidget(groupBox, 0, 1, 1, 1);

        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(320, 180));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        webcamGetClass->setCentralWidget(centralWidget);

        retranslateUi(webcamGetClass);

        QMetaObject::connectSlotsByName(webcamGetClass);
    } // setupUi

    void retranslateUi(QMainWindow *webcamGetClass)
    {
        webcamGetClass->setWindowTitle(QApplication::translate("webcamGetClass", "ambilight", 0, QApplication::UnicodeUTF8));
        smooth->setText(QApplication::translate("webcamGetClass", "Smooth average", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("webcamGetClass", "Saturation", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        saturation->setToolTip(QApplication::translate("webcamGetClass", "saturation", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        groupBox1->setTitle(QApplication::translate("webcamGetClass", "config", 0, QApplication::UnicodeUTF8));
        saveButton->setText(QApplication::translate("webcamGetClass", "save", 0, QApplication::UnicodeUTF8));
        openButton->setText(QApplication::translate("webcamGetClass", "open", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class webcamGetClass: public Ui_webcamGetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WEBCAMGET_H
