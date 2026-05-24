#include "RegistrationForm.h"

RegistrationForm::RegistrationForm(QWidget *parent)
    : QWidget(parent)
{
    setupUI();
    applyStyles();
    setupValidators();


    firstNameEdit->installEventFilter(this);
    lastNameEdit->installEventFilter(this);
    nicknameEdit->installEventFilter(this);
    idKeyEdit->installEventFilter(this);
    emailEdit->installEventFilter(this);
    passwordEdit->installEventFilter(this);
    photoLabel->installEventFilter(this);


    connect(registerBtn, &QPushButton::clicked, this, &RegistrationForm::onRegisterClicked);
    connect(loadPhotoBtn, &QPushButton::clicked, this, &RegistrationForm::onLoadPhotoClicked);


    defaultPhoto = QPixmap(150, 150);
    defaultPhoto.fill(QColor(45, 55, 72));
}

RegistrationForm::~RegistrationForm()
{
}

void RegistrationForm::setupUI()
{
    setWindowTitle("Регистрация пользователя");
    setFixedSize(600, 700);


    photoLabel = new QLabel(this);
    photoLabel->setFixedSize(150, 150);
    photoLabel->setAlignment(Qt::AlignCenter);
    photoLabel->setText("Фото\n");

    loadPhotoBtn = new QPushButton("Загрузить фото", this);


    QGroupBox *serversGroup = new QGroupBox("Сервера:", this);
    europeCheck = new QCheckBox("Европа");
    asiaCheck = new QCheckBox("Азия");
    americaCheck = new QCheckBox("Америка");

    QHBoxLayout *serversLayout = new QHBoxLayout;
    serversLayout->addWidget(europeCheck);
    serversLayout->addWidget(asiaCheck);
    serversLayout->addWidget(americaCheck);
    serversGroup->setLayout(serversLayout);


    firstNameEdit = new QLineEdit(this);
    lastNameEdit = new QLineEdit(this);
    nicknameEdit = new QLineEdit(this);
    idKeyEdit = new QLineEdit(this);
    emailEdit = new QLineEdit(this);
    passwordEdit = new QLineEdit(this);
    passwordEdit->setEchoMode(QLineEdit::Password);

    registerBtn = new QPushButton("Регистрация", this);


    QVBoxLayout *mainLayout = new QVBoxLayout(this);


    QHBoxLayout *photoLayout = new QHBoxLayout;
    photoLayout->addWidget(photoLabel, 0, Qt::AlignCenter);
    mainLayout->addLayout(photoLayout);

    QHBoxLayout *photoBtnLayout = new QHBoxLayout;
    photoBtnLayout->addWidget(loadPhotoBtn, 0, Qt::AlignCenter);
    mainLayout->addLayout(photoBtnLayout);

    mainLayout->addSpacing(10);
    mainLayout->addWidget(serversGroup);
    mainLayout->addSpacing(10);


    QGridLayout *fieldsLayout = new QGridLayout;
    fieldsLayout->addWidget(new QLabel("Имя:", this), 0, 0);
    fieldsLayout->addWidget(firstNameEdit, 0, 1);
    fieldsLayout->addWidget(new QLabel("Фамилия:", this), 1, 0);
    fieldsLayout->addWidget(lastNameEdit, 1, 1);
    fieldsLayout->addWidget(new QLabel("Никнейм:", this), 2, 0);
    fieldsLayout->addWidget(nicknameEdit, 2, 1);
    fieldsLayout->addWidget(new QLabel("ID-Key:", this), 3, 0);
    fieldsLayout->addWidget(idKeyEdit, 3, 1);
    fieldsLayout->addWidget(new QLabel("Почта:", this), 4, 0);
    fieldsLayout->addWidget(emailEdit, 4, 1);
    fieldsLayout->addWidget(new QLabel("Пароль:", this), 5, 0);
    fieldsLayout->addWidget(passwordEdit, 5, 1);

    mainLayout->addLayout(fieldsLayout);
    mainLayout->addSpacing(20);
    mainLayout->addWidget(registerBtn, 0, Qt::AlignCenter);
}

