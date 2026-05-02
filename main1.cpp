#include <QApplication>
#include <QWidget>
#include <QPixmap>
#include <QPainter>
#include <QMouseEvent>
#include <QTimer>
#include <QFont>
#include <QLabel>
#include <QRandomGenerator>
#include <QDebug>
#include <QDateTime>

class Background : public QWidget
{
    Q_OBJECT

public:
    Background(QWidget *parent = nullptr) : QWidget(parent)
    {
        background.load("C:/Users/39036/Downloads/像素背景.jpeg");
        background_night.load("C:/Users/39036/Downloads/夜晚背景1.jpeg");
        resize(2560,1440);
        catty.load("C:/Users/39036/Downloads/1c7b786a7421514a4f6dc59cbf58c384-removebg-preview.png");
        cattymeow.load("C:/Users/39036/Downloads/3567d77ff12cfe08b70b3cab18de473f-removebg-preview.png");
        cattysleep.load("C:/Users/39036/Downloads/睡觉-removebg-preview (1).png");
        ismeow = false;
        connect(&meowTimer, &QTimer::timeout, this, &Background::ResetCatty);
        connect(&nightTimer, &QTimer::timeout, this, &Background::ResetNight);
        meowTimer.setSingleShot(true);
        nightTimer.setSingleShot(true);
        money.load("C:/Users/39036/Downloads/pixil-frame-0.png");
        money = money.scaled(100,100);
        shop.load("C:/Users/39036/Downloads/商店页面.jpeg");
        water_bowl.load("C:/Users/39036/Downloads/水碗-removebg-preview (1).png");
        posof_water_bowl = QPoint(680,720);
        posof_ball = QPoint(1380,900);
        posof_ipad = QPoint(1600,600);
        posof_board = QPoint(2400,1200);
        posof_Catnip = QPoint(-100,1000);
        offset_water_bowl = QPoint(0,0);
        connect(&Coin_not_enough_Timer, &QTimer::timeout, this, &Background::Coin_not_enough_Display);
        scratch_board.load("C:/Users/39036/Downloads/猫抓板-removebg-preview.png");
        Catnip.load("C:/Users/39036/Downloads/猫薄荷-removebg-preview.png");
        ball.load("C:/Users/39036/Downloads/毛线球-removebg-preview.png");
        iPad.load("C:/Users/39036/Downloads/生成特定动作小猫图片__2_-removebg-preview.png");
        quiz_background.load("C:/Users/39036/Downloads/答题背景.jpeg");
        catty_buttons[1].load("C:/Users/39036/Downloads/小猫按钮-removebg-preview.png");
        catty_buttons[2].load("C:/Users/39036/Downloads/小猫按钮-removebg-preview.png");
        catty_buttons[3].load("C:/Users/39036/Downloads/小猫按钮-removebg-preview.png");
        catty_buttons[4].load("C:/Users/39036/Downloads/小猫按钮-removebg-preview.png");
        description1.load("C:/Users/39036/Downloads/问号-removebg-preview.png");
        description1 = description1.scaled(100,100);
        desc_paper.load("C:/Users/39036/Downloads/说明页面1-removebg-preview__1_-removebg-preview.png");
        close_page.load("C:/Users/39036/Downloads/关闭页面.png");
        mystery_key.load("C:/Users/39036/Downloads/神秘钥匙-removebg-preview.png");
        curtain1.load("C:/Users/39036/Downloads/chuanglianclose-removebg-preview.png");
        curtain1 = curtain1.scaled(725,500);
        curtainopen.load("C:/Users/39036/Downloads/chuanglianopen-removebg-preview.png");
        curtainopen = curtainopen.scaled(725,500);
    }
private slots:
    void ResetCatty()
    {
        ismeow = false;
        update();
    }
private slots:
    void ResetNight()
    {
        is_night = false;
        update();
    }
private slots:
    void Coin_not_enough_Display()
    {
        Coin_not_enough = false;
        update();
    }

private:
    QPixmap background;
    QPixmap background_night;
    QPixmap catty;
    QPixmap cattymeow;
    QPixmap cattysleep;
    bool ismeow;
    QTimer meowTimer;
    QPixmap money;
    int coin = 10000;
    int Day = 1;
    int Love = 0;
    bool enter_quiz = false;
    bool enter_shop = false;
    bool is_night = false;
    QTimer nightTimer;
    QPixmap shop;
    QPixmap water_bowl;
    QPixmap scratch_board;
    QPixmap Catnip;
    QPixmap ball;
    QPixmap iPad;
    QPixmap mystery_key;
    QPixmap curtain1;
    QPixmap curtainopen;
    bool bought_1 = false;
    bool bought_2 = false;
    bool bought_3 = false;
    bool bought_4 = false;
    bool bought_5 = false;
    bool bought_6 = false;
    bool Coin_not_enough = false;
    bool is_bought_curtain = true;
    bool is_open_curtain = false;
    QTimer Coin_not_enough_Timer;
    bool is_Dragging_water_bowl = false;
    QPoint posof_water_bowl;
    QPoint offset_water_bowl;
    bool is_Dragging_board = false;
    QPoint posof_board;
    QPoint offset_board;
    bool is_Dragging_Catnip = false;
    QPoint posof_Catnip;
    QPoint offset_Catnip;
    bool is_Dragging_ball = false;
    QPoint posof_ball;
    QPoint offset_ball;
    bool is_Dragging_ipad = false;
    QPoint posof_ipad;
    QPoint offset_ipad;
    QPixmap quiz_background;
    bool have_selected = false;
    int rng = QRandomGenerator::global()->bounded(1,6);
    bool ended = false;
    QPixmap catty_buttons[100];
    QPixmap description1;
    bool desc_page = false;
    QPixmap desc_paper;
    QPixmap close_page;
    bool flag = false;
    bool isPointOnCatty(QPoint& pos)
    {
        QRect isoncatty (1750,825,catty.width(),catty.height());
        if (!isoncatty.contains(pos)) return false;
        return true;
    }

