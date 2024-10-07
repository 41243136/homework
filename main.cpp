/*
    組長(leader) 1~36,81~84
    組員1(member2) 37~53
    組員2(member3) 54~67
    組員3(member4) 68~80
*/
//----------leader
#include <QApplication>
#include "QTabWidget"
#include "QVBoxLayout"
#include "QPushButton"
#include "QLabel"
#include "QColorDialog"
#include "QPalette"
#include "QFontDialog"
#include "QFileDialog"

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    QTabWidget *tabWidget=new QTabWidget;
    tabWidget->resize(300,300);
    tabWidget->setWindowTitle("Team 12");

    QWidget *tab1=new QWidget;
    QVBoxLayout *layout1 =new QVBoxLayout;
    QLabel *label=new QLabel("陳志杰\n林沛慧\n王翔禹\n徐祥恩");
    QPalette palette;
    palette.setColor(QPalette::WindowText,Qt::blue);
    label->setPalette(palette);
    layout1->addWidget(label);
    tab1->setLayout(layout1);
    tabWidget->addTab(tab1,"陳志杰");
    //----------
    //----------member2
    QWidget *tab2=new QWidget;
    QPushButton *labelColorButton=new QPushButton;
    labelColorButton->setText("select label color");
    QObject::connect(labelColorButton, &QPushButton::clicked, [label]() {
    QColor color = QColorDialog::getColor();
    if (color.isValid()) {
        QPalette pal = label->palette();
        pal.setColor(QPalette::WindowText, color);
        label->setPalette(pal);
    }
    });
    QVBoxLayout *layout2=new QVBoxLayout;
    layout2->addWidget(labelColorButton);
    tab2->setLayout(layout2);
    tabWidget->addTab(tab2,"林沛慧");
    //----------
    //----------leader
    tabWidget->show();
    return a.exec();
}   //----------
