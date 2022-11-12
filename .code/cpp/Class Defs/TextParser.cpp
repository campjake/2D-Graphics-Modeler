#include "TextParser.h"

#include <Qt>
#include <QPen>
#include <QColor>
#include <QFont>
#include <QMap>
#include <QPoint>

Shape* ReadLine(std::ifstream&, int id);
Shape* ReadPolyline(std::ifstream&, int id);
Shape* ReadPolygon(std::ifstream&, int id);
Shape* ReadRectangle(std::ifstream&, int id);
Shape* ReadEllipse(std::ifstream&, int id);
Shape* ReadText(std::ifstream&, int id);

Qt::GlobalColor		getColor(const std::string&);
Qt::PenStyle		getPenStyle(const std::string&);
Qt::PenCapStyle		getCapStyle(const std::string&);
Qt::PenJoinStyle	getPenJoinStyle(const std::string&);
Qt::BrushStyle		getBrushStyle(const std::string&);
QFont::Weight		getFontWeight(const std::string*);	


const QMap<ShapeNames, std::string> INPUT_SHAPE_NAMES
{
	{LINE, "Line"},
	{POLYLINE, "Polyline"},
	{POLYGON, "Polygon"},
	{RECTANGLE, "Rectangle"},
	{ELLIPSE, "Ellipse"},
	{TEXT, "Text"}
}

vector<Shape*> LoadFile()
{
	ifstream fin;
	fin.open("shapes.txt");

	vector<Shape*> v_Shapes;
	int id;

	while(fin)
	{
		std::string typeString;
		ShapeNames typeShape;


		// BEGIN READING THE FILES

		// 1st line is empty, ignore until we reach colon
		fin.ignore(std::numeric_limits<std::streamsize>::max(), ':');
		// GET SHAPE ID
		fin >> id;
		fin.ignore(std::numeric_limits<std::streamsize>::max(), ':');

		// GET SHAPE TYPE
		getline(fin, typeString);
		type = INPUT_SHAPE_NAMES.key(typeString);

		// If we are at the end of the file, do not enter the SWITCH
		if(fin.eof())
		{
			break;
		}

		// Determine how we read in the file based on the shape type
		switch(typeShape)
		{
			case LINE 		: v_Shapes.push_back(ReadLine(fin, id));
			break;
			
			case POLYLINE 	: v_Shapes.push_back(ReadPolyline(fin, id));
			break;
						
			case POLYGON 	: v_Shapes.push_back(ReadPolygon(fin, id));
			break;
			
			case RECTANGLE 	: v_Shapes.push_back(ReadRectangle(fin, id));
			break;
			
			case ELLIPSE 	: v_Shapes.push_back(ReadEllipse(fin, id));
			break;
			
			case TEXT 		: v_Shapes.push_back(ReadText(fin, id));
			break;
		}

	}

	fin.close();

	return v_Shapes;
}

// Read the relevant info for a Line object using a Shape pointer
// Pre-conditions - fin input file must be open & pass in id
// Post-conditions - Returns a Shape pointer to a new line object
Shape* ReadLine(std::ifstream& fin, int id)
{
	// We have 1) ID & 2) Shape Name, 3 - 6
	// coordinates
	int x1;				
	int y1;
	int x2;
	int y2;

	// Pen Properties
	string 	color;
	int		penWidth;
	string 	penStyle;
	string  capStyle;
	string	joinStyle;
	


	// 1) Dimensions
	fin.ignore(std::numeric_limits<std::streamsize>::max(), ':');

	fin >> x1;
	fin.ignore(std::numeric_limits<std::streamsize>::max(), ',');
	fin >> y1;
	fin.ignore(std::numeric_limits<std::streamsize>::max(), ',');
	fin >> x2;
	fin.ignore(std::numeric_limits<std::streamsize>::max(), ',');
	fin >> y2;

	QPoint front(x1, y1);
	QPoint end(x2, y2);

	fin.ignore(std::numeric_limits<std::streamsize>::max(), ':');

	// 2) Color
	getline(fin, color);
	fin.ignore(std::numeric_limits<std::streamsize>::max(), ':');

	// 3) Width
	fin >> penWidth;
	fin.ignore(std::numeric_limits<std::streamsize>::max(), ':');

	// 4) Pen Style
	getline(fin, penStyle);
	fin.ignore(std::numeric_limits<std::streamsize>::max(), ':');

	// 5) Cap Style
	getline(fin, capStyle);
	fin.ignore(std::numeric_limits<std::streamsize>::max(), ':');

	// 6) Pen Join Style
	getline(fin, joinStyle);
	fin.ignore(std::numeric_limits<std::streamsize>::max(), ':');
	
	// Instantiate brush & pen using strings we read in previously ^^^
	QBrush brush(color);
	QPen pen(brush, penWidth, getPenStyle(style), 
			 getCapStyle(capStyle), getPenJoinStyle(joinStyle));

	// Instantiate Line object using the brush, pen, & data passed in
	Line  *line = new Line(front, end, brush, pen, id);

	return line;
}

