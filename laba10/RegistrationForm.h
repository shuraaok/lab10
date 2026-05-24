#ifndef REGISTRATIONFORM_H
#define REGISTRATIONFORM_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QCheckBox>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QFile>
#include <QTextStream>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QCryptographicHash>
#include <QMessageBox>
#include <QFileDialog>
#include <QPixmap>
#include <QDir>
#include <QStandardPaths>
#include <QRegularExpression>
#include <QRegularExpressionValidator>
#include <QEvent>
#include <QMouseEvent>

class RegistrationForm : public QWidget
{
    Q_OBJECT

public:
    RegistrationForm(QWidget *parent = nullptr);
    ~RegistrationForm();

private slots:
    void onRegisterClicked();
    void onLoadPhotoClicked();

protected:
    bool eventFilter(QObject *obj, QEvent *event) override;

private:
    QLabel *photoLabel;
    QPushButton *loadPhotoBtn;
    QCheckBox *europeCheck;
    QCheckBox *asiaCheck;
    QCheckBox *americaCheck;
    QLineEdit *firstNameEdit;
    QLineEdit *lastNameEdit;
    QLineEdit *nicknameEdit;
    QLineEdit *idKeyEdit;
    QLineEdit *emailEdit;
    QLineEdit *passwordEdit;
    QPushButton *registerBtn;

    QString currentPhotoPath;
    QPixmap defaultPhoto;

    bool validateFields();
    bool isNicknameTaken(const QString &nickname);
    QString encryptPassword(const QString &password);
    void createAccountDirectory(const QString &nickname, const QJsonObject &userData, const QString &encryptedPassword);
    void setupValidators();
    void setupUI();
    void applyStyles();
};

#endif // REGISTRATIONFORM_H
