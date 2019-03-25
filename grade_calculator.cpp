#include "grade_calculator.h"
#include "ui_grade_calculator.h"


grade_calculator::grade_calculator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::grade_calculator)
{
    ui->setupUi(this);
    QObject::connect(ui->scA,SIGNAL(toggled(bool)),ui->scB,SLOT(setChecked(!bool)));
    QObject::connect(ui->scB,SIGNAL(toggled(bool)),ui->scA,SLOT(setChecked(!bool)));

    QObject::connect(ui->slider_hw1,SIGNAL(sliderMoved(int)),ui->spinBox_hw1,SLOT(setValue(int)));
    QObject::connect(ui->spinBox_hw1,SIGNAL(valueChanged(int)),ui->slider_hw1,SLOT(setValue(int)));

    QObject::connect(ui->slider_hw2,SIGNAL(sliderMoved(int)),ui->spinBox_hw2,SLOT(setValue(int)));
    QObject::connect(ui->spinBox_hw2,SIGNAL(valueChanged(int)),ui->slider_hw2,SLOT(setValue(int)));

    QObject::connect(ui->slider_hw3,SIGNAL(sliderMoved(int)),ui->spinBox_hw3,SLOT(setValue(int)));
    QObject::connect(ui->spinBox_hw3,SIGNAL(valueChanged(int)),ui->slider_hw3,SLOT(setValue(int)));

    QObject::connect(ui->slider_hw4,SIGNAL(sliderMoved(int)),ui->spinBox_hw4,SLOT(setValue(int)));
    QObject::connect(ui->spinBox_hw4,SIGNAL(valueChanged(int)),ui->slider_hw4,SLOT(setValue(int)));

    QObject::connect(ui->slider_hw5,SIGNAL(sliderMoved(int)),ui->spinBox_hw5,SLOT(setValue(int)));
    QObject::connect(ui->spinBox_hw5,SIGNAL(valueChanged(int)),ui->slider_hw5,SLOT(setValue(int)));

    QObject::connect(ui->slider_hw6,SIGNAL(sliderMoved(int)),ui->spinBox_hw6,SLOT(setValue(int)));
    QObject::connect(ui->spinBox_hw6,SIGNAL(valueChanged(int)),ui->slider_hw6,SLOT(setValue(int)));

    QObject::connect(ui->slider_hw7,SIGNAL(sliderMoved(int)),ui->spinBox_hw7,SLOT(setValue(int)));
    QObject::connect(ui->spinBox_hw7,SIGNAL(valueChanged(int)),ui->slider_hw7,SLOT(setValue(int)));

    QObject::connect(ui->slider_hw8,SIGNAL(sliderMoved(int)),ui->spinBox_hw8,SLOT(setValue(int)));
    QObject::connect(ui->spinBox_hw8,SIGNAL(valueChanged(int)),ui->slider_hw8,SLOT(setValue(int)));

    QObject::connect(ui->slider_mt1,SIGNAL(sliderMoved(int)),ui->spinBox_mt1,SLOT(setValue(int)));
    QObject::connect(ui->spinBox_mt1,SIGNAL(valueChanged(int)),ui->slider_mt1,SLOT(setValue(int)));

    QObject::connect(ui->slider_mt2,SIGNAL(sliderMoved(int)),ui->spinBox_mt2,SLOT(setValue(int)));
    QObject::connect(ui->spinBox_mt2,SIGNAL(valueChanged(int)),ui->slider_mt2,SLOT(setValue(int)));

    QObject::connect(ui->spinBox_fin,SIGNAL(valueChanged(int)),ui->slider_fin,SLOT(setValue(int)));
    QObject::connect(ui->slider_fin,SIGNAL(sliderMoved(int)),ui->spinBox_fin,SLOT(setValue(int)));

    QObject::connect(ui->score_button,SIGNAL(cicked()),this,SLOT(on_score_button_clicked()));
     // hw 1-8, mt1, mt2, final
}

grade_calculator::~grade_calculator()
{
    delete ui;
}


double grade_calculator::comboBox_A(bool radio_button, double midterm_lower, double midterm_higher, double final, double hw) { // pic10B class, from previous syllabus

    if (radio_button) { // scheme A is checked, 25% Assignments + 20% Midterm 1 + 20% Midterm 2 + 35% Final Exam
        return (hw * 0.25 + midterm_lower * 0.2 +  midterm_higher* 0.2 + final *0.35);
    }
    return ( hw * 0.25 + midterm_higher * 0.3 +  final * 0.45 );
}

double grade_calculator::comboBox_B(bool radio_button, double midterm_lower, double midterm_higher, double final, double hw) { // the other class, from spec

    if (radio_button) { // scheme A is checked

        return (hw * 0.25 + midterm_lower * 0.2 +  midterm_higher* 0.2 + final *0.35);
    }
    return (hw * 0.25 + midterm_higher * 0.3 +  final * 0.44 );
}



void grade_calculator::on_score_button_clicked(){
    double score;
    score_array[0]=ui->spinBox_hw1->value();
    score_array[1]=ui->spinBox_hw2->value();
    score_array[2]=ui->spinBox_hw3->value();
    score_array[3]=ui->spinBox_hw4->value();
    score_array[4]=ui->spinBox_hw5->value();
    score_array[5]=ui->spinBox_hw6->value();
    score_array[6]=ui->spinBox_hw7->value();
    score_array[7]=ui->spinBox_hw8->value();
    // score_array[8]=ui->spinBox_mt1->value();
    // score_array[9]=ui->spinBox_mt2->value();
    // score_array[10]=ui->spinBox_fin->value();
    double midterm_lower = ui->spinBox_mt1->value();
    double midterm_higher = ui->spinBox_mt2->value();
    double final = score_array[10]=ui->spinBox_fin->value();
    double homework_average_with_drop=0;
    double homework_average_without_drop=0;
    double min_score=score_array[0];


    for (int i=0; i< 8; ++i) {
        homework_average_without_drop += score_array[i];
        if (min_score < score_array[i])
            min_score = score_array[i];
    }
    homework_average_with_drop = homework_average_without_drop - min_score;
    homework_average_with_drop = homework_average_with_drop / 7.0;
    homework_average_without_drop = homework_average_without_drop / 8.0;


    if (midterm_lower > midterm_higher)
        std::swap(midterm_lower, midterm_higher);

    if (ui->comboBox->currentText()=="Pic 10C. Interemediate Programming"){

        score = comboBox_A(ui->scA->isChecked(), midterm_lower, midterm_higher, final, homework_average_without_drop);
    }

    else {
        score = comboBox_B(ui->scA->isChecked(), midterm_lower, midterm_higher, final, homework_average_with_drop);
    }

    ui->overall_score->setText(QString::number(score));

    return;
}


