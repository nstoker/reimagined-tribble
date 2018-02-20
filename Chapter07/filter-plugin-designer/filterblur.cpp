#include <opencv2/imgproc.hpp>
#include "filterblur.h"

FilterBlur::FilterBlur()
{

}

FilterBlur::~FilterBlur()
{

}

QImage FilterBlur::process(const QImage &image)
{
    cv::Mat tmp(image.height(), image.width(), CV_8UC4, (uchar*)image.bits(), image.bytesPerLine());

    int blur = 17;
    cv::Mat resultMat;
    cv::GaussianBlur(tmp, resultMat, cv::Size(blur, blur), 0.0, 0.0);

    QImage resultImage((const uchar*) resultMat.data, resultMat.cols, resultMat.rows, resultMat.step, QImage::Format_RGB32);

    return resultImage.copy();

}
