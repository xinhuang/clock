#include "clock.h"
#include "ui_clock.h"

#include <QTime>
#include <QMouseEvent>
#include <QMenu>
#include <QSettings>

Clock::Clock(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Clock) {

    QSettings settings;
    restoreGeometry(settings.value("mainWindowGeometry").toByteArray());

    ui->setupUi(this);

    restoreState(settings.value("mainWindowState").toByteArray());

    timer.reset(new QTimer(this));
    connect(timer.get(), &QTimer::timeout, this, &Clock::onTick);
    timer->start(100);
}

Clock::~Clock() {
    delete ui;
}

void Clock::onTick() {
    const auto& now = QTime::currentTime();
    ui->timeValue->setText(now.toString("HH:mm:ss"));
}

void Clock::closeEvent(QCloseEvent* e)
{
    timer->stop();
    QSettings settings;
    settings.setValue("mainWindowGeometry", saveGeometry());
    settings.setValue("mainWindowState", saveState());
    e->accept();
}

void Clock::mousePressEvent(QMouseEvent *e) {
    isMoving = true;
    offset = e->globalPos() - this->pos();
}

void Clock::mouseReleaseEvent(QMouseEvent *e) {
    isMoving = false;

    if (e->button() == Qt::RightButton) {
        std::unique_ptr<QMenu> menu(createMenu());
        menu->exec(e->globalPos());
    }
}

void Clock::mouseMoveEvent(QMouseEvent *e) {
    if (isMoving) {
        move(e->globalPos() - offset);
    }
}

QMenu* Clock::createMenu() {
    QMenu* menu= new QMenu(this);
    menu->addAction(tr("Quit"), this, &Clock::close);
    return menu;
}
