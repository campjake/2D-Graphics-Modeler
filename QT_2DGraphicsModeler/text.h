#ifndef TEXT_H
#define TEXT_H

#include "shape.h"

class Text : public Shape
{
	public:
		//Constructor
		Text();

		//Alternate Constructor
		//In order : ID, Text, Font, Color, Position, Height, Width, Alignment
		Text(int newId, QString newString, QFont newFont, QColor newColor, QPoint newPos,
			 int newHeight, int newWidth, AlignmentFlag newAlign);

		/***********
		* ACCESSPR
		 ***********/
		Qstring GetTextString() const;

		/***********
		 * MUTATORS
		 ***********/
		void SetWidth(const int userWidth);
		void SetHeight(const int userHeight);
		void SetTextString(const QString userString);
		void SetColor(const QColor userColor);
		void SetFont(const QFont userFont);
		void SetAlignment(const AlignmentFlag userAlignment);


		//Derived
		void Draw(QPainter painter) const;

		    // Move function
		void Move(int xCoord, int yCoord);

		    // CalcPerimeter
		 double CalcPerimeter();

		    // CalcArea
		 double CalcArea();

	private:
		int width;	//Text Box Width
		int height; //Text Box Height
		QString textString;  //Text to display
		QFont textFont;		 //Handles PointSize, Style, Weight, and FontFamily

		//Qt::GlobalColor
		QColor textColor;	 //TextColor

		//Qt::AlignmentFlag
		AlignmentFlag textAlignment; //Alignment of text can be: left, center, top, etc...


};

#endif // TEXT_H
