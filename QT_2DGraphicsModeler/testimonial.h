#ifndef TESTIMONIAL_H
#define TESTIMONIAL_H

#include <QDialog>
#include <QObject>

namespace Ui {
class testimonial;
}

class testimonial : public QDialog
{
    Q_OBJECT

public:
    explicit testimonial(QWidget *parent = nullptr);
    ~testimonial();

private slots:

    void on_button_Save_accepted();

private:
    Ui::testimonial *ui;
};

#endif // TESTIMONIAL_H
