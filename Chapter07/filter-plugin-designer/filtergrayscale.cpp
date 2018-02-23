#include "filtergrayscale.h"
#include <opencv2/imgproc.hpp>


FilterGrayscale::FilterGrayscale()
{

}

FilterGrayscale::~FilterGrayscale()
{

}

QImage FilterGrayscale::process(const QImage &image)
{
    // QImage to cv::mat
    cv::Mat tmp(image.height(), image.width(), CV_8UC4, (uchar*)image.bits(),image.bytesPerLine());

    cv::Mat resultMat;
    cv::cvtColor(tmp, resultMat, cv::COLOR_BGR2GRAY);

    QImage resultImage((const uchar *) resultMat.data,
                        resultMat.cols,
                        resultMat.rows,
                        resultMat.step,
                        QImage::Format_Grayscale8);
    return resultImage;
}
