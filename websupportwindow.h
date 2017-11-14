#ifndef WEBSUPPORTWINDOW_H
#define WEBSUPPORTWINDOW_H

#include <QDialog>
#include <QUrl>

namespace Ui {
class WebSupportWindow;
}

class WebSupportWindow : public QDialog
{
    Q_OBJECT

public:
    explicit WebSupportWindow(QWidget *parent = 0,QUrl URL=QUrl(QString("https://zzzzzzs.github.io/")));
    ~WebSupportWindow();

    void load();
private slots:
    void BackSlot();
private:
    Ui::WebSupportWindow *ui;
};

#endif // WEBSUPPORTWINDOW_H
