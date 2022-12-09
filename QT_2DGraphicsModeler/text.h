#ifndef TEXT_H
#define TEXT_H

#include "shape.h"
#include <QString>

class Text : public Shape
{
	public:
		//Constructor
        Text(QPaintDevice* device = nullptr, int newID = -1, ShapeType newShapeType = ShapeType::Text);

		//Alternate Constructor
		//In order : ID, Text, Font, Color, Position, Height, Width, Alignment
        Text(int newId, QString newString, QFont newFont, QColor newColor, QPoint newPos,
             int newHeight, int newWidth, Qt::AlignmentFlag newAlign);

		/***********
		* ACCESSOR
         ***********/
        QString GetTextString() const;

        Qt::AlignmentFlag GetAlign() const
        {
            return textAlignment;
        }
        QFont GetFont() const
        {
            return textFont;
        }

		/***********
		 * MUTATORS
		 ***********/
		void SetWidth(const int userWidth);
		void SetHeight(const int userHeight);
		void SetTextString(const QString userString);
		void SetColor(const QColor userColor);
		void SetFont(const QFont userFont);
        void SetAlignment(const Qt::AlignmentFlag userAlignment);


		//Derived
        virtual void Draw(QPainter* painter);

		    // Move function
//        virtual void Move(int xCoord, int yCoord);

		    // CalcPerimeter
        virtual double CalcPerimeter() const;

		    // CalcArea
        virtual double CalcArea() const;

	private:
		int width;	//Text Box Width
		int height; //Text Box Height
		QString textString;  //Text to display
		QFont textFont;		 //Handles PointSize, Style, Weight, and FontFamily

		//Qt::GlobalColor
		QColor textColor;	 //TextColor

		//Qt::AlignmentFlag
        Qt::AlignmentFlag textAlignment; //Alignment of text can be: left, center, top, etc...


};

#endif // TEXT_H
