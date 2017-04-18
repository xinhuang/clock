#ifndef CLOCK_H
#define CLOCK_H

#include <memory>

#include <QMainWindow>
#include <QTimer>
#include <QPoint>

namespace Ui {
class Clock;
}

class Clock : public QMainWindow
{
    Q_OBJECT

public:
    explicit Clock(QWidget *parent = 0);
    ~Clock();

private:
    void onTick();

    void mousePressEvent(QMouseEvent * e) override;
    void mouseReleaseEvent(QMouseEvent * e) override;
    void mouseMoveEvent(QMouseEvent *e) override;

private:
    Ui::Clock *ui;
    std::unique_ptr<QTimer> timer;
    bool isMoving = false;
    QPoint pressPos;
};

#endif // CLOCK_H