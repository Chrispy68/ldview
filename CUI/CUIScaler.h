#ifndef __CUISCALER_H__
#define __CUISCALER_H__

#include <CUI/CUIWindow.h>

class CUIExport CUIScaler : public TCObject
{
public:
	CUIScaler(CUIWindow *window);
	double getScaleFactor(bool recalculate = false, UINT *dpiX = NULL,
		UINT *dpiY = NULL);
	int scale(int points) { return (int)(points * getScaleFactor()); }
	int unscale(int pixels) { return (int)(pixels / getScaleFactor()); }
	bool scaleBitmap(HBITMAP hSrc, HBITMAP& hDst, double scaleFactor = -1.0);
	static bool use32bit(void) { return sm_use32bit; }
	static UINT imageListCreateFlags(void)
	{
		return use32bit() ? ILC_COLOR32 : ILC_COLOR24 | ILC_MASK;
	}
protected:
	virtual ~CUIScaler(void);
	virtual void dealloc(void);

	CUIWindow *m_window;
	HDC m_hScaleSrcDC;
	HDC m_hScaleDstDC;
	double m_scaleFactor;
	UINT m_dpiX;
	UINT m_dpiY;
	static bool sm_use32bit;
};

#endif // __CUISCALER_H__