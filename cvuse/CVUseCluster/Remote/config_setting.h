#ifndef CONFIG_SETTING_H
#define CONFIG_SETTING_H

#include <QSettings>

struct RemoteCode
{
    const QString code_send = "[code]:send";
    const QString code_accept = "[code]:accept";
};

class ConfigSetting
{
public:
    ConfigSetting();
    ~ConfigSetting();

    const QString getValue(const QString &key);

    const void setValue(const QString &key);

protected:
    void init();

private:
    QSettings *config;

    QHash<QString, QString> configHash;

    QString temp;
};

#endif // CONFIG_SETTING_H
