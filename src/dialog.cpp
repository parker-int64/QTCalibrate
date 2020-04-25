#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(close()));

    // Add scroll bar's qss
    QFile qss("../uiComponents/scrollbar.qss");
    qss.open(QFile::ReadOnly);
    QString style = qss.readAll();
    ui->textBrowser->verticalScrollBar()->setStyleSheet(style);
    qss.close();
}


void Dialog::calibHelp(){
    QString help = "帮助文档:\n"
                   "单目相机标定，分为基础设置(Basic Settings)和高级设置(Advanced settings)\n"
                   "1.必须要填入的参数是选取的图像来源(Picture Source)，标定模式(Calibrate)\n"
                   "棋盘格或者圆点标靶的宽和高以及单位元素大小(Board Width,Board Height & Board Size)\n"
                   "2.在完成基础设置后，点击添加图片至imagelist.yaml(Add to imagelist.yml)\n"
                   "3.点击标定(Calibrate)，开始标定\n"
                   "高级设置可以获取更高的标定精度，部分参数简要中文说明如下：\n"
                   "Calibrate output.............................标定文件输出路径，默认在程序data目录下面\n\n"
                   "WinSize......................................设置角点子像素搜索窗口的一半\n\n"
                   "Distance.....................................标定图左上角和右上角之间的实际距离\n\n"
                   "Write Detected Feature Points................写入检测到的特征点\n\n"
                   "Write Extrinsic Parameters...................写入外参矩阵\n\n"
                   "Write Refined 3D object Points...............写入优化的三维对象点\n\n"
                   "Assume Zero Tangential Distortion............假设切向畸变为零\n\n"
                   "Fix Aspect Ratio.............................固定纵横比\n\n"
                   "Fix the Principal Point......................将主点固定在中心\n\n"
                   "Flip the Captured Images.....................水平翻转图像\n\n"
                   "Show Undistorted Images......................标定结束后显示无畸变图像\n\n"
                   "标定结果：RMS的值越小，标定越精确，一般来说 < 1即可。可以多次取材标定\n\n"
                   "标定成功的要素：\n"
                   "1.取材要清晰。\n"
                   "2.标定板要足够精确。\n"
                   "3.标定照片数量要合适。\n"
                   "4.标定的角度要足够多。\n"
                   "本程序使用QT + OpenCV编写,部分素材来源于互联网，仅供学习与参考。\n";
    ui->textBrowser->insertPlainText(help);
}

void Dialog::stereoHelp(){
    QString help ="帮助文档:\n"
                  "双目相机标定，请选择左相机和右相机照片\n"
                  "确保左相机照片数量和右相机照片数量相等\n"
                  "然后设置棋盘格高(Chessboard Height)，棋盘格宽(Chessboard Width)和棋盘格单位元素大小(Chessboard Size)\n"
                  "点击添加到stereolist.yaml(Add to stereolist.yaml)\n"
                  "而后点击Calibrate进行标定\n"
                  "默认输出内参，外参矩阵在软件目录data下面\n"
                  "标定结果：RMS的值越小，标定越精确\n"
                  "如果矫正结果一团黑，则标定失败(要有正确的矫正画面输出，RMS必须小于1)\n"
                  "标定成功的要素：\n"
                  "1.取材要清晰。\n"
                  "2.标定板要足够精确。\n"
                  "3.标定照片数量要合适。\n"
                  "4.标定的角度要足够多。\n"
                  "本程序使用QT + OpenCV编写,部分素材来源于互联网，仅供学习与参考。\n";
    ui->textBrowser->insertPlainText(help);
}

Dialog::~Dialog()
{
    delete ui;
}
