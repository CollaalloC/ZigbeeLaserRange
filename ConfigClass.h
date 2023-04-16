#pragma once

#include <QWidget>
#include "ui_ConfigClass.h"
#include "Config.h"

class ConfigClass : public QWidget
{
	Q_OBJECT

public:
	ConfigClass(QWidget *parent = nullptr);
	~ConfigClass();

private:
	Ui::ConfigClassClass ui;
};
