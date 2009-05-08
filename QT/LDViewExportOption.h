#ifndef __LDVIEWExportOption_H__
#define __LDVIEWExportOption_H__

#include "ui_ExportOptionPanel.h"
#include <TCFoundation/TCStlIncludes.h>
#include <QtGui/QDialog>

class QScrollView;
class QVBox;
class Preferences;
class LDrawModelViewer;
class LDExporter;
class LDExporterSetting;

typedef std::map<LDExporterSetting *, QWidget *> SettingsMap;

class LDViewExportOption : public QDialog , Ui::ExportOptionPanel
{
	Q_OBJECT
public:
	LDViewExportOption(QWidget *parent,LDrawModelViewer *modelViewer);
	~LDViewExportOption();

public slots:
	int exec(void);
	void doOk(void);
	void doCancel(void);
	void doReset(void);

protected:
//	void populateTypeBox(void);
	void populate(void);

	void doTypeBoxActivated(void);

	LDrawModelViewer *m_modelViewer;
    LDExporter *m_exporter;
	QScrollView *m_sv;
	QVBox *m_box;
	SettingsMap m_settings;
	int m_origType;
};

#endif // __LDVIEWExportOption_H__
