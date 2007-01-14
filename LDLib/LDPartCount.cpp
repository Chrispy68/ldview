#include "LDPartCount.h"
#include <LDLoader/LDLModel.h>

LDPartCount::LDPartCount(void)
	:m_model(NULL),
	m_totalCount(0),
	m_colorsCalculated(false)
{
}

LDPartCount::LDPartCount(const LDPartCount &other)
	:m_filename(other.m_filename),
	m_model((LDLModel *)TCObject::retain(other.m_model)),
	m_totalCount(other.m_totalCount),
	m_colorCounts(other.m_colorCounts),
	m_colors(other.m_colors),
	m_colorsCalculated(other.m_colorsCalculated)
{
}

LDPartCount::~LDPartCount(void)
{
	TCObject::release(m_model);
}

void LDPartCount::setModel(const char *filename, LDLModel *model)
{
	if (model != m_model)
	{
		TCObject::release(m_model);
		m_model = model;
		m_model->retain();
		m_totalCount = 0;
		m_filename = filename;
	}
}

void LDPartCount::addPart(int color)
{
	m_totalCount++;
	m_colorCounts[color]++;
	m_colorsCalculated = false;
}

int LDPartCount::getColorCount(int color) const
{
	IntIntMap::const_iterator it = m_colorCounts.find(color);

	if (it != m_colorCounts.end())
	{
		return it->second;
	}
	return 0;
}

const IntVector &LDPartCount::getColors(void) const
{
	if (!m_colorsCalculated)
	{
		IntIntMap::const_iterator it;

		m_colorsCalculated = true;
		m_colors.clear();
		m_colors.reserve(m_colorCounts.size());
		for (it = m_colorCounts.begin(); it != m_colorCounts.end(); it++)
		{
			m_colors.push_back(it->first);
		}
	}
	return m_colors;
}
