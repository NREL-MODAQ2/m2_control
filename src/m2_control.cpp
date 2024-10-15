/**
 * @file m2_control.cpp
 * @author Robert Raye (robert.raye@nrel.gov)
 * @brief ros node doing basic HMI control
 * @version 0.1
 * @date 2024-10-02
 * 
 * @copyright Copyright (c) 2024
 * 
**/
#include "modaq_messages/msg/hmi.hpp"
#include "rclcpp/rclcpp.hpp"
#include <iostream>

class M2Control : public rclcpp::Node
{

public:
    M2Control()
        : Node("m2_control")
    {
        subscription_1 = this->create_subscription<modaq_messages::msg::Hmi>(
            "/hmi_ctl", 10, std::bind(&M2Control::sub1_callback, this, std::placeholders::_1));
    }

private:
    void sub1_callback(const modaq_messages::msg::Hmi::SharedPtr msg)
    {
        std::cout <<  msg << std::endl;

    }

    rclcpp::Subscription<modaq_messages::msg::Hmi>::SharedPtr subscription_1;

};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<M2Control>());
    rclcpp::shutdown();
    return 0;
}