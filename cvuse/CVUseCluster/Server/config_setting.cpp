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
    config->setValue("remoteTCP/ip", "127.0.0.1");
    config->setValue("remoteTCP/port", "2222");
    config->setValue("remoteTCP/brif", "TCP 基本信息");

    config->setValue("remoteUDP/ip", "127.0.0.1");
    config->setValue("remoteUDP/port", "1111");
    config->setValue("remoteUDP/brif", "UDP 基本信息");
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
