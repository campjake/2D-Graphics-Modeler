#ifndef CONTACTUS_H
#define CONTACTUS_H

#include <QDialog>

namespace Ui {
class ContactUs;
}

class ContactUs : public QDialog
{
    Q_OBJECT

public:
    ContactUs();
    ~ContactUs();

private:
    Ui::ContactUs *ui;
};
#endif // CONTACTUS_H
