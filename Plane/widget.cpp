#include "widget.h"
#include "config.h"
#include <QPainter>
#include <QMouseEvent>
#include "myplane.h"
#include "bullet.h"
#include "enemypla.h"
#include "enbullet.h"
#include "boom.h"
#include <QPushButton>
#include <QApplication>

Widget::Widget(QWidget *parent) : QWidget(parent){

    this->move(310,0);
    windowset();

    QPushButton* startpage = new QPushButton;
    startpage->setParent(this);

    startpage->resize(WIDTH + 2,HIGH + 2);
    startpage->move(-1,-1);
    startpage->setText("PlaneVS Game");
    startpage->setStyleSheet(" QPushButton{font-family:'华文彩云';font-size:120px;color:rgb(0,0,0,255);}\
                               QPushButton{background-color:rgb(224,223,180)}");

    QPushButton* begin = new QPushButton;
    begin->setParent(this);
    begin->setText("开始新游戏""\n""\n""(用鼠标拖动你的飞机)");
    begin->resize(200,100);
    begin->move(305,600);
    begin->setStyleSheet(" QPushButton{font-family:'华文琥珀';font-size:20px;border-radius:20px;color:rgb(0,0,0,255);}\
                           QPushButton{background-color:rgb(98,182,153)}\
                           QPushButton:hover{background-color:rgb(242,234,147)}");
    QPushButton* _quit1 = new QPushButton;
    _quit1->setParent(this);
    _quit1->resize(100, 50);
    _quit1->move(350, 715);
    _quit1->setText("退出游戏");
    _quit1->setStyleSheet(" QPushButton{font-family:'华文琥珀';font-size:20px;border-radius:20px;color:rgb(0,0,0,255);}\
                           QPushButton{background-color:rgb(98,182,153)}\
                           QPushButton:hover{background-color:rgb(242,234,147)}");

    connect(begin, &QPushButton::clicked, this, [=]{
        begin->close();
        _quit1->close();
        startpage->close();
        play();
    });

    connect(_quit1, &QPushButton::clicked, this, [=]{
              QApplication *app1;
              app1->quit();
    });

    connect(over, &widget2::mysignal, this, [=]{

        this->setGeometry(over->geometry());
        this->show();
        _resetposition();
        over->close();

    });


}

Widget::~Widget(){
}


