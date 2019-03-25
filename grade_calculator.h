#ifndef GRADE_CALCULATOR_H
#define GRADE_CALCULATOR_H

#include <QMainWindow>
#include <vector>

namespace Ui {
class grade_calculator;
}

class grade_calculator : public QMainWindow
{
    Q_OBJECT

public:
    explicit grade_calculator(QWidget *parent = nullptr);
    ~grade_calculator();

private slots:
    void on_score_button_clicked();
    double comboBox_A(bool radio_button, double midterm1, double midterm2, double final, double hw);
    double comboBox_B(bool radio_button, double midterm1, double midterm2, double final, double hw);


private:
    Ui::grade_calculator *ui;
    std::vector<double> score_array{8};
};

#endif // GRADE_CALCULATOR_H

