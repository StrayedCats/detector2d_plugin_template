#pragma once

#include <opencv2/opencv.hpp>
#include <vision_msgs/msg/detection2_d_array.hpp>

namespace example_pkg{
class DetectorExample
{
public:
    DetectorExample();
    void detect(const cv::Mat &, vision_msgs::msg::Detection2DArray &);
};
}
