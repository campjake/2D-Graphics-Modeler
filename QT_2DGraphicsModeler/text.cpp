#include "text.h"

//Default Constructor
Text::Text(QPaintDevice* device, int newID, ShapeType newShapeType)	:Shape(device, newID, newShapeType)
{
	width = 12;
	height = 9;
	textString     = "Text";
    textAlignment  = Qt::AlignLeft;
	textFont.setPointSize(12);
    textFont.setWeight(QFont::Weight::Thin);
    textFont.setStyle(QFont::Style::StyleNormal);
}

//Alternate Constructor
//In order : ID, Text, Font, Color, Position, Height, Width, Alignment
Text::Text(int newId, QString newString, QFont newFont, QColor newColor, QPoint newPos,
            int newHeight, int newWidth, Qt::AlignmentFlag newAlign)

    :  width{newWidth}, height{newHeight}, textString{newString},
       textFont{newFont}, textColor{newColor}, textAlignment{newAlign}
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
QString Text::GetTextString() const{
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
void Text::SetTextString(const QString userString){
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
void Text::SetAlignment(const Qt::AlignmentFlag userAlignment){
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
void Text::Draw(QPainter* painter) {

	QSize rectSize(width, height);	//Dimension for boundingBox
	QRect boundBox(Shape::GetPos(), rectSize);	//Text Location + box size

    painter->setPen(textColor);	//Assigns Qcolor textColor
    painter->setFont(textFont);	//Assigns QFont textFont

	//This uses drawText(const QRect &rectangle, int flags, const QString &text, QRect *boundingRect = nullptr)
    painter->drawText(boundBox, textAlignment, textString);

    painter->drawText(GetPos(), QString::number(GetID()));
}

/*********************************************************************
* void Draw
* ------------------------------------------------------------------
* Draws the text onto the canvas. Assigns painter the color and QFont
* written on the text variable then outputs the text within the given
* boundary box.
*********************************************************************/
//void Text::Move(int xCoord, int yCoord){
//	Shape::SetPos(QPoint(xCoord, yCoord));
//}

//-1 as text shouldnt have perimeter/area
double Text::CalcPerimeter() const{
	return -1;
}

   // CalcArea
double Text::CalcArea() const{
	return -1;
}

void Text::Print(QTextStream &fout)
{
    vector<QString>  dimensions;
    QString shapeName = "Text";

    QString colorName;
    QString style;

    dimensions.resize(4);
    dimensions[0] = QString::number(GetPos().x()) + ", ";
    dimensions[1] = QString::number(GetPos().y()) + ", ";

    dimensions[2] = QString::number(GetWidth()) + ", ";
    dimensions[3] = QString::number(GetHeight());

    // Print Text to File
    fout << "\nShapeId: "   << GetID();
    fout << "\nShapeType: " << shapeName;
    fout << "\nShapeDimensions: ";

    // Print Position, A, B
    for(int i = 0; i < dimensions.size() - 1; i++)
    {
        fout << dimensions[i];
    }

    fout << dimensions[dimensions.size() - 1];

    // Print Pen Color
    if(GetPen().color()  == QColor(Qt::red))
    {
        colorName = "red";
    }
    else if(GetPen().color() == QColor(Qt::green))
    {
        colorName = "green";

    }
    else if(GetPen().color() == QColor(Qt::blue))
    {
        colorName = "blue";
    }
    else if(GetPen().color() == QColor(Qt::yellow))
    {
        colorName = "yellow";
    }
    else if(GetPen().color() == QColor(Qt::cyan))
    {
        colorName = "cyan";
    }
    else if(GetPen().color() == QColor(Qt::magenta))
    {
        colorName = "magenta";
    }
    else if(GetPen().color() == QColor(Qt::white))
    {
        colorName = "white";
    }
    else if(GetPen().color() == QColor(Qt::black))
    {
        colorName = "black";
    }
    else if(GetPen().color() == QColor(Qt::gray))
    {
        colorName = "gray";
    }

    fout << "\nPenColor: " << colorName;

    // Print Pen Width
    fout << "\nPenWidth: " << GetPen().width();

    // Get Pen Style
    switch(GetPen().style())
      {
          case 0: style = "NoPen";
                  break;
          case 1: style = "SolidLine";
                  break;
          case 2: style = "DashLine";
                  break;
          case 3: style = "DotLine";
                  break;
          case 4: style = "DashDotLine";
                  break;
          case 5: style = "DashDotDotLine";
                  break;
          case 6: style = "CustomDashLine";
                  break;
          case 15: style = "MPenStyle";
      }

    fout << "\nPenStyle: " << style;

    //Handling PenCapStyle using enum values for capstyle
    switch(GetPen().capStyle())
    {
        case 0: style = "FlatCap";
                break;
        case 16: style = "SquareCap";
                 break;
        case 32: style = "RoundCap";
                 break;
        case 48: style = "MPenCapStyle";
    }

    fout << "\nPenCapStyle: " << style;

    // Pen Join Style
    switch(GetPen().joinStyle())
    {
        case 0: style = "MiterJoin";
                break;
        case 64: style = "BevelJoin";
                 break;
        case 128: style = "RoundJoin";
                  break;
        case 256: style = "SvgMiterJoin";
                  break;
        case 448: style = "MPenJoinStyle";
    }

    fout << "\nPenJoinStyle: " << style;

    // Text Data
    //Text String
    fout << "\nTextString: " << GetTextString();

    // Text color
    if(GetPen().color() == QColor(Qt::red))
    {
        colorName = "red";
    }
    else if(GetPen().color() == QColor(Qt::green))
    {
        colorName = "green";

    }
    else if(GetPen().color() == QColor(Qt::blue))
    {
        colorName = "blue";
    }
    else if(GetPen().color() == QColor(Qt::yellow))
    {
        colorName = "Yellow";
    }
    else if(GetPen().color() == QColor(Qt::cyan))
    {
        colorName = "Cyan";
    }
    else if(GetPen().color() == QColor(Qt::magenta))
    {
        colorName = "Magenta";
    }
    else if(GetPen().color() == QColor(Qt::white))
    {
        colorName = "White";
    }
    else if(GetPen().color() == QColor(Qt::black))
    {
        colorName = "Black";
    }
    else if(GetPen().color() == QColor(Qt::gray))
    {
        colorName = "Gray";
    }
    fout << "\nTextColor: : " << colorName;

    // Get the Alignment Flags
    switch(GetAlign())
    {
    case 1: style = "AlignLeft";
            break;
    case 2: style = "AlignRight";
            break;
    case 4: style = "AlignHCenter";
            break;
    case 8: style = "AlignJustify";
         break;
    case 16: style = "AlignAbsolute";
             break;
    case 31: style = "AlignHorizontal_Mask";
             break;
    case 64: style = "AlignBottom";
             break;
    case 132: style = "AlignCenter";
              break;
    case 256: style = "AlignBaseline";
    }

    fout << "\nTextAlignment: " << style;

    // GET FONT DATA

    // just do it in line next time

    fout << "\nTextPointSize: " << GetFont().pointSize();
    fout << "\nTextFontFamily: " << GetFont().family();

    // Font style
    switch(GetFont().style())
    {
    case 0: style = "StyleNormal";
            break;
    case 1: style = "StyleItalic";
            break;
    case 2: style = "StyleOblique";
    }

    fout << "\nTextFontStyle: " << style;

    /*  for jake's reference
     *  100 thin
     *  200 ex light
     *  300 light
     *  400 norm
     *  500 med
     *  600 demibold
     *  700 bold
     *  800 ex bold
     *  900 black
     * */

    switch(GetFont().weight())
    {
    case 100: style = "Thin";
              break;
    case 200: style = "ExtraLight";
              break;
    case 300: style = "Light";
              break;
    case 400: style = "Normal";
              break;
    case 500: style = "Medium";
              break;
    case 600: style = "DemiBold";
              break;
    case 700: style = "Bold";
              break;
    case 800: style = "ExtraBold";
              break;
    case 900: style = "Black";
    }

    fout << "\nTextFontWeight: " << style;

}