void Widget::windowset(){


    setFixedSize(WIDTH,HIGH);
    setWindowTitle(TITLE);
    setWindowIcon(QIcon(_ICON));
    //填充背景
    QImage _ima;
    _ima.load(BACKGROUND);
    setAutoFillBackground(true);
    QPalette _pal(palette());
    _pal.setBrush(QPalette::Window,QBrush(_ima.scaled(size(), Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));
    setPalette(_pal);


    timer.setInterval(_TIME);

}

 void Widget::play()
{

    timer.start();
    connect(&timer, &QTimer::timeout,[=]()
    {

        updposition();    
        crash();
        update();
    });



}

void Widget::updposition()
{

    QPainter _paint(this);
    _paint.drawPixmap( mpla.plx, mpla.ply, mpla._myplane);
    mpla._PRect.moveTo(mpla.plx,mpla.ply);

    //我的子弹一
    mybullet1.bly -= _BULLETMOVESPEED;
    if (mybullet1.bly <= 0){
        mybullet1.blx = mpla.plx;
        mybullet1.bly = HIGH - (HIGH + 25 - mpla.ply);
    }
    _paint.drawPixmap(mybullet1.blx, mybullet1.bly, mybullet1._bullet);
    mybullet1._bRect.moveTo(mybullet1.blx, mybullet1.bly);

    //我的子弹二
    mybullet2.bly -= _BULLETMOVESPEED;
    if (mybullet2.bly <= 0){
        mybullet2.blx = mpla.plx + mpla._myplane.width() - mybullet2._bullet.width();
        mybullet2.bly = HIGH - (HIGH + 25 - mpla.ply);
    }
    _paint.drawPixmap(mybullet2.blx, mybullet2.bly, mybullet2._bullet);
    mybullet2._bRect.moveTo(mybullet2.blx, mybullet2.bly);

    //敌机

    eplane1.eply += _ENEMYSPEED;
    eplane1.eplx += eplane1.rand;
    if (eplane1.eply >= HIGH){
        eplane1.eply = -70;
        eplane1.eplx = QRandomGenerator::global()->bounded(1, WIDTH - 1);
    }
    if (eplane1.eplx <= 0 ){

            eplane1.eplx += _ENEMYSPEED*20;
            eplane1.rand = -eplane1.rand;

    }
    else if (eplane1.eplx + eplane1._enemypla.width() >= WIDTH){

            eplane1.eplx -= _ENEMYSPEED*20;
            eplane1.rand = -eplane1.rand;

    }
    _paint.drawPixmap(eplane1.eplx, eplane1.eply, eplane1._enemypla);
    eplane1._ePRect.moveTo(eplane1.eplx, eplane1.eply);

    //敌机
    eplane2.eply += _ENEMYSPEED;
    eplane2.eplx += eplane2.rand;
    if (eplane2.eply >= HIGH){
        eplane2.eply = -70;
        eplane2.eplx = QRandomGenerator::global()->bounded(1, WIDTH - 1);
    }
    if (eplane2.eplx <= 0 ){

            eplane2.eplx += _ENEMYSPEED*21;
            eplane2.rand = -eplane2.rand;

    }
    else if (eplane2.eplx + eplane2._enemypla.width() >= WIDTH){

            eplane2.eplx -= _ENEMYSPEED*21;
            eplane2.rand = -eplane2.rand;

    }

    _paint.drawPixmap(eplane2.eplx, eplane2.eply, eplane2._enemypla);
    eplane2._ePRect.moveTo(eplane2.eplx, eplane2.eply);

    //敌机
    eplane3.eply += _ENEMYSPEED;
    eplane3.eplx += eplane3.rand;
    if (eplane3.eply >= HIGH){
        eplane3.eply = -70;
        eplane3.eplx = QRandomGenerator::global()->bounded(1, WIDTH - 1);
    }
    if (eplane3.eplx <= 0 ){

            eplane3.eplx += _ENEMYSPEED*22;
            eplane3.rand = -eplane3.rand;

    }
    else if (eplane3.eplx + eplane3._enemypla.width() >= WIDTH){

            eplane3.eplx -= _ENEMYSPEED*22;
            eplane3.rand = -eplane3.rand;

    }

    _paint.drawPixmap(eplane3.eplx, eplane3.eply, eplane3._enemypla);
    eplane3._ePRect.moveTo(eplane3.eplx, eplane3.eply);

    //敌人子弹
    if (ebullet1.flag == 1){
        ebullet1.ebly += _ENEMYBULLETSPEED;
        ebullet1.eblx += ebullet1.rand;
        if (ebullet1.ebly >= HIGH){
            ebullet1.ebly = eplane1.eply + eplane1._enemypla.height() + 2;
            ebullet1.eblx = eplane1.eplx + eplane1._enemypla.width()/2;
        }
        if (ebullet1.eblx <= 0 ){

                ebullet1.eblx += _ENEMYBULLETSPEED*2;
                ebullet1.rand = -ebullet1.rand;

        }
        else if ( ebullet1.eblx + ebullet1._ebullet.width() >= WIDTH){

               ebullet1.eblx -= _ENEMYBULLETSPEED*2;
               ebullet1.rand = -ebullet1.rand;

        }

    }
    else {
        ebullet1.eblx = eplane1.eplx + eplane1._enemypla.width()/2;
        ebullet1.ebly = eplane1.eply + eplane1._enemypla.height() + 2;
        ebullet1.flag = 1;

    }
    _paint.drawPixmap(ebullet1.eblx, ebullet1.ebly, ebullet1._ebullet);
   ebullet1._ebRect.moveTo(ebullet1.eblx, ebullet1.ebly);

   if (ebullet2.flag == 1){
       ebullet2.ebly += _ENEMYBULLETSPEED;
       ebullet2.eblx += ebullet2.rand;
       if (ebullet2.ebly >= HIGH){
           ebullet2.ebly = eplane2.eply + eplane2._enemypla.height() + 2;
           ebullet2.eblx = eplane2.eplx + eplane2._enemypla.width()/2;
       }
       if (ebullet2.eblx <= 0 ){

               ebullet2.eblx += _ENEMYBULLETSPEED*1;
               ebullet2.rand = -ebullet2.rand;

       }
       else if ( ebullet2.eblx + ebullet2._ebullet.width() >= WIDTH){

              ebullet2.eblx -= _ENEMYBULLETSPEED*1;
              ebullet2.rand = -ebullet2.rand;

       }

   }
   else {
       ebullet2.eblx = eplane2.eplx + eplane2._enemypla.width()/2;
       ebullet2.ebly = eplane2.eply + eplane2._enemypla.height() + 2;
       ebullet2.flag = 1;

   }
   _paint.drawPixmap(ebullet2.eblx, ebullet2.ebly, ebullet2._ebullet);
  ebullet2._ebRect.moveTo(ebullet2.eblx, ebullet2.ebly);

  if (ebullet3.flag == 1){
      ebullet3.ebly += _ENEMYBULLETSPEED;
      ebullet3.eblx += ebullet3.rand;
      if (ebullet3.ebly >= HIGH){
          ebullet3.ebly = eplane3.eply + eplane3._enemypla.height() + 2;
          ebullet3.eblx = eplane3.eplx + eplane3._enemypla.width()/2;
      }
      if (ebullet3.eblx <= 0 ){

              ebullet3.eblx += _ENEMYBULLETSPEED*3;
              ebullet3.rand = -ebullet3.rand;

      }
      else if ( ebullet3.eblx + ebullet3._ebullet.width() >= WIDTH){

             ebullet3.eblx -= _ENEMYBULLETSPEED*3;
             ebullet3.rand = -ebullet3.rand;

      }

  }
  else {
      ebullet3.eblx = eplane3.eplx + eplane3._enemypla.width()/2;
      ebullet3.ebly = eplane3.eply + eplane3._enemypla.height() + 2;
      ebullet3.flag = 1;

  }
  _paint.drawPixmap(ebullet3.eblx, ebullet3.ebly, ebullet3._ebullet);
  ebullet3._ebRect.moveTo(ebullet3.eblx, ebullet3.ebly);

}

void Widget::paintEvent(QPaintEvent *)
{

    QPainter _paint(this);
    _paint.drawPixmap(mpla.plx,mpla.ply,mpla._myplane);

    _paint.drawPixmap(mybullet1.blx, mybullet1.bly, mybullet1._bullet);
    _paint.drawPixmap(mybullet2.blx, mybullet2.bly, mybullet2._bullet);

    _paint.drawPixmap(eplane1.eplx, eplane1.eply, eplane1._enemypla);
    _paint.drawPixmap(eplane2.eplx, eplane2.eply, eplane2._enemypla);
    _paint.drawPixmap(eplane3.eplx, eplane3.eply, eplane3._enemypla);

    _paint.drawPixmap(ebullet1.eblx, ebullet1.ebly, ebullet1._ebullet);
    _paint.drawPixmap(ebullet2.eblx, ebullet2.ebly, ebullet2._ebullet);
    _paint.drawPixmap(ebullet3.eblx, ebullet3.ebly, ebullet3._ebullet);

    _paint.drawPixmap(bom1.boox, bom1.booy, bom1.booom);
    _paint.drawPixmap(bom2.boox, bom2.booy, bom2.booom);
    _paint.drawPixmap(bom3.boox, bom3.booy, bom3.booom);

}

void Widget::mouseMoveEvent(QMouseEvent * event)
{
    mpla.plx = event->x() -(mpla._myplane.width())/2;
    mpla.ply = event->y() -(mpla._myplane.height())/2;

}

void Widget::crash()
{
    if (eplane1._ePRect.top() < mybullet1._bRect.top() && mybullet1._bRect.top() < eplane1._ePRect.bottom()
            && eplane1._ePRect.top() < mybullet1._bRect.bottom() && mybullet1._bRect.bottom() < eplane1._ePRect.bottom()
            && eplane1._ePRect.left() < mybullet1._bRect.left() && mybullet1._bRect.left() < eplane1._ePRect.right()
            &&  eplane1._ePRect.left() < mybullet1._bRect.right() && mybullet1._bRect.right() < eplane1._ePRect.right()){

        //爆炸图片效果

        bom1.boox = eplane1.eplx; bom1.booy = eplane1.eply;
        bom1.paintbooom();

        eplane1.eply = 0;
        eplane1.eplx = QRandomGenerator::global()->bounded(1, WIDTH - 1);
    }

    if (eplane2._ePRect.top() < mybullet1._bRect.top() && mybullet1._bRect.top() < eplane2._ePRect.bottom()
            && eplane2._ePRect.top() < mybullet1._bRect.bottom() && mybullet1._bRect.bottom() < eplane2._ePRect.bottom()
            && eplane2._ePRect.left() < mybullet1._bRect.left() && mybullet1._bRect.left() < eplane2._ePRect.right()
            &&  eplane2._ePRect.left() < mybullet1._bRect.right() && mybullet1._bRect.right() < eplane2._ePRect.right()){


        bom2.boox = eplane2.eplx; bom2.booy = eplane2.eply;
        bom2.paintbooom();

        eplane2.eply = 0;
        eplane2.eplx = QRandomGenerator::global()->bounded(1, WIDTH - 1);
    }

    if (eplane3._ePRect.top() < mybullet1._bRect.top() && mybullet1._bRect.top() < eplane3._ePRect.bottom()
            && eplane3._ePRect.top() < mybullet1._bRect.bottom() && mybullet1._bRect.bottom() < eplane3._ePRect.bottom()
            && eplane3._ePRect.left() < mybullet1._bRect.left() && mybullet1._bRect.left() < eplane3._ePRect.right()
            &&  eplane3._ePRect.left() < mybullet1._bRect.right() && mybullet1._bRect.right() < eplane3._ePRect.right()){


        bom3.boox = eplane3.eplx; bom3.booy = eplane3.eply;
        bom3.paintbooom();

        eplane3.eply = 0;
        eplane3.eplx = QRandomGenerator::global()->bounded(1, WIDTH - 1);
    }



    if (eplane1._ePRect.top() < mybullet2._bRect.top() && mybullet2._bRect.top() < eplane1._ePRect.bottom()
            && eplane1._ePRect.top() < mybullet2._bRect.bottom() && mybullet2._bRect.bottom() < eplane1._ePRect.bottom()
            && eplane1._ePRect.left() < mybullet2._bRect.left() && mybullet2._bRect.left() < eplane1._ePRect.right()
            &&  eplane1._ePRect.left() < mybullet2._bRect.right() && mybullet2._bRect.right() < eplane1._ePRect.right()){


        bom1.boox = eplane1.eplx; bom1.booy = eplane1.eply;
        bom1.paintbooom();

        eplane1.eply = 0;
        eplane1.eplx = QRandomGenerator::global()->bounded(1, WIDTH - 1);



    }

    if (eplane2._ePRect.top() < mybullet2._bRect.top() && mybullet2._bRect.top() < eplane2._ePRect.bottom()
            && eplane2._ePRect.top() < mybullet2._bRect.bottom() && mybullet2._bRect.bottom() < eplane2._ePRect.bottom()
            && eplane2._ePRect.left() < mybullet2._bRect.left() && mybullet2._bRect.left() < eplane2._ePRect.right()
            &&  eplane2._ePRect.left() < mybullet2._bRect.right() && mybullet2._bRect.right() < eplane2._ePRect.right()){


        bom2.boox = eplane2.eplx; bom2.booy = eplane2.eply;
        bom2.paintbooom();


        eplane2.eply = 0;
        eplane2.eplx = QRandomGenerator::global()->bounded(1, WIDTH - 1);
    }

    if (eplane3._ePRect.top() < mybullet2._bRect.top() && mybullet2._bRect.top() < eplane3._ePRect.bottom()
            && eplane3._ePRect.top() < mybullet2._bRect.bottom() && mybullet2._bRect.bottom() < eplane3._ePRect.bottom()
            && eplane3._ePRect.left() < mybullet2._bRect.left() && mybullet2._bRect.left() < eplane3._ePRect.right()
            &&  eplane3._ePRect.left() < mybullet2._bRect.right() && mybullet2._bRect.right() < eplane3._ePRect.right())
    {


        bom3.boox = eplane3.eplx; bom3.booy = eplane3.eply;
        bom3.paintbooom();

        eplane3.eply = 0;
        eplane3.eplx = QRandomGenerator::global()->bounded(1, WIDTH - 1);
    }



    if (mpla._PRect.top() <= ebullet1._ebRect.bottom()  && ebullet1._ebRect.bottom() <= mpla._PRect.bottom()
            && mpla._PRect.top() <= ebullet1._ebRect.top() && ebullet1._ebRect.top() <= mpla._PRect.bottom()
            && mpla._PRect.left() <= ebullet1._ebRect.left() && ebullet1._ebRect.left() <= mpla._PRect.right()
            && mpla._PRect.left() <= ebullet1._ebRect.right() && ebullet1._ebRect.right() <= mpla._PRect.right())
    {
        //游戏结束


        over->setGeometry(this->geometry());
        over->show();
        this->close();

    }
    else if (mpla._PRect.top() <= ebullet2._ebRect.bottom()  && ebullet2._ebRect.bottom() <= mpla._PRect.bottom()
             && mpla._PRect.top() <= ebullet2._ebRect.top() && ebullet2._ebRect.top() <= mpla._PRect.bottom()
             && mpla._PRect.left() <= ebullet2._ebRect.left() && ebullet2._ebRect.left() <= mpla._PRect.right()
             && mpla._PRect.left() <= ebullet2._ebRect.right() && ebullet2._ebRect.right() <= mpla._PRect.right())
    {


        over->setGeometry(this->geometry());
        over->show();
        this->close();

    }
    else if (mpla._PRect.top() <= ebullet3._ebRect.bottom()  && ebullet3._ebRect.bottom() <= mpla._PRect.bottom()
             && mpla._PRect.top() <= ebullet3._ebRect.top() && ebullet3._ebRect.top() <= mpla._PRect.bottom()
             && mpla._PRect.left() <= ebullet3._ebRect.left() && ebullet3._ebRect.left() <= mpla._PRect.right()
             && mpla._PRect.left() <= ebullet3._ebRect.right() && ebullet3._ebRect.right() <= mpla._PRect.right())
    {


        over->setGeometry(this->geometry());
        over->show();
        this->close();

    }
}

void Widget::_resetposition()
{
    mpla.plx = (WIDTH - mpla._myplane.width())>>1; mpla.ply = (HIGH - mpla._myplane.height());

    mybullet1.blx = mpla.plx;
    mybullet1.bly = HIGH - (HIGH + 25 - mpla.ply);
    mybullet2.blx = mpla.plx;
    mybullet2.bly = HIGH - (HIGH + 25 - mpla.ply);

    eplane1.eplx = QRandomGenerator::global()->bounded(1, WIDTH - 1); eplane1.eply = 0;
    eplane2.eplx = QRandomGenerator::global()->bounded(1, WIDTH - 1); eplane2.eply = 0;
    eplane3.eplx = QRandomGenerator::global()->bounded(1, WIDTH - 1); eplane3.eply = 0;

    ebullet1.eblx = -30; ebullet1.ebly = -30;
    ebullet2.eblx = -30; ebullet2.ebly = -30;
    ebullet3.eblx = -30; ebullet3.ebly = -30;

    bom1.boox = -100; bom1.booy = -100;
    bom2.boox = -100; bom2.booy = -100;
    bom3.boox = -100; bom3.booy = -100;

}
