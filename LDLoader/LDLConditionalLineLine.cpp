#include "LDLConditionalLineLine.h"

LDLConditionalLineLine::LDLConditionalLineLine(LDLModel *mainModel,
											   const char *line, int lineNumber)
	:LDLLineLine(mainModel, line, lineNumber),
	m_controlPoints(NULL)
{
}

LDLConditionalLineLine::LDLConditionalLineLine(const LDLConditionalLineLine
											   &other)
	:LDLLineLine(other),
	m_controlPoints(NULL)
{
	if (other.m_controlPoints)
	{
		int i;
		int count = other.getNumControlPoints();

		m_controlPoints = new Vector[count];
		for (i = 0; i < count; i++)
		{
			m_controlPoints[i] = other.m_controlPoints[i];
		}
	}
}

bool LDLConditionalLineLine::parse(void)
{
	float x1, y1, z1;
	float x2, y2, z2;
	float x3, y3, z3;
	float x4, y4, z4;
	int lineType;

	if (sscanf(m_line, "%d %i %f %f %f %f %f %f %f %f %f %f %f %f", &lineType,
		&m_colorNumber, &x1, &y1, &z1, &x2, &y2, &z2, &x3, &y3, &z3,
		&x4, &y4, &z4) == 14)
	{
		m_points = new Vector[2];
		m_points[0] = Vector(x1, y1, z1);
		m_points[1] = Vector(x2, y2, z2);
		m_controlPoints = new Vector[2];
		m_controlPoints[0] = Vector(x3, y3, z3);
		m_controlPoints[1] = Vector(x4, y4, z4);
		return true;
	}
	else
	{
		setError(LDLEParse, "Error parsing conditional line line.");
		return false;
	}
}

void LDLConditionalLineLine::dealloc(void)
{
	delete[] m_controlPoints;
	LDLLineLine::dealloc();
}

TCObject *LDLConditionalLineLine::copy(void)
{
	return new LDLConditionalLineLine(*this);
}
