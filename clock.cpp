#include "clock.h"
#include "ui_clock.h"

#include <QTime>
#include <QMouseEvent>

Clock::Clock(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Clock) {
    ui->setupUi(this);

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

void Clock::mousePressEvent(QMouseEvent *e) {
    isMoving = true;
    offset = e->globalPos() - this->pos();
}

void Clock::mouseReleaseEvent(QMouseEvent */*e*/) {
    isMoving = false;
}

void Clock::mouseMoveEvent(QMouseEvent *e) {
    if (isMoving) {
        move(e->globalPos() - offset);
    }
}