// Read the relevant info for a Polyline object using a Shape pointer
// Pre-conditions - fin input file must be open & pass in id
// Post-conditions - Returns a Shape pointer to a new polyline object
Shape* ReadPolyline(std::ifstream& fin, int id)
{
	// We have 1) ID & 2) Shape Name, 3 - 6 needed
	int count;
	// Pen Properties
	string 	color;
	int		penWidth;
	string 	penStyle;
	string  capStyle;
	string	joinStyle;
	
	char comma;
	bool invalid = true;
	int  points = 2;

	// 1) Dimensions
		// Polyline has at least 4 coordinates
	vector<QPoint> polylineDimensions(points);
	int x1;				
	int y1;
	int x2;
	int y2;

	fin.ignore(std::numeric_limits<std::streamsize>::max(), ':');

	fin >> polylineDimensions[0];
	fin.ignore(std::numeric_limits<std::streamsize>::max(), ',');
	fin >> polylineDimensions[1];
	fin.ignore(std::numeric_limits<std::streamsize>::max(), ',');
	fin >> polylineDimensions[2];
	fin.ignore(std::numeric_limits<std::streamsize>::max(), ',');
	fin >> polylineDimensions[3];

	// Gets first 4 coordinates
	QPoint p1(x1, y1);
	QPoint p2(x2, y2);
	polylineDimensions[0] = p1;
	polylineDimensions[1] = p2;

	// Get n number of coordinates
	do
	{
		fin.get(comma);

		if(comma == ',')
		{
			int tempX;
			int tempY;
			fin >> tempX;
			fin.ignore(std::numeric_limits<std::streamsize>::max(), ',');
			fin >> tempY;

			QPoint tempP(tempX, tempY);
			polylineDimensions.push_back(tempP);

			points++;
			
		}
		else
		{
			invalid = false;
		}
	} while (invalid);

	fin.ignore(std::numeric_limits<std::streamsize>::max(), ':');

	// 2) Color
	getline(fin, color);
	fin.ignore(std::numeric_limits<std::streamsize>::max(), ':');

	// 3) Width
	fin >> penWidth;
	fin.ignore(std::numeric_limits<std::streamsize>::max(), ':');

	// 4) Pen Style
	getline(fin, penStyle);
	fin.ignore(std::numeric_limits<std::streamsize>::max(), ':');

	// 5) Cap Style
	getline(fin, capStyle);
	fin.ignore(std::numeric_limits<std::streamsize>::max(), ':');

	// 6) Pen Join Style
	getline(fin, joinStyle);
	fin.ignore(std::numeric_limits<std::streamsize>::max(), ':');
	
	// Instantiate brush & pen using strings we read in previously ^^^
	QBrush brush(color);
	QPen pen(brush, penWidth, getPenStyle(style), 
			 getCapStyle(capStyle), getPenJoinStyle(joinStyle));

	// Instantiate Line object using the brush, pen, & data passed in
	Polyline *polyline = new Polyline(polylineDimensions, brush, pen, id);

	return polyline;
}

Shape* ReadPolygon(std::ifstream& fin, int id)
{
		// We have 1) ID & 2) Shape Name, 3 - 6 needed
	int count;
	// Pen Properties
	string 	color;
	int		penWidth;
	string 	penStyle;
	string  capStyle;
	string	joinStyle;
	string	brushColor;
	string	brushStyle;
	
	char comma;
	bool invalid = true;
	int  points = 2;

	// 1) Dimensions
		// polygon has at least 4 coordinates
	vector<QPoint> polygonDimensions(points);
	int x1;				
	int y1;
	int x2;
	int y2;

	fin.ignore(std::numeric_limits<std::streamsize>::max(), ':');

	fin >> polygonDimensions[0];
	fin.ignore(std::numeric_limits<std::streamsize>::max(), ',');
	fin >> polygonDimensions[1];
	fin.ignore(std::numeric_limits<std::streamsize>::max(), ',');
	fin >> polygonDimensions[2];
	fin.ignore(std::numeric_limits<std::streamsize>::max(), ',');
	fin >> polygonDimensions[3];

	// Gets first 4 coordinates
	QPoint p1(x1, y1);
	QPoint p2(x2, y2);
	polygonDimensions[0] = p1;
	polygonDimensions[1] = p2;

	// Get n number of coordinates
	do
	{
		fin.get(comma);

		if(comma == ',')
		{
			int tempX;
			int tempY;
			fin >> tempX;
			fin.ignore(std::numeric_limits<std::streamsize>::max(), ',');
			fin >> tempY;

			QPoint tempP(tempX, tempY);
			polygonDimensions.push_back(tempP);

			points++;
			
		}
		else
		{
			invalid = false;
		}
	} while (invalid);

	fin.ignore(std::numeric_limits<std::streamsize>::max(), ':');

	// 2) Color
	getline(fin, color);
	fin.ignore(std::numeric_limits<std::streamsize>::max(), ':');

	// 3) Width
	fin >> penWidth;
	fin.ignore(std::numeric_limits<std::streamsize>::max(), ':');

	// 4) Pen Style
	getline(fin, penStyle);
	fin.ignore(std::numeric_limits<std::streamsize>::max(), ':');

	// 5) Cap Style
	getline(fin, capStyle);
	fin.ignore(std::numeric_limits<std::streamsize>::max(), ':');

	// 6) Pen Join Style
	getline(fin, joinStyle);
	fin.ignore(std::numeric_limits<std::streamsize>::max(), ':');

	// 7) Pen Join Style
	getline(fin, brushColor);
	fin.ignore(std::numeric_limits<std::streamsize>::max(), ':');

	// 8) Pen Join Style
	getline(fin, brushStyle);
	fin.ignore(std::numeric_limits<std::streamsize>::max(), ':');
	
	// Instantiate brush & pen using strings we read in previously ^^^
	QBrush brush(brushColor, brushStyle);
	QBrush brushForPen(color, penStyle);
	QPen pen(brushforPen, penWidth, getPenStyle(style), 
			 getCapStyle(capStyle), getPenJoinStyle(joinStyle));

	// Instantiate Line object using the brush, pen, & data passed in
	Polylgon *polygon = new Polygon(polygonDimensions, brush, pen, id);

	return polygon;
}

Shape* ReadRectangle(std::ifstream& fin, int id)
{
	
}

Shape* ReadEllipse(std::ifstream& fin, int id)
{
	
}

Shape* ReadText(std::ifstream& fin, int id)
{
	
}