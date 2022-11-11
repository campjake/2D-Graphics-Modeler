#ifndef FILEPARSER_H_
#define FILEPARSER_H_

#incluide <iostream>
#include <string>
#include <fstream>
#include <map>
#include <limits>
#include "vector.h"
#include "Shape.h"
#include "Line.h"
#include "Polyline.h"
#include "Polygon.h"
#include "Rectangle.h"
#include "Ellipse.h"
#include "Text.h"

enum ShapeNames
{
	LINE = 1,
	POLYLINE,
	POLYGON,
	RECTANGLE,
	ELLIPSE,
	CIRCLE,
	TEXT
};

extern const QMap<ShapenNames, std::string> INPUT_SHAPE_NAMES;

vector<Shape*> LoadFile();

#endif // FILEPARSER_H_
