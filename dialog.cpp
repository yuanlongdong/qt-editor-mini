#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    this->setWindowFlags(Qt::Window |
                            Qt::WindowMinimizeButtonHint |
                            Qt::WindowMaximizeButtonHint |
                            Qt::WindowCloseButtonHint);

    this->setAttribute(Qt::WA_DontShowOnScreen, false);

    connect(ui->radioButtonBlack,SIGNAL(clicked()),this,SLOT(setTextFontColor()));
    connect(ui->radioButtonBlue,SIGNAL(clicked()),this,SLOT(setTextFontColor()));
    connect(ui->radioButtonRed,SIGNAL(clicked()),this,SLOT(setTextFontColor()));
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_checkBoxUnder_clicked(bool checked)
{
    QFont font=ui->txtEdit->font();

    font.setUnderline(checked);
    ui->txtEdit->setFont(font);

}

void Dialog::on_checkBoxBold_clicked(bool checked)
{
    QFont font=ui->txtEdit->font();
    font.setBold(checked);
    ui->txtEdit->setFont(font);
}

void Dialog::on_checkBoxItalic_clicked(bool checked)
{
    QFont font=ui->txtEdit->font();
    font.setItalic(checked);
    ui->txtEdit->setFont(font);
}

void Dialog::setTextFontColor()
{
    QPalette plet=ui->txtEdit->palette();

    if(ui->radioButtonBlue->isChecked())
    {
        plet.setColor(QPalette::Text,Qt::blue);
    }
    else if(ui->radioButtonRed->isChecked())
    {
        plet.setColor(QPalette::Text,Qt::red);
    }
    else if(ui->radioButtonBlack->isChecked())
    {
        plet.setColor(QPalette::Text,Qt::black);
    }
    else
    {
        plet.setColor(QPalette::Text,Qt::black);
    }


    ui->txtEdit->setPalette(plet);
}

