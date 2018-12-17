#include "../inc/view.hpp"

void gpub::View::updateBallState(State state, cv::Mat img){
/*

        capture.read(original);

        if(original.empty() == true)
            return;

        // Text box to see slider values (can be used as an event for efficiency)
        ui->SldBlueValue->clear();
        ui->SldBlueValue->appendPlainText(QString("(") +
                                          QString::number(ui->SldBlueLower->value()).rightJustified(3,' ') +
                                          QString(",") +
                                          QString::number(ui->SldBlueUpper->value()).rightJustified(3,' ') +
                                          QString(")"));


        // Check inRange based on the slider values
        cv::inRange(original,cv::Scalar(ui->SldBlueLower->value(),ui->SldGreenLower->value(),ui->SldRedLower->value()),
                             cv::Scalar(ui->SldBlueUpper->value(),ui->SldGreenUpper->value(),ui->SldRedUpper->value()),processed);
        // Blur image
        //cv::GaussianBlur(processed,processed,cv::Size(9,9),1.5);
        // Algorithm function here



        // OpenCV to QImage datatype to display on labels
        cv::cvtColor(original,original,CV_BGR2RGB);
        QImage qimgOriginal((uchar*) original.data,original.cols,original.rows,original.step,QImage::Format_RGB888); // for color images
        QImage qimgProcessed((uchar*) processed.data,processed.cols,processed.rows,processed.step,QImage::Format_Indexed8); // for grayscale images

        // Update the labels on the form
        ui->lblOriginal->setPixmap(QPixmap::fromImage(qimgOriginal));

*/
}
