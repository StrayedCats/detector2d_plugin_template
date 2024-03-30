#include "example_pkg/example.hpp"

namespace example_pkg{
    DetectorExample::DetectorExample() {
        /* TODO: Initialize the detector with default values */
    }

    void DetectorExample::detect(const cv::Mat & frame, vision_msgs::msg::Detection2DArray & boxes)
    {
        /* TODO: Implement the detection algorithm */
    }

    cv::Mat3b DetectorExample::draw_bboxes(
        const cv::Mat & frame,
        const vision_msgs::msg::Detection2DArray & boxes)
    {
        cv::Mat3b frame_out;
        if (frame.channels() == 1)
        {
            cv::cvtColor(frame, frame_out, cv::COLOR_GRAY2BGR);
        }
        else {
            frame_out = frame;
        }

        for (auto detection : boxes.detections)
        {
            cv::Rect bbox;
            bbox.x = detection.bbox.center.position.x - detection.bbox.size_x / 2;
            bbox.y = detection.bbox.center.position.y - detection.bbox.size_y / 2;
            bbox.width = detection.bbox.size_x;
            bbox.height = detection.bbox.size_y;
            cv::rectangle(frame_out, bbox, cv::Scalar(0, 255, 0), 2);
        }
        return frame_out;
    }
}
