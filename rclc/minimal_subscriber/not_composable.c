// Copyright 2016 Open Source Robotics Foundation, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <rclc/rclc.h>

#include <std_msgs/msg/string.h>

#include <stdio.h>

void chatter_callback(const void* v_msg)
{
  const std_msgs__msg__String* msg = v_msg;
  printf("I heard: [%s]\n", msg->data.data);
}

int main(void)
{
  static int argc = 0;
  static char **argv = NULL;

  rclc_init(argc, argv);
  rclc_node_t* node = rclc_create_node("minimal_subscriber", "");
  rclc_subscription_t* sub =
      rclc_create_subscription(node, RCLC_GET_MSG_TYPE_SUPPORT(std_msgs, msg, String), "topic", chatter_callback, 1, false);

  rclc_spin_node(node);

  rclc_destroy_subscription(sub);
  rclc_destroy_node(node);
  return 0;
}
