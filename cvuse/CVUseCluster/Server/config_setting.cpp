#include "config_setting.h"

#include <QFile>

ConfigSetting::ConfigSetting()
{
    config = new QSettings("./config/network_config.ini", QSettings::IniFormat);

    init();
}

ConfigSetting::~ConfigSetting()
{
    delete config;
}

void ConfigSetting::init()
{
    config->setValue("remote/ip", "123");
    config->sync();
}

const QString ConfigSetting::getValue(const QString &key)
{
    return configHash.value(key);
}

const QString ConfigSetting::setValue(const QString &key)
{
    temp = key;
}