void RegistrationForm::applyStyles()
{
    setStyleSheet(
        "QWidget {"
        "    background-color: #1a202c;"
        "    color: #e2e8f0;"
        "    font-family: 'Segoe UI', Arial, sans-serif;"
        "}"
        "QLineEdit {"
        "    background-color: #2d3748;"
        "    border: 2px solid #4a5568;"
        "    border-radius: 5px;"
        "    padding: 8px;"
        "    color: #e2e8f0;"
        "    font-size: 12px;"
        "}"
        "QLineEdit:focus {"
        "    border-color: #4299e1;"
        "}"
        "QPushButton {"
        "    background-color: #4299e1;"
        "    border: none;"
        "    border-radius: 5px;"
        "    padding: 10px 20px;"
        "    color: white;"
        "    font-weight: bold;"
        "    font-size: 14px;"
        "}"
        "QPushButton:hover {"
        "    background-color: #3182ce;"
        "}"
        "QPushButton:pressed {"
        "    background-color: #2b6cb0;"
        "}"
        "QGroupBox {"
        "    border: 2px solid #4a5568;"
        "    border-radius: 5px;"
        "    margin-top: 10px;"
        "    font-weight: bold;"
        "}"
        "QGroupBox::title {"
        "    subcontrol-origin: margin;"
        "    left: 10px;"
        "    padding: 0 5px 0 5px;"
        "}"
        "QLabel {"
        "    color: #e2e8f0;"
        "}"
        "QCheckBox {"
        "    color: #e2e8f0;"
        "}"
        "QCheckBox::indicator {"
        "    width: 13px;"
        "    height: 13px;"
        "}"
        );
}

void RegistrationForm::setupValidators()
{

    QRegularExpression idRegex("^[A-Z]\\d{3}-\\d{2}[A-Z]-[A-Z]$");
    QRegularExpressionValidator *idValidator = new QRegularExpressionValidator(idRegex, this);
    idKeyEdit->setValidator(idValidator);


    QRegularExpression emailRegex("^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$");
    QRegularExpressionValidator *emailValidator = new QRegularExpressionValidator(emailRegex, this);
    emailEdit->setValidator(emailValidator);


    QRegularExpression nameRegex("^[A-Za-zА-Яа-я]{2,}$");
    QRegularExpressionValidator *nameValidator = new QRegularExpressionValidator(nameRegex, this);
    firstNameEdit->setValidator(nameValidator);
    lastNameEdit->setValidator(nameValidator);


    QRegularExpression nicknameRegex("^[A-Za-z0-9_]{3,}$");
    QRegularExpressionValidator *nicknameValidator = new QRegularExpressionValidator(nicknameRegex, this);
    nicknameEdit->setValidator(nicknameValidator);


    QRegularExpression passwordRegex("^.{6,}$");
    QRegularExpressionValidator *passwordValidator = new QRegularExpressionValidator(passwordRegex, this);
    passwordEdit->setValidator(passwordValidator);
}

bool RegistrationForm::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::MouseButtonDblClick) {
        if (obj == firstNameEdit) firstNameEdit->clear();
        else if (obj == lastNameEdit) lastNameEdit->clear();
        else if (obj == nicknameEdit) nicknameEdit->clear();
        else if (obj == idKeyEdit) idKeyEdit->clear();
        else if (obj == emailEdit) emailEdit->clear();
        else if (obj == passwordEdit) passwordEdit->clear();
        else if (obj == photoLabel) {
            currentPhotoPath.clear();
            defaultPhoto = QPixmap(150, 150);
            defaultPhoto.fill(QColor(45, 55, 72));
            photoLabel->setPixmap(QPixmap());
            photoLabel->setText("Фото\n");
            QMessageBox::information(this, "Успех", "Фото удалено");
        }
        return true;
    }
    return QWidget::eventFilter(obj, event);
}

bool RegistrationForm::validateFields()
{

    if (firstNameEdit->text().isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Пожалуйста, введите имя");
        return false;
    }
    if (lastNameEdit->text().isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Пожалуйста, введите фамилию");
        return false;
    }
    if (nicknameEdit->text().isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Пожалуйста, введите никнейм");
        return false;
    }
    if (idKeyEdit->text().isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Пожалуйста, введите ID-Key");
        return false;
    }
    if (emailEdit->text().isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Пожалуйста, введите почту");
        return false;
    }
    if (passwordEdit->text().isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Пожалуйста, введите пароль");
        return false;
    }


    if (!europeCheck->isChecked() && !asiaCheck->isChecked() && !americaCheck->isChecked()) {
        QMessageBox::warning(this, "Ошибка", "Пожалуйста, выберите хотя бы один сервер");
        return false;
    }


    QRegularExpression idRegex("^[A-Z]\\d{3}-\\d{2}[A-Z]-[A-Z]$");
    if (!idRegex.match(idKeyEdit->text()).hasMatch()) {
        QMessageBox::warning(this, "Ошибка", "ID-Key должен быть в формате: A111-11A-A");
        return false;
    }

    QRegularExpression emailRegex("^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$");
    if (!emailRegex.match(emailEdit->text()).hasMatch()) {
        QMessageBox::warning(this, "Ошибка", "Неверный формат email");
        return false;
    }

    QRegularExpression nameRegex("^[A-Za-zА-Яа-я]{2,}$");
    if (!nameRegex.match(firstNameEdit->text()).hasMatch()) {
        QMessageBox::warning(this, "Ошибка", "Имя должно содержать только буквы (минимум 2 символа)");
        return false;
    }
    if (!nameRegex.match(lastNameEdit->text()).hasMatch()) {
        QMessageBox::warning(this, "Ошибка", "Фамилия должна содержать только буквы (минимум 2 символа)");
        return false;
    }

    QRegularExpression nicknameRegex("^[A-Za-z0-9_]{3,}$");
    if (!nicknameRegex.match(nicknameEdit->text()).hasMatch()) {
        QMessageBox::warning(this, "Ошибка", "Никнейм должен содержать буквы, цифры или _ (минимум 3 символа)");
        return false;
    }

    QRegularExpression passwordRegex("^.{6,}$");
    if (!passwordRegex.match(passwordEdit->text()).hasMatch()) {
        QMessageBox::warning(this, "Ошибка", "Пароль должен содержать минимум 6 символов");
        return false;
    }

    return true;
}

