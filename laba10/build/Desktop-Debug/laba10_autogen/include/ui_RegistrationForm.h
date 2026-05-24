/********************************************************************************
** Form generated from reading UI file 'RegistrationForm.ui'
**
** Created by: Qt User Interface Compiler version 6.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTRATIONFORM_H
#define UI_REGISTRATIONFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RegistrationForm
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *photoLayout;
    QLabel *photoLabel;
    QHBoxLayout *photoBtnLayout;
    QPushButton *loadPhotoBtn;
    QSpacerItem *verticalSpacer;
    QGroupBox *serversGroup;
    QHBoxLayout *serversLayout;
    QCheckBox *europeCheck;
    QCheckBox *asiaCheck;
    QCheckBox *americaCheck;
    QSpacerItem *verticalSpacer_2;
    QGridLayout *fieldsLayout;
    QLabel *firstNameLabel;
    QLineEdit *firstNameEdit;
    QLabel *lastNameLabel;
    QLineEdit *lastNameEdit;
    QLabel *nicknameLabel;
    QLineEdit *nicknameEdit;
    QLabel *idKeyLabel;
    QLineEdit *idKeyEdit;
    QLabel *emailLabel;
    QLineEdit *emailEdit;
    QLabel *passwordLabel;
    QLineEdit *passwordEdit;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *registerBtnLayout;
    QPushButton *registerBtn;

    void setupUi(QWidget *RegistrationForm)
    {
        if (RegistrationForm->objectName().isEmpty())
            RegistrationForm->setObjectName("RegistrationForm");
        RegistrationForm->resize(600, 700);
        RegistrationForm->setStyleSheet(QString::fromUtf8("\n"
"    QWidget {\n"
"        background-color: #1a202c;\n"
"        color: #e2e8f0;\n"
"        font-family: 'Segoe UI', Arial, sans-serif;\n"
"    }\n"
"    QLineEdit {\n"
"        background-color: #2d3748;\n"
"        border: 2px solid #4a5568;\n"
"        border-radius: 5px;\n"
"        padding: 8px;\n"
"        color: #e2e8f0;\n"
"        font-size: 12px;\n"
"    }\n"
"    QLineEdit:focus {\n"
"        border-color: #4299e1;\n"
"    }\n"
"    QPushButton {\n"
"        background-color: #4299e1;\n"
"        border: none;\n"
"        border-radius: 5px;\n"
"        padding: 10px 20px;\n"
"        color: white;\n"
"        font-weight: bold;\n"
"        font-size: 14px;\n"
"    }\n"
"    QPushButton:hover {\n"
"        background-color: #3182ce;\n"
"    }\n"
"    QPushButton:pressed {\n"
"        background-color: #2b6cb0;\n"
"    }\n"
"    QGroupBox {\n"
"        border: 2px solid #4a5568;\n"
"        border-radius: 5px;\n"
"        margin-top: 10px;\n"
"        font-weight: bold;\n"
"    }\n"
"    QGroup"
                        "Box::title {\n"
"        subcontrol-origin: margin;\n"
"        left: 10px;\n"
"        padding: 0 5px 0 5px;\n"
"    }\n"
"    QLabel {\n"
"        color: #e2e8f0;\n"
"    }\n"
"    QCheckBox {\n"
"        color: #e2e8f0;\n"
"    }\n"
"    QCheckBox::indicator {\n"
"        width: 13px;\n"
"        height: 13px;\n"
"    }\n"
"   "));
        verticalLayout = new QVBoxLayout(RegistrationForm);
        verticalLayout->setObjectName("verticalLayout");
        photoLayout = new QHBoxLayout();
        photoLayout->setObjectName("photoLayout");
        photoLabel = new QLabel(RegistrationForm);
        photoLabel->setObjectName("photoLabel");
        photoLabel->setFixedSize(QSize(150, 150));
        photoLabel->setStyleSheet(QString::fromUtf8("border: 2px solid #4a5568; border-radius: 10px; background-color: #2d3748;"));
        photoLabel->setAlignment(Qt::AlignCenter);

        photoLayout->addWidget(photoLabel);


        verticalLayout->addLayout(photoLayout);

        photoBtnLayout = new QHBoxLayout();
        photoBtnLayout->setObjectName("photoBtnLayout");
        loadPhotoBtn = new QPushButton(RegistrationForm);
        loadPhotoBtn->setObjectName("loadPhotoBtn");

        photoBtnLayout->addWidget(loadPhotoBtn);


        verticalLayout->addLayout(photoBtnLayout);

        verticalSpacer = new QSpacerItem(20, 10, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        serversGroup = new QGroupBox(RegistrationForm);
        serversGroup->setObjectName("serversGroup");
        serversLayout = new QHBoxLayout(serversGroup);
        serversLayout->setObjectName("serversLayout");
        europeCheck = new QCheckBox(serversGroup);
        europeCheck->setObjectName("europeCheck");

        serversLayout->addWidget(europeCheck);

        asiaCheck = new QCheckBox(serversGroup);
        asiaCheck->setObjectName("asiaCheck");

        serversLayout->addWidget(asiaCheck);

        americaCheck = new QCheckBox(serversGroup);
        americaCheck->setObjectName("americaCheck");

        serversLayout->addWidget(americaCheck);


        verticalLayout->addWidget(serversGroup);

        verticalSpacer_2 = new QSpacerItem(20, 10, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout->addItem(verticalSpacer_2);

        fieldsLayout = new QGridLayout();
        fieldsLayout->setObjectName("fieldsLayout");
        firstNameLabel = new QLabel(RegistrationForm);
        firstNameLabel->setObjectName("firstNameLabel");

        fieldsLayout->addWidget(firstNameLabel, 0, 0, 1, 1);

        firstNameEdit = new QLineEdit(RegistrationForm);
        firstNameEdit->setObjectName("firstNameEdit");

        fieldsLayout->addWidget(firstNameEdit, 0, 1, 1, 1);

        lastNameLabel = new QLabel(RegistrationForm);
        lastNameLabel->setObjectName("lastNameLabel");

        fieldsLayout->addWidget(lastNameLabel, 1, 0, 1, 1);

        lastNameEdit = new QLineEdit(RegistrationForm);
        lastNameEdit->setObjectName("lastNameEdit");

        fieldsLayout->addWidget(lastNameEdit, 1, 1, 1, 1);

        nicknameLabel = new QLabel(RegistrationForm);
        nicknameLabel->setObjectName("nicknameLabel");

        fieldsLayout->addWidget(nicknameLabel, 2, 0, 1, 1);

        nicknameEdit = new QLineEdit(RegistrationForm);
        nicknameEdit->setObjectName("nicknameEdit");

        fieldsLayout->addWidget(nicknameEdit, 2, 1, 1, 1);

        idKeyLabel = new QLabel(RegistrationForm);
        idKeyLabel->setObjectName("idKeyLabel");

        fieldsLayout->addWidget(idKeyLabel, 3, 0, 1, 1);

        idKeyEdit = new QLineEdit(RegistrationForm);
        idKeyEdit->setObjectName("idKeyEdit");

        fieldsLayout->addWidget(idKeyEdit, 3, 1, 1, 1);

        emailLabel = new QLabel(RegistrationForm);
        emailLabel->setObjectName("emailLabel");

        fieldsLayout->addWidget(emailLabel, 4, 0, 1, 1);

        emailEdit = new QLineEdit(RegistrationForm);
        emailEdit->setObjectName("emailEdit");

        fieldsLayout->addWidget(emailEdit, 4, 1, 1, 1);

        passwordLabel = new QLabel(RegistrationForm);
        passwordLabel->setObjectName("passwordLabel");

        fieldsLayout->addWidget(passwordLabel, 5, 0, 1, 1);

        passwordEdit = new QLineEdit(RegistrationForm);
        passwordEdit->setObjectName("passwordEdit");
        passwordEdit->setEchoMode(QLineEdit::Password);

        fieldsLayout->addWidget(passwordEdit, 5, 1, 1, 1);


        verticalLayout->addLayout(fieldsLayout);

        verticalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout->addItem(verticalSpacer_3);

        registerBtnLayout = new QHBoxLayout();
        registerBtnLayout->setObjectName("registerBtnLayout");
        registerBtn = new QPushButton(RegistrationForm);
        registerBtn->setObjectName("registerBtn");

        registerBtnLayout->addWidget(registerBtn);


        verticalLayout->addLayout(registerBtnLayout);


        retranslateUi(RegistrationForm);

        QMetaObject::connectSlotsByName(RegistrationForm);
    } // setupUi

    void retranslateUi(QWidget *RegistrationForm)
    {
        RegistrationForm->setWindowTitle(QCoreApplication::translate("RegistrationForm", "\320\240\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\321\217 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217", nullptr));
        photoLabel->setText(QCoreApplication::translate("RegistrationForm", "\320\244\320\276\321\202\320\276\n"
"        ", nullptr));
        loadPhotoBtn->setText(QCoreApplication::translate("RegistrationForm", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214 \321\204\320\276\321\202\320\276", nullptr));
        serversGroup->setTitle(QCoreApplication::translate("RegistrationForm", "\320\241\320\265\321\200\320\262\320\265\321\200\320\260:", nullptr));
        europeCheck->setText(QCoreApplication::translate("RegistrationForm", "\320\225\320\262\321\200\320\276\320\277\320\260", nullptr));
        asiaCheck->setText(QCoreApplication::translate("RegistrationForm", "\320\220\320\267\320\270\321\217", nullptr));
        americaCheck->setText(QCoreApplication::translate("RegistrationForm", "\320\220\320\274\320\265\321\200\320\270\320\272\320\260", nullptr));
        firstNameLabel->setText(QCoreApplication::translate("RegistrationForm", "\320\230\320\274\321\217:", nullptr));
        lastNameLabel->setText(QCoreApplication::translate("RegistrationForm", "\320\244\320\260\320\274\320\270\320\273\320\270\321\217:", nullptr));
        nicknameLabel->setText(QCoreApplication::translate("RegistrationForm", "\320\235\320\270\320\272\320\275\320\265\320\271\320\274:", nullptr));
        idKeyLabel->setText(QCoreApplication::translate("RegistrationForm", "ID-Key:", nullptr));
        emailLabel->setText(QCoreApplication::translate("RegistrationForm", "\320\237\320\276\321\207\321\202\320\260:", nullptr));
        passwordLabel->setText(QCoreApplication::translate("RegistrationForm", "\320\237\320\260\321\200\320\276\320\273\321\214:", nullptr));
        registerBtn->setText(QCoreApplication::translate("RegistrationForm", "\320\240\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\321\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RegistrationForm: public Ui_RegistrationForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTRATIONFORM_H
