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
        catty_buttons[5].load("C:/Users/39036/Downloads/小猫按钮-removebg-preview.png");
        description1.load("C:/Users/39036/Downloads/问号-removebg-preview.png");
        description1 = description1.scaled(100,100);
        desc_paper.load("C:/Users/39036/Downloads/说明页面1-removebg-preview__1_-removebg-preview.png");
        close_page.load("C:/Users/39036/Downloads/关闭页面.png");
        mystery_key.load("C:/Users/39036/Downloads/神秘钥匙-removebg-preview.png");
        curtain1.load("C:/Users/39036/Downloads/chuanglianclose-removebg-preview.png");
        curtain1 = curtain1.scaled(725,500);
        curtainopen.load("C:/Users/39036/Downloads/chuanglianopen-removebg-preview.png");
        curtainopen = curtainopen.scaled(725,500);
        flower.load("C:/Users/39036/Downloads/flower4-shadow-removebg-preview.png");
        flower = flower.scaled(800,400);
        flower_night.load("C:/Users/39036/Downloads/flower-night-removebg-preview.png");
        flower_night = flower_night.scaled(800,400);
        cattyhat1.load("C:/Users/39036/Downloads/cat-rabbithat-removebg-preview.png");
        cattyhat2.load("C:/Users/39036/Downloads/cat-dinosaurhat-removebg-preview.png");
        cattyhat3.load("C:/Users/39036/Downloads/cat-doghat-removebg-preview.png");
        cattyhat1 = cattyhat1.scaled(catty.width(),catty.height());
        cattyhat2 = cattyhat2.scaled(catty.width(),catty.height());
        cattyhat3 = cattyhat3.scaled(catty.width(),catty.height());
        is_bought_hat[0] = true;
        is_bought_hat[1] = true;
        is_bought_hat[2] = false;
        is_bought_hat[3] = true;
        background_wb.load("C:/Users/39036/Downloads/background_wb.png");
        stone.load("C:/Users/39036/Downloads/stone_w-removebg-preview.png");
        sci.load("C:/Users/39036/Downloads/sci_w-removebg-preview.png");
        bu.load("C:/Users/39036/Downloads/bu_w-removebg-preview.png");
        stone1.load("C:/Users/39036/Downloads/stone_w-removebg-preview.png");
        sci1.load("C:/Users/39036/Downloads/sci_w-removebg-preview.png");
        bu1.load("C:/Users/39036/Downloads/bu_w-removebg-preview.png");
        stone2.load("C:/Users/39036/Downloads/stone_w-removebg-preview.png");
        sci2.load("C:/Users/39036/Downloads/sci_w-removebg-preview.png");
        bu2.load("C:/Users/39036/Downloads/bu_w-removebg-preview.png");
        stone2 = stone2.scaled(500,500);
        sci2 = sci2.scaled(500,500);
        bu2 = bu2.scaled(500,500);
        seqNumbers.resize(8);
        seqCurrentIndex = 0;
        seqDisplaying = false;
        seqPlaying = false;
        seqError = false;
        seqWin = false;
        seqDisplayStep = 0;
        seqCurrentDisplayNumber = -1;
        seqDisplayTimer.setSingleShot(true);
        connect(&seqDisplayTimer, &QTimer::timeout, this, &Background::onSeqDisplayTimeout);
        puzzleActive = false;
        puzzleWin = false;
        stopGameActive = false;
        stopGameWin = false;
        stopGameFail = false;
        pointerAngle = 0.0;
        pointerDirection = 1;
        minAngle = -30.0;
        maxAngle = 30.0;
        stopGameTimer.setSingleShot(false);  // 循环定时器
        connect(&stopGameTimer, &QTimer::timeout, this, &Background::updatePointer);
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
private slots:
    void startGame3()
    {
        seqDisplaying = true;
        seqPlaying = false;
        seqError = false;
        seqWin = false;
        seqCurrentIndex = 0;
        seqDisplayStep = 0;
        seqNumbers.clear();
        for (int i = 0; i < 8; ++i)
            seqNumbers.append(QRandomGenerator::global()->bounded(0, 10));
        seqCurrentDisplayNumber = seqNumbers[0];
        seqDisplayTimer.start(2000);
        update();
    }