    bool isPointOnCurtain(QPoint& pos)
    {
        QRect isoncurtain(920,150,curtain1.width(),curtain1.height());
        if (!isoncurtain.contains(pos)) return false;
        return true;
    }

    bool isPointOnExit(QPoint& pos)
    {
        QRect isonexit (2160,350,300,100);
        if (isonexit.contains(pos)) return true;
        return false;
    }

    bool isPointOnQuiz(QPoint& pos)
    {
        QRect isonexit (2160,50,300,100);
        if (isonexit.contains(pos)) return true;
        return false;
    }

    bool isPointOnBed(QPoint& pos)
    {
        QRect isonexit (2160,500,300,100);
        if (isonexit.contains(pos)) return true;
        return false;
    }

    bool isPointOnShop(QPoint& pos)
    {
        QRect isonexit (2160,200,300,100);
        if (isonexit.contains(pos)) return true;
        return false;
    }

        bool isPointOnShop1(QPoint& pos)
        {
            QRect isonexit (96,167,750,420);
            if (isonexit.contains(pos) && enter_shop) return true;
            return false;
        }

        bool isPointOnShop2(QPoint& pos)
        {
            QRect isonexit (860,167,750,420);
            if (isonexit.contains(pos) && enter_shop) return true;
            return false;
        }

        bool isPointOnShop3(QPoint& pos)
        {
            QRect isonexit (1660,167,750,420);
            if (isonexit.contains(pos) && enter_shop) return true;
            return false;
        }

        bool isPointOnShop4(QPoint& pos)
        {
            QRect isonexit (96,737,750,420);
            if (isonexit.contains(pos) && enter_shop) return true;
            return false;
        }

        bool isPointOnShop5(QPoint& pos)
        {
            QRect isonexit (860,737,750,420);
            if (isonexit.contains(pos) && enter_shop) return true;
            return false;
        }

        bool isPointOnShop6(QPoint& pos)
        {
            QRect isonexit (1660,737,750,420);
            if (isonexit.contains(pos) && enter_shop) return true;
            return false;
        }

        bool isExitShop(QPoint& pos)
        {
            QRect isexitshop = rect();
            if (isexitshop.contains(pos) && enter_shop) return true;
            return false;
        }

        bool isPointOnWaterBowl(QPoint& pos)
        {
            if (!bought_1) return false;
            QRect water_bowl_pos(posof_water_bowl,water_bowl.size());
            if (!enter_shop && water_bowl_pos.contains(pos)) return true;
            return false;
        }

        bool isPointOnBoard(QPoint& pos)
        {
            if (!bought_2) return false;
            QRect board_pos(posof_board,scratch_board.size());
            if (!enter_shop && board_pos.contains(pos)) return true;
            return false;
        }

