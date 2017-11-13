#ifndef ABOUTWINDOW_H
#define ABOUTWINDOW_H

#include <QDialog>
#include <QDesktopServices>
namespace Ui {
class AboutWindow;
}

class AboutWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AboutWindow(QWidget *parent = 0);
    ~AboutWindow();

private slots:
    void BlogSlot();
    void FeedBackSlot();
private:
    Ui::AboutWindow *ui;
    QPixmap logo;
    QPixmap zzs;
};


#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#endif // ABOUTWINDOW_H
