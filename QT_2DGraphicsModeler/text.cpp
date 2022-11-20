#include "text.h"

//Default Constructor
Text::Text()	: Shape()
{
	SetShapeType(ShapeType::Text);
	width = 12;
	height = 9;
	textString     = "Text";
	textAlignment  = AlignLeft;
	textFont.setPointSize(12);
	textFont.setWeight(Weight::Thin);
	textFont.setStyle(Style::StyleNormal);
}

//Alternate Constructor
//In order : ID, Text, Font, Color, Position, Height, Width, Alignment
Text::Text(int newId, QString newString, QFont newFont, QColor newColor, QPoint newPos,
			int newHeight, int newWidth, AlignmentFlag newAlign)

	: textString{newString}, textFont{newFont}, texColor{newColor},
	  width{newWidth}, height{newHeight}, textAlignment{newAlign}
{
	Shape::SetID(newId);
	Shape::SetPos(newPos);
	Shape::SetShapeType(ShapeType::Text);
}

/*********************************************************************
* void GetTextString
* ------------------------------------------------------------------
* This method returns QString textString
* Post-Condition: returns textString
*********************************************************************/
Qstring Text::GetTextString() const{
	return textString;
}

/***********
 * MUTATORS
 ***********/

/*********************************************************************
* void SetWidth
* ------------------------------------------------------------------
* This method sets width to userWidth
* Post-Condition: width = userWidth
*********************************************************************/
void Text::SetWidth(const int userWidth){
	width = userWidth;
}

/*********************************************************************
* void SetHeight
* ------------------------------------------------------------------
* This method sets height to userHeight
* Post-Condition: height = userHeight
*********************************************************************/
void Text::SetHeight(const int userHeight){
	height = userHeight;
}
/*********************************************************************
* void SetTextString
* ------------------------------------------------------------------
* This method sets textString to userString
* Post-Condition: textString = userString
*********************************************************************/
void Text::SetTextString(const Qstring userString){
	textString = userString;
}
/*********************************************************************
* void SetColor
* ------------------------------------------------------------------
* This method sets textColor to userColor
* Post-Condition: textColor = userColor
*********************************************************************/
void Text::SetColor(const QColor userColor){
	textColor = userColor;
}
/*********************************************************************
* void SetFont
* ------------------------------------------------------------------
* This method sets textFont to userFont
* Post-Condition: textFont = userFont
*********************************************************************/
void Text::SetFont(const QFont userFont){
	textFont = userFont;
}

/*********************************************************************
* void SetAlignment
* ------------------------------------------------------------------
* Alignment can be: AlignLeft, AlignRight, AlignTop, AlignBottom, AlignCenter
* This method sets textAlignment to userAlignment
* Post-Condition: textAlignment = userAlignment
*********************************************************************/
void Text::SetAlignment(const AlignmentFlag userAlignment){
	textAlignment = userAlignment;
}


//Derived
/*********************************************************************
* void Draw
* ------------------------------------------------------------------
* Draws the text onto the canvas. Assigns painter the color and QFont
* written on the text variable then outputs the text within the given
* boundary box.
*********************************************************************/
void Text::Draw(QPainter painter) const{

	QSize rectSize(width, height);	//Dimension for boundingBox
	QRect boundBox(Shape::GetPos(), rectSize);	//Text Location + box size

	painter.setPen(textColor);	//Assigns Qcolor textColor
	painter.setFont(textFont);	//Assigns QFont textFont

	//This uses drawText(const QRect &rectangle, int flags, const QString &text, QRect *boundingRect = nullptr)
	painter.drawText(boundBox, textAlignment, textString);
}

/*********************************************************************
* void Draw
* ------------------------------------------------------------------
* Draws the text onto the canvas. Assigns painter the color and QFont
* written on the text variable then outputs the text within the given
* boundary box.
*********************************************************************/
void Text::Move(int xCoord, int yCoord){
	Shape::SetPos(QPoint(xCoord, yCoord));
}

//-1 as text shouldnt have perimeter/area
double Text::CalcPerimeter(){
	return -1;
}

   // CalcArea
double Text::CalcArea(){
	return -1;
}
