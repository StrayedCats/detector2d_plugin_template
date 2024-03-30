#include "example_pkg/example.hpp"

namespace example_pkg{
    DetectorExample::DetectorExample() {
        /* TODO: Initialize the detector with default values */
    }

    void DetectorExample::detect(const cv::Mat & frame, vision_msgs::msg::Detection2DArray & boxes)
    {
        /* TODO: Implement the detection algorithm */
    }
}
