// GPL-3.0

#ifndef WIDGET_H
#define WIDGET_H

#include <unistd.h>

#include <QObject>
#include <QWidget>
#include <QApplication>
#include <QDesktopWidget>
#include <QGuiApplication>
#include <QListWidget>
#include <QMouseEvent>
#include <QMenu>
#include <QActionGroup>
#include <QAction>
#include <QPainter>
#include <QPen>
#include <QLineF>
#include <QPainterPath>
#include <QPixmap>
#include <QRegion>
#include <QFrame>
#include <QGraphicsDropShadowEffect>
#include <QStyleOption>
#include <QBrush>
#include <QLabel>
#include <QRect>
#include <QTimer>
#include <QDebug>
#include <QDateTime>
#include <QString>
#include <QStringList>
#include <QVector>
#include <QIODevice>
#include <QDir>
#include <QStandardPaths>
#include <QFileInfo>
#include <QFile>

#include "define.h"
#include "getsysinfo.h"
#include "datastruct.h"

class Widget : public QWidget, public GetSysInfo
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    // event
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);        // 绘制界面 (paint interface)

    // addon
    QLabel *cpu_label;        // cpu标签 (cpu tag)
    QLabel *mem_label;        // mem标签 (mem tag)
    QLabel *mem_chart;        // mem图表 (mem chart)
    QLabel *mail_indic_label; // mail指示器 (mail indicating)
    QMenu *rightBtnMenu;      // 右键菜单 (right menu)
    QActionGroup *rightBtnMenu_actonGroup; // 右键菜单 act


    // methods
    void deal_configFile(int mode);  // 检测和生成配置文件SET_MODE:use SET_MODE:set (test and create configure) at ~/.config/PopBall               //
    void init();                     // 设置初始数据 (set initial data)
    void ending();                   // 析构
    void right_contextMenu();          // 右键菜单 (right context menu)
    void main_ui_style();            // 设置主要样式 (set main style)
    void timer_setInterval();        // 用于全局唯一计时器执行 (only timer func)
    void content();                  // 内容 (content func)
    void window_adsorb(bool isInit); // 窗口吸附位置
    GetSysInfo *Get_sys_info;        // 获取内容方法 (get content func)

private:
    // event cor
    bool mouseIsPress = false; // 鼠标是否按下 (mouse is press)
    QPoint curPoint;           // 当前坐标 (current coordinate)
    QTimer *global_timer;      // 全局唯一计时器对象 (only timer obj)

    // data
    double cpu_data;
    double cpu_usageData;
    double mem_data;
    QVector<double> mem_data_history;      // data of mem
    QVector<double> cpuUsage_data_history; // data of cpuUsage

    struct cfg {                       // configure item
        int     POSITION_X;            // x at window
        int     POSITION_Y;            // y at window
        int     REFRESH_INTERVAL=1000; // data refresh interval
        int     SHOW_CPU_LABEL;        // cpu label show or hide

        int     CHART_ROW      = 41;   // 图表最大列数 (max row)
        double  CPU_LINE_W     = 1.5;  // cpu line width
        int     WIDTH          = 100;  // window width;
        int     HEIGHT         = 100;  // window height;
        int     BORDER_WIDTH   = 3;    // border width
        int     OUTER_CIRCLE_X = 3;    // outer circle
        int     OUTER_CIRCLE_Y = 3;
        int     OUTER_CIRCLE_W = 94;
        int     OUTER_CIRCLE_H = 94;
        int     MAIN_CIRCLE_X  = 0;    // main circle
        int     MAIN_CIRCLE_Y  = 0;
        int     MAIN_CIRCLE_W  = 100;
        int     MAIN_CIRCLE_H  = 100;
        // font
        QString LABEL_FONT_TYPE     = "Microsoft YaHei";
        int     LABEL_FONT_SIZE     = 10;
        int     LABEL_FONT_WEIGHT   = 74;
        QString LABEL_STYLE         = "color:#fdfefd;";
        int     LABEL_FONT_SHADOW_R = 11;
        // color
        double  MAIN_OPACITY            = 0.89;
        int     MAIN_COLOR[3]           = {35, 38, 41};
        int     OUTER_BORDER_COLOR[3]   = {249, 249, 249};
        int     MEM_CHART_COLOR[4]      = {19, 187, 177, 191};
        int     CPU_LINE_COLOR[3]       = {121, 230, 203};
        int     CPUUSAGE_CHART_COLOR[4] = {19, 187, 177, 191};
    } cfg;

    // effect
    QGraphicsDropShadowEffect *text_shadowEffect; // text shadow effect

    // configure file name
    QString CONF_FILE_NAME = "yt-popball.conf"; // name
    // configure file
    const char CONF_FILE_DEFAULT_CONTENT[127] =
            "POSITION=0 0\n"            // x y and autoset
            "REFRESH_INTERVAL=3000\n"   // ms
            "SHOW_CPU_LABEL=1\n"        // 0: hide 1: show
            "MAIN_OPACITY=0.89\n"       // opacity
            ;

    // 窗口模式外观 (MINI and NORMAL) (window look)
    int WINDOW_SIZE_LOOK     = NORMAL_MODE;      // default normal mode
    int WINDOW_SET_DIRECTION = NOTEDGE_MODE; // window on edge (left or right or other)    
};
#endif // WIDGET_H