        bool isPointOnCatnip(QPoint& pos)
        {
            if (!bought_3) return false;
            QRect Catnip_pos(posof_Catnip,Catnip.size());
            if (!enter_shop && Catnip_pos.contains(pos)) return true;
            return false;
        }

        bool isPointOnBall(QPoint& pos)
        {
            if (!bought_4) return false;
            QRect ball_pos(posof_ball,ball.size());
            if (!enter_shop && ball_pos.contains(pos)) return true;
            return false;
        }

        bool isPointOnIpad(QPoint& pos)
        {
            if (!bought_5) return false;
            QRect ipad_pos(posof_ipad,iPad.size());
            if (!enter_shop && ipad_pos.contains(pos)) return true;
            return false;
        }

        bool isPointOnQuizExit(QPoint& pos)
        {
            if (!enter_quiz) return false;
            QRect quiz_exit(2027,237,162,162);
            if (quiz_exit.contains(pos)) return true;
            return false;
        }

        bool isPointOnQuizS1(QPoint& pos)
        {
            QRect quiz_s1(515,489,2000,120);
            if (quiz_s1.contains(pos)) return true;
            return false;
        }

        bool isPointOnQuizS2(QPoint& pos)
        {
            QRect quiz_s1(515,727,2000,120);
            if (quiz_s1.contains(pos)) return true;
            return false;
        }

        bool isPointOnQuizS3(QPoint& pos)
        {
            QRect quiz_s1(515,963,2000,120);
            if (quiz_s1.contains(pos)) return true;
            return false;
        }

        bool isPointOnDesc(QPoint& pos)
        {
            QRect desc_rect(2000,45,description1.width(),description1.height());
            if (desc_rect.contains(pos)) return true;
            return false;
        }

        bool isPointOnClose(QPoint& pos)
        {
            if (!desc_page) return false;
            QRect close_area(2080,220,close_page.width(),close_page.height());
            if (close_area.contains(pos)) return true;
            return false;
        }

