#include "wndcalculator.hpp"
#include <QDebug>
#include "./ui_wndcalculator.h"

wndCalculator::wndCalculator(QWidget *parent)
: QMainWindow(parent), ui(new Ui::wndCalculator) {
  ui->setupUi(this);

  connect(ui->cmd0, &QPushButton::clicked, this, &wndCalculator::btnClicked);
  connect(ui->cmd1, &QPushButton::clicked, this, &wndCalculator::btnClicked);
  connect(ui->cmd2, &QPushButton::clicked, this, &wndCalculator::btnClicked);
  connect(ui->cmd3, &QPushButton::clicked, this, &wndCalculator::btnClicked);
  connect(ui->cmd4, &QPushButton::clicked, this, &wndCalculator::btnClicked);
  connect(ui->cmd5, &QPushButton::clicked, this, &wndCalculator::btnClicked);
  connect(ui->cmd6, &QPushButton::clicked, this, &wndCalculator::btnClicked);
  connect(ui->cmd7, &QPushButton::clicked, this, &wndCalculator::btnClicked);
  connect(ui->cmd8, &QPushButton::clicked, this, &wndCalculator::btnClicked);
  connect(ui->cmd9, &QPushButton::clicked, this, &wndCalculator::btnClicked);

  connect(ui->cmdPlus, &QPushButton::clicked, this, &wndCalculator::btnClicked);
  connect(ui->cmdMinus, &QPushButton::clicked, this,
          &wndCalculator::btnClicked);
  connect(ui->cmdMult, &QPushButton::clicked, this, &wndCalculator::btnClicked);
  connect(ui->cmdDiv, &QPushButton::clicked, this, &wndCalculator::btnClicked);

  connect(ui->cmdResult, &QPushButton::clicked, this,
          &wndCalculator::btnClicked);
}

wndCalculator::~wndCalculator() { delete ui; }
/**
 * @brief clickedButton
 * "-" - умножение на -1
 * "." -
 * "=" - вызов функции calculate()
 */
void wndCalculator::btnClicked() {
  QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());

  QString str = clickedButton->text();

  if (str.contains(QRegExp("[0-9]"))) {
    _sDisplay = str;
    _opstack.push(str);
    ui->lcdResult->display(_sDisplay.toDouble());
    ui->lblResult->setText(_sDisplay);
  }

  if (str.contains(QRegExp("[+\\-*/]"))) {
    _opstack.push(str);
    ui->lblResult->setText(_sDisplay);
  }

  if (str == "=") {
    ui->lblResult->setText(calculate());
    _opstack.clear();
  }
}

QString wndCalculator::calculate() {
  qreal _op002 = _opstack.pop().toFloat();
  QString _sOpertor = _opstack.pop();
  qreal _op001 = _opstack.pop().toFloat();
  qreal _rResult = 0;

  if (_sOpertor == "+") {
    _rResult = _op001 + _op002;
  }

  if (_sOpertor == "-") {
    _rResult = _op001 - _op002;
  }

  if (_sOpertor == "*") {
    _rResult = _op001 * _op002;
  }

  if (_sOpertor == "/") {
    _rResult = _op001 / _op002;
  }

  ui->lcdResult->display(_rResult);

  return QString::number(_rResult, 'f', 4);
}