bool RegistrationForm::isNicknameTaken(const QString &nickname)
{
    QString desktopPath = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
    QString accountsPath = desktopPath + "/Accounts";

    QDir accountsDir(accountsPath);
    if (!accountsDir.exists()) {
        return false;
    }


    return accountsDir.exists(nickname);
}

QString RegistrationForm::encryptPassword(const QString &password)
{

    QByteArray hash = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256);
    return hash.toHex();
}

void RegistrationForm::createAccountDirectory(const QString &nickname, const QJsonObject &userData, const QString &encryptedPassword)
{
    QString desktopPath = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
    QString accountsPath = desktopPath + "/Accounts";
    QString userPath = accountsPath + "/" + nickname;


    QDir dir;
    if (!dir.exists(accountsPath)) {
        dir.mkpath(accountsPath);
    }
    if (!dir.exists(userPath)) {
        dir.mkpath(userPath);
    }


    QString photoPath = userPath + "/avatar.jpg";
    if (!currentPhotoPath.isEmpty() && QFile::exists(currentPhotoPath)) {
        QFile::copy(currentPhotoPath, photoPath);
    } else {
        defaultPhoto.save(photoPath, "JPG");
    }


    QJsonObject jsonData = userData;
    jsonData.remove("password");

    QFile jsonFile(userPath + "/user_data.json");
    if (jsonFile.open(QIODevice::WriteOnly)) {
        QJsonDocument doc(jsonData);
        jsonFile.write(doc.toJson());
        jsonFile.close();
    }


    QFile txtFile(userPath + "/password.txt");
    if (txtFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&txtFile);
        out << emailEdit->text() << "/" << encryptedPassword;
        txtFile.close();
    }
}

void RegistrationForm::onRegisterClicked()
{
    if (!validateFields()) {
        return;
    }

    QString nickname = nicknameEdit->text();


    if (isNicknameTaken(nickname)) {
        QMessageBox::warning(this, "Ошибка", "Данный никнейм уже занят");
        return;
    }


    QJsonObject userData;
    userData["first_name"] = firstNameEdit->text();
    userData["last_name"] = lastNameEdit->text();
    userData["nickname"] = nickname;
    userData["email"] = emailEdit->text();
    userData["id_key"] = idKeyEdit->text();


    QStringList servers;
    if (europeCheck->isChecked()) servers.append("Европа");
    if (asiaCheck->isChecked()) servers.append("Азия");
    if (americaCheck->isChecked()) servers.append("Америка");


    QJsonArray serversArray;
    for (const QString &server : servers) {
        serversArray.append(server);
    }
    userData["servers"] = serversArray;

    userData["photo_path"] = currentPhotoPath.isEmpty() ? "default" : currentPhotoPath;


    QString encryptedPassword = encryptPassword(passwordEdit->text());


    createAccountDirectory(nickname, userData, encryptedPassword);

    QMessageBox::information(this, "Успех",
                             QString("Регистрация успешно завершена!\n"
                                     "Данные сохранены в папке: Рабочий стол/Accounts/%1").arg(nickname));


    firstNameEdit->clear();
    lastNameEdit->clear();
    nicknameEdit->clear();
    idKeyEdit->clear();
    emailEdit->clear();
    passwordEdit->clear();
    europeCheck->setChecked(false);
    asiaCheck->setChecked(false);
    americaCheck->setChecked(false);
    currentPhotoPath.clear();
    photoLabel->setText("Фото\n");
    photoLabel->setPixmap(QPixmap());
}

void RegistrationForm::onLoadPhotoClicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    "Выберите фото",
                                                    QDir::homePath(),
                                                    "Images (*.png *.jpg *.jpeg *.bmp)");

    if (!fileName.isEmpty()) {
        QPixmap pixmap(fileName);
        if (!pixmap.isNull()) {
            currentPhotoPath = fileName;
            photoLabel->setPixmap(pixmap.scaled(150, 150, Qt::KeepAspectRatio, Qt::SmoothTransformation));
            photoLabel->setText("");
        } else {
            QMessageBox::warning(this, "Ошибка", "Не удалось загрузить изображение");
        }
    }
}
