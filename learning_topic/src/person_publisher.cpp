#include <ros/ros.h>
#include "learning_topic/Person.h"

int main(int argc, char **argv) {
   ros::init(argc, argv, "person_publisher");

   ros::NodeHandle n;
  
   //发布名为/person_info的topic, 消息类型为learning_topic::Person, 队列长度10
   ros::Publisher person_info_sub = n.advertise<learning_topic::Person>("/person_info", 10);

   ros::Rate loop_rate(1);

   int count = 0;
   while(ros::ok()) {
      learning_topic::Person person_msg;
      person_msg.name = "Tom";
      person_msg.age = 18;
      person_msg.sex = learning_topic::Person::male;

      person_info_sub.publish(person_msg);

      ROS_INFO("Publish Person info: name:%s age:%d sex:%d",
              person_msg.name.c_str(), person_msg.age, person_msg.sex);

      loop_rate.sleep();

   }
   return 0;
}
