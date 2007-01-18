#ifndef __LDVIEWPARTLIST_H__
#define __LDVIEWPARTLIST_H__

#include "ModelViewerWidget.h"
#include "LDLib/LDHtmlInventory.h"

class PartListPanel;
class QButton;
class LDHtmlInventory;
class QCheckListItem;

class PartList
{
public:
	PartList(ModelViewerWidget *modelWidget, LDHtmlInventory *htmlInventory);
	~PartList(void);

	void doOk();
	void doCancel();
	void doUp();
	void doDown();
	int exec();
	int result();
	void controlDirectionButtons();
	void populateColumnList();
	QCheckListItem *description;
protected:
	void doMoveColumn(int distance);
	LDrawModelViewer *modelViewer;
	ModelViewerWidget *modelWidget;
	PartListPanel *panel;
	LDHtmlInventory *m_htmlInventory;
};
#endif //__LDVIEWPARTLIST_H__
