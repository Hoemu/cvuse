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
    // 设置初始值
    config->setValue("remote/name", "tcp_remote");
    config->setValue("remote/ip", "127.0.0.1");
    config->setValue("remote/port", "9999");
    config->setValue("remote/is_use", "true");

    config->sync();
}

const QString ConfigSetting::getValue(const QString &key)
{
    return configHash.value(key);
}

const QString ConfigSetting::setValue(const QString &key)
{
    temp = key;
    return configHash[key];
}

void ConfigSetting::clear()
{
    configHash.clear();
}
