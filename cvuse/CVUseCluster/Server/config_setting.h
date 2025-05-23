#ifndef CONFIG_SETTING_H
#define CONFIG_SETTING_H

#include <QSettings>

class ConfigSetting
{
public:
    ConfigSetting();
    ~ConfigSetting();

    const QString getValue(const QString &key);

    const QString setValue(const QString &key);

protected:
    void init();

private:
    QSettings *config;

    QHash<QString, QString> configHash;

    QString temp;
};

#endif // CONFIG_SETTING_H
