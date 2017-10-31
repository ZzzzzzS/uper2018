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
};

#endif // ABOUTWINDOW_H