private slots:
    void onSeqDisplayTimeout()
    {
        seqDisplayStep++;
        if (seqDisplayStep < 8) {
            seqCurrentDisplayNumber = seqNumbers[seqDisplayStep];
            seqDisplayTimer.start(2000);
        } else {
            seqDisplaying = false;
            seqPlaying = true;
            seqCurrentDisplayNumber = -1;
            seqCurrentIndex = 0;
            update();
        }
        update();
    }
private slots:
    void updatePointer()
    {
        if (!stopGameActive) return;
        pointerAngle += pointerDirection * 15.0;
        update();
    }
private slots:
    void stopAndCheck()
    {
        if (!stopGameActive) return;
        stopGameTimer.stop();

        double angle = fmod(pointerAngle, 360.0);
        if (angle < 0) angle += 360.0;

        bool hit = (angle >= 150.0 && angle <= 210.0);

        if (hit) {
            stopGameWin = true;
            coin += 75;
            Love++;
        } else {
            stopGameFail = true;
        }
        stopGameActive = false;
        update();

        QTimer::singleShot(1500, this, [this]() {
            enter_quiz = false;
            have_selected = true;
            stopGameWin = false;
            stopGameFail = false;
            stopGameActive = false;
            update();
        });
    }

private:
    QPixmap background;
    QPixmap background_night;
    QPixmap catty;
    QPixmap cattymeow;
    QPixmap cattysleep;
    QPixmap cattyhat1;
    QPixmap cattyhat2;
    QPixmap cattyhat3;
    bool ismeow;
    QTimer meowTimer;
    QPixmap money;
    int coin = 10000;
    int Day = 1;
    int Love = 0;
    bool enter_quiz = false;
    bool enter_shop = false;
    bool enter_decoration = false;
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
    QPixmap flower;
    QPixmap flower_night;
    QPixmap background_wb;
    QPixmap stone;
    QPixmap sci;
    QPixmap bu;
    QPixmap stone1;
    QPixmap sci1;
    QPixmap bu1;
    QPixmap stone2;
    QPixmap sci2;
    QPixmap bu2;
    bool bought_1 = false;
    bool bought_2 = false;
    bool bought_3 = false;
    bool bought_4 = false;
    bool bought_5 = false;
    bool bought_6 = false;
    bool Coin_not_enough = false;
    bool is_bought_curtain = true;
    bool is_open_curtain = false;
    bool is_bought_flower = true;
    QVector<int> seqNumbers;
    int seqCurrentIndex;
    bool seqDisplaying;
    bool seqPlaying;
    bool seqError;
    bool seqWin;
    QTimer seqDisplayTimer;
    int seqDisplayStep;
    int seqCurrentDisplayNumber;
    int hat = 0;
    bool is_bought_hat[4];
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
    int gameclass = QRandomGenerator::global()->bounded(1,6);
    int temprng = QRandomGenerator::global()->bounded(1,4);
    QTimer stopGameTimer;
    bool stopGameActive;
    bool stopGameWin;
    bool stopGameFail;
    double pointerAngle;
    int pointerDirection;
    double minAngle, maxAngle;
    bool ended = false;
    QPixmap catty_buttons[100];
    QPixmap description1;
    bool desc_page = false;
    QPixmap desc_paper;
    QPixmap close_page;
    bool flag = false;
    int select2 = 0;
    bool waitingForResult = false;
    int playerChoice = 0;
    int computerChoice = 0;
    int puzzle[3][3];
    int emptyRow, emptyCol;
    bool puzzleActive;
    bool puzzleWin;
    void initPuzzle() {
        int nums[9] = {1,2,3,4,5,6,7,8,0};
        for (int step = 0; step < 100; ++step) {
            int i = QRandomGenerator::global()->bounded(9);
            int j = QRandomGenerator::global()->bounded(9);
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }
        for (int r = 0; r < 3; ++r) {
            for (int c = 0; c < 3; ++c) {
                puzzle[r][c] = nums[r*3 + c];
                if (puzzle[r][c] == 0) {
                    emptyRow = r;
                    emptyCol = c;
                }
            }
        }
    }
    bool isPointOnCatty(QPoint& pos)
    {
        QRect isoncatty[4];
        isoncatty[0] = QRect(1750,825,catty.width(),catty.height());
        isoncatty[1] = QRect(1750,825,cattyhat1.width(),cattyhat1.height());
        isoncatty[2] = QRect(1750,825,cattyhat2.width(),cattyhat2.height());
        isoncatty[3] = QRect(1750,825,cattyhat3.width(),cattyhat3.height());
        if (isoncatty[hat].contains(pos))
        {
            return true;
        }
        return false;
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

    bool isPointOnDecoration(QPoint& pos)
    {
        QRect isondec(2160,650,300,100);
        if (isondec.contains(pos)) return true;
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

    bool isPointOnShop1(QPoint& pos) {
        if (!bought_1 && enter_shop) {
            QRect rect(168, 108, water_bowl.width(), water_bowl.height());
            return rect.contains(pos);
        }
        return false;
    }

    bool isPointOnShop2(QPoint& pos) {
        if (!bought_2 && enter_shop) {
            QRect rect(1008, 108, scratch_board.width(), scratch_board.height());
            return rect.contains(pos);
        }
        return false;
    }

    bool isPointOnShop3(QPoint& pos) {
        if (!bought_3 && enter_shop) {
            QRect rect(1848, 108, Catnip.width(), Catnip.height());
            return rect.contains(pos);
        }
        return false;
    }

    bool isPointOnShop4(QPoint& pos) {
        if (!bought_4 && enter_shop) {
            QRect rect(168, 608, ball.width(), ball.height());
            return rect.contains(pos);
        }
        return false;
    }

    bool isPointOnShop5(QPoint& pos) {
        if (!bought_5 && enter_shop) {
            QRect rect(908, 688, iPad.width(), iPad.height());
            return rect.contains(pos);
        }
        return false;
    }

    bool isPointOnShop6(QPoint& pos) {
        if (!bought_6 && enter_shop) {
            QRect rect(1848, 588, mystery_key.width(), mystery_key.height());
            return rect.contains(pos);
        }
        return false;
    }

        bool isExitShop(QPoint& pos)
        {
            QRect isexitshop = rect();
            if (isexitshop.contains(pos) && enter_shop) return true;
            return false;
        }

        bool isPointOnStone(QPoint &pos)
        {
            QRect isonstone (300,750,stone.width(),stone.height());
            if (isonstone.contains(pos) && gameclass == 2 && enter_quiz) return true;
            return false;
        }

        bool isPointOnsci(QPoint &pos)
        {
            QRect isonsci (600,750,sci.width(),sci.height());
            if (isonsci.contains(pos) && gameclass == 2 && enter_quiz) return true;
            return false;
        }

        bool isPointOnbu(QPoint &pos)
        {
            QRect isonbu (900,750,bu.width(),bu.height());
            if (isonbu.contains(pos) && gameclass == 2 && enter_quiz) return true;
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
        if (!enter_quiz && !enter_shop && !enter_decoration)
        {
            Q_UNUSED(event);
            painter.drawPixmap(rect(),background);
            QPoint pointer_catty(1750,825);
            if (!is_night)
            {
                painter.drawPixmap(rect(),background);
                if (is_bought_flower)
                {
                    QPoint flower_pointer(600,700);
                    painter.drawPixmap(flower_pointer,flower);
                }
                if (hat == 0) painter.drawPixmap(pointer_catty,catty);
                else if (hat == 1) painter.drawPixmap(pointer_catty,cattyhat1);
                else if (hat == 2) painter.drawPixmap(pointer_catty,cattyhat2);
                else if (hat == 3) painter.drawPixmap(pointer_catty,cattyhat3);
            }
            else
            {
                painter.drawPixmap(rect(),background_night);
                painter.drawPixmap(pointer_catty,cattysleep);
                if (is_bought_flower)
                {
                    QPoint flower_pointer(600,700);
                    painter.drawPixmap(flower_pointer,flower_night);
                }

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

            int coin_textX = 220;
            int coin_textY = 160;
            painter.drawText(coin_textX, coin_textY, coin_text);

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
            QString decoration = QString("装饰品");
            QPoint pointer_buttons1(2060,-150);
            QPoint pointer_buttons2(2060,0);
            QPoint pointer_buttons3(2060,150);
            QPoint pointer_buttons4(2060,300);
            QPoint pointer_buttons5(2060,450);
            painter.drawPixmap(pointer_buttons1,catty_buttons[1]);
            painter.drawPixmap(pointer_buttons2,catty_buttons[2]);
            painter.drawPixmap(pointer_buttons3,catty_buttons[3]);
            painter.drawPixmap(pointer_buttons4,catty_buttons[4]);
            painter.drawPixmap(pointer_buttons5,catty_buttons[5]);
            QPen pen_text;
            painter.setPen(pen_text);
            painter.drawText(2250,120,quiz);
            painter.drawText(2250,270,shop);
            painter.drawText(2250,420,exit);
            painter.drawText(2250,570,bed);
            painter.drawText(2220,720,decoration);
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
            if (gameclass == 1)
            {
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
                    painter.drawText(tg,"归并排序的最坏时间复杂度是多少?");
                    painter.drawText(A,"A");
                    painter.drawText(B,"B");
                    painter.drawText(C,"C");
                    painter.drawText(s1,"O(n)");
                    painter.drawText(s2,"O(nlogn)");
                    painter.drawText(s3,"O(n²)");
                }
                else if (rng == 2)
                {
                    QFont font4 = painter.font();
                    font4.setPixelSize(60);
                    painter.setFont(font4);
                    painter.drawText(tg,"dijkstra算法的时间复杂度是多少?");
                    painter.drawText(A,"A");
                    painter.drawText(B,"B");
                    painter.drawText(C,"C");
                    painter.drawText(s1,"O(nlogn)");
                    painter.drawText(s2,"O((n+m)logn)");
                    painter.drawText(s3,"O(mlogn)");
                }
                else if (rng == 3)
                {
                    QFont font4 = painter.font();
                    font4.setPixelSize(60);
                    painter.setFont(font4);
                    painter.drawText(tg,"BFS一般需要用到哪种数据结构?");
                    painter.drawText(A,"A");
                    painter.drawText(B,"B");
                    painter.drawText(C,"C");
                    painter.drawText(s1,"栈");
                    painter.drawText(s2,"二叉树");
                    painter.drawText(s3,"队列");
                }
                else if (rng == 4)
                {
                    QFont font4 = painter.font();
                    font4.setPixelSize(60);
                    painter.setFont(font4);
                    painter.drawText(tg,"线段树比起前缀和的显著优势是什么");
                    painter.drawText(A,"A");
                    painter.drawText(B,"B");
                    painter.drawText(C,"C");
                    painter.drawText(s1,"快速区间查询");
                    painter.drawText(s2,"快速区间排序");
                    painter.drawText(s3,"快速区间修改");
                }
                else if (rng == 5)
                {
                    QFont font4 = painter.font();
                    font4.setPixelSize(60);
                    painter.setFont(font4);
                    painter.drawText(tg,"当n超过哪个数量级时，O(nlogn)的算法会TLE?");
                    painter.drawText(A,"A");
                    painter.drawText(B,"B");
                    painter.drawText(C,"C");
                    painter.drawText(s1,"10^5");
                    painter.drawText(s2,"10^6");
                    painter.drawText(s3,"10^7");
                }
            }
            else if (gameclass == 2)
            {
                QPoint pointer_backgroundbw (320,180);
                painter.drawPixmap(pointer_backgroundbw, background_wb.scaled(1920,1080));

                stone.scaled(120,120); painter.drawPixmap(300,750, stone);
                sci.scaled(120,120);   painter.drawPixmap(600,750, sci);
                bu.scaled(120,120);    painter.drawPixmap(900,750, bu);

                QFont titleFont = painter.font();
                titleFont.setPixelSize(80);
                titleFont.setBold(true);
                painter.setFont(titleFont);
                painter.setPen(Qt::black);
                painter.drawText(1110, 320, "石头剪刀布");

                QFont subFont = painter.font();
                subFont.setPixelSize(40);
                painter.setFont(subFont);
                painter.drawText(1060, 400, "选择你的手势与小猫对决");

                if (playerChoice == 1)
                    painter.drawPixmap(400,400, stone1.scaled(500,500));
                else if (playerChoice == 2)
                    painter.drawPixmap(400,400, sci1.scaled(500,500));
                else if (playerChoice == 3)
                    painter.drawPixmap(400,400, bu1.scaled(500,500));
                if (computerChoice == 1)
                    painter.drawPixmap(1600,400, stone2);
                else if (computerChoice == 2)
                    painter.drawPixmap(1600,400, sci2);
                else if (computerChoice == 3)
                    painter.drawPixmap(1600,400, bu2);
            }
            else if (gameclass == 3)
            {
                QPoint pointer_backgroundbw (320,180);
                painter.drawPixmap(pointer_backgroundbw, background_wb.scaled(1920,1080));

                QFont titleFont = painter.font();
                titleFont.setPixelSize(50);
                titleFont.setBold(true);
                painter.setFont(titleFont);
                painter.setPen(Qt::black);
                painter.drawText(1100, 320, "顺序记忆");
                painter.setFont(QFont("Arial", 30));
                painter.drawText(750, 380, "记住右侧数字顺序，然后依次点击左侧数字");

                if (seqPlaying && !seqError && !seqWin) {
                    int leftStartX = 500, leftStartY = 600;
                    int btnW = 100, btnH = 80;
                    int spacingX = 30, spacingY = 30;
                    int cols = 5;
                    for (int i = 0; i <= 9; ++i) {
                        int row = i / cols;
                        int col = i % cols;
                        int x = leftStartX + col * (btnW + spacingX);
                        int y = leftStartY + row * (btnH + spacingY);
                        painter.drawRect(x, y, btnW, btnH);
                        painter.setFont(QFont("Arial", 40));
                        painter.drawText(QRect(x, y, btnW, btnH), Qt::AlignCenter, QString::number(i));
                    }
                }

                if (seqDisplaying) {
                    // 展示阶段：显示大数字
                    painter.setFont(QFont("Arial", 200));
                    painter.setPen(Qt::blue);
                    painter.drawText(1500, 800, QString::number(seqCurrentDisplayNumber));
                    painter.setFont(QFont("Arial", 30));
                    painter.drawText(1500, 500, QString("记住数字 %1 / 8").arg(seqDisplayStep + 1));
                } else if (seqPlaying && !seqError && !seqWin) {
                    // 点击阶段：显示当前需要点击第几个数字（不显示具体数字，考验记忆）
                    painter.setFont(QFont("Arial", 50));
                    painter.setPen(Qt::black);
                    painter.drawText(1500, 800, QString("点击第 %1 个数字").arg(seqCurrentIndex + 1));
                    painter.setFont(QFont("Arial", 30));
                    painter.drawText(1500, 500, "（记住刚才的数字）");
                }

                if (seqError) {
                    painter.setFont(QFont("Arial", 120));
                    painter.setPen(Qt::red);
                    painter.drawText(width() / 2 - 80, height() / 2, "X");
                } else if (seqWin) {
                    painter.setFont(QFont("Arial", 100));
                    painter.setPen(Qt::green);
                    painter.drawText(width() / 2 - 120, height() / 2, "WIN");
                }
            }
            else if (gameclass == 4)
            {
                QPoint pointer_backgroundbw (320,180);
                painter.drawPixmap(pointer_backgroundbw, background_wb.scaled(1920,1080));

                QFont titleFont = painter.font();
                titleFont.setPixelSize(60);
                titleFont.setBold(true);
                painter.setFont(titleFont);
                painter.setPen(Qt::black);
                painter.drawText(1100, 320, "数字华容道");
                painter.setFont(QFont("Arial", 30));
                painter.drawText(900, 400, "点击数字移动到空格，拼回 1-8");

                int startX = 900, startY = 500;
                int cellW = 160, cellH = 160;
                int spacing = 10;
                for (int r = 0; r < 3; ++r) {
                    for (int c = 0; c < 3; ++c) {
                        int x = startX + c * (cellW + spacing);
                        int y = startY + r * (cellH + spacing);
                        painter.setPen(QPen(Qt::black, 3));
                        painter.setBrush(QBrush(QColor(240, 240, 240)));
                        painter.drawRect(x, y, cellW, cellH);

                        int num = puzzle[r][c];
                        if (num != 0) {
                            painter.setFont(QFont("Arial", 60));
                            painter.setPen(Qt::black);
                            painter.drawText(QRect(x, y, cellW, cellH), Qt::AlignCenter, QString::number(num));
                        } else {
                            painter.setBrush(QBrush(QColor(200, 200, 200)));
                            painter.drawRect(x, y, cellW, cellH);
                        }
                    }
                }

                if (puzzleWin) {
                    painter.setFont(QFont("Arial", 100));
                    painter.setPen(Qt::green);
                    painter.drawText(width() / 2 - 120, height() / 2, "WIN");
                }
            }
            else if (gameclass == 5)
            {
                QPoint pointer_backgroundbw (320,180);
                painter.drawPixmap(pointer_backgroundbw, background_wb.scaled(1920,1080));

                QFont titleFont = painter.font();
                titleFont.setPixelSize(60);
                titleFont.setBold(true);
                painter.setFont(titleFont);
                painter.setPen(Qt::black);
                painter.drawText(1050, 320, "反应停止");
                painter.setFont(QFont("Arial", 30));
                painter.drawText(800, 400, "指针进入绿色区域时点击「停止」");

                int centerX = width() / 2;      // 1280
                int centerY = 800;
                int radius = 300;
                painter.setBrush(QBrush(Qt::green));
                painter.drawPie(centerX - radius, centerY - radius, radius*2, radius*2,
                                (270 - 30) * 16, 60 * 16);   // 起始角（12点为0°，顺时针）
                painter.setBrush(QBrush(Qt::red));
                painter.drawPie(centerX - radius, centerY - radius, radius*2, radius*2,
                                (270 + 30) * 16, 300 * 16);
                double rad = pointerAngle * 3.14159 / 180.0;
                int px = centerX + (int)((radius - 20) * cos(rad - 3.14159/2));
                int py = centerY + (int)((radius - 20) * sin(rad - 3.14159/2));
                painter.setBrush(QBrush(Qt::black));
                painter.drawLine(centerX, centerY, px, py);
                painter.drawEllipse(centerX - 10, centerY - 10, 20, 20);

                int btnX = 1150, btnY = 1050, btnW = 200, btnH = 80;
                painter.setBrush(QBrush(QColor(200, 200, 200)));
                painter.drawRect(btnX, btnY, btnW, btnH);
                painter.setFont(QFont("Arial", 40));
                painter.drawText(QRect(btnX, btnY, btnW, btnH), Qt::AlignCenter, "停止");

                if (stopGameWin) {
                    painter.setFont(QFont("Arial", 100));
                    painter.setPen(Qt::green);
                    painter.drawText(width() / 2 - 120, height() / 2 + 100, "WIN");
                } else if (stopGameFail) {
                    painter.setFont(QFont("Arial", 100));
                    painter.setPen(Qt::red);
                    painter.drawText(width() / 2 - 120, height() / 2 + 100, "X");
                }
            }
        }
        else if (enter_decoration)
        {
            painter.drawPixmap(rect(),shop);
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
                    if (gameclass == 1)
                    {
                        if (isPointOnQuizS1(pos1))
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
                    else if (gameclass == 2)
                    {
                        if (waitingForResult) return;

                        int choice = 0;
                        if (isPointOnStone(pos1)) choice = 1;
                        else if (isPointOnsci(pos1)) choice = 2;
                        else if (isPointOnbu(pos1)) choice = 3;
                        else return;

                        playerChoice = choice;
                        computerChoice = QRandomGenerator::global()->bounded(1, 4);


                        bool win = false;
                        if (playerChoice == 1 && computerChoice == 2) win = true;
                        else if (playerChoice == 2 && computerChoice == 3) win = true;
                        else if (playerChoice == 3 && computerChoice == 1) win = true;

                        update();
                        waitingForResult = true;

                        if (win) {
                            coin += 75;
                            Love++;
                            QTimer::singleShot(1000, this, [this]() {
                                enter_quiz = false;
                                have_selected = true;
                                waitingForResult = false;
                                playerChoice = 0;
                                computerChoice = 0;
                                update();
                            });
                        }
                        else if (playerChoice == computerChoice) {
                            QTimer::singleShot(1000, this, [this]() {
                                waitingForResult = false;
                                playerChoice = 0;
                                computerChoice = 0;
                                update();
                            });
                        }
                        else {
                            QTimer::singleShot(1000, this, [this]() {
                                enter_quiz = false;
                                have_selected = true;
                                waitingForResult = false;
                                playerChoice = 0;
                                computerChoice = 0;
                                update();
                            });
                        }
                        return;
                    }
                    else if(gameclass == 3)
                    {
                        if (!seqPlaying || seqError || seqWin) return;

                        int leftStartX = 500, leftStartY = 600;
                        int btnW = 100, btnH = 80;
                        int spacingX = 30, spacingY = 30;
                        int cols = 5;
                        int clickedNum = -1;
                        for (int i = 0; i <= 9; ++i) {
                            int row = i / cols;
                            int col = i % cols;
                            int x = leftStartX + col * (btnW + spacingX);
                            int y = leftStartY + row * (btnH + spacingY);
                            QRect rect(x, y, btnW, btnH);
                            if (rect.contains(pos1)) {
                                clickedNum = i;
                                break;
                            }
                        }
                        if (clickedNum == -1) return;

                        if (clickedNum == seqNumbers[seqCurrentIndex]) {
                            seqCurrentIndex++;
                            update();
                            if (seqCurrentIndex == seqNumbers.size()) {
                                seqWin = true;
                                seqPlaying = false;
                                coin += 75;
                                Love++;
                                update();
                                QTimer::singleShot(1000, this, [this]() {
                                    enter_quiz = false;
                                    have_selected = true;
                                    seqWin = false;
                                    seqPlaying = false;
                                    update();
                                });
                            }
                        } else {
                            seqError = true;
                            seqPlaying = false;
                            update();
                            QTimer::singleShot(1000, this, [this]() {
                                enter_quiz = false;
                                have_selected = true;
                                seqError = false;
                                update();
                            });
                        }
                    }
                    else if (gameclass == 4)
                    {
                        if (!puzzleActive || puzzleWin) return;

                        int startX = 900, startY = 400;
                        int cellW = 160, cellH = 160;
                        int spacing = 10;
                        int clickedRow = -1, clickedCol = -1;
                        for (int r = 0; r < 3; ++r) {
                            for (int c = 0; c < 3; ++c) {
                                int x = startX + c * (cellW + spacing);
                                int y = startY + r * (cellH + spacing);
                                QRect rect(x, y, cellW, cellH);
                                if (rect.contains(pos1)) {
                                    clickedRow = r;
                                    clickedCol = c;
                                    break;
                                }
                            }
                            if (clickedRow != -1) break;
                        }
                        if (clickedRow == -1) return;

                        if ((abs(clickedRow - emptyRow) + abs(clickedCol - emptyCol)) == 1) {
                            puzzle[emptyRow][emptyCol] = puzzle[clickedRow][clickedCol];
                            puzzle[clickedRow][clickedCol] = 0;
                            emptyRow = clickedRow;
                            emptyCol = clickedCol;
                            update();

                            bool win = true;
                            for (int r = 0; r < 3; ++r) {
                                for (int c = 0; c < 3; ++c) {
                                    int expected = r * 3 + c + 1;
                                    if (expected == 9) expected = 0;  // 最后一个为空格
                                    if (puzzle[r][c] != expected) {
                                        win = false;
                                        break;
                                    }
                                }
                            }
                            if (win) {
                                puzzleWin = true;
                                puzzleActive = false;
                                coin += 100;
                                Love += 2;
                                update();
                                QTimer::singleShot(1500, this, [this]() {
                                    enter_quiz = false;
                                    have_selected = true;
                                    puzzleWin = false;
                                    puzzleActive = false;
                                    update();
                                });
                            }
                        }
                    }
                    else if (gameclass == 5)
                    {
                        int btnX = 1150, btnY = 1050, btnW = 200, btnH = 80;
                        QRect stopBtn(btnX, btnY, btnW, btnH);
                        if (stopBtn.contains(pos1)) {
                            if (stopGameActive && !stopGameWin && !stopGameFail) {
                                stopAndCheck();
                            }
                        }
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
                    if (isPointOnCatty(pos1))
                    {
                        hat = (hat + 1) % 4;
                        while (!is_bought_hat[hat]) hat = (hat + 1) % 4;
                        update();
                        return;
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
                    if (isPointOnDecoration(pos1))
                    {
                        enter_decoration = true;
                        update();
                        return;
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
                            Love += 1;
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
                            Love += 5;
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
                            Love += 8;
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
                            Love += 20;
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
                            Love += 50;
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
                            Love += 9999;
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
                    else if (isPointOnQuiz(pos1) && !have_selected)
                    {
                        enter_quiz = true;
                        if (gameclass == 3) {
                            startGame3();
                        } else if (gameclass == 4) {
                            initPuzzle();
                            puzzleActive = true;
                            puzzleWin = false;
                        } else if (gameclass == 5) {
                            stopGameActive = true;
                            stopGameWin = false;
                            stopGameFail = false;
                            pointerAngle = 0.0;
                            pointerDirection = 1;
                            stopGameTimer.start(20);
                        }
                        update();
                    }
                    else if (isPointOnBed(pos1))
                    {
                        is_night = true;
                        nightTimer.start(2000);
                        Day++;
                        rng = QRandomGenerator::global()->bounded(1,6);
                        gameclass = QRandomGenerator::global()->bounded(1,6);
                        temprng = QRandomGenerator::global()->bounded(1,4);
                        stopGameTimer.stop();
                        stopGameActive = false;
                        stopGameWin = false;
                        stopGameFail = false;
                        pointerAngle = 0.0;
                        pointerDirection = 1;
                        seqDisplayTimer.stop();
                        seqDisplaying = false;
                        seqPlaying = false;
                        seqError = false;
                        seqWin = false;
                        puzzleActive = false;
                        puzzleWin = false;
                        seqCurrentIndex = 0;
                        seqDisplayStep = 0;
                        seqCurrentDisplayNumber = -1;
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
                    isPointOnCatty(pos1);
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
