// Copyright 2016 Proyectos y Sistemas de Mantenimiento SL (eProsima).
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

#include <string>
#include <vector>

#include "namespace_prefix.hpp"

extern "C"
{
// static for internal linkage
const char * const ros_topic_prefix = "rt";
const char * const ros_service_requester_prefix = "rq";
const char * const ros_service_response_prefix = "rr";

const std::vector<std::string> _ros_prefixes =
{ros_topic_prefix, ros_service_requester_prefix, ros_service_response_prefix};
}  // extern "C"

/// Return the ROS specific prefix if it exists, otherwise "".
std::string
_get_ros_prefix_if_exists(const std::string & topic_name)
{
  for (auto prefix : _ros_prefixes) {
    if (topic_name.rfind(std::string(prefix) + "/", 0) == 0) {
      return prefix;
    }
  }
  return "";
}