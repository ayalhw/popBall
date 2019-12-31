#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMouseEvent>
#include <QMenu>
#include <QPainter>
#include <QFrame>
#include <QStyleOption>
#include <QBrush>
#include <QLabel>
#include <QTimer>
#include <QDebug>
#include <QDateTime>

#include "getsysinfo.h"

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

//    鼠标是否按下
    bool mouseIsPress = false;

//    当前坐标
    QPoint curPoint;

//    右键菜单
    QMenu *rightBtnMenu;

//    绘制圆角窗口
    void paintEvent(QPaintEvent *event);

//    内容
    void content();
    QLabel *cpu_label; // cpu标签

//    获取内容方法
    GetSysInfo *Get_sys_info;

//    全局唯一计时器对象
    QTimer *global_timer;
private slots:
//    全局唯一计时器
    void timer_setInterval();

};
#endif // WIDGET_H
