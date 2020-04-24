#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
//    connect(pushButton,SIGNAL(clicked()),this,SLOT(close()));
    QString help = "帮助文档:\n"
                   "单目相机标定，分为基础设置(Basic Settings)和高级设置(Advanced settings)\n"
                   "1.必须要填入的参数是选取的图像来源(Picture Source)，标定模式(Calibrate)\n"
                   "棋盘格或者圆点标靶的宽和高以及单位元素大小(Board Width,Board Height & Board Size)\n"
                   "2.在完成基础设置后，点击添加图片至imagelist.yaml(Add to imagelist.yml)\n"
                   "3.点击标定(Calibrate)，开始标定\n"
                   "高级设置可以获取更高的标定精度，部分参数简要中文说明如下：\n"
                   "Calibrate output.............................标定文件输出路径，默认在程序data目录下面\n"
                   "WinSize......................................设置角点子像素搜索窗口的一半\n"
                   "Distance.....................................标定图左上角和右上角之间的实际距离\n"
                   "Write Detected Feature Points................写入检测到的特征点\n"
                   "Write Extrinsic Parameters...................写入外参矩阵\n"
                   "Write Refined 3D object Points...............写入优化的三维对象点\n"
                   "Assume Zero Tangential Distortion............假设切向畸变为零\n"
                   "Fix Aspect Ratio.............................固定纵横比\n"
                   "Fix the Principal Point......................将主点固定在中心\n"
                   "Flip the Captured Images.....................水平翻转图像\n"
                   "Show Undistorted Images......................标定结束后显示无畸变图像\n"
                   "标定结果：RMS的值越小，标定越精确，一般来说 < 1即可。可以多次取材标定\n"
                   "本程序使用QT + OpenCV编写,部分素材来源于互联网，仅供学习与参考。\n";
    ui->textBrowser->insertPlainText(help);
}

Dialog::~Dialog()
{
    delete ui;
}
