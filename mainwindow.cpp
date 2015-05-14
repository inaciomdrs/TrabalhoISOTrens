#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    trem1 = new Trem (1, 60, 40);

    trem2 = new Trem (2, 310, 40);

    trem3 = new Trem (3, 540, 40);

    trem4 = new Trem (4, 170, 150);

    trem5 = new Trem (5, 420, 150);

    trem6 = new Trem (6, 290, 280);

    connect(trem1,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));

    connect(trem2,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));

    connect(trem3,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));

    connect(trem4,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));

    connect(trem5,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));

    connect(trem6,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));

    // LEGENDA
    // =================================================================================
    // "regiao" ~> é a região crítica
    // "[1-5]" ~> é o retangulo, contando de cima para baixo, da direita para a esquerda
    // "B" ~> Baixo
    // "L" ~> Lado
    // "[D,E]" ~> Direita e Esquerda

    regiao1B = new Trilho(12);

    regiao2LD = new Trilho(2124);
    regiao2BD = new Trilho(224);
    regiao2BE = new Trilho(225);

    regiao3BE = new Trilho(325);

    regiao4LD = new Trilho(4124);
    regiao4BD = new Trilho(424);

    regiao5BE = new Trilho(525);


}

void MainWindow::updateInterface(int id, int x, int y)
{
    switch (id) {
    case 1:
        ui->label_T1->setGeometry(x,y,21,21);
        break;
    case 2:
        ui->label_T2->setGeometry(x,y,21,21);
        break;
    case 3:
        ui->label_T3->setGeometry(x,y,21,21);
        break;
    case 4:
        ui->label_T4->setGeometry(x,y,21,21);
        break;
    case 5:
        ui->label_T5->setGeometry(x,y,21,21);
        break;
    case 6:
        ui->label_T6->setGeometry(x,y,21,21);
        break;
    default:
        break;
    }
    ui->lcdNumber->display(trem1->getVelocidade());
    ui->lcdNumber_2->display(trem2->getVelocidade());
    ui->lcdNumber_3->display(trem3->getVelocidade());
    ui->lcdNumber_4->display(trem4->getVelocidade());
    ui->lcdNumber_5->display(trem5->getVelocidade());
    ui->lcdNumber_6->display(trem6->getVelocidade());
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    trem1->setStop(false);
    trem2->setStop(false);
    trem3->setStop(false);
    trem4->setStop(false);
    trem5->setStop(false);
    trem6->setStop(false);
    trem1->start();
    trem2->start();
    trem3->start();
    trem4->start();
    trem5->start();
    trem6->start();
}



void MainWindow::on_pushButton_2_clicked()
{
    trem1->finalizar();
    trem2->finalizar();
    trem3->finalizar();
    trem4->finalizar();
    trem5->finalizar();
    trem6->finalizar();
}

void MainWindow::on_pushButton_3_clicked()
{
    trem1->decrementaSleep();
}

void MainWindow::on_pushButton_4_clicked()
{
    trem2->decrementaSleep();
}

void MainWindow::on_pushButton_5_clicked()
{
    trem3->decrementaSleep();
}

void MainWindow::on_pushButton_6_clicked()
{
    trem4->decrementaSleep();
}

void MainWindow::on_pushButton_7_clicked()
{
    trem5->decrementaSleep();
}

void MainWindow::on_pushButton_8_clicked()
{
    trem6->decrementaSleep();
}

void MainWindow::on_pushButton_9_clicked()
{
    trem1->incrementaSleep();
}

void MainWindow::on_pushButton_10_clicked()
{
    trem2->incrementaSleep();
}

void MainWindow::on_pushButton_11_clicked()
{
    trem3->incrementaSleep();
}

void MainWindow::on_pushButton_12_clicked()
{
    trem4->incrementaSleep();
}

void MainWindow::on_pushButton_13_clicked()
{
    trem5->incrementaSleep();
}

void MainWindow::on_pushButton_14_clicked()
{
    trem6->incrementaSleep();
}

void MainWindow::on_pushButton_15_clicked()
{
    trem1->setStop(false);
    trem1->start();
}

void MainWindow::on_pushButton_16_clicked()
{
    trem2->setStop(false);
    trem2->start();
}

void MainWindow::on_pushButton_17_clicked()
{
    trem3->setStop(false);
    trem3->start();
}

void MainWindow::on_pushButton_18_clicked()
{
    trem4->setStop(false);
    trem4->start();
}

void MainWindow::on_pushButton_19_clicked()
{
    trem5->setStop(false);
    trem5->start();
}

void MainWindow::on_pushButton_20_clicked()
{
    trem6->setStop(false);
    trem6->start();
}

void MainWindow::on_pushButton_21_clicked()
{
    ui->lcdNumber->display(0);
    trem1->finalizar();
}

void MainWindow::on_pushButton_22_clicked()
{
    ui->lcdNumber_2->display(0);
    trem2->finalizar();
}

void MainWindow::on_pushButton_23_clicked()
{
    ui->lcdNumber_3->display(0);
    trem3->finalizar();
}

void MainWindow::on_pushButton_24_clicked()
{
    ui->lcdNumber_4->display(0);
    trem4->finalizar();
}

void MainWindow::on_pushButton_25_clicked()
{
    ui->lcdNumber_5->display(0);
    trem5->finalizar();
}

void MainWindow::on_pushButton_26_clicked()
{
    ui->lcdNumber_6->display(0);
    trem6->finalizar();
}
