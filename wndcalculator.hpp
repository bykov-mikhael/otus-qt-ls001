#pragma once

#include <QMainWindow>
#include <QStack>

QT_BEGIN_NAMESPACE
namespace Ui { class wndCalculator; }
QT_END_NAMESPACE

class wndCalculator : public QMainWindow {
  Q_OBJECT

  public:
  wndCalculator(QWidget *parent = nullptr);
  ~wndCalculator();

  private slots:
  void btnClicked();

  private:
  Ui::wndCalculator *ui;

  QString calculate();

  QStack<QString> _opstack;
  QString _sDisplay;
};