        bool isPointOnCloseEnd(QPoint& pos)
        {
            if (!ended) return false;
            QRect close_area(2080,220,close_page.width(),close_page.height());
            if (close_area.contains(pos)) return true;
            return false;
        }
protected:
    void paintEvent(QPaintEvent *event) override
    {
        Q_UNUSED(event);
        QPainter painter(this);
        if (ended)
        {
            painter.drawPixmap(rect(),background);
            QPoint pointer_desc_paper(320,180);
            desc_paper = desc_paper.scaled(1920,1080);
            painter.drawPixmap(pointer_desc_paper,desc_paper);
            QPoint pointer_close(2080,220);
            painter.drawPixmap(pointer_close,close_page);
            QFont font6 = painter.font();
            font6.setPixelSize(40);
            font6.setWeight(10);
            painter.setFont(font6);
            QPoint pointer_text1(500,380);
            painter.drawText(pointer_text1,"恭喜你通关本游戏！");
            QPoint pointer_text2(500,460);
            QString text2 = QString("你成功达到了99好感度，并且只花费了%1天！").arg(Day);
            painter.drawText(pointer_text2,text2);
            QPoint pointer_text3(500,540);
            painter.drawText(pointer_text3,"接下来，你可以继续游戏，尝试买下所有物品或刷到更高的好感度！");
            QPoint pointer_text4(500,620);
            painter.drawText(pointer_text4,"感谢你的游玩！");
            return ;
        }
        if (desc_page)
        {
            painter.drawPixmap(rect(),background);
            QPoint pointer_desc_paper(320,180);
            desc_paper = desc_paper.scaled(1920,1080);
            painter.drawPixmap(pointer_desc_paper,desc_paper);
            QPoint pointer_close(2080,220);
            painter.drawPixmap(pointer_close,close_page);
            QFont font6 = painter.font();
            font6.setPixelSize(40);
            font6.setWeight(10);
            painter.setFont(font6);
            QPoint pointer_text1(500,380);
            painter.drawText(pointer_text1,"欢迎来到南开大学26C++大作业，本游戏的开发者是于沛铎");
            QPoint pointer_text2(500,460);
            QString text2 = QString("游戏玩法：每天答题获得金币和好感度，金币在商店内购买物品，好感度达到99时获胜");
            painter.drawText(pointer_text2,text2);
            QPoint pointer_text3(500,540);
            painter.drawText(pointer_text3,"商店物品1--水碗：购买后直接增加3好感度");
            QPoint pointer_text4(500,620);
            painter.drawText(pointer_text4,"商店物品2--猫抓板：每天有1/5概率增加1好感度");
            QPoint pointer_text5(500,700);
            painter.drawText(pointer_text5,"商店物品3--猫薄荷：避免每天结束时可能的好感度下降效果");
            QPoint pointer_text6(500,780);
            painter.drawText(pointer_text6,"商店物品4--超大毛绒球：每天增加1好感度和25金币");
            QPoint pointer_text7(500,860);
            painter.drawText(pointer_text7,"商店物品5--平板电脑：每天增加3好感度");
            QPoint pointer_text8(500,940);
            painter.drawText(pointer_text8,"你能在最短多少回合内获胜呢？来挑战一下吧！");
            return ;
        }
        if (!enter_quiz && !enter_shop)
        {
            Q_UNUSED(event);
            painter.drawPixmap(rect(),background);
            QPoint pointer_catty(1750,825);
            if (!is_night)
            {
                painter.drawPixmap(rect(),background);
                if (!ismeow)
                {
                    painter.drawPixmap(pointer_catty,catty);
                }
                else
                {
                    painter.drawPixmap(pointer_catty,cattymeow);
                }
            }
            else
            {
                painter.drawPixmap(rect(),background_night);
                painter.drawPixmap(pointer_catty,cattysleep);

            }
            if (is_bought_curtain)
            {
                QPoint curtain_pointer1(920,150);
                if (!is_open_curtain) painter.drawPixmap(curtain_pointer1, curtain1);
                else painter.drawPixmap(curtain_pointer1, curtainopen);
            }
            if (bought_1 && !is_night)
            {
                QPoint pointer_1(posof_water_bowl);
                painter.drawPixmap(pointer_1,water_bowl);
            }
            if (bought_2 && !is_night)
            {
                QPoint pointer_2(posof_board);
                painter.drawPixmap(pointer_2,scratch_board);
            }
            if (bought_3 && !is_night)
            {
                QPoint pointer_3(posof_Catnip);
                painter.drawPixmap(pointer_3,Catnip);
            }
            if (bought_4 && !is_night)
            {
                QPoint pointer_4(posof_ball);
                painter.drawPixmap(pointer_4,ball);
            }
            if (bought_5 && !is_night)
            {
                QPoint pointer_5(posof_ipad);
                painter.drawPixmap(pointer_5,iPad);
            }
            QPoint pointer_gold(100, 100);
            painter.drawPixmap(pointer_gold,money);
            QPoint pointer_desc(2000,45);
            painter.drawPixmap(pointer_desc,description1);
            QString coin_text = QString("%1").arg(coin);
            QString Day_text = QString("天数：%1").arg(Day);
            QString Love_text = QString("好感度：%1").arg(Love);
            QFont font1("Courier New");
            font1.setPixelSize(60);
            font1.setBold(true);
            font1.setStyleStrategy(QFont::NoAntialias);
            painter.setFont(font1);
            painter.setPen(Qt::red);

            QFontMetrics fm(font1);

            // 在背景框上绘制文本（垂直居中）
            int coin_textX = 220;   // 左内边距10像素
            int coin_textY = 160; // 垂直居中
            painter.drawText(coin_textX, coin_textY, coin_text); //此处使用ai确定长度及写金币数量代码

            int Day_textX = 110;
            int Day_textY = 280;
            painter.drawText(Day_textX, Day_textY, Day_text);

            int Love_textX = 110;
            int Love_textY = 400;
            painter.drawText(Love_textX, Love_textY, Love_text);

            QString quiz = QString("答题");
            QString shop = QString("商店");
            QString exit = QString("退出");
            QString bed = QString("睡觉");
//            QPen pen_button;
//            pen_button.setWidth(10);
//            pen_button.setColor(Qt::black);
//            painter.setPen(pen_button);
            QPoint pointer_buttons1(2060,-150);
            QPoint pointer_buttons2(2060,0);
            QPoint pointer_buttons3(2060,150);
            QPoint pointer_buttons4(2060,300);
            painter.drawPixmap(pointer_buttons1,catty_buttons[1]);
            painter.drawPixmap(pointer_buttons2,catty_buttons[2]);
            painter.drawPixmap(pointer_buttons3,catty_buttons[3]);
            painter.drawPixmap(pointer_buttons4,catty_buttons[4]);
            QPen pen_text;
            painter.setPen(pen_text);
            painter.drawText(2250,120,quiz);
            painter.drawText(2250,270,shop);
            painter.drawText(2250,420,exit);
            painter.drawText(2250,570,bed);
        }
        if (enter_shop)
        {
            painter.drawPixmap(rect(),shop);
            QPoint pointer_shop1(168,108);
            painter.drawPixmap(pointer_shop1,water_bowl);
            QPoint pointer_shop2(1008,108);
            painter.drawPixmap(pointer_shop2,scratch_board);
            QPoint pointer_shop3(1848,108);
            painter.drawPixmap(pointer_shop3,Catnip);
            QPoint pointer_shop4(168,608);
            painter.drawPixmap(pointer_shop4,ball);
            QPoint pointer_shop5(908,688);
            painter.drawPixmap(pointer_shop5,iPad);
            QPoint pointer_shop6(1848,588);
            painter.drawPixmap(pointer_shop6,mystery_key);
            QString not_enough = QString("金币不足！");
            QString have_sold_1 = QString("售罄");
            QFont font2 = painter.font();
            font2.setPointSize(60);
            painter.setFont(font2);
            if (Coin_not_enough)
            {
                painter.drawText(980,720,not_enough);
            }
            QPen pen_have_sold;
            pen_have_sold.setWidth(10);
            font2.setPixelSize(60);
            font2.setBold(true);
            painter.setPen(pen_have_sold);
            if (bought_1)
            {
                painter.drawRect(308,288,280,140);
                font2.setPointSize(20);
                painter.setFont(font2);
                painter.drawText(408,368,have_sold_1);
            }
            if (bought_2)
            {
                painter.drawRect(1058,288,280,140);
                font2.setPointSize(20);
                painter.setFont(font2);
                painter.drawText(1158,368,have_sold_1);
            }
            if (bought_3)
            {
                painter.drawRect(1808,288,280,140);
                font2.setPointSize(20);
                painter.setFont(font2);
                painter.drawText(1908,368,have_sold_1);
            }
            if (bought_4)
            {
                painter.drawRect(308,788,280,140);
                font2.setPointSize(20);
                painter.setFont(font2);
                painter.drawText(408,868,have_sold_1);
            }
            if (bought_5)
            {
                painter.drawRect(1058,788,280,140);
                font2.setPointSize(20);
                painter.setFont(font2);
                painter.drawText(1158,868,have_sold_1);
            }
            if (bought_6)
            {
                painter.drawRect(1808,788,280,140);
                font2.setPointSize(20);
                painter.setFont(font2);
                painter.drawText(1908,868,have_sold_1);
            }
        }
        else if (enter_quiz)
        {
            painter.drawPixmap(rect(),background);
            QPoint pointer_quiz(320,180);
            quiz_background = quiz_background.scaled(1920,1080);
            painter.drawPixmap(pointer_quiz,quiz_background);
            QPoint tg(426,304);
            QPoint A(515,539);
            QPoint B(515,777);
            QPoint C(515,1013);
            QPoint s1(700,555);
            QPoint s2(700,800);
            QPoint s3(700,1025);
            if (rng == 1)
            {
                QFont font4 = painter.font();
                font4.setPixelSize(60);
                painter.setFont(font4);
                painter.drawText(tg,"猫猫的平均寿命是多少?");
                painter.drawText(A,"A");
                painter.drawText(B,"B");
                painter.drawText(C,"C");
                painter.drawText(s1,"5-8年");
                painter.drawText(s2,"12-18年");
                painter.drawText(s3,"20-25年");
            }
            else if (rng == 2)
            {
                QFont font4 = painter.font();
                font4.setPixelSize(60);
                painter.setFont(font4);
                painter.drawText(tg,"猫猫的孕期有多长?");
                painter.drawText(A,"A");
                painter.drawText(B,"B");
                painter.drawText(C,"C");
                painter.drawText(s1,"35天");
                painter.drawText(s2,"65天");
                painter.drawText(s3,"95天");
            }
            else if (rng == 3)
            {
                QFont font4 = painter.font();
                font4.setPixelSize(60);
                painter.setFont(font4);
                painter.drawText(tg,"猫猫的正常体温是多少?");
                painter.drawText(A,"A");
                painter.drawText(B,"B");
                painter.drawText(C,"C");
                painter.drawText(s1,"36.5度");
                painter.drawText(s2,"37.5度");
                painter.drawText(s3,"38.5度");
            }
            else if (rng == 4)
            {
                QFont font4 = painter.font();
                font4.setPixelSize(60);
                painter.setFont(font4);
                painter.drawText(tg,"猫猫绝育的最佳年龄是多少?");
                painter.drawText(A,"A");
                painter.drawText(B,"B");
                painter.drawText(C,"C");
                painter.drawText(s1,"约3个月时");
                painter.drawText(s2,"约5个月时");
                painter.drawText(s3,"约7个月时");
            }
            else if (rng == 5)
            {
                QFont font4 = painter.font();
                font4.setPixelSize(60);
                painter.setFont(font4);
                painter.drawText(tg,"猫猫的胡须有什么用?");
                painter.drawText(A,"A");
                painter.drawText(B,"B");
                painter.drawText(C,"C");
                painter.drawText(s1,"测量");
                painter.drawText(s2,"美观");
                painter.drawText(s3,"保暖");
            }
        }
    }
    void mousePressEvent(QMouseEvent *event) override
        {
            if (event->button() == Qt::LeftButton)
            {
                QPoint pos1 = event->pos();
                if (enter_quiz)
                {
                    if (isPointOnQuizExit(pos1))
                    {
                        enter_quiz = false;
                        update();
                        return;
                    }
                    else if (isPointOnQuizS1(pos1))
                    {
                        have_selected = true;
                        enter_quiz = false;
                        if (rng == 5)
                        {
                            coin += 75;
                            Love++;
                        }
                        update();
                        return;
                    }
                    else if (isPointOnQuizS2(pos1))
                    {
                        have_selected = true;
                        enter_quiz = false;
                        if (rng == 1 || rng == 2)
                        {
                            coin+=75;
                            Love++;
                        }
                        update();
                        return;
                    }
                    else if (isPointOnQuizS3(pos1))
                    {
                        have_selected = true;
                        enter_quiz = false;
                        if (rng == 3 || rng == 4)
                        {
                            coin+=75;
                            Love++;
                        }
                        update();
                        return;
                    }
                }
                else
                {
                    if (isPointOnCurtain(pos1))
                    {
                        bool temp = is_open_curtain;
                        if (temp) is_open_curtain = 0;
                        else is_open_curtain = 1;
                        update();
                        return ;
                    }
                    if (isPointOnCloseEnd(pos1))
                    {
                        ended = false;
                        update();
                        return ;
                    }
                    if (isPointOnClose(pos1))
                    {
                        desc_page = false;
                        update();
                        return ;
                    }
                    if (isPointOnWaterBowl(pos1))
                    {
                        is_Dragging_water_bowl = true;
                        offset_water_bowl = pos1 - posof_water_bowl;
                        update();
                        return ;
                    }
                    if (isPointOnBoard(pos1))
                    {
                        is_Dragging_board = true;
                        offset_board = pos1 - posof_board;
                        update();
                        return ;
                    }
                    if (isPointOnCatnip(pos1))
                    {
                        is_Dragging_Catnip = true;
                        offset_Catnip = pos1 - posof_Catnip;
                        update();
                        return ;
                    }
                    if (isPointOnBall(pos1))
                    {
                        is_Dragging_ball = true;
                        offset_ball = pos1 - posof_ball;
                        update();
                        return ;
                    }
                    if (isPointOnIpad(pos1))
                    {
                        is_Dragging_ipad = true;
                        offset_ipad = pos1 - posof_ipad;
                        update();
                        return ;
                    }
                    if (isPointOnShop1(pos1) && !bought_1)
                    {
                        if (coin >= 100)
                        {
                            bought_1 = true;
                            coin -= 100;
                            Love += 3;
                            update();
                        }
                        else
                        {
                            Coin_not_enough = true;
                            Coin_not_enough_Timer.start(1500);
                            update();
                        }
                        return;
                    }
                    if (isPointOnShop2(pos1) && !bought_2)
                    {
                        if (coin >= 300)
                        {
                            bought_2 = true;
                            coin -= 300;
                            update();
                        }
                        else
                        {
                            Coin_not_enough = true;
                            Coin_not_enough_Timer.start(1500);
                            update();
                        }
                        return;
                    }
                    if (isPointOnShop3(pos1) && !bought_3)
                    {
                        if (coin >= 500)
                        {
                            bought_3 = true;
                            coin -= 500;
                            update();
                        }
                        else
                        {
                            Coin_not_enough = true;
                            Coin_not_enough_Timer.start(1500);
                            update();
                        }
                        return;
                    }
                    if (isPointOnShop4(pos1) && !bought_4)
                    {
                        if (coin >= 1000)
                        {
                            bought_4 = true;
                            coin -= 1000;
                            update();
                        }
                        else
                        {
                            Coin_not_enough = true;
                            Coin_not_enough_Timer.start(1500);
                            update();
                        }
                        return;
                    }
                    if (isPointOnShop5(pos1) && !bought_5)
                    {
                        if (coin >= 2000)
                        {
                            bought_5 = true;
                            coin -= 2000;
                            update();
                        }
                        else
                        {
                            Coin_not_enough = true;
                            Coin_not_enough_Timer.start(1500);
                            update();
                        }
                        return;
                    }
                    if (isPointOnShop6(pos1) && !bought_6)
                    {
                        if (coin >= 9999)
                        {
                            bought_6 = true;
                            coin -= 9999;
                            update();
                        }
                        else
                        {
                            Coin_not_enough = true;
                            Coin_not_enough_Timer.start(1500);
                            update();
                        }
                        return;
                    }
                    else if (isExitShop(pos1))
                    {
                        Coin_not_enough = false;
                        enter_shop = false;
                        update();
                    }
                    else if (isPointOnDesc(pos1))
                    {
                        desc_page = true;
                        update();
                    }
                    else if (isPointOnExit(pos1))
                    {
                        close();
                        return;
                    }
                    else if (isPointOnCatty(pos1))
                    {
                        ismeow = true;
                        meowTimer.start(500);
                        update();
                    }
                    else if (isPointOnQuiz(pos1) && !have_selected)
                    {
                        enter_quiz = true;
                        update();
                    }
                    else if (isPointOnBed(pos1))
                    {
                        is_night = true;
                        nightTimer.start(2000);
                        Day++;
                        rng = QRandomGenerator::global()->bounded(1,6);
                        have_selected = false;
                        if (rng >= 4 && !bought_3) Love--;
                        if (rng == 2 && bought_2) Love++;
                        if (bought_4)
                        {
                            Love++;
                            coin += 25;
                        }
                        if (bought_5) Love+=3;
                        if (Love >= 99)
                        {
                            if (!flag)
                            {
                                ended = true;
                                flag = true;
                            }
                        }
                        update();
                    }
                    else if (isPointOnShop(pos1))
                    {
                        enter_shop = true;
                        update();
                    }
                }
            }
        }

        void mouseMoveEvent(QMouseEvent *event) override
        {
            if (is_Dragging_water_bowl)
            {
                posof_water_bowl = event->pos() - offset_water_bowl;
                update();
            }
            else if (is_Dragging_board)
            {
                posof_board = event->pos() - offset_board;
                update();
            }
            else if (is_Dragging_Catnip)
            {
                posof_Catnip = event->pos() - offset_Catnip;
                update();
            }
            else if (is_Dragging_ball)
            {
                posof_ball = event->pos() - offset_ball;
                update();
            }
            else if (is_Dragging_ipad)
            {
                posof_ipad = event->pos() - offset_ipad;
                update();
            }
        }

        void mouseReleaseEvent(QMouseEvent *event) override
        {
            if (event->button() == Qt::LeftButton && is_Dragging_water_bowl)
            {
                is_Dragging_water_bowl = false;
            }
            if (event->button() == Qt::LeftButton && is_Dragging_board)
            {
                is_Dragging_board = false;
            }
            if (event->button() == Qt::LeftButton && is_Dragging_Catnip)
            {
                is_Dragging_Catnip = false;
            }
            if (event->button() == Qt::LeftButton && is_Dragging_ball)
            {
                is_Dragging_ball = false;
            }
            if (event->button() == Qt::LeftButton && is_Dragging_ipad)
            {
                is_Dragging_ipad = false;
            }
        }
    };

    #include "main.moc"

    int main(int argc, char *argv[])
    {
        QApplication app(argc, argv);
        Background w;
        w.show();
        return app.exec();
    }
